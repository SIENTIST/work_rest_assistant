#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "assistant.h"
#include "rest_remind_dialog/rest_remind_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_switchBtn_clicked();
    void WorkRestCircle();

public:


private:
    Ui::MainWindow *ui;

    int m_stateFlag;
    int m_workMinute;
    int m_restMinute;

    int m_workRestState;

    sTime m_currentTime;
    sTime m_startWorkTime;

    sTime m_workEndTime;
    sTime m_restEndTime;

    QTimer* m_pWorkRestTimer;

    QPixmap m_messagePix;

    CrestRemindDialog m_restRemindDisplay;
};
#endif // MAINWINDOW_H
