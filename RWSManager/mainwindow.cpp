#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QUdpSocket(this);
    if(socket->bind(4000))
    {
        //        connect(navSocket,SIGNAL(readyRead()),this, SLOT(ReadNavData()));
        //initAverCapture();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bt_send_pid_clicked()
{
    float value = ui->lineEdit_vp->text().toFloat();
    setParam("vp",value);
    value = ui->lineEdit_vi->text().toFloat();
    setParam("vi",value);
    value = ui->lineEdit_vd->text().toFloat();
    setParam("vd",value);
    value = ui->lineEdit_hp->text().toFloat();
    setParam("hp",value);
    value = ui->lineEdit_hi->text().toFloat();
    setParam("hi",value);
    value = ui->lineEdit_hd->text().toFloat();
    setParam("hd",value);

}
void MainWindow::setParam(QString com,float value)
{
    QByteArray dataout;
    dataout.append("$COM,set,");
    dataout.append(com.toUtf8());
    dataout.append(",");
    dataout.append(QString::number(value));
    //    dataout.append(",");
    socket->writeDatagram(dataout,QHostAddress("192.168.0.7"),4001);

}
