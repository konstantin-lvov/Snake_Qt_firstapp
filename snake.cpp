#include "snake.h"

using namespace std;

/*Конструктор создает первоначалного червяка и заполняет
 оставшийся массив минус еденицами*/
Snake::Snake() {

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 100; j++) {
            snake_array [i] [j] = -1;
        }
    }
    snake_array [0][0] = 2;
    snake_array [1][0] = 3;
    snake_array [0][1] = 2;
    snake_array [1][1] = 4;

    cout << "Конструктор отработал" << endl;
}

Snake::~Snake() {
    cout << "Деструктор индахаус" << endl;
}

/*функция проверяет на столкновение змеиной голвы с туловищем*/
bool Snake::checkCollisions(){
    for(int i = 1; i < Snake::getLenght(); i++){
        
        if(snake_array [0][0] == snake_array [0][i] && 
                snake_array [1][0] == snake_array [1][i]){
            std::cout << "true" << std::endl;
            return true;
        }
    }
            return false;
        
}

/*Генерирует новые случайные координаты для яблока*/
void Snake::randomizeAppleCoords() {
    bool nomatch = true;

    while (nomatch) {
        nomatch = false;
        std::srand(clock());
        xApple = std::rand() % 10;
        std::srand(clock());
        yApple = std::rand() % 10;
        for (int j = 0; j < 100; j++) {
            if (snake_array [0][j] == xApple &
                    snake_array [1][j] == yApple) {
                nomatch = true;
            }

        }
    }

}

int Snake::getXApple() {
    return Snake::xApple;
}

int Snake::getYApple() {
    return Snake::yApple;
}

int Snake::getArrEll(int a, int b) {
    return snake_array [a] [b];
}

/*для получения длинны тела змеии*/
int Snake::getLenght() {
    unsigned int count;
    for (count = 0; count < (sizeof (snake_array) /
            sizeof (snake_array [0][0])) / 2; count++) {
        if (snake_array [0][count] < 0) {
            break;
        }
    }
    lenght = count;
    return lenght;
}

/*шаг вправо*/
void Snake::stepRight() {
    int tmpArray [2][100];

    for (int j = 0; j < 100; j++) {
        tmpArray [0][j] = snake_array [0][j];
        tmpArray [1][j] = snake_array [1][j];
    }
    /*Выполняю если справа нет "эллемента туловища"*/
    if (snake_array [0][1] != snake_array [0][0] + 1) {
        if (snake_array [0][0] == 9) {
            snake_array [0][0] = 0;
            Snake::keyBlock = 16777234;
        } else {
            int tmp = tmpArray [0][0];
            snake_array [0][0] = ++tmp;
            Snake::keyBlock = 16777234;
        }
    }

        for (int j = 1; j <= Snake::getLenght(); j++) {
            if (j == Snake::getLenght()) {
                Snake::xTail = tmpArray [0][j - 1];
                Snake::yTail = tmpArray [1][j - 1];
                break;
            }
            snake_array [0][j] = tmpArray [0][j - 1];
            snake_array [1][j] = tmpArray [1][j - 1];
    }
}

/*шаг влево*/
void Snake::stepLeft() {
    int tmpArray [2][100];

    for (int j = 0; j < 100; j++) {
        tmpArray [0][j] = snake_array [0][j];
        tmpArray [1][j] = snake_array [1][j];
    }

    /*Выполняю если слева нет "эллемента туловища"*/
    if (snake_array [0][1] != snake_array [0][0] - 1) {
        if (snake_array [0][0] == 0) {
            snake_array [0][0] = 9;
            Snake::keyBlock = 16777236;
        } else {
            int tmp = tmpArray [0][0];
            snake_array [0][0] = --tmp;
            Snake::keyBlock = 16777236;
        }

        for (int j = 1; j <= Snake::getLenght(); j++) {
            if (j == Snake::getLenght()) {
                Snake::xTail = tmpArray [0][j - 1];
                Snake::yTail = tmpArray [1][j - 1];
                break;
            }
            snake_array [0][j] = tmpArray [0][j - 1];
            snake_array [1][j] = tmpArray [1][j - 1];
        }
    }
}

/*шаг вверх*/
void Snake::stepUp() {
    int tmpArray [2][100];

    for (int j = 0; j < 100; j++) {
        tmpArray [0][j] = snake_array [0][j];
        tmpArray [1][j] = snake_array [1][j];
    }

    /*Выполняю если сверху нет "эллемента туловища"*/
    if (snake_array [1][1] != snake_array [1][0] - 1) {
        if (snake_array [1][0] == 0) {
            snake_array [1][0] = 9;
            Snake::keyBlock = 16777237;
        } else {
            int tmp = tmpArray [1][0];
            snake_array [1][0] = --tmp;
            Snake::keyBlock = 16777237;
        }

        for (int j = 1; j <= Snake::getLenght(); j++) {
            if (j == Snake::getLenght()) {
                Snake::xTail = tmpArray [0][j - 1];
                Snake::yTail = tmpArray [1][j - 1];
                break;
            }
            snake_array [0][j] = tmpArray [0][j - 1];
            snake_array [1][j] = tmpArray [1][j - 1];
        }
    }
}

/*шаг вниз*/
void Snake::stepDown() {
    int tmpArray [2][100];

    for (int j = 0; j < 100; j++) {
        tmpArray [0][j] = snake_array [0][j];
        tmpArray [1][j] = snake_array [1][j];
    }

    /*Выполняю если по вертикали нет "эллемента туловища"*/
    if (snake_array [1][1] != snake_array [1][0] + 1) {
        if (snake_array [1][0] == 9) {
            snake_array [1][0] = 0;
            Snake::keyBlock = 16777235;
        } else {
            int tmp = tmpArray [1][0];
            snake_array [1][0] = ++tmp;
            Snake::keyBlock = 16777235;
        }

        for (int j = 1; j <= Snake::getLenght(); j++) {
            if (j == Snake::getLenght()) {
                Snake::xTail = tmpArray [0][j - 1];
                Snake::yTail = tmpArray [1][j - 1];
                break;
            }
            snake_array [0][j] = tmpArray [0][j - 1];
            snake_array [1][j] = tmpArray [1][j - 1];
        }
    }
}

int Snake::getKeyBlock() {
    return Snake::keyBlock;
}

/*устанавливает координаты для нового элемента туловища*/
void Snake::addToTail() {

    int tmpLen = Snake::getLenght();

    snake_array [0][tmpLen] = Snake::xTail;
    snake_array [1][tmpLen] = Snake::yTail;

}
