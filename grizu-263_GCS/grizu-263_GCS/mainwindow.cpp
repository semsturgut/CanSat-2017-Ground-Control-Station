#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::makePlot();
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot(){
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
