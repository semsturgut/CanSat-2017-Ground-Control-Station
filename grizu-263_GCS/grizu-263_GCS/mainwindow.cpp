#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QObject>

QSerialPort *serial;
QString raw;
QStringList raw_list;
QStringList sensorData;
double con_alt,con_temp,con_volt;
//bool ok;



MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        //MainWindow::makePlot();
        //On Windows you should change directory. D:/Documents/grizu-263/GRIZU-263 (CANSAT)/Electronic Team/grizu-263_GCS/resources/
        QPixmap compass("/home/sems/Documents/grizu-263/CanSat-2017-Ground-Control-Station/grizu-263_GCS/resources/compass.png");
        ui->pic_compass->setPixmap(compass);
        QPixmap logo("/home/sems/Documents/grizu-263/CanSat-2017-Ground-Control-Station/grizu-263_GCS/resources/grizulogo.png");
        ui->pic_logo->setPixmap(logo);
        QPixmap state("/home/sems/Documents/grizu-263/CanSat-2017-Ground-Control-Station/grizu-263_GCS/resources/true.png");
        ui->pic_state->setPixmap(state);
        QPixmap beun("/home/sems/Documents/grizu-263/CanSat-2017-Ground-Control-Station/grizu-263_GCS/resources/beun.png");
        ui->pic_beun->setPixmap(beun);
        setWindowIcon(QIcon(logo));

        ui->lcdNumber->setDigitCount(4);

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setPen(QPen(QColor(244, 66, 66)));
        ui->customPlot_2->addGraph();
        ui->customPlot_2->graph(0)->setPen(QPen(QColor(73, 65, 244)));
        ui->customPlot_3->addGraph();
        ui->customPlot_3->graph(0)->setPen(QPen(QColor(244, 241, 65)));
        ui->customPlot_4->addGraph();
        ui->customPlot_4->graph(0)->setPen(QPen(QColor(157, 65, 244)));
        ui->customPlot_5->addGraph();
        ui->customPlot_5->graph(0)->setPen(QPen(QColor(244, 241, 65)));
        ui->customPlot_6->addGraph();
        ui->customPlot_6->graph(0)->setPen(QPen(QColor(244, 241, 65)));
        ui->customPlot_7->addGraph();
        ui->customPlot_7->graph(0)->setPen(QPen(QColor(244, 241, 65)));
        ui->customPlot_8->addGraph();
        ui->customPlot_8->graph(0)->setPen(QPen(QColor(244, 241, 65)));

        QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
        timeTicker->setTimeFormat("%m:%s");

        ui->customPlot->xAxis->setTicker(timeTicker);
        ui->customPlot->axisRect()->setupFullAxesBox();
        ui->customPlot->yAxis->setRange(-5, 100);

        ui->customPlot_2->xAxis->setTicker(timeTicker);
        ui->customPlot_2->axisRect()->setupFullAxesBox();
        ui->customPlot_2->yAxis->setRange(-5, 50);

        ui->customPlot_3->xAxis->setTicker(timeTicker);
        ui->customPlot_3->axisRect()->setupFullAxesBox();
        ui->customPlot_3->yAxis->setRange(-5, 100);

        ui->customPlot_4->xAxis->setTicker(timeTicker);
        ui->customPlot_4->axisRect()->setupFullAxesBox();
        ui->customPlot_4->yAxis->setRange(-5, 10);

        ui->customPlot_5->xAxis->setTicker(timeTicker);
        ui->customPlot_5->axisRect()->setupFullAxesBox();
        ui->customPlot_5->yAxis->setRange(-5, 5);

        ui->customPlot_6->xAxis->setTicker(timeTicker);
        ui->customPlot_6->axisRect()->setupFullAxesBox();
        ui->customPlot_6->yAxis->setRange(-5, 10);

        ui->customPlot_7->xAxis->setTicker(timeTicker);
        ui->customPlot_7->axisRect()->setupFullAxesBox();
        ui->customPlot_7->yAxis->setRange(-5, 50);

        ui->customPlot_8->xAxis->setTicker(timeTicker);
        ui->customPlot_8->axisRect()->setupFullAxesBox();
        ui->customPlot_8->yAxis->setRange(-5, 150000);


        //Serial communication
        serial = new QSerialPort(this);
        serial->setPortName("/dev/ttyUSB0");
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        serial->open(QIODevice::ReadWrite);
        connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));

}

