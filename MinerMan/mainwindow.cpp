#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProcess>
QHash<QString,QString> miner_output;
QProcess process_miner;
QProcess process_oc;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // in constructor

    runProcess();
    startTimer(1000);

}
// slot connected to a QAction
void MainWindow::timerEvent(QTimerEvent *event)
{
    if(!process_miner.isOpen())process_miner.start();
    if(!process_oc.isOpen())
    {
        process_oc.setArguments(QStringList());
        process_oc.start();
    }
}
void MainWindow::readOutputOC()
{
    QString output = process_oc.readAllStandardOutput();
    ui->plainTextEdit_oc->setPlainText(output);
}
void MainWindow::runProcess()
{
    QString sh = "PhoenixMiner/PhoenixMiner.exe" ;
    QString args = "-pool ssl://asia1.ethermine.org:5555 -pool2 asia2.ethermine.org:5555 -wal 0x8f3ef62b3ce472ffe7999dc52701a6957efc6e45.g5phuong";//qgetenv("SHELL");
    args.append(" -epsw x -mode 1 -log 0 -mport 0 -etha 0 -ftime 55 -retrydelay 1 -tt 79 -tstop 89 -coin eth");
    process_miner.setProgram(sh);
    process_miner.setArguments(args.split(" "));
    sh = QString("nvoc.exe");
    args = QString();
    process_oc.setArguments(args.split(" "));
    connect(&process_miner, &QProcess::readyReadStandardOutput, this, &MainWindow::readOutputMiner);
    connect(&process_oc, &QProcess::readyReadStandardOutput, this, &MainWindow::readOutputOC);
//    process_miner.start();//sh,QStringList() << "-i");

//    process.write("dir"); // first test
    // process.execute("ls"); // second test

//    process.closeWriteChannel();
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
    if(process_miner.isOpen())process_miner.kill();

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
