/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
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
    QLabel *label_4;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPlainTextEdit *plainTextEdit;
    QLineEdit *lineEdit_core;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QPushButton *pushButton_oc;
    QLabel *label;
    QLineEdit *lineEdit_mem;
    QPlainTextEdit *plainTextEdit_oc;
    QLineEdit *lineEdit_core_2;
    QLabel *label_3;
    QLineEdit *lineEdit_pool1;
    QPlainTextEdit *plainTextEdit_params;
    QLabel *label_5;
    QLineEdit *lineEdit_pool2;
    QLineEdit *lineEdit_wallet;
    QLabel *label_6;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 629);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 5, 0, 1, 2);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 6, 0, 1, 3);

        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout->addWidget(checkBox_2, 7, 0, 1, 2);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 8, 0, 1, 3);

        lineEdit_core = new QLineEdit(centralwidget);
        lineEdit_core->setObjectName(QStringLiteral("lineEdit_core"));

        gridLayout->addWidget(lineEdit_core, 0, 4, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 5, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 3, 1, 1);

        pushButton_oc = new QPushButton(centralwidget);
        pushButton_oc->setObjectName(QStringLiteral("pushButton_oc"));

        gridLayout->addWidget(pushButton_oc, 5, 4, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 3, 1, 1);

        lineEdit_mem = new QLineEdit(centralwidget);
        lineEdit_mem->setObjectName(QStringLiteral("lineEdit_mem"));

        gridLayout->addWidget(lineEdit_mem, 1, 4, 1, 1);

        plainTextEdit_oc = new QPlainTextEdit(centralwidget);
        plainTextEdit_oc->setObjectName(QStringLiteral("plainTextEdit_oc"));

        gridLayout->addWidget(plainTextEdit_oc, 8, 4, 1, 1);

        lineEdit_core_2 = new QLineEdit(centralwidget);
        lineEdit_core_2->setObjectName(QStringLiteral("lineEdit_core_2"));

        gridLayout->addWidget(lineEdit_core_2, 0, 1, 1, 2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_pool1 = new QLineEdit(centralwidget);
        lineEdit_pool1->setObjectName(QStringLiteral("lineEdit_pool1"));

        gridLayout->addWidget(lineEdit_pool1, 1, 1, 1, 2);

        plainTextEdit_params = new QPlainTextEdit(centralwidget);
        plainTextEdit_params->setObjectName(QStringLiteral("plainTextEdit_params"));

        gridLayout->addWidget(plainTextEdit_params, 4, 1, 1, 2);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1, Qt::AlignTop);

        lineEdit_pool2 = new QLineEdit(centralwidget);
        lineEdit_pool2->setObjectName(QStringLiteral("lineEdit_pool2"));

        gridLayout->addWidget(lineEdit_pool2, 2, 1, 1, 2);

        lineEdit_wallet = new QLineEdit(centralwidget);
        lineEdit_wallet->setObjectName(QStringLiteral("lineEdit_wallet"));

        gridLayout->addWidget(lineEdit_wallet, 3, 1, 1, 2);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

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
        label_4->setText(QApplication::translate("MainWindow", "Miner:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Prevent auto switching pool", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "Force OC settings(reapply if crashed)", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Stop miner", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Mem clock offset:", Q_NULLPTR));
        pushButton_oc->setText(QApplication::translate("MainWindow", "Set OC", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Core clock offset:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Pool address:", Q_NULLPTR));
        lineEdit_pool1->setText(QApplication::translate("MainWindow", "ssl://asia1.ethermine.org:5555", Q_NULLPTR));
        plainTextEdit_params->setPlainText(QApplication::translate("MainWindow", " -epsw x -mode 1 -log 0 -mport 0 -etha 0 -ftime 55 -retrydelay 1 -tt 79 -tstop 89 -coin eth", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Parameters:", Q_NULLPTR));
        lineEdit_pool2->setText(QApplication::translate("MainWindow", "ssl://asia2.ethermine.org:5555", Q_NULLPTR));
        lineEdit_wallet->setText(QApplication::translate("MainWindow", "0x8f3ef62b3ce472ffe7999dc52701a6957efc6e45", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Wallet:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
