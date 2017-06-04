// @@@ Grafik x ekseni default degerleri yarismadan once kontrol edilecek.
// TODO: Veri alisverisinden belirli bir sure sonra olusan arayuz takilmasi problemi giderilecek..
// TODO: Glider 2d harita hatalari duzeltilecek.

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "triangle.h"
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QObject>
#include <qapplication.h>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

QSerialPort *serial;
QString raw;
QStringList raw_list;
QStringList sensorData;
QString softState,con_missionTime,gld_missionTime;
double con_alt,con_temp,con_volt;
double gld_alt,gld_press,gld_temp,gld_volt;
int con_count;
int gld_count,gld_speed,gld_heading,gld_img_count;
int con_loss = 0,gld_loss=0;


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
        ui->setupUi(this);

        scene = new QGraphicsScene();   /// Initialize the graphics scene
        triangle = new Triangle();      /// Initialize triangle

        ui->graphicsView->setScene(scene);  /// Set the graphic scene in qgraphicsView
        ui->graphicsView->setRenderHint(QPainter::Antialiasing);    /// Install anti-aliasing

        //On Windows you should change directory. D:/Documents/grizu-263/GRIZU-263 (CANSAT)/Electronic Team/grizu-263_GCS/resources/
        QPixmap logo("/home/sems/Documents/grizu-263/CanSat-2017-Ground-Control-Station/grizu-263_GCS/resources/grizulogo.png");
        ui->pic_logo->setPixmap(logo);
        QPixmap beun("/home/sems/Documents/grizu-263/CanSat-2017-Ground-Control-Station/grizu-263_GCS/resources/beun.png");
        ui->pic_beun->setPixmap(beun);
        QPixmap aas("/home/sems/Documents/grizu-263/CanSat-2017-Ground-Control-Station/grizu-263_GCS/resources/aas.png");
        ui->pic_aas->setPixmap(aas);
        QPixmap aiaa("/home/sems/Documents/grizu-263/CanSat-2017-Ground-Control-Station/grizu-263_GCS/resources/aiaa.png");
        ui->pic_aiaa->setPixmap(aiaa);
        QPixmap nasa("/home/sems/Documents/grizu-263/CanSat-2017-Ground-Control-Station/grizu-263_GCS/resources/nasa.png");
        ui->pic_nasa->setPixmap(nasa);
        setWindowIcon(QIcon(logo));

        ui->lcdNumber->setDigitCount(4);

        ui->conAltPlot->addGraph(); // Container Altitude
        ui->conAltPlot->graph(0)->setPen(QPen(QColor(244, 66, 66)));
        ui->conTempPlot->addGraph(); // Container Temperature
        ui->conTempPlot->graph(0)->setPen(QPen(QColor(73, 65, 244)));
        ui->glidAltPlot->addGraph(); // Glider Altitude
        ui->glidAltPlot->graph(0)->setPen(QPen(QColor(244, 241, 65)));
        ui->conVoltPlot->addGraph(); // Container Voltage
        ui->conVoltPlot->graph(0)->setPen(QPen(QColor(157, 65, 244)));
        ui->glidSpdPlot->addGraph(); // Glider Speed
        ui->glidSpdPlot->graph(0)->setPen(QPen(QColor(244, 241, 65)));
        ui->glidVoltPlot->addGraph(); // Glider Voltage
        ui->glidVoltPlot->graph(0)->setPen(QPen(QColor(244, 241, 65)));
        ui->glidTempPlot->addGraph(); // Glider Temperature
        ui->glidTempPlot->graph(0)->setPen(QPen(QColor(244, 241, 65)));
        ui->glidPresPlot->addGraph(); // Glider Pressure
        ui->glidPresPlot->graph(0)->setPen(QPen(QColor(244, 241, 65)));

        QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
        timeTicker->setTimeFormat("%m:%s");

        ui->conAltPlot->xAxis->setTicker(timeTicker);
        ui->conAltPlot->axisRect()->setupFullAxesBox();
        ui->conAltPlot->yAxis->setRange(-5, 200);

        ui->conTempPlot->xAxis->setTicker(timeTicker);
        ui->conTempPlot->axisRect()->setupFullAxesBox();
        ui->conTempPlot->yAxis->setRange(-5, 50);

        ui->glidAltPlot->xAxis->setTicker(timeTicker);
        ui->glidAltPlot->axisRect()->setupFullAxesBox();
        ui->glidAltPlot->yAxis->setRange(-5, 200);

        ui->conVoltPlot->xAxis->setTicker(timeTicker);
        ui->conVoltPlot->axisRect()->setupFullAxesBox();
        ui->conVoltPlot->yAxis->setRange(0, 10);

        ui->glidSpdPlot->xAxis->setTicker(timeTicker);
        ui->glidSpdPlot->axisRect()->setupFullAxesBox();
        ui->glidSpdPlot->yAxis->setRange(-5, 30);

        ui->glidVoltPlot->xAxis->setTicker(timeTicker);
        ui->glidVoltPlot->axisRect()->setupFullAxesBox();
        ui->glidVoltPlot->yAxis->setRange(0, 10);

        ui->glidTempPlot->xAxis->setTicker(timeTicker);
        ui->glidTempPlot->axisRect()->setupFullAxesBox();
        ui->glidTempPlot->yAxis->setRange(-5, 50);

        ui->glidPresPlot->xAxis->setTicker(timeTicker);
        ui->glidPresPlot->axisRect()->setupFullAxesBox();
        ui->glidPresPlot->yAxis->setRange(0, 5000);


        //Serial communication
        serial = new QSerialPort(this);
        serial->setPortName("/dev/ttyUSB0"); // Windows'ta "COM0" olarak degistirilmesi gerekiyor. Linux da ise "/dev/ttyUSB0"
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        serial->open(QIODevice::ReadWrite);
        connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));
        scene->addItem(triangle);   /// Adding to the scene triangle
        triangle->setPos(0,0);      /// Set the triangle in the center of the stage

}

