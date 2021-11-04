#include "rest_remind_dialog.h"
#include "ui_rest_remind_dialog.h"

#include <QLabel>
#include <QRandomGenerator>

CrestRemindDialog::CrestRemindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CrestRemindDialog)
{

    ui->setupUi(this);

    for(int i = 0; i <= 17; i++)
    {
        QPixmap pixmap;
        if(!(pixmap.load(":/new/prefix1/picture_resource/" + QString::number(i) + ".jpg"))) //加载图像到vector中
        {
            continue;
        }

        QPixmap scalePixmap = pixmap.scaled(ui->pictureLabel->size(), Qt::KeepAspectRatio);
        m_pixmapVec.push_back(scalePixmap);
    }
}

CrestRemindDialog::~CrestRemindDialog()
{
    delete ui;
}

void CrestRemindDialog::changePictureLable()
{
    ui->pictureLabel->setScaledContents(true);

    int vecSize = m_pixmapVec.size();

    int index = QRandomGenerator::global()->bounded(vecSize - 1); //生成一个随机数

    ui->pictureLabel->setPixmap(m_pixmapVec[index]);
}

void CrestRemindDialog::getRestTime(QString restTime)
{
    ui->restRemindLabel->setText("(=^_^=)  Please rest for " + restTime + " minute.  (=￣ω￣=)");
}

void CrestRemindDialog::getOtherRemind(QString remindStr)
{
    ui->otherRemindLabel->setText(remindStr);
}
