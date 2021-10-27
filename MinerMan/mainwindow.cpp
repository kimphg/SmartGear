#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QProcess>
int stage = 0;
int stabCount = 0;
QHash<QString,QString> miner_output;
QProcess process_miner;
QProcess process_oc;
QProcess process_watcher;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // in constructor

    runProcess();
    startTimer(1000);
    stage = 0;

}
// slot connected to a QAction
void MainWindow::timerEvent(QTimerEvent *event)
{
    stabCount++;
    if(stabCount>12&&stage==1)
    {
        stage = 2;
    }
    if(!process_oc.isOpen())
    {
        process_oc.setArguments(QStringList());
        process_oc.start();
    }

//    if(!process_watcher.isOpen())
//    {
//        process_watcher.setArguments(QStringList());
//        process_watcher.start();
//    }
}
void MainWindow::readOutputOC()
{
    QString output = process_oc.readAllStandardOutput();
    ui->plainTextEdit_oc->setPlainText(output);
}
void MainWindow::StartMiner()
{
    //miner process
    QString sh = "PhoenixMiner/PhoenixMiner.exe" ;
    process_miner.setProgram(sh);
    QString args = " -pool " +ui->lineEdit_pool1->text()+" -pool2 "+ ui->lineEdit_pool2->text();//asia2.ethermine.org:5555 -wal 0x8f3ef62b3ce472ffe7999dc52701a6957efc6e45.g5phuong";
    args.append(" -wal "+ ui->lineEdit_wallet->text());
    args.append(" "+ui->plainTextEdit_params->toPlainText());
    process_miner.setArguments(args.split(" "));
    if(!process_miner.isOpen())
    {
        system("taskkill /im phoenixminer.exe");
        process_miner.start();
    }
}
void MainWindow::runProcess()
{
    //miner process
    QString sh = "PhoenixMiner/PhoenixMiner.exe" ;
    QString args = "-pool ssl://asia1.ethermine.org:5555 -pool2 ssl://asia2.ethermine.org:5555 -wal 0x8f3ef62b3ce472ffe7999dc52701a6957efc6e45.g5phuong";//qgetenv("SHELL");
    args.append(" -epsw x -mode 1 -log 0 -mport 0 -etha 0 -ftime 55 -retrydelay 1 -tt 79 -tstop 89 -coin eth");
    process_miner.setProgram(sh);
    process_miner.setArguments(args.split(" "));
    connect(&process_miner, &QProcess::readyReadStandardOutput, this, &MainWindow::readOutputMiner);

    //oc process
    sh = QString("nvoc.exe");
    args = QString();
    process_oc.setProgram(sh);
    process_oc.setArguments(args.split(" "));
    connect(&process_oc, &QProcess::readyReadStandardOutput, this, &MainWindow::readOutputOC);

    //watcher process
    sh = QString("tasklist");
    args = QString();
    process_watcher.setProgram(sh);
    process_watcher.setArguments(args.split(" "));
    connect(&process_watcher, &QProcess::readyReadStandardOutput, this, &MainWindow::readOutputWatcher);

}
void MainWindow::readOutputMiner()
{
    QString output = process_miner.readAllStandardOutput();
    QStringList datafields = output.split(':');
    if(datafields.size()>1)
    {
        QString key = datafields[0];
        QString data = output;
        miner_output.insert(key,data);
        updateInfo();
    }
    if(stage==2)
    {
        //check pool
        if(output.contains("New job"))
        {
            if(!output.contains(ui->lineEdit_pool1->text()))
            if(!output.contains(ui->lineEdit_pool2->text()))
            {
                ui->plainTextEdit_system->appendPlainText(QDateTime::currentDateTime().toString("hh:mm:ss")+"pool changed, restart miner\n");
                on_pushButton_clicked();
            }
        }

    }

}
void MainWindow::readOutputWatcher()
{
    QString output = process_miner.readAllStandardOutput();
    printf(output.toStdString().data());
    flushall();

}
void MainWindow::updateInfo()
{
    ui->plainTextEdit->clear();
    for ( QHash<QString,QString>::iterator it = miner_output.begin(); it != miner_output.end(); ++it)
    {
        ui->plainTextEdit->appendPlainText(it.value());
    }
}
MainWindow::~MainWindow()
{
    process_miner.terminate();
    process_miner.waitForFinished();
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

        system("taskkill /im phoenixminer.exe");
        process_miner.start();
        stage=1;


//    process.write("dir"); // first test
}

void MainWindow::on_pushButton_oc_clicked()
{
    QStringList args;
    args.append(ui->lineEdit_core->text());
    args.append(ui->lineEdit_mem->text());
    process_oc.setArguments(args);
    process_oc.start();
}
