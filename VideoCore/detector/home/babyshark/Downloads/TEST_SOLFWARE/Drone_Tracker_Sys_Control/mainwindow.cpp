#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QByteArray>
#include <QBuffer>
#include <QDataStream>
#include <QDebug>
#include<QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , udpSocket(new QUdpSocket(this))
{
    ui->setupUi(this);

    // Thiết lập socket để lắng nghe trên cổng 12345
    udpSocket->bind(QHostAddress::LocalHost, 12345);
    connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::processPendingDatagrams);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processPendingDatagrams()
{
    static QByteArray buffer;
    static int expectedChunks = 0;
    static int receivedChunks = 0;

    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());

        QDataStream in(&datagram, QIODevice::ReadOnly);
        quint32 chunkSize, chunkIndex, totalChunks;
        in >> chunkSize >> chunkIndex >> totalChunks;

        QByteArray chunkData;
        chunkData.resize(chunkSize);
        in.readRawData(chunkData.data(), chunkSize);

        if (expectedChunks == 0) {
            expectedChunks = totalChunks;
            receivedChunks = 0;
            buffer.clear();
        }

        buffer.append(chunkData);
        receivedChunks++;

        if (receivedChunks == expectedChunks) {
            QFile file("/home/babyshark/Downloads/UDP/test_received_image.png");
            if (file.open(QIODevice::WriteOnly)) {
                file.write(buffer);
                file.close();
                qDebug() << "Image data written to file";
            } else {
                qDebug() << "Failed to write image data to file";
            }

            QImage image;
            if (image.loadFromData(buffer, "PNG")) {
                ui->label->setPixmap(QPixmap::fromImage(image));
                ui->label->resize(image.size());
                this->resize(image.size());
            } else {
                qDebug() << "Failed to load image from data";
            }

            // Reset cho khung hình tiếp theo
            expectedChunks = 0;
            receivedChunks = 0;
            buffer.clear();
        }
    }
}
