/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcgaugewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_show_setup;
    QPushButton *bt_control_file_2;
    QPushButton *bt_control_file_3;
    QPushButton *bt_control_file_4;
    QPushButton *bt_control_file_5;
    QPushButton *bt_control_file_7;
    QPushButton *bt_control_focusauto;
    QPushButton *bt_control_kv;
    QPushButton *bt_tracksizeup;
    QPushButton *bt_tracksizeup_2;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_play_video;
    QPushButton *pushButton_record;
    QPushButton *pushButton_power_off;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_10;
    QLabel *label_stim_stat;
    QLabel *label_cu_connection;
    QLabel *label_video_fps_3;
    QLabel *label_video_fps_5;
    QLabel *label_video_fps_17;
    QLabel *label_video_fps_18;
    QLabel *label_plc_1;
    QLabel *label_plc2;
    QPushButton *connectButton;
    QFrame *frame_7;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QTextBrowser *textBrowser_msg;
    QPushButton *pushButton_clear_msg;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QLabel *image_label_8;
    QLabel *image_label_10;
    QLabel *image_label_9;
    QLabel *image_label_12;
    QLabel *image_label_11;
    QLabel *image_label_13;
    QLabel *label_range;
    QLabel *label_5;
    QLabel *label;
    QSlider *slider_fov;
    QLabel *label_fov;
    QSlider *slider_range;
    QLabel *label_speed;
    QLabel *label_speed_2;
    QLabel *label_fovSpeed;
    QGroupBox *groupBox_setup;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_12;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *label_10;
    QTextEdit *textEdit_gearh;
    QTextEdit *textEdit_gearv;
    QTextEdit *textEdit_pprh;
    QTextEdit *textEdit_pprv;
    QPushButton *bt_save_setting_2;
    QPushButton *bt_send_pid_2;
    QTextEdit *textEdit_acc;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QLabel *label_6;
    QTextEdit *textEdit_ballistic_k;
    QPushButton *bt_save_setting;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_8;
    QPushButton *bt_control_1_pulse;
    QPushButton *bt_control_2_pulse;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_9;
    QLabel *label_8;
    QTextEdit *textEdit_dv;
    QTextEdit *textEdit_ph;
    QTextEdit *textEdit_ih;
    QTextEdit *textEdit_dh;
    QTextEdit *textEdit_iv;
    QLabel *label_7;
    QTextEdit *textEdit_pv;
    QPushButton *bt_send_pid;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout_13;
    QLabel *label_14;
    QTextEdit *textEdit_p_track;
    QTextEdit *textEdit_d_track;
    QLabel *label_13;
    QLabel *label_12;
    QTextEdit *textEdit_i_track;
    QPushButton *bt_send_pid_track;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_2;
    QLabel *label_video_fps;
    QLabel *label_video_fps_2;
    QLabel *label_track_x;
    QLabel *label_track_y;
    QGroupBox *groupBox_81;
    QGridLayout *gridLayout_4;
    QLabel *label_video_fps_10;
    QLabel *label_video_fps_11;
    QLabel *label_video_fps_7;
    QLabel *label_ele;
    QSlider *slider_ele;
    QLabel *label_video_fps_12;
    QLabel *label_video_fps_8;
    QLabel *label_video_fps_9;
    QLabel *label_video_fps_15;
    QLabel *label_video_fps_16;
    QLabel *label_video_fps_13;
    QLabel *label_video_fps_14;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_11;
    QPushButton *bt_video_test_2;
    QPushButton *bt_stab_2;
    QcGaugeWidget *view_azi;
    QGroupBox *groupBox_angle_limit;
    QGridLayout *gridLayout_14;
    QRadioButton *radioButton_leftlimit;
    QRadioButton *radioButton_nolimit;
    QRadioButton *radioButton_uplimit;
    QRadioButton *radioButton_downlimit;
    QRadioButton *radioButton_rightlimit;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_15;
    QPushButton *bt_video_main;
    QPushButton *bt_video_thermal;
    QPushButton *bt_video_off;
    QGroupBox *groupBox_16;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton_sightup;
    QPushButton *pushButton_sight_right;
    QGroupBox *groupBox_17;
    QGridLayout *gridLayout_16;
    QPushButton *bt_zero_set_3;
    QPushButton *bt_control_usb;
    QPushButton *bt_control_usb_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 1024);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(0, 160, 131, 411));
        groupBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 64, 128); color:rgb(255, 255, 255)"));
        verticalLayout = new QVBoxLayout(groupBox_5);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        pushButton_show_setup = new QPushButton(groupBox_5);
        pushButton_show_setup->setObjectName(QString::fromUtf8("pushButton_show_setup"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_show_setup->sizePolicy().hasHeightForWidth());
        pushButton_show_setup->setSizePolicy(sizePolicy);
        pushButton_show_setup->setCheckable(false);

        verticalLayout->addWidget(pushButton_show_setup);

        bt_control_file_2 = new QPushButton(groupBox_5);
        bt_control_file_2->setObjectName(QString::fromUtf8("bt_control_file_2"));
        sizePolicy.setHeightForWidth(bt_control_file_2->sizePolicy().hasHeightForWidth());
        bt_control_file_2->setSizePolicy(sizePolicy);
        bt_control_file_2->setCheckable(false);

        verticalLayout->addWidget(bt_control_file_2);

        bt_control_file_3 = new QPushButton(groupBox_5);
        bt_control_file_3->setObjectName(QString::fromUtf8("bt_control_file_3"));
        sizePolicy.setHeightForWidth(bt_control_file_3->sizePolicy().hasHeightForWidth());
        bt_control_file_3->setSizePolicy(sizePolicy);
        bt_control_file_3->setCheckable(false);

        verticalLayout->addWidget(bt_control_file_3);

        bt_control_file_4 = new QPushButton(groupBox_5);
        bt_control_file_4->setObjectName(QString::fromUtf8("bt_control_file_4"));
        sizePolicy.setHeightForWidth(bt_control_file_4->sizePolicy().hasHeightForWidth());
        bt_control_file_4->setSizePolicy(sizePolicy);
        bt_control_file_4->setCheckable(false);

        verticalLayout->addWidget(bt_control_file_4);

        bt_control_file_5 = new QPushButton(groupBox_5);
        bt_control_file_5->setObjectName(QString::fromUtf8("bt_control_file_5"));
        sizePolicy.setHeightForWidth(bt_control_file_5->sizePolicy().hasHeightForWidth());
        bt_control_file_5->setSizePolicy(sizePolicy);
        bt_control_file_5->setCheckable(false);

        verticalLayout->addWidget(bt_control_file_5);

        bt_control_file_7 = new QPushButton(groupBox_5);
        bt_control_file_7->setObjectName(QString::fromUtf8("bt_control_file_7"));
        sizePolicy.setHeightForWidth(bt_control_file_7->sizePolicy().hasHeightForWidth());
        bt_control_file_7->setSizePolicy(sizePolicy);
        bt_control_file_7->setCheckable(false);

        verticalLayout->addWidget(bt_control_file_7);

        bt_control_focusauto = new QPushButton(groupBox_5);
        bt_control_focusauto->setObjectName(QString::fromUtf8("bt_control_focusauto"));
        sizePolicy.setHeightForWidth(bt_control_focusauto->sizePolicy().hasHeightForWidth());
        bt_control_focusauto->setSizePolicy(sizePolicy);
        bt_control_focusauto->setCheckable(true);

        verticalLayout->addWidget(bt_control_focusauto);

        bt_control_kv = new QPushButton(groupBox_5);
        bt_control_kv->setObjectName(QString::fromUtf8("bt_control_kv"));
        sizePolicy.setHeightForWidth(bt_control_kv->sizePolicy().hasHeightForWidth());
        bt_control_kv->setSizePolicy(sizePolicy);
        bt_control_kv->setCheckable(true);

        verticalLayout->addWidget(bt_control_kv);

        bt_tracksizeup = new QPushButton(groupBox_5);
        bt_tracksizeup->setObjectName(QString::fromUtf8("bt_tracksizeup"));
        sizePolicy.setHeightForWidth(bt_tracksizeup->sizePolicy().hasHeightForWidth());
        bt_tracksizeup->setSizePolicy(sizePolicy);
        bt_tracksizeup->setCheckable(false);

        verticalLayout->addWidget(bt_tracksizeup);

        bt_tracksizeup_2 = new QPushButton(groupBox_5);
        bt_tracksizeup_2->setObjectName(QString::fromUtf8("bt_tracksizeup_2"));
        sizePolicy.setHeightForWidth(bt_tracksizeup_2->sizePolicy().hasHeightForWidth());
        bt_tracksizeup_2->setSizePolicy(sizePolicy);
        bt_tracksizeup_2->setCheckable(false);

        verticalLayout->addWidget(bt_tracksizeup_2);

        bt_control_file_2->raise();
        bt_control_file_5->raise();
        bt_control_file_4->raise();
        bt_control_file_7->raise();
        bt_control_file_3->raise();
        pushButton_show_setup->raise();
        bt_control_kv->raise();
        bt_control_focusauto->raise();
        bt_tracksizeup->raise();
        bt_tracksizeup_2->raise();
        groupBox_11 = new QGroupBox(centralwidget);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(10, 690, 121, 131));
        groupBox_11->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 64, 128); color:rgb(255, 255, 255)"));
        verticalLayout_5 = new QVBoxLayout(groupBox_11);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(5, 5, 5, 5);
        pushButton_play_video = new QPushButton(groupBox_11);
        pushButton_play_video->setObjectName(QString::fromUtf8("pushButton_play_video"));
        sizePolicy.setHeightForWidth(pushButton_play_video->sizePolicy().hasHeightForWidth());
        pushButton_play_video->setSizePolicy(sizePolicy);
        pushButton_play_video->setCheckable(false);

        verticalLayout_5->addWidget(pushButton_play_video);

        pushButton_record = new QPushButton(groupBox_11);
        pushButton_record->setObjectName(QString::fromUtf8("pushButton_record"));
        sizePolicy.setHeightForWidth(pushButton_record->sizePolicy().hasHeightForWidth());
        pushButton_record->setSizePolicy(sizePolicy);
        pushButton_record->setCheckable(true);

        verticalLayout_5->addWidget(pushButton_record);

        pushButton_power_off = new QPushButton(groupBox_11);
        pushButton_power_off->setObjectName(QString::fromUtf8("pushButton_power_off"));
        sizePolicy.setHeightForWidth(pushButton_power_off->sizePolicy().hasHeightForWidth());
        pushButton_power_off->setSizePolicy(sizePolicy);
        pushButton_power_off->setCheckable(false);

        verticalLayout_5->addWidget(pushButton_power_off);

        groupBox_10 = new QGroupBox(centralwidget);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(1150, 190, 121, 171));
        groupBox_10->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 64, 128); color:rgb(255, 255, 255)"));
        gridLayout_10 = new QGridLayout(groupBox_10);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_stim_stat = new QLabel(groupBox_10);
        label_stim_stat->setObjectName(QString::fromUtf8("label_stim_stat"));

        gridLayout_10->addWidget(label_stim_stat, 2, 1, 1, 1);

        label_cu_connection = new QLabel(groupBox_10);
        label_cu_connection->setObjectName(QString::fromUtf8("label_cu_connection"));

        gridLayout_10->addWidget(label_cu_connection, 1, 1, 1, 1);

        label_video_fps_3 = new QLabel(groupBox_10);
        label_video_fps_3->setObjectName(QString::fromUtf8("label_video_fps_3"));

        gridLayout_10->addWidget(label_video_fps_3, 1, 0, 1, 1);

        label_video_fps_5 = new QLabel(groupBox_10);
        label_video_fps_5->setObjectName(QString::fromUtf8("label_video_fps_5"));

        gridLayout_10->addWidget(label_video_fps_5, 2, 0, 1, 1);

        label_video_fps_17 = new QLabel(groupBox_10);
        label_video_fps_17->setObjectName(QString::fromUtf8("label_video_fps_17"));

        gridLayout_10->addWidget(label_video_fps_17, 3, 0, 1, 1);

        label_video_fps_18 = new QLabel(groupBox_10);
        label_video_fps_18->setObjectName(QString::fromUtf8("label_video_fps_18"));

        gridLayout_10->addWidget(label_video_fps_18, 4, 0, 1, 1);

        label_plc_1 = new QLabel(groupBox_10);
        label_plc_1->setObjectName(QString::fromUtf8("label_plc_1"));

        gridLayout_10->addWidget(label_plc_1, 3, 1, 1, 1);

        label_plc2 = new QLabel(groupBox_10);
        label_plc2->setObjectName(QString::fromUtf8("label_plc2"));

        gridLayout_10->addWidget(label_plc2, 4, 1, 1, 1);

        connectButton = new QPushButton(groupBox_10);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        sizePolicy.setHeightForWidth(connectButton->sizePolicy().hasHeightForWidth());
        connectButton->setSizePolicy(sizePolicy);
        connectButton->setCheckable(false);

        gridLayout_10->addWidget(connectButton, 0, 0, 1, 2);

        frame_7 = new QFrame(centralwidget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(10, 830, 1071, 171));
        frame_7->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 32, 128); color:rgb(255, 255, 255)"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_7);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_4 = new QGroupBox(frame_7);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        textBrowser_msg = new QTextBrowser(groupBox_4);
        textBrowser_msg->setObjectName(QString::fromUtf8("textBrowser_msg"));

        gridLayout_5->addWidget(textBrowser_msg, 0, 0, 1, 1);

        pushButton_clear_msg = new QPushButton(groupBox_4);
        pushButton_clear_msg->setObjectName(QString::fromUtf8("pushButton_clear_msg"));

        gridLayout_5->addWidget(pushButton_clear_msg, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_4, 0, 0, 3, 1);

        frame_2 = new QFrame(frame_7);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 64, 128); color:rgb(255, 255, 255)"));
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        image_label_8 = new QLabel(frame_2);
        image_label_8->setObjectName(QString::fromUtf8("image_label_8"));
        image_label_8->setFrameShape(QFrame::Panel);

        gridLayout_3->addWidget(image_label_8, 0, 1, 1, 1);

        image_label_10 = new QLabel(frame_2);
        image_label_10->setObjectName(QString::fromUtf8("image_label_10"));
        image_label_10->setFrameShape(QFrame::Panel);

        gridLayout_3->addWidget(image_label_10, 1, 1, 1, 1);

        image_label_9 = new QLabel(frame_2);
        image_label_9->setObjectName(QString::fromUtf8("image_label_9"));
        image_label_9->setFrameShape(QFrame::Panel);

        gridLayout_3->addWidget(image_label_9, 1, 2, 1, 1);

        image_label_12 = new QLabel(frame_2);
        image_label_12->setObjectName(QString::fromUtf8("image_label_12"));
        image_label_12->setFrameShape(QFrame::Panel);

        gridLayout_3->addWidget(image_label_12, 2, 1, 1, 1);

        image_label_11 = new QLabel(frame_2);
        image_label_11->setObjectName(QString::fromUtf8("image_label_11"));
        image_label_11->setFrameShape(QFrame::Panel);

        gridLayout_3->addWidget(image_label_11, 0, 2, 1, 1);

        image_label_13 = new QLabel(frame_2);
        image_label_13->setObjectName(QString::fromUtf8("image_label_13"));
        image_label_13->setFrameShape(QFrame::Panel);

        gridLayout_3->addWidget(image_label_13, 2, 2, 1, 1);


        gridLayout->addWidget(frame_2, 0, 5, 3, 1);

        label_range = new QLabel(frame_7);
        label_range->setObjectName(QString::fromUtf8("label_range"));
        QFont font1;
        font1.setPointSize(16);
        label_range->setFont(font1);

        gridLayout->addWidget(label_range, 1, 2, 1, 1);

        label_5 = new QLabel(frame_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 2, 1, 1, 1);

        label = new QLabel(frame_7);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        slider_fov = new QSlider(frame_7);
        slider_fov->setObjectName(QString::fromUtf8("slider_fov"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(slider_fov->sizePolicy().hasHeightForWidth());
        slider_fov->setSizePolicy(sizePolicy1);
        slider_fov->setMinimumSize(QSize(500, 0));
        slider_fov->setMinimum(17);
        slider_fov->setMaximum(600);
        slider_fov->setSingleStep(1);
        slider_fov->setPageStep(10);
        slider_fov->setValue(600);
        slider_fov->setOrientation(Qt::Horizontal);
        slider_fov->setTickPosition(QSlider::TicksAbove);
        slider_fov->setTickInterval(1);

        gridLayout->addWidget(slider_fov, 2, 3, 1, 2);

        label_fov = new QLabel(frame_7);
        label_fov->setObjectName(QString::fromUtf8("label_fov"));
        label_fov->setFont(font1);

        gridLayout->addWidget(label_fov, 2, 2, 1, 1);

        slider_range = new QSlider(frame_7);
        slider_range->setObjectName(QString::fromUtf8("slider_range"));
        sizePolicy1.setHeightForWidth(slider_range->sizePolicy().hasHeightForWidth());
        slider_range->setSizePolicy(sizePolicy1);
        slider_range->setMinimumSize(QSize(500, 0));
        slider_range->setMinimum(1);
        slider_range->setMaximum(30);
        slider_range->setSingleStep(1);
        slider_range->setPageStep(1);
        slider_range->setValue(1);
        slider_range->setOrientation(Qt::Horizontal);
        slider_range->setTickPosition(QSlider::TicksAbove);
        slider_range->setTickInterval(1);

        gridLayout->addWidget(slider_range, 1, 3, 1, 2);

        label_speed = new QLabel(frame_7);
        label_speed->setObjectName(QString::fromUtf8("label_speed"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_speed->sizePolicy().hasHeightForWidth());
        label_speed->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_speed, 0, 3, 1, 1);

        label_speed_2 = new QLabel(frame_7);
        label_speed_2->setObjectName(QString::fromUtf8("label_speed_2"));
        sizePolicy2.setHeightForWidth(label_speed_2->sizePolicy().hasHeightForWidth());
        label_speed_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_speed_2, 0, 1, 1, 1);

        label_fovSpeed = new QLabel(frame_7);
        label_fovSpeed->setObjectName(QString::fromUtf8("label_fovSpeed"));
        sizePolicy2.setHeightForWidth(label_fovSpeed->sizePolicy().hasHeightForWidth());
        label_fovSpeed->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_fovSpeed, 3, 3, 1, 1);

        groupBox_setup = new QGroupBox(centralwidget);
        groupBox_setup->setObjectName(QString::fromUtf8("groupBox_setup"));
        groupBox_setup->setGeometry(QRect(270, 100, 721, 631));
        groupBox_setup->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 64, 128); color:rgb(255, 255, 255)"));
        gridLayout_7 = new QGridLayout(groupBox_setup);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_13 = new QGroupBox(groupBox_setup);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        gridLayout_12 = new QGridLayout(groupBox_13);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_11 = new QLabel(groupBox_13);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_12->addWidget(label_11, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox_13);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_12->addWidget(label_9, 1, 0, 1, 1);

        label_10 = new QLabel(groupBox_13);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_12->addWidget(label_10, 2, 0, 1, 1);

        textEdit_gearh = new QTextEdit(groupBox_13);
        textEdit_gearh->setObjectName(QString::fromUtf8("textEdit_gearh"));

        gridLayout_12->addWidget(textEdit_gearh, 1, 1, 1, 1);

        textEdit_gearv = new QTextEdit(groupBox_13);
        textEdit_gearv->setObjectName(QString::fromUtf8("textEdit_gearv"));

        gridLayout_12->addWidget(textEdit_gearv, 1, 2, 1, 1);

        textEdit_pprh = new QTextEdit(groupBox_13);
        textEdit_pprh->setObjectName(QString::fromUtf8("textEdit_pprh"));

        gridLayout_12->addWidget(textEdit_pprh, 2, 1, 1, 1);

        textEdit_pprv = new QTextEdit(groupBox_13);
        textEdit_pprv->setObjectName(QString::fromUtf8("textEdit_pprv"));

        gridLayout_12->addWidget(textEdit_pprv, 2, 2, 1, 1);

        bt_save_setting_2 = new QPushButton(groupBox_13);
        bt_save_setting_2->setObjectName(QString::fromUtf8("bt_save_setting_2"));
        sizePolicy.setHeightForWidth(bt_save_setting_2->sizePolicy().hasHeightForWidth());
        bt_save_setting_2->setSizePolicy(sizePolicy);
        bt_save_setting_2->setAutoExclusive(true);

        gridLayout_12->addWidget(bt_save_setting_2, 0, 3, 1, 1);

        bt_send_pid_2 = new QPushButton(groupBox_13);
        bt_send_pid_2->setObjectName(QString::fromUtf8("bt_send_pid_2"));
        sizePolicy.setHeightForWidth(bt_send_pid_2->sizePolicy().hasHeightForWidth());
        bt_send_pid_2->setSizePolicy(sizePolicy);
        bt_send_pid_2->setAutoExclusive(true);

        gridLayout_12->addWidget(bt_send_pid_2, 1, 3, 2, 1);

        textEdit_acc = new QTextEdit(groupBox_13);
        textEdit_acc->setObjectName(QString::fromUtf8("textEdit_acc"));

        gridLayout_12->addWidget(textEdit_acc, 0, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_13, 0, 0, 1, 2);

        groupBox_6 = new QGroupBox(groupBox_setup);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_6 = new QLabel(groupBox_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_6->addWidget(label_6, 0, 0, 1, 1);

        textEdit_ballistic_k = new QTextEdit(groupBox_6);
        textEdit_ballistic_k->setObjectName(QString::fromUtf8("textEdit_ballistic_k"));

        gridLayout_6->addWidget(textEdit_ballistic_k, 0, 1, 1, 1);

        bt_save_setting = new QPushButton(groupBox_6);
        bt_save_setting->setObjectName(QString::fromUtf8("bt_save_setting"));
        sizePolicy.setHeightForWidth(bt_save_setting->sizePolicy().hasHeightForWidth());
        bt_save_setting->setSizePolicy(sizePolicy);
        bt_save_setting->setAutoExclusive(true);

        gridLayout_6->addWidget(bt_save_setting, 0, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_6, 2, 1, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_setup);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_8 = new QGridLayout(groupBox_7);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        bt_control_1_pulse = new QPushButton(groupBox_7);
        bt_control_1_pulse->setObjectName(QString::fromUtf8("bt_control_1_pulse"));
        bt_control_1_pulse->setCheckable(true);
        bt_control_1_pulse->setChecked(true);
        bt_control_1_pulse->setAutoExclusive(true);

        gridLayout_8->addWidget(bt_control_1_pulse, 0, 0, 1, 2);

        bt_control_2_pulse = new QPushButton(groupBox_7);
        bt_control_2_pulse->setObjectName(QString::fromUtf8("bt_control_2_pulse"));
        bt_control_2_pulse->setCheckable(true);
        bt_control_2_pulse->setAutoExclusive(true);

        gridLayout_8->addWidget(bt_control_2_pulse, 1, 0, 1, 2);


        gridLayout_7->addWidget(groupBox_7, 2, 0, 1, 1);

        groupBox_8 = new QGroupBox(groupBox_setup);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_9 = new QGridLayout(groupBox_8);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_8 = new QLabel(groupBox_8);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_9->addWidget(label_8, 1, 2, 1, 1);

        textEdit_dv = new QTextEdit(groupBox_8);
        textEdit_dv->setObjectName(QString::fromUtf8("textEdit_dv"));

        gridLayout_9->addWidget(textEdit_dv, 5, 2, 1, 1);

        textEdit_ph = new QTextEdit(groupBox_8);
        textEdit_ph->setObjectName(QString::fromUtf8("textEdit_ph"));

        gridLayout_9->addWidget(textEdit_ph, 3, 1, 1, 1);

        textEdit_ih = new QTextEdit(groupBox_8);
        textEdit_ih->setObjectName(QString::fromUtf8("textEdit_ih"));

        gridLayout_9->addWidget(textEdit_ih, 4, 1, 1, 1);

        textEdit_dh = new QTextEdit(groupBox_8);
        textEdit_dh->setObjectName(QString::fromUtf8("textEdit_dh"));

        gridLayout_9->addWidget(textEdit_dh, 5, 1, 1, 1);

        textEdit_iv = new QTextEdit(groupBox_8);
        textEdit_iv->setObjectName(QString::fromUtf8("textEdit_iv"));

        gridLayout_9->addWidget(textEdit_iv, 4, 2, 1, 1);

        label_7 = new QLabel(groupBox_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_9->addWidget(label_7, 1, 1, 1, 1);

        textEdit_pv = new QTextEdit(groupBox_8);
        textEdit_pv->setObjectName(QString::fromUtf8("textEdit_pv"));

        gridLayout_9->addWidget(textEdit_pv, 3, 2, 1, 1);

        bt_send_pid = new QPushButton(groupBox_8);
        bt_send_pid->setObjectName(QString::fromUtf8("bt_send_pid"));
        sizePolicy.setHeightForWidth(bt_send_pid->sizePolicy().hasHeightForWidth());
        bt_send_pid->setSizePolicy(sizePolicy);
        bt_send_pid->setAutoExclusive(true);

        gridLayout_9->addWidget(bt_send_pid, 3, 3, 3, 1);

        label_2 = new QLabel(groupBox_8);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_9->addWidget(label_2, 3, 0, 1, 1);

        label_3 = new QLabel(groupBox_8);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_9->addWidget(label_3, 4, 0, 1, 1);

        label_4 = new QLabel(groupBox_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_9->addWidget(label_4, 5, 0, 1, 1);

        label_7->raise();
        label_8->raise();
        textEdit_dv->raise();
        textEdit_ph->raise();
        textEdit_ih->raise();
        textEdit_dh->raise();
        textEdit_iv->raise();
        textEdit_pv->raise();
        bt_send_pid->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();

        gridLayout_7->addWidget(groupBox_8, 1, 0, 1, 2);

        groupBox_14 = new QGroupBox(groupBox_setup);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        gridLayout_13 = new QGridLayout(groupBox_14);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        label_14 = new QLabel(groupBox_14);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_13->addWidget(label_14, 2, 0, 1, 1);

        textEdit_p_track = new QTextEdit(groupBox_14);
        textEdit_p_track->setObjectName(QString::fromUtf8("textEdit_p_track"));

        gridLayout_13->addWidget(textEdit_p_track, 0, 1, 1, 1);

        textEdit_d_track = new QTextEdit(groupBox_14);
        textEdit_d_track->setObjectName(QString::fromUtf8("textEdit_d_track"));

        gridLayout_13->addWidget(textEdit_d_track, 2, 1, 1, 1);

        label_13 = new QLabel(groupBox_14);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_13->addWidget(label_13, 1, 0, 1, 1);

        label_12 = new QLabel(groupBox_14);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_13->addWidget(label_12, 0, 0, 1, 1);

        textEdit_i_track = new QTextEdit(groupBox_14);
        textEdit_i_track->setObjectName(QString::fromUtf8("textEdit_i_track"));

        gridLayout_13->addWidget(textEdit_i_track, 1, 1, 1, 1);

        bt_send_pid_track = new QPushButton(groupBox_14);
        bt_send_pid_track->setObjectName(QString::fromUtf8("bt_send_pid_track"));
        sizePolicy.setHeightForWidth(bt_send_pid_track->sizePolicy().hasHeightForWidth());
        bt_send_pid_track->setSizePolicy(sizePolicy);
        bt_send_pid_track->setAutoExclusive(true);

        gridLayout_13->addWidget(bt_send_pid_track, 0, 2, 3, 1);


        gridLayout_7->addWidget(groupBox_14, 3, 0, 1, 2);

        groupBox_9 = new QGroupBox(centralwidget);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(1150, 370, 121, 111));
        groupBox_9->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 64, 128); color:rgb(255, 255, 255)"));
        gridLayout_2 = new QGridLayout(groupBox_9);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_video_fps = new QLabel(groupBox_9);
        label_video_fps->setObjectName(QString::fromUtf8("label_video_fps"));

        gridLayout_2->addWidget(label_video_fps, 0, 0, 1, 1);

        label_video_fps_2 = new QLabel(groupBox_9);
        label_video_fps_2->setObjectName(QString::fromUtf8("label_video_fps_2"));

        gridLayout_2->addWidget(label_video_fps_2, 2, 0, 1, 1);

        label_track_x = new QLabel(groupBox_9);
        label_track_x->setObjectName(QString::fromUtf8("label_track_x"));

        gridLayout_2->addWidget(label_track_x, 0, 1, 1, 1);

        label_track_y = new QLabel(groupBox_9);
        label_track_y->setObjectName(QString::fromUtf8("label_track_y"));

        gridLayout_2->addWidget(label_track_y, 2, 1, 1, 1);

        groupBox_81 = new QGroupBox(centralwidget);
        groupBox_81->setObjectName(QString::fromUtf8("groupBox_81"));
        groupBox_81->setGeometry(QRect(1150, 490, 121, 231));
        groupBox_81->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 64, 128); color:rgb(255, 255, 255)"));
        gridLayout_4 = new QGridLayout(groupBox_81);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_video_fps_10 = new QLabel(groupBox_81);
        label_video_fps_10->setObjectName(QString::fromUtf8("label_video_fps_10"));

        gridLayout_4->addWidget(label_video_fps_10, 1, 2, 1, 1);

        label_video_fps_11 = new QLabel(groupBox_81);
        label_video_fps_11->setObjectName(QString::fromUtf8("label_video_fps_11"));
        label_video_fps_11->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_4->addWidget(label_video_fps_11, 0, 0, 1, 1);

        label_video_fps_7 = new QLabel(groupBox_81);
        label_video_fps_7->setObjectName(QString::fromUtf8("label_video_fps_7"));
        label_video_fps_7->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        gridLayout_4->addWidget(label_video_fps_7, 4, 0, 1, 1);

        label_ele = new QLabel(groupBox_81);
        label_ele->setObjectName(QString::fromUtf8("label_ele"));

        gridLayout_4->addWidget(label_ele, 5, 1, 1, 1);

        slider_ele = new QSlider(groupBox_81);
        slider_ele->setObjectName(QString::fromUtf8("slider_ele"));
        slider_ele->setMinimum(-15);
        slider_ele->setMaximum(55);
        slider_ele->setPageStep(1);
        slider_ele->setOrientation(Qt::Vertical);
        slider_ele->setTickPosition(QSlider::TicksBothSides);
        slider_ele->setTickInterval(5);

        gridLayout_4->addWidget(slider_ele, 0, 1, 5, 1);

        label_video_fps_12 = new QLabel(groupBox_81);
        label_video_fps_12->setObjectName(QString::fromUtf8("label_video_fps_12"));
        label_video_fps_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_4->addWidget(label_video_fps_12, 0, 2, 1, 1);

        label_video_fps_8 = new QLabel(groupBox_81);
        label_video_fps_8->setObjectName(QString::fromUtf8("label_video_fps_8"));
        label_video_fps_8->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_4->addWidget(label_video_fps_8, 4, 2, 1, 1);

        label_video_fps_9 = new QLabel(groupBox_81);
        label_video_fps_9->setObjectName(QString::fromUtf8("label_video_fps_9"));
        label_video_fps_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_video_fps_9, 1, 0, 1, 1);

        label_video_fps_15 = new QLabel(groupBox_81);
        label_video_fps_15->setObjectName(QString::fromUtf8("label_video_fps_15"));
        label_video_fps_15->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        gridLayout_4->addWidget(label_video_fps_15, 2, 0, 1, 1);

        label_video_fps_16 = new QLabel(groupBox_81);
        label_video_fps_16->setObjectName(QString::fromUtf8("label_video_fps_16"));
        label_video_fps_16->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_4->addWidget(label_video_fps_16, 2, 2, 1, 1);

        label_video_fps_13 = new QLabel(groupBox_81);
        label_video_fps_13->setObjectName(QString::fromUtf8("label_video_fps_13"));
        label_video_fps_13->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        gridLayout_4->addWidget(label_video_fps_13, 3, 0, 1, 1);

        label_video_fps_14 = new QLabel(groupBox_81);
        label_video_fps_14->setObjectName(QString::fromUtf8("label_video_fps_14"));
        label_video_fps_14->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_4->addWidget(label_video_fps_14, 3, 2, 1, 1);

        groupBox_12 = new QGroupBox(centralwidget);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(1030, 10, 111, 111));
        groupBox_12->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 64, 32); color:rgb(255, 255, 255)"));
        gridLayout_11 = new QGridLayout(groupBox_12);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        bt_video_test_2 = new QPushButton(groupBox_12);
        bt_video_test_2->setObjectName(QString::fromUtf8("bt_video_test_2"));
        bt_video_test_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 64, 32); color:rgb(255, 255, 255)"));
        bt_video_test_2->setCheckable(true);
        bt_video_test_2->setChecked(true);
        bt_video_test_2->setAutoExclusive(true);

        gridLayout_11->addWidget(bt_video_test_2, 1, 0, 1, 1);

        bt_stab_2 = new QPushButton(groupBox_12);
        bt_stab_2->setObjectName(QString::fromUtf8("bt_stab_2"));
        bt_stab_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 64, 32); color:rgb(255, 255, 255)"));
        bt_stab_2->setCheckable(true);
        bt_stab_2->setAutoExclusive(true);

        gridLayout_11->addWidget(bt_stab_2, 2, 0, 1, 1);

        view_azi = new QcGaugeWidget(centralwidget);
        view_azi->setObjectName(QString::fromUtf8("view_azi"));
        view_azi->setGeometry(QRect(1090, 830, 180, 180));
        view_azi->setAutoFillBackground(false);
        view_azi->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 64, 128); color:rgb(255, 255, 255)"));
        groupBox_angle_limit = new QGroupBox(centralwidget);
        groupBox_angle_limit->setObjectName(QString::fromUtf8("groupBox_angle_limit"));
        groupBox_angle_limit->setGeometry(QRect(1150, 730, 121, 91));
        groupBox_angle_limit->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 64, 128); color:rgb(255, 255, 255)"));
        gridLayout_14 = new QGridLayout(groupBox_angle_limit);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        radioButton_leftlimit = new QRadioButton(groupBox_angle_limit);
        radioButton_leftlimit->setObjectName(QString::fromUtf8("radioButton_leftlimit"));

        gridLayout_14->addWidget(radioButton_leftlimit, 1, 0, 1, 1);

        radioButton_nolimit = new QRadioButton(groupBox_angle_limit);
        radioButton_nolimit->setObjectName(QString::fromUtf8("radioButton_nolimit"));

        gridLayout_14->addWidget(radioButton_nolimit, 1, 1, 1, 1);

        radioButton_uplimit = new QRadioButton(groupBox_angle_limit);
        radioButton_uplimit->setObjectName(QString::fromUtf8("radioButton_uplimit"));

        gridLayout_14->addWidget(radioButton_uplimit, 0, 1, 1, 1);

        radioButton_downlimit = new QRadioButton(groupBox_angle_limit);
        radioButton_downlimit->setObjectName(QString::fromUtf8("radioButton_downlimit"));

        gridLayout_14->addWidget(radioButton_downlimit, 2, 1, 1, 1);

        radioButton_rightlimit = new QRadioButton(groupBox_angle_limit);
        radioButton_rightlimit->setObjectName(QString::fromUtf8("radioButton_rightlimit"));

        gridLayout_14->addWidget(radioButton_rightlimit, 1, 2, 1, 1);

        groupBox_15 = new QGroupBox(centralwidget);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        groupBox_15->setGeometry(QRect(0, 10, 131, 141));
        groupBox_15->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 64, 128); color:rgb(255, 255, 255)"));
        gridLayout_15 = new QGridLayout(groupBox_15);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        bt_video_main = new QPushButton(groupBox_15);
        bt_video_main->setObjectName(QString::fromUtf8("bt_video_main"));
        sizePolicy.setHeightForWidth(bt_video_main->sizePolicy().hasHeightForWidth());
        bt_video_main->setSizePolicy(sizePolicy);
        bt_video_main->setCheckable(true);
        bt_video_main->setAutoExclusive(false);

        gridLayout_15->addWidget(bt_video_main, 1, 0, 1, 1);

        bt_video_thermal = new QPushButton(groupBox_15);
        bt_video_thermal->setObjectName(QString::fromUtf8("bt_video_thermal"));
        sizePolicy.setHeightForWidth(bt_video_thermal->sizePolicy().hasHeightForWidth());
        bt_video_thermal->setSizePolicy(sizePolicy);
        bt_video_thermal->setCheckable(true);
        bt_video_thermal->setAutoExclusive(false);

        gridLayout_15->addWidget(bt_video_thermal, 0, 0, 1, 1);

        bt_video_off = new QPushButton(groupBox_15);
        bt_video_off->setObjectName(QString::fromUtf8("bt_video_off"));
        sizePolicy.setHeightForWidth(bt_video_off->sizePolicy().hasHeightForWidth());
        bt_video_off->setSizePolicy(sizePolicy);
        bt_video_off->setCheckable(true);
        bt_video_off->setAutoExclusive(false);

        gridLayout_15->addWidget(bt_video_off, 2, 0, 1, 1);

        groupBox_16 = new QGroupBox(centralwidget);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        groupBox_16->setGeometry(QRect(10, 580, 121, 101));
        groupBox_16->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 64, 128); color:rgb(255, 255, 255)"));
        verticalLayout_6 = new QVBoxLayout(groupBox_16);
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(5, 5, 5, 5);
        pushButton_sightup = new QPushButton(groupBox_16);
        pushButton_sightup->setObjectName(QString::fromUtf8("pushButton_sightup"));
        sizePolicy.setHeightForWidth(pushButton_sightup->sizePolicy().hasHeightForWidth());
        pushButton_sightup->setSizePolicy(sizePolicy);
        pushButton_sightup->setCheckable(false);

        verticalLayout_6->addWidget(pushButton_sightup);

        pushButton_sight_right = new QPushButton(groupBox_16);
        pushButton_sight_right->setObjectName(QString::fromUtf8("pushButton_sight_right"));
        sizePolicy.setHeightForWidth(pushButton_sight_right->sizePolicy().hasHeightForWidth());
        pushButton_sight_right->setSizePolicy(sizePolicy);
        pushButton_sight_right->setCheckable(true);

        verticalLayout_6->addWidget(pushButton_sight_right);

        groupBox_17 = new QGroupBox(centralwidget);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        groupBox_17->setGeometry(QRect(1150, 10, 121, 171));
        groupBox_17->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 64, 32); color:rgb(255, 255, 255)"));
        gridLayout_16 = new QGridLayout(groupBox_17);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        bt_zero_set_3 = new QPushButton(groupBox_17);
        bt_zero_set_3->setObjectName(QString::fromUtf8("bt_zero_set_3"));
        sizePolicy.setHeightForWidth(bt_zero_set_3->sizePolicy().hasHeightForWidth());
        bt_zero_set_3->setSizePolicy(sizePolicy);
        bt_zero_set_3->setCheckable(true);
        bt_zero_set_3->setAutoExclusive(true);

        gridLayout_16->addWidget(bt_zero_set_3, 0, 0, 1, 1);

        bt_control_usb = new QPushButton(groupBox_17);
        bt_control_usb->setObjectName(QString::fromUtf8("bt_control_usb"));
        sizePolicy.setHeightForWidth(bt_control_usb->sizePolicy().hasHeightForWidth());
        bt_control_usb->setSizePolicy(sizePolicy);
        bt_control_usb->setCheckable(true);
        bt_control_usb->setAutoExclusive(true);

        gridLayout_16->addWidget(bt_control_usb, 1, 0, 1, 1);

        bt_control_usb_2 = new QPushButton(groupBox_17);
        bt_control_usb_2->setObjectName(QString::fromUtf8("bt_control_usb_2"));
        sizePolicy.setHeightForWidth(bt_control_usb_2->sizePolicy().hasHeightForWidth());
        bt_control_usb_2->setSizePolicy(sizePolicy);
        bt_control_usb_2->setCheckable(true);
        bt_control_usb_2->setChecked(true);
        bt_control_usb_2->setAutoExclusive(true);

        gridLayout_16->addWidget(bt_control_usb_2, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        groupBox_setup->raise();
        groupBox_5->raise();
        groupBox_11->raise();
        groupBox_10->raise();
        frame_7->raise();
        groupBox_9->raise();
        groupBox_8->raise();
        groupBox_12->raise();
        view_azi->raise();
        groupBox_angle_limit->raise();
        groupBox_15->raise();
        groupBox_16->raise();
        groupBox_17->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\304\220K camera:", nullptr));
        pushButton_show_setup->setText(QCoreApplication::translate("MainWindow", "C\303\240i \304\221\341\272\267t", nullptr));
        bt_control_file_2->setText(QCoreApplication::translate("MainWindow", "Zoom +", nullptr));
        bt_control_file_3->setText(QCoreApplication::translate("MainWindow", "Zoom -", nullptr));
        bt_control_file_4->setText(QCoreApplication::translate("MainWindow", "Focus+", nullptr));
        bt_control_file_5->setText(QCoreApplication::translate("MainWindow", "Focus-", nullptr));
        bt_control_file_7->setText(QCoreApplication::translate("MainWindow", "\304\220o xa laser", nullptr));
        bt_control_focusauto->setText(QCoreApplication::translate("MainWindow", "Autofocus", nullptr));
        bt_control_kv->setText(QCoreApplication::translate("MainWindow", "K\303\255nh v\341\272\241ch", nullptr));
        bt_tracksizeup->setText(QCoreApplication::translate("MainWindow", "T\304\203ng \303\264 b\303\241m", nullptr));
        bt_tracksizeup_2->setText(QCoreApplication::translate("MainWindow", "Gi\341\272\243m \303\264 b\303\241m", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("MainWindow", "Video", nullptr));
        pushButton_play_video->setText(QCoreApplication::translate("MainWindow", "Open video", nullptr));
        pushButton_record->setText(QCoreApplication::translate("MainWindow", "Ghi l\306\260u", nullptr));
        pushButton_power_off->setText(QCoreApplication::translate("MainWindow", "Stop replay", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "K\341\272\277t n\341\273\221i:", nullptr));
        label_stim_stat->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        label_cu_connection->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        label_video_fps_3->setText(QCoreApplication::translate("MainWindow", "CU:", nullptr));
        label_video_fps_5->setText(QCoreApplication::translate("MainWindow", "GYRO:", nullptr));
        label_video_fps_17->setText(QCoreApplication::translate("MainWindow", "MCU 1:", nullptr));
        label_video_fps_18->setText(QCoreApplication::translate("MainWindow", "MCU 2:", nullptr));
        label_plc_1->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        label_plc2->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "N\341\273\221i PLC", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Th\303\264ng b\303\241o", nullptr));
        pushButton_clear_msg->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        image_label_8->setText(QCoreApplication::translate("MainWindow", "Ch\341\272\277 \304\221\341\273\231 b\341\272\257n:", nullptr));
        image_label_10->setText(QCoreApplication::translate("MainWindow", "\304\220\341\272\241n:", nullptr));
        image_label_9->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        image_label_12->setText(QCoreApplication::translate("MainWindow", "S\341\272\265n s\303\240ng:", nullptr));
        image_label_11->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        image_label_13->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        label_range->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "FOV(\304\221\341\273\231):", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "C\341\273\261 ly(m):", nullptr));
        label_fov->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        label_speed->setText(QCoreApplication::translate("MainWindow", "00", nullptr));
        label_speed_2->setText(QCoreApplication::translate("MainWindow", "T\341\273\221c \304\221\341\273\231 xe(km/h):", nullptr));
        label_fovSpeed->setText(QCoreApplication::translate("MainWindow", "00", nullptr));
        groupBox_setup->setTitle(QCoreApplication::translate("MainWindow", "C\303\240i \304\221\341\272\267t", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("MainWindow", "\304\220\341\273\231ng c\306\241", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "H\341\273\207 s\341\273\221 qu\303\241n t\303\255nh:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "H\341\273\231p s\341\273\221:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "PPR", nullptr));
        textEdit_gearh->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">200</p></body></html>", nullptr));
        textEdit_gearv->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">500</p></body></html>", nullptr));
        textEdit_pprh->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">500</p></body></html>", nullptr));
        textEdit_pprv->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">500</p></body></html>", nullptr));
        bt_save_setting_2->setText(QCoreApplication::translate("MainWindow", "L\306\260u", nullptr));
        bt_send_pid_2->setText(QCoreApplication::translate("MainWindow", "L\306\260u", nullptr));
        textEdit_acc->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0.1</p></body></html>", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\304\220\306\260\341\273\235ng \304\221\341\272\241n:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "H\341\273\207 s\341\273\221 ch\341\273\211nh \304\221\341\273\231 cao \304\221\306\260\341\273\235ng \304\221\341\272\241n:", nullptr));
        textEdit_ballistic_k->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1</p></body></html>", nullptr));
        bt_save_setting->setText(QCoreApplication::translate("MainWindow", "L\306\260u", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "\304\220i\341\273\201u khi\341\273\203n", nullptr));
        bt_control_1_pulse->setText(QCoreApplication::translate("MainWindow", "Ch\341\272\277 \304\221\341\273\231 1 xung", nullptr));
        bt_control_2_pulse->setText(QCoreApplication::translate("MainWindow", "Ch\341\272\277 \304\221\341\273\231 2 xung", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "\341\273\224n \304\221\341\273\213nh con quay", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "T\341\272\247m:", nullptr));
        textEdit_dv->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        textEdit_ph->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1</p></body></html>", nullptr));
        textEdit_ih->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0.06</p></body></html>", nullptr));
        textEdit_dh->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        textEdit_iv->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0.06</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "H\306\260\341\273\233ng:", nullptr));
        textEdit_pv->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1</p></body></html>", nullptr));
        bt_send_pid->setText(QCoreApplication::translate("MainWindow", "L\306\260u", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "H\341\273\207 s\341\273\221 P:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "H\341\273\207 s\341\273\221 I:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "H\341\273\207 s\341\273\221 D:", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("MainWindow", "B\303\241m \341\272\243nh:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "H\341\273\207 s\341\273\221 D:", nullptr));
        textEdit_p_track->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1</p></body></html>", nullptr));
        textEdit_d_track->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "H\341\273\207 s\341\273\221 I:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "H\341\273\207 s\341\273\221 P:", nullptr));
        textEdit_i_track->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0.06</p></body></html>", nullptr));
        bt_send_pid_track->setText(QCoreApplication::translate("MainWindow", "L\306\260u", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "FPS:", nullptr));
        label_video_fps->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        label_video_fps_2->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        label_track_x->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        label_track_y->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        groupBox_81->setTitle(QCoreApplication::translate("MainWindow", "G\303\263c t\341\272\247m:", nullptr));
        label_video_fps_10->setText(QCoreApplication::translate("MainWindow", "30", nullptr));
        label_video_fps_11->setText(QCoreApplication::translate("MainWindow", "55", nullptr));
        label_video_fps_7->setText(QCoreApplication::translate("MainWindow", "-15", nullptr));
        label_ele->setText(QCoreApplication::translate("MainWindow", "00", nullptr));
        label_video_fps_12->setText(QCoreApplication::translate("MainWindow", "55", nullptr));
        label_video_fps_8->setText(QCoreApplication::translate("MainWindow", "-15", nullptr));
        label_video_fps_9->setText(QCoreApplication::translate("MainWindow", "30", nullptr));
        label_video_fps_15->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        label_video_fps_16->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        label_video_fps_13->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_video_fps_14->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("MainWindow", "T\304\220 c\303\242n b\341\272\261ng;", nullptr));
        bt_video_test_2->setText(QCoreApplication::translate("MainWindow", "T\341\272\257t STAB", nullptr));
        bt_stab_2->setText(QCoreApplication::translate("MainWindow", "Stab 2", nullptr));
        groupBox_angle_limit->setTitle(QCoreApplication::translate("MainWindow", "Gi\341\273\233i h\341\272\241n g\303\263c:", nullptr));
        radioButton_leftlimit->setText(QString());
        radioButton_nolimit->setText(QString());
        radioButton_uplimit->setText(QString());
        radioButton_downlimit->setText(QString());
        radioButton_rightlimit->setText(QString());
        groupBox_15->setTitle(QCoreApplication::translate("MainWindow", "Ch\341\272\277 \304\221\341\273\231 video:", nullptr));
        bt_video_main->setText(QCoreApplication::translate("MainWindow", "Ng\303\240y", nullptr));
        bt_video_thermal->setText(QCoreApplication::translate("MainWindow", "\304\220\303\252m", nullptr));
        bt_video_off->setText(QCoreApplication::translate("MainWindow", "T\341\272\257t", nullptr));
        groupBox_16->setTitle(QCoreApplication::translate("MainWindow", "Th\306\260\341\273\233c ng\341\272\257m", nullptr));
        pushButton_sightup->setText(QCoreApplication::translate("MainWindow", "Ch\341\273\211nh l\303\252n", nullptr));
        pushButton_sight_right->setText(QCoreApplication::translate("MainWindow", "Ch\341\273\211nh xu\341\273\221ng", nullptr));
        groupBox_17->setTitle(QCoreApplication::translate("MainWindow", "\304\220i\341\273\201u khi\341\273\203n:", nullptr));
        bt_zero_set_3->setText(QCoreApplication::translate("MainWindow", "Joystick", nullptr));
        bt_control_usb->setText(QCoreApplication::translate("MainWindow", "USB", nullptr));
        bt_control_usb_2->setText(QCoreApplication::translate("MainWindow", "B\303\240n ph\303\255m", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