MainWindow::~MainWindow() {
        delete ui;
}


void MainWindow::serialReceived() {
        if(serial->canReadLine()) {
                QByteArray tel_data = serial->readLine();
                std::string message(tel_data.constData(), tel_data.length());
                raw = QString::fromStdString(message);
                // qDebug() << raw;
                raw_list = QString(raw).split("4773",QString::SkipEmptyParts);
                raw_list = QString(raw_list.at(0)).split("\r",QString::SkipEmptyParts);
                raw_list = QString(raw_list.at(0)).split(",",QString::SkipEmptyParts);
                qDebug() << raw_list;
                QString csvName = "/home/sems/Documents/grizu-263/CanSat-2017-Ground-Control-Station/grizu-263_GCS/resources/CANSAT2017_TLM_4773_GRIZU263.csv";
                QFile csvFile(csvName);
                if(!csvFile.open(QFile::WriteOnly | QFile::Append)) {
                    qDebug() << "Error openning file.";
                }

                if (raw_list.at(0) == "CONTAINER") {
                        if(raw_list.size() >= 7) {
                                ui->lcdNumber->display(raw_list.at(2));
                                // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
                                QTimer *dataTimer = new QTimer(this);
                                bool ok;

                                QTextStream stream(&csvFile);
                                stream << "4773";
                                stream << ",";
                                stream << raw_list.at(0);
                                stream << ",";
                                con_missionTime = raw_list.at(1);
                                stream << raw_list.at(1);
                                stream << ",";
                                con_count = raw_list.at(2).toInt();
                                stream << raw_list.at(2);
                                stream << ",";
                                con_alt = raw_list.at(3).toDouble(&ok);
                                stream << raw_list.at(3);
                                stream << ",";
                                con_temp = raw_list.at(4).toDouble(&ok);
                                stream << raw_list.at(4);
                                stream << ",";
                                con_volt = raw_list.at(5).toDouble(&ok);
                                stream << raw_list.at(5);
                                stream << ",";
                                softState = raw_list.at(6);
                                stream << raw_list.at(6) << endl;
                                csvFile.flush();
                                csvFile.close();

                                ui->mssnTimeLbl->setText(con_missionTime);
                                ui->conAltLbl->setText(QString::number(con_alt));
                                ui->conTempLbl->setText(QString::number(con_temp));
                                ui->conVoltLbl->setText(QString::number(con_volt));
                                ui->stateLbl->setText(softState);


                                connect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
                                dataTimer->start(0); // Interval 0 means to refresh as fast as possible
                        } else if (raw_list.size() > 0) {
                                con_loss++;
                                qDebug() << "Data loss problem appeared..";
                                qDebug() << "Total data loss on CONTAINER: " << con_loss;
                        }
                } else if (raw_list.at(0) == "GLIDER") {
                        if(raw_list.size() >= 11) {
                                ui->lcdNumber->display(raw_list.at(2));
                                // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
                                QTimer *dataTimer = new QTimer(this);
                                bool ok;
                                gld_missionTime = raw_list.at(1);
                                gld_count = raw_list.at(2).toInt();
                                gld_alt = raw_list.at(3).toDouble(&ok);
                                gld_press = raw_list.at(4).toDouble(&ok);
                                gld_speed = raw_list.at(5).toInt();
                                gld_temp = raw_list.at(6).toInt();
                                gld_volt = raw_list.at(7).toDouble(&ok);
                                gld_heading = raw_list.at(8).toInt();
                                softState = raw_list.at(9);
                                gld_img_count = raw_list.at(10).toInt();

                                ui->mssnTimeLbl->setText(gld_missionTime);
                                ui->gldPosLbl->setText(QString::number(gld_heading));
                                ui->glidAltLbl->setText(QString::number(gld_alt));
                                ui->glidPresLbl->setText(QString::number(gld_press));
                                ui->glidSpdLbl->setText(QString::number(gld_speed));
                                ui->glidTempLbl->setText(QString::number(gld_temp));
                                ui->glidVoltLbl->setText(QString::number(gld_volt));
                                ui->stateLbl->setText(softState);

                                connect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
                                dataTimer->start(0); // Interval 0 means to refresh as fast as possible

                                glider_angle = gld_heading;
                                glider_speed = gld_speed;
                                timer = new QTimer();
                                connect(timer, &QTimer::timeout, triangle, &Triangle::slotGameTimer);
                                timer->start(1000 / 50);

                        } else if (raw_list.size() > 0) {
                                con_loss++;
                                qDebug() << "Data loss problem appeared..";
                                qDebug() << "Total data loss on GLIDER: " << con_loss;
                        }
                }
                tel_data.clear();
                raw.clear();
                raw_list.clear();
        }
}

