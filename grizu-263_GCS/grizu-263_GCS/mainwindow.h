#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>
#include "triangle.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void serialReceived();
    void realtimeDataSlot();

private:
    Ui::MainWindow *ui;
    QGraphicsScene  *scene;     /// We declare a graphic scene
    Triangle        *triangle;  /// and triangle
    QTimer          *timer;     /* We declare the game a timer,
                                 * by which will be changing the position of an object
                                 * on the stage when exposed to the keyboard keys
                                 * */
};

#endif // MAINWINDOW_H
