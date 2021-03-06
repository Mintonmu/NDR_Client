#pragma once
#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFontDatabase>
#include <QLibraryInfo>
#include <QMap>
#include <QObject>
#include <QStringList>
#include <QTranslator>
#include <ndrapplication.hpp>
#include <ndrconfig.hpp>
#include <qaesencryption.h>
#include <resourcemanager.hpp>
#include <settingsset.hpp>

namespace utils {
extern QString appHome; //家目录
extern QString tempDir; //临时文件夹
extern QSharedPointer<SettingsSet> settings;
extern QTranslator ndr_tr, qt_tr;
extern ResourceManager resourceManager;
extern QSharedPointer<QAESEncryption> encryption;
/** 获取账户名套餐后缀列表*/
QStringList getDrModelPostfixTable();

/** 根据套餐后缀获取套餐描述*/
QVariant getDrModelCaption(QString const &postfix);

QString getDrModel(QString const &postfix);

/** 获取语言所在路径，失败返回空字符串*/
QString getLangDir();

QString getVersionString();

QStringList getLangFileNameTable();

/**
 * @brief getLanguageName 根据文件名获取语言名称
 * @param fileName 文件名
 * @return 成功/失败 待返回的语言名称字符串
 */
QVariant getLanguageName(QString const &fileName);

void initAppHome();
void initTempDir();

/** 设置项*/
extern QSharedPointer<SettingsSet> settings;
void initSettingsSet();

void initLanguage();
void initFont(QString const &fontFile);
void initStyleSheet(NdrApplication *a, QString const &sheetFile);
void messageHandler(QtMsgType type, const QMessageLogContext &context,
                    const QString &msg);

} // namespace utils

