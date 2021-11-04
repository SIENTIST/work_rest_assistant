#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QMessageBox>
#include <QImage>
#include <QPixmap>

#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("It's time for a break"); //rest time is comming

    ui->workTimeEdit->setText("45"); //设定显示的初始值
    ui->restTimeEdit->setText("5");
    ui->otherRemindLineEdit->setText("记得喝水");

    m_stateFlag = 0;

    m_pWorkRestTimer = new QTimer(this);
    m_pWorkRestTimer->stop();
    m_pWorkRestTimer->setInterval(1000); //设置定时周期，单位:毫秒   现在设定为每一秒检查一次时间
    connect(m_pWorkRestTimer, SIGNAL(timeout()), this, SLOT(WorkRestCircle())); //将工作休息定时器连接到函数

    m_workRestState = 0; // 0未启动；1工作中；2休息中
}


//http://c.biancheng.net/view/1848.html
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::WorkRestCircle()
{
    sTime currrntTime = getCurrentTime(); //获取当前时间

    if(m_workRestState == 1 //正在工作中
    && currrntTime.hour == m_workEndTime.hour
    && currrntTime.minute >= m_workEndTime.minute) //工作时间到头
    {
        // 弹出提醒休息窗口

//        if(QMessageBox::Yes == QMessageBox::question(this,"Rest reminder", "Please rest " + ui->restTimeEdit->text() + " minute!", QMessageBox::Yes, QMessageBox::No))
//        {
//        } //程序的进程会卡在这里


//        QMessageBox message(QMessageBox::NoIcon, "休息时间到了~", "Please reset for " + ui->restTimeEdit->text() + " minutes.");
//        message.setIconPixmap(m_messagePix);
//        message.setWindowFlags(Qt::WindowStaysOnTopHint);
//        message.exec();

        m_restRemindDisplay.changePictureLable();

        m_restRemindDisplay.getRestTime(ui->restTimeEdit->text());
        m_restRemindDisplay.getOtherRemind(ui->otherRemindLineEdit->text());

        m_restRemindDisplay.setWindowFlags(m_restRemindDisplay.windowFlags() | Qt::WindowStaysOnTopHint); //使对话框弹出在所有程序的顶端
        m_restRemindDisplay.exec();  //使用exec而不是show，使程序阻塞在此处

//        ///---实例化消息对话框对象
//        QMessageBox *msgBox;
//        msgBox = new QMessageBox("title",		///--这里是设置消息框标题
//            "messageBox comment",						///--这里是设置消息框显示的内容
//            QMessageBox::Critical,							///--这里是在消息框显示的图标
//            QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
//            QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
//            0);														///---这里是 定义第三个按钮， 该例子 只是 了显示2个按钮

//        msgBox->show();									///---显示消息框

//        QMessageBox *msgBox;
//        msgBox = new QMessageBox("title", "text", QMessageBox::Question,QMessageBox::Ok | QMessageBox::Default,NULL,0);
//        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
//        msgBox->exec();


        m_workRestState = -1; //进入休息状态

        currrntTime = getCurrentTime(); //重新获取当前时间
        int restTimeMinute = (int)ui->restTimeEdit->text().toFloat(); //获取休息时间

        m_restEndTime = TimeAddMinute(currrntTime, restTimeMinute);   //计算休息结束时间
    }

    if(m_workRestState == -1 //在休息中
    && currrntTime.hour == m_restEndTime.hour
    && currrntTime.minute >= m_restEndTime.minute)  //休息时间到头
    {
        m_workRestState = 1; //进入工作状态

        int workTimeMinute = (int)ui->workTimeEdit->text().toFloat(); //获取工作时间  不直接转int，是为了避免输入浮点型造成错误
        m_workEndTime = TimeAddMinute(currrntTime, workTimeMinute); //计算新的工作结束时间
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

        m_pWorkRestTimer->start(); //启动工作休息定时器
        m_workRestState = 1;       //进入工作状态

        sTime currrntTime = getCurrentTime(); //获取当前时间
        int workTimeMinute = (int)ui->workTimeEdit->text().toFloat(); //获取工作时间  不直接转int，是为了避免输入浮点型造成错误

        m_workEndTime = TimeAddMinute(currrntTime, workTimeMinute);   //计算工作结束时间
    }
    else if(m_stateFlag == 1)
    {
        ui->switchBtn->setText("^ Start ^");
        QString str = "状态：停止运行";
        ui->displayStateLabel->setText(str);

        m_stateFlag = 0;

        memset( (void *)&m_startWorkTime, 0x00, sizeof(sTime));
        memset( (void *)&m_workEndTime, 0x00, sizeof(sTime));

        m_pWorkRestTimer->stop(); //关闭工作休息定时器
        m_workRestState = 0;
    }
#endif
}
