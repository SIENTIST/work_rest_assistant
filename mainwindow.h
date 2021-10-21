#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "assistant.h"

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
    void Circle();
public:


private:
    Ui::MainWindow *ui;

    int m_stateFlag;
    int m_workMinute;
    int m_restMinute;

    sTime m_currentTime;
    sTime m_startTime;
    sTime m_endTime;

    QTimer* m_pCircleTimer;
};
#endif // MAINWINDOW_H
