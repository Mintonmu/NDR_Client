#ifndef MESSAGEVIEWERDIALOG_H
#define MESSAGEVIEWERDIALOG_H

#include <QDialog>

namespace Ui {
class MessageViewerDialog;
}

class MessageViewerDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MessageViewerDialog(QWidget *parent = 0);
    ~MessageViewerDialog();
    
private:
    Ui::MessageViewerDialog *ui;
};

#endif // MESSAGEVIEWERDIALOG_H