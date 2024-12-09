#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 30 && x <530)
                x+=10;
            else if (x == 530 && y < 150)
                y+=10;
            else if (x > 260 && y == 150)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (y == 30 && x <800)
                x+=10;
            else if (x == 800 && y < 150)
                y+=10;
            else if (x > 530 && y == 150)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //trem 3
            if(y == 150 && x < 395)
                x+=10;
            else if(x == 395 && y < 270)
                y+=10;
            else if(x > 125 && y ==270)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);
            break;
        case 4:
            if(y == 150 && x < 665)
                x+=10;
            else if(x == 665 && y < 270)
                y+=10;
            else if(x > 395 && y == 270)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);
            break;
        case 5:
            if(y == 150 && x < 935)
                x+=10;
            emit updateGUI(ID, x, y);
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}




