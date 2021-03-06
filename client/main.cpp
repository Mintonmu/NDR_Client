#include <QApplication>
#include <QNetworkProxy>
#include <QNetworkProxyFactory>
#include <QObject>
#include <QSharedMemory>
#include <QStyleFactory>
#include <QTextCodec>
#include <ndrapplication.hpp>
#include <pppoe.hpp>
#include <qapplication.h>
#include <resourcemanager.hpp>
#include <utils.hpp>

#include "qmlmanager/qmlwindowsmanager.hpp"
#include <QMessageBox>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickItem>
#include <QQuickView>
#include <iostream>

#if defined(QT_DEBUG) && defined(Q_OS_WIN)
#include <DbgHelp.h>
#endif

#if defined(QT_DEBUG) && defined(Q_OS_WIN)
// windows debug handler
LONG ApplicationCrashHandler(EXCEPTION_POINTERS *pException) { //程式异常捕获
    /*
     ***保存数据代码***
     */
    //创建 Dump 文件
    HANDLE hDumpFile = CreateFileW(NULL, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
                                   FILE_ATTRIBUTE_NORMAL, NULL);
    if (hDumpFile != INVALID_HANDLE_VALUE) {
        // Dump信息
        MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
        dumpInfo.ExceptionPointers = pException;
        dumpInfo.ThreadId = GetCurrentThreadId();
        dumpInfo.ClientPointers = TRUE;
        //写入Dump文件内容
        MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile,
                          MiniDumpNormal, &dumpInfo, NULL, NULL);
    }
    //这里弹出一个错误对话框并退出程序
    EXCEPTION_RECORD *record = pException->ExceptionRecord;
    QString errCode(QString::number(record->ExceptionCode, 16)),
        errAdr(QString::number(
            reinterpret_cast<uint64_t>(record->ExceptionAddress), 16)),
        errMod;
    QMessageBox::critical(
        NULL, "程式崩溃",
        "<FONT size=4><div><b>对于发生的错误，表示诚挚的歉意</b><br/></div>" +
            QString("<div>错误代码：%1</div><div>错误地址：%2</div></FONT>")
                .arg(errCode)
                .arg(errAdr),
        QMessageBox::Ok);
    return EXCEPTION_EXECUTE_HANDLER;
}
#endif

int main(int argc, char *argv[]) {
    //  high dpi support!
    // this support is so bad, we can not use it
    qInstallMessageHandler(utils::messageHandler);
    QNetworkProxyFactory::setUseSystemConfiguration(false);

#if defined(Q_OS_MAC) || defined(Q_OS_WIN32)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
#ifndef Q_OS_MAC
    QApplication::setStyle("cleanlooks");
#endif
#if defined(QT_DEBUG) && defined(Q_OS_WIN)
    SetUnhandledExceptionFilter(
        static_cast<LPTOP_LEVEL_EXCEPTION_FILTER>(ApplicationCrashHandler));
#endif

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    qDebug () << "start";
    NdrApplication ndrApp{"N-Client", argc, argv};



    ndrApp.NdrApplication::setQuitOnLastWindowClosed(false);

    qDebug() << "stat load qml";
    QMLWindowsManager qmlAboutDialog{&ndrApp};

    return ndrApp.NdrApplication::exec();
}
