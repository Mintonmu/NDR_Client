#include "noticedialog.hpp"
#include "ui_noticedialog.h"
#include <QDesktopWidget>
#include <QDebug>
#include <QMouseEvent>

NoticeDialog::NoticeDialog(QWidget *parent)
    : QDialog(parent), ui{new Ui::NoticeDialog} {
  this->setWindowOpacity(0.8);
  this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint |
                       Qt::Tool);
  ui->setupUi(this);
  setFixedSize(this->width(), this->height());
}

void NoticeDialog::showMessage(QString const &msg) {
  qDebug() << "message thread: " << QThread::currentThread() << endl;
  // first set text, then show
  this->ui->label->setText(msg);
  // change to half model dialog
  if (this->isVisible()) {
    QSize desktop_size = qApp->desktop()->size();
    move((desktop_size.width() - this->width()) / 2,
         (desktop_size.height() - this->height()) / 2);
    this->show();
    this->setModal(true);
  }
}

void NoticeDialog::mouseMoveEvent(QMouseEvent *e) {
  if (isDown) {
    this->move(this->pos().x() + (e->globalX() - x),
               this->pos().y() + (e->globalY() - y));
    x = e->globalX();
    y = e->globalY();
  }
}

void NoticeDialog::mouseReleaseEvent(QMouseEvent *e) {
  if (e->button() == Qt::LeftButton) {
    isDown = false;
  }
}

void NoticeDialog::mousePressEvent(QMouseEvent *e) {
  if (e->button() == Qt::LeftButton) {
    isDown = true;
    x = e->globalX();
    y = e->globalY();
  }
}
