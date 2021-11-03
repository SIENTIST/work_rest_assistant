#ifndef REST_REMIND_DIALOG_H
#define REST_REMIND_DIALOG_H

#include <QDialog>
#include <vector>
#include <QPixmap>
#include <QString>

namespace Ui {
class CrestRemindDialog;
}

class CrestRemindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CrestRemindDialog(QWidget *parent = nullptr);
    ~CrestRemindDialog();

    void changePictureLable();

    void getRestTime(QString restTime);
    void getOtherRemind(QString remindStr);
private:
    Ui::CrestRemindDialog *ui;

    std::vector<QPixmap> m_pixmapVec;
};

#endif // REST_REMIND_DIALOG_H
