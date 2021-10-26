#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void runProcess();
public slots:
    void readOutputMiner();
    void readOutputOC();
protected slots:
    void timerEvent(QTimerEvent *event);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_oc_clicked();

private:
    Ui::MainWindow *ui;
    void updateInfo();

};
#endif // MAINWINDOW_H
