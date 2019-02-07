#include "widget.h"

/*В конструкторе:
 копируем указатель на змею
 создаем и настраиваем лейбл который показывает счет
 выводим начальное сообщение для пользователя
 запускаем таймер*/
Widget::Widget(Snake *ps) {
    std::cout << "widget constr snake arg: " << ps << " " << &ps << std::endl;
    Widget::setSnake(ps);

    label = new QLabel(this);
    label->setStyleSheet(QString("font-size: %1px").arg(12));
    label->setGeometry(0, 0, 13, 13);


    QMessageBox msgBox;
    msgBox.setWindowTitle("Змейка");
    msgBox.setText("Сложность увеличивается с каждым съеденым яблоком.\n"
            "Игра запустится после нажатия кнопки 'ок'.");
    msgBox.exec();

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerOn()));
    timer->start(500);
}

/*paintEvent функция вызывается каждый раз при вызове функции update()*/
void Widget::paintEvent(QPaintEvent * event) {
    QPainter painter(this);
    /*Заканчиваем игру если было столкновение*/
    if(psnake->checkCollisions()){
        Widget::gameOver();
    }
    /*Если голова съела яблоко то отрисовываем новое яблоко
     в рандомном месте + добавляем к хвосту змеи новый элемент
     + инкрементируем счетчик и обновляем таймер*/
    if (psnake->getArrEll(0, 0) == psnake->getXApple()
            && psnake->getArrEll(1, 0) == psnake->getYApple()) {

        painter.setPen(QPen(Qt::green));
        psnake->randomizeAppleCoords();
        painter.drawEllipse(psnake->getXApple()*30 + 10,
                psnake->getYApple()*30 + 10, 5, 5);
        psnake->addToTail();
        Widget::gameCount++;
        timer->setInterval(500 - gameCount * 4);


    } else {/*иначе рисуем яблоко там где оно было*/
        painter.setPen(QPen(Qt::green));
        painter.drawEllipse(psnake->getXApple()*30 + 5,
                psnake->getYApple()*30 + 5, 20, 20);
    }
    /*В цикле отрисовываем змею, счетчик*/
    for (int j = 0; j < psnake->getLenght(); j++) {
        if (j == 0) {
            painter.setPen(QPen(Qt::red));
            painter.drawEllipse(psnake->getArrEll(0, j)*30,
                    psnake->getArrEll(1, j)*30, 30, 30);

            label->move(((psnake->getArrEll(0, j)*30) + 7),
                    ((psnake->getArrEll(1, j)*30) + 7));
            label->setText(str.setNum(Widget::gameCount));


            label->show();


            continue;
        }
        painter.setPen(QPen(Qt::black));
        painter.drawEllipse(psnake->getArrEll(0, j)*30,
                psnake->getArrEll(1, j)*30, 30, 30);
    }
    /*Если игрок набрал максимум очков то заканчиваем игру*/
    if (gameCount == 98) {
        Widget::gameOver();
        
    }

}

/*Game Over*/
void Widget::gameOver(){
    Widget::close();
        QMessageBox msgBox;
        msgBox.setWindowTitle("Конец игры");
        str.clear();
        str.append(QString("===== Ваш счет: "));
        str.append(QString(QString::number(gameCount)));
        str.append(QString(" ====="));
        msgBox.setText(str);
        msgBox.exec();
}

/*данный слот вызывается по таймеру постоянно
 в нем по последней нажатой стрелке делается шаг змеии
 в соответствующем направлении
 И обновляется виджет*/
void Widget::slotTimerOn() {
    
    switch (Widget::key) {
        case 16777234:
            psnake->stepLeft();
            break;
        case 16777235:
            psnake->stepUp();
            break;
        case 16777236:
            psnake->stepRight();
            break;
        case 16777237:
            psnake->stepDown();
            break;
    }
    Widget::update(); //обновляем виджет вызывается paintEvent
}

/*функция вызывается при нажатии на клавиши*/
void Widget::keyPressEvent(QKeyEvent* event) {
    int tmp = event->key();
    if (psnake->getKeyBlock() != tmp) {
        Widget::key = tmp;
    }
}

int Widget::getKey() {
    return Widget::key;
}

void Widget::setSnake(Snake* s) {
    Widget::psnake = s;
}

Widget::~Widget() {

}