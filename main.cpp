#include "widget.h"
#include <QApplication>
#include <iostream>
#include <snake.h>

int main(int argc, char *argv[])
{
    
    Snake snake;
    Snake *psnake = &snake;
    
    QApplication a(argc, argv);
    
    Widget *w = new Widget(psnake);
    w->setGeometry(500,300,300,300);
    w->show();
    
    return a.exec();
}
