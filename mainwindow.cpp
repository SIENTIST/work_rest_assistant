#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QMessageBox>

#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->workTimeEdit->setText("45");
    ui->restTimeEdit->setText("5");

    m_stateFlag = 0;

    m_pCircleTimer = new QTimer(this);
    m_pCircleTimer->stop();
    m_pCircleTimer->setInterval(1000); //设置定时周期，单位：毫秒
    connect(m_pCircleTimer, SIGNAL(timeout()), this, SLOT(Circle()));


}

//http://c.biancheng.net/view/1848.html
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Circle()
{
    sTime currrntTime = getCurrentTime();

    if(currrntTime.hour == m_endTime.hour
    && currrntTime.minute >= m_endTime.minute)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"Rest reminder", "Please rest.", QMessageBox::Yes, QMessageBox::No))
        {
        }

        m_startTime = currrntTime;
        m_endTime = calcEndTime(currrntTime, m_workMinute);
    }


}

void MainWindow::on_switchBtn_clicked()
{

#if 1
    if(m_stateFlag == 0)
    {
        m_stateFlag = 1;

        QString finishStr = "| 结束 |";
        ui->switchBtn->setText(finishStr);

        QString str = "状态：正在运行";
        ui->displayStateLabel->setText(str);

        m_startTime = getCurrentTime();

        m_workMinute = (int)ui->workTimeEdit->text().toFloat();

        m_endTime = calcEndTime(m_startTime, m_workMinute);

        m_pCircleTimer->start();

    }
    else if(m_stateFlag == 1)
    {
        ui->switchBtn->setText("^ Start ^");
        QString str = "状态：停止运行";
        ui->displayStateLabel->setText(str);

        m_stateFlag = 0;

        memset( (void *)&m_startTime, 0x00, sizeof(sTime));
        memset( (void *)&m_endTime, 0x00, sizeof(sTime));

        m_pCircleTimer->stop();
    }
#endif
}
