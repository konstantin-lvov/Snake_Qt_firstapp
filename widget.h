#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <iostream>
#include <QPainter>
#include <QWidget>
#include <QSize>
#include <QEvent>
#include <QDebug>
#include "snake.h"
#include <QKeyEvent>
#include <QTimer>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QMessageBox>

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    Widget(Snake *snake);
    void setSnake(Snake *);
    ~Widget();
    int getKey();
    void gameOver();
    

private slots:
    void slotTimerOn();

protected:
    void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Snake *psnake;
    int key = 16777235;
    QTimer *timer;
    QLabel *label;
    QString str;
    int gameCount = 0;
};

#endif // WIDGET_H