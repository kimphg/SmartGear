/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_5;
    QPushButton *pushButton_oc;
    QLabel *label_3;
    QPushButton *pushButton_oc_power;
    QLabel *label_10;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_pool2;
    QLineEdit *lineEdit_mem_2;
    QLineEdit *lineEdit_pool1;
    QLineEdit *lineEdit_core_2;
    QLabel *label_8;
    QLabel *label_2;
    QLineEdit *lineEdit_core;
    QLabel *label_6;
    QLabel *label_4;
    QCheckBox *checkBox;
    QLineEdit *lineEdit_wallet;
    QLabel *label_7;
    QPushButton *pushButton;
    QLineEdit *lineEdit_mem;
    QCheckBox *checkBox_2;
    QPlainTextEdit *plainTextEdit_params;
    QPlainTextEdit *plainTextEdit_oc;
    QPlainTextEdit *plainTextEdit_system;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_9;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(851, 629);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 3, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1, Qt::AlignTop);

        pushButton_oc = new QPushButton(centralwidget);
        pushButton_oc->setObjectName(QStringLiteral("pushButton_oc"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_oc->sizePolicy().hasHeightForWidth());
        pushButton_oc->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_oc, 0, 5, 2, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        pushButton_oc_power = new QPushButton(centralwidget);
        pushButton_oc_power->setObjectName(QStringLiteral("pushButton_oc_power"));
        sizePolicy.setHeightForWidth(pushButton_oc_power->sizePolicy().hasHeightForWidth());
        pushButton_oc_power->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_oc_power, 2, 5, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 12, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 8, 2, 1, 1);

        lineEdit_pool2 = new QLineEdit(centralwidget);
        lineEdit_pool2->setObjectName(QStringLiteral("lineEdit_pool2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_pool2->sizePolicy().hasHeightForWidth());
        lineEdit_pool2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEdit_pool2, 2, 1, 1, 2);

        lineEdit_mem_2 = new QLineEdit(centralwidget);
        lineEdit_mem_2->setObjectName(QStringLiteral("lineEdit_mem_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_mem_2->sizePolicy().hasHeightForWidth());
        lineEdit_mem_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(lineEdit_mem_2, 2, 4, 1, 1);

        lineEdit_pool1 = new QLineEdit(centralwidget);
        lineEdit_pool1->setObjectName(QStringLiteral("lineEdit_pool1"));

        gridLayout->addWidget(lineEdit_pool1, 1, 1, 1, 2);

        lineEdit_core_2 = new QLineEdit(centralwidget);
        lineEdit_core_2->setObjectName(QStringLiteral("lineEdit_core_2"));

        gridLayout->addWidget(lineEdit_core_2, 0, 1, 1, 2);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 9, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 3, 1, 1);

        lineEdit_core = new QLineEdit(centralwidget);
        lineEdit_core->setObjectName(QStringLiteral("lineEdit_core"));
        sizePolicy2.setHeightForWidth(lineEdit_core->sizePolicy().hasHeightForWidth());
        lineEdit_core->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(lineEdit_core, 0, 4, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 5, 4, 1, 1);

        lineEdit_wallet = new QLineEdit(centralwidget);
        lineEdit_wallet->setObjectName(QStringLiteral("lineEdit_wallet"));

        gridLayout->addWidget(lineEdit_wallet, 3, 1, 1, 4);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 3, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 8, 0, 1, 2);

        lineEdit_mem = new QLineEdit(centralwidget);
        lineEdit_mem->setObjectName(QStringLiteral("lineEdit_mem"));
        sizePolicy2.setHeightForWidth(lineEdit_mem->sizePolicy().hasHeightForWidth());
        lineEdit_mem->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(lineEdit_mem, 1, 4, 1, 1);

        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout->addWidget(checkBox_2, 6, 4, 1, 1);

        plainTextEdit_params = new QPlainTextEdit(centralwidget);
        plainTextEdit_params->setObjectName(QStringLiteral("plainTextEdit_params"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(plainTextEdit_params->sizePolicy().hasHeightForWidth());
        plainTextEdit_params->setSizePolicy(sizePolicy3);
        plainTextEdit_params->setMaximumSize(QSize(16777215, 100));

        gridLayout->addWidget(plainTextEdit_params, 5, 0, 2, 4);

        plainTextEdit_oc = new QPlainTextEdit(centralwidget);
        plainTextEdit_oc->setObjectName(QStringLiteral("plainTextEdit_oc"));

        gridLayout->addWidget(plainTextEdit_oc, 10, 0, 1, 3);

        plainTextEdit_system = new QPlainTextEdit(centralwidget);
        plainTextEdit_system->setObjectName(QStringLiteral("plainTextEdit_system"));

        gridLayout->addWidget(plainTextEdit_system, 13, 0, 1, 3);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 8, 3, 6, 3);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 7, 3, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setCheckable(true);
        pushButton_3->setAutoExclusive(true);

        gridLayout_2->addWidget(pushButton_3, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setCheckable(true);
        pushButton_4->setAutoExclusive(true);

        gridLayout_2->addWidget(pushButton_4, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setCheckable(true);
        pushButton_5->setAutoExclusive(true);

        gridLayout_2->addWidget(pushButton_5, 0, 2, 1, 1);


        gridLayout->addWidget(frame, 4, 1, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Core clock offset:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Parameters:", Q_NULLPTR));
        pushButton_oc->setText(QApplication::translate("MainWindow", "Set ", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Pool address:", Q_NULLPTR));
        pushButton_oc_power->setText(QApplication::translate("MainWindow", "Set ", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "System output:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Stop miner", Q_NULLPTR));
        lineEdit_pool2->setText(QApplication::translate("MainWindow", "ssl://asia2.ethermine.org:5555", Q_NULLPTR));
        lineEdit_pool1->setText(QApplication::translate("MainWindow", "ssl://asia1.ethermine.org:5555", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "OC output:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Mem clock offset:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Wallet:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Miner:", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Prevent miner from auto switching pool", Q_NULLPTR));
        lineEdit_wallet->setText(QApplication::translate("MainWindow", "0x8f3ef62b3ce472ffe7999dc52701a6957efc6e45.worker01", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Power limit:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Start miner", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "Force OC settings(reapply OC if crashed)", Q_NULLPTR));
        plainTextEdit_params->setPlainText(QApplication::translate("MainWindow", " -epsw x -mode 1 -log 0 -mport 0 -etha 0 -ftime 55 -retrydelay 1 -tt 79 -tstop 89 -coin eth -leaveoc", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Miner output:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "ETH", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "ETC", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "RVN", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