MainWindow::~MainWindow()
{
        delete ui;
}

void MainWindow::serialReceived(){
        if(serial->canReadLine()) {
                QByteArray tel_data = serial->readLine();
                std::string message(tel_data.constData(), tel_data.length());
                raw = QString::fromStdString(message);
                raw_list = QString(raw).split("4773",QString::SkipEmptyParts);
                raw_list = QString(raw_list.at(1)).split("\r",QString::SkipEmptyParts);
                raw_list = QString(raw_list.at(0)).split(",",QString::SkipEmptyParts);
                qDebug()<<raw_list;
                ui->lcdNumber->display(raw_list.at(2));
                // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
                QTimer *dataTimer = new QTimer(this);
                bool ok;
                con_alt = raw_list.at(3).toDouble(&ok);
                con_temp = raw_list.at(4).toDouble(&ok);
                con_volt = raw_list.at(5).toDouble(&ok);
                connect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
                dataTimer->start(0); // Interval 0 means to refresh as fast as possible
                tel_data.clear();
                raw.clear();
                raw_list.clear();
        }
}

void MainWindow::realtimeDataSlot(){

        static QTime time(QTime::currentTime());
        // calculate two new data points:
        double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
        static double lastPointKey = 0;
        if (key-lastPointKey > 0.002) // at most add point every 2 ms
        {
                // add data to lines:
                ui->customPlot->graph(0)->addData(key, con_alt);
                ui->customPlot_2->graph(0)->addData(key, con_temp);
                ui->customPlot_3->graph(0)->addData(key, 0);
                ui->customPlot_4->graph(0)->addData(key, con_volt);
                ui->customPlot_5->graph(0)->addData(key, 0);
                ui->customPlot_6->graph(0)->addData(key, 0);
                ui->customPlot_7->graph(0)->addData(key, 0);
                ui->customPlot_8->graph(0)->addData(key, 0);
                // rescale value (vertical) axis to fit the current data:
                ui->customPlot->graph(0)->rescaleValueAxis(true);
                ui->customPlot_2->graph(0)->rescaleValueAxis(true);
                ui->customPlot_3->graph(0)->rescaleValueAxis(true);
                ui->customPlot_4->graph(0)->rescaleValueAxis(true);
                ui->customPlot_5->graph(0)->rescaleValueAxis(true);
                ui->customPlot_6->graph(0)->rescaleValueAxis(true);
                ui->customPlot_7->graph(0)->rescaleValueAxis(true);
                ui->customPlot_8->graph(0)->rescaleValueAxis(true);
                lastPointKey = key;
        }
// make key axis range scroll with the data (at a constant range size of 8):
        ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->customPlot->replot();
        ui->customPlot_2->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->customPlot_2->replot();
        ui->customPlot_3->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->customPlot_3->replot();
        ui->customPlot_4->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->customPlot_4->replot();
        ui->customPlot_5->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->customPlot_5->replot();
        ui->customPlot_6->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->customPlot_6->replot();
        ui->customPlot_7->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->customPlot_7->replot();
        ui->customPlot_8->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->customPlot_8->replot();

// calculate frames per second:
        static double lastFpsKey;
        static int frameCount;
        ++frameCount;
        if (key-lastFpsKey > 2) // average fps over 2 seconds
        {
                ui->statusBar->showMessage(
                        QString("%1 FPS, Total Data points: %2")
                        .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
                        .arg(ui->customPlot->graph(0)->data()->size())
                        , 0);
                lastFpsKey = key;
                frameCount = 0;
        }
        /*
           // generate some data:
           QVector<double> x(101), y(101); // initialize with entries 0..100
           for (int i=0; i<101; ++i)
           {
           x[i] = i/50.0 - 1; // x goes from -1 to 1
           y[i] = x[i]*x[i]; // let's plot a quadratic function
           }
           // create graph and assign data to it:
           ui->customPlot->addGraph();
           ui->customPlot->graph(0)->setData(x, y);
           // give the axes some labels:
           ui->customPlot->xAxis->setLabel("x");
           ui->customPlot->yAxis->setLabel("y");
           // set axes ranges, so we see all data:
           ui->customPlot->xAxis->setRange(-1, 1);
           ui->customPlot->yAxis->setRange(0, 1);
           ui->customPlot->replot();*/
}
