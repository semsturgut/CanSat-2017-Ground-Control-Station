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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *customPlot_2;
    QLCDNumber *lcdNumber;
    QCustomPlot *customPlot;
    QLabel *label;
    QCustomPlot *customPlot_3;
    QCustomPlot *customPlot_4;
    QCustomPlot *customPlot_5;
    QCustomPlot *customPlot_6;
    QCustomPlot *customPlot_7;
    QCustomPlot *customPlot_8;
    QLabel *pic_compass;
    QLabel *pic_logo;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *pic_state;
    QLabel *label_21;
    QComboBox *comboBox;
    QLabel *label_22;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLabel *label_23;
    QComboBox *comboBox_4;
    QLabel *label_24;
    QComboBox *comboBox_5;
    QLabel *label_25;
    QPushButton *pushButton;
    QLabel *label_26;
    QPushButton *pushButton_2;
    QLabel *pic_beun;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1061, 772);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        customPlot_2 = new QCustomPlot(centralWidget);
        customPlot_2->setObjectName(QStringLiteral("customPlot_2"));
        customPlot_2->setGeometry(QRect(280, 290, 241, 191));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(630, 130, 64, 23));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        lcdNumber->setFont(font);
        lcdNumber->setStyleSheet(QStringLiteral("background-color: rgb(0, 85, 127);"));
        lcdNumber->setProperty("intValue", QVariant(0));
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(20, 290, 241, 191));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(520, 130, 101, 16));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        customPlot_3 = new QCustomPlot(centralWidget);
        customPlot_3->setObjectName(QStringLiteral("customPlot_3"));
        customPlot_3->setGeometry(QRect(800, 290, 241, 191));
        customPlot_4 = new QCustomPlot(centralWidget);
        customPlot_4->setObjectName(QStringLiteral("customPlot_4"));
        customPlot_4->setGeometry(QRect(540, 290, 241, 191));
        customPlot_5 = new QCustomPlot(centralWidget);
        customPlot_5->setObjectName(QStringLiteral("customPlot_5"));
        customPlot_5->setGeometry(QRect(280, 520, 241, 191));
        customPlot_6 = new QCustomPlot(centralWidget);
        customPlot_6->setObjectName(QStringLiteral("customPlot_6"));
        customPlot_6->setGeometry(QRect(800, 520, 241, 191));
        customPlot_7 = new QCustomPlot(centralWidget);
        customPlot_7->setObjectName(QStringLiteral("customPlot_7"));
        customPlot_7->setGeometry(QRect(540, 520, 241, 191));
        customPlot_8 = new QCustomPlot(centralWidget);
        customPlot_8->setObjectName(QStringLiteral("customPlot_8"));
        customPlot_8->setGeometry(QRect(20, 520, 241, 191));
        pic_compass = new QLabel(centralWidget);
        pic_compass->setObjectName(QStringLiteral("pic_compass"));
        pic_compass->setGeometry(QRect(320, 30, 161, 161));
        pic_logo = new QLabel(centralWidget);
        pic_logo->setObjectName(QStringLiteral("pic_logo"));
        pic_logo->setGeometry(QRect(760, 90, 251, 181));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(395, 0, 21, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(396, 190, 20, 31));
        label_3->setFont(font2);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(300, 90, 16, 41));
        label_4->setFont(font2);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(490, 90, 16, 41));
        label_5->setFont(font2);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(520, 40, 91, 21));
        label_6->setFont(font2);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(520, 60, 171, 41));
        label_7->setFont(font1);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(520, 100, 161, 21));
        label_8->setFont(font1);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(70, 490, 151, 21));
        label_9->setFont(font1);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(310, 490, 181, 21));
        label_10->setFont(font1);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(590, 490, 141, 21));
        label_11->setFont(font1);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(860, 490, 121, 21));
        label_12->setFont(font1);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(80, 720, 121, 21));
        label_13->setFont(font1);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(360, 720, 101, 21));
        label_14->setFont(font1);
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(590, 720, 151, 21));
        label_15->setFont(font1);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(870, 720, 111, 21));
        label_16->setFont(font1);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(350, 240, 121, 21));
        label_17->setFont(font1);
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(520, 160, 111, 21));
        label_18->setFont(font1);
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(630, 160, 71, 21));
        label_19->setFont(font2);
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(520, 190, 111, 21));
        label_20->setFont(font1);
        pic_state = new QLabel(centralWidget);
        pic_state->setObjectName(QStringLiteral("pic_state"));
        pic_state->setGeometry(QRect(630, 180, 51, 41));
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(50, 40, 71, 21));
        QFont font3;
        font3.setPointSize(10);
        label_21->setFont(font3);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(120, 40, 81, 22));
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(50, 70, 71, 21));
        label_22->setFont(font3);
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(120, 70, 81, 22));
        comboBox_3 = new QComboBox(centralWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(120, 100, 81, 22));
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(50, 100, 71, 21));
        label_23->setFont(font3);
        comboBox_4 = new QComboBox(centralWidget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(120, 130, 81, 22));
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(50, 130, 71, 21));
        label_24->setFont(font3);
        comboBox_5 = new QComboBox(centralWidget);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setGeometry(QRect(120, 160, 81, 22));
        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(40, 160, 71, 21));
        QFont font4;
        font4.setPointSize(9);
        label_25->setFont(font4);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 200, 101, 51));
        pushButton->setFont(font1);
        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(396, 220, 20, 21));
        label_26->setFont(font1);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 200, 101, 51));
        pushButton_2->setFont(font1);
        pic_beun = new QLabel(centralWidget);
        pic_beun->setObjectName(QStringLiteral("pic_beun"));
        pic_beun->setGeometry(QRect(740, 0, 301, 81));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "grizu-263 Ground Control Station V0.1", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Packet Count:", Q_NULLPTR));
        pic_compass->setText(QString());
        pic_logo->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "S", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "W", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "E", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "grizu-263", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Bulent Ecevit University\n"
"Space Team", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Team Number #4773", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Container - Altitude", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Container - Temperature", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Container - Voltage", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Glider - Altitude", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Glider - Pressure", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Glider - Speed", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Glider - Temperature", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Glider - Voltage", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Glider - Heading", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Mission Time:", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "0:00:00", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Software State:", Q_NULLPTR));
        pic_state->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "Baudrate:", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "9600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "300", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4800", Q_NULLPTR)
         << QApplication::translate("MainWindow", "14400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "28800", Q_NULLPTR)
         << QApplication::translate("MainWindow", "38400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "57600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "115200", Q_NULLPTR)
        );
        label_22->setText(QApplication::translate("MainWindow", "Data Bits:", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "7", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8", Q_NULLPTR)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Even", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Mark", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Odd", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Space", Q_NULLPTR)
        );
        label_23->setText(QApplication::translate("MainWindow", "Parity:", Q_NULLPTR));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
        );
        label_24->setText(QApplication::translate("MainWindow", "Stop Bits:", Q_NULLPTR));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Hardware", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Xon/Xoff", Q_NULLPTR)
        );
        label_25->setText(QApplication::translate("MainWindow", "Flow Control:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "0\302\260", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Draw Plot\n"
" From Log", Q_NULLPTR));
        pic_beun->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