void MainWindow::realtimeDataSlot() {

        static QTime time(QTime::currentTime());
        // calculate two new data points:
        double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
        static double lastPointKey = 0;
        if (key-lastPointKey > 1) { // at most add point every 1 second

                // add data to lines:
                ui->conAltPlot->graph(0)->addData(key, con_alt);
                ui->conTempPlot->graph(0)->addData(key, con_temp);
                ui->glidAltPlot->graph(0)->addData(key, gld_alt);
                ui->conVoltPlot->graph(0)->addData(key, con_volt);
                ui->glidSpdPlot->graph(0)->addData(key, gld_speed);
                ui->glidVoltPlot->graph(0)->addData(key, gld_volt);
                ui->glidTempPlot->graph(0)->addData(key, gld_temp);
                ui->glidPresPlot->graph(0)->addData(key, gld_press);
                // rescale value (vertical) axis to fit the current data:
                ui->conAltPlot->graph(0)->rescaleValueAxis(true);
                ui->conTempPlot->graph(0)->rescaleValueAxis(true);
                ui->glidAltPlot->graph(0)->rescaleValueAxis(true);
                ui->conVoltPlot->graph(0)->rescaleValueAxis(true);
                ui->glidSpdPlot->graph(0)->rescaleValueAxis(true);
                ui->glidVoltPlot->graph(0)->rescaleValueAxis(true);
                ui->glidTempPlot->graph(0)->rescaleValueAxis(true);
                ui->glidPresPlot->graph(0)->rescaleValueAxis(true);
                lastPointKey = key;
        }

        // make key axis range scroll with the data (at a constant range size of 8):
        ui->conAltPlot->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->conAltPlot->replot();
        ui->conTempPlot->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->conTempPlot->replot();
        ui->glidAltPlot->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->glidAltPlot->replot();
        ui->conVoltPlot->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->conVoltPlot->replot();
        ui->glidSpdPlot->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->glidSpdPlot->replot();
        ui->glidVoltPlot->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->glidVoltPlot->replot();
        ui->glidTempPlot->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->glidTempPlot->replot();
        ui->glidPresPlot->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->glidPresPlot->replot();

}
