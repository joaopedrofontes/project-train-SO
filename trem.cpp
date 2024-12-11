#include "trem.h"
#include <QtCore>
#include <QMutex>

QMutex mut0;
QMutex mut1;

QMutex mut4;

QMutex mut6;

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}
void Trem::setVelocidade(int value)
{
    this->velocidade = value;
}
//Função a ser executada após executar trem->START
void Trem::run(){

    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 150 && x <480) {
                if(x == 460) {
                    mut0.lock();
                }
                x+=10;
            }
            else if (x == 480 && y < 270) {
                y+=10;
            }
            else if (x > 210 && y == 270) {
                if(x == 460) {
                    mut0.unlock();
                }
                if(x == 360) {
                    mut1.lock();
                }
                if(x == 220) {
                    mut1.unlock();
                }
                x-=10;
            }
            else if (x == 210 && y > 150){
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (y == 150 && x <750) {
                x+=10;
            }
            else if (x == 750 && y < 270) {
                if(y == 250) {
                    mut4.lock();
                }
                y+=10;
            }
            else if (x > 480 && y == 270) {
                if(x == 500) {
                    mut0.lock();
                }
                if(x == 600) {
                    mut4.unlock();
                }
                x-=10;
            }
            else if (x == 480 && y > 150) {
                if (y == 160) {
                    mut0.unlock();
                }
                y -= 10;
           }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //Trem 3
            if (y == 270 && x <340) {
                if(x == 190) {
                    mut1.lock();
                }
                if(x == 330) {
                    mut1.unlock();
                }
                x+=10;
            }
            else if (x == 340 && y < 390)
                y+=10;
            else if (x > 70 && y == 390)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4: //Trem 4
            if (y == 270 && x <620)
                x+=10;
            else if (x == 620 && y < 390)
                y+=10;
            else if (x > 340 && y == 390)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5: //Trem 5
            if (y == 270 && x <890) {
                if(x == 770) {
                    mut4.unlock();
                }
                x+=10;
            }
            else if (x == 890 && y < 390)
                y+=10;
            else if (x > 620 && y == 390) {
                x-=10;
            }
            else if (x == 620 && y > 270) {
                if(y == 290) {
                    mut4.lock();
                }
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}




