#include "trem.h"
#include <QtCore>
#include <QMutex>


QMutex mut0;
QMutex mut1;
QMutex mut2;
QMutex mut3;
QMutex mut4;
QMutex mut5;
QMutex mut6;



//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
 
 
    //mut1.lock();
    //mut3.lock();
}

void Trem::setVelocidade(int value)
{
    this->velocidade = value;
}
//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1 código sem mutex
            /*if (y == 150 && x <480)
                x+=10;
            else if (x == 480 && y < 270)
                y+=10;
            else if (x > 210 && y == 270)
                x-=10;
            else
                y-=10;*/
            //Trem 1 código com mutex
            if(y == 150)
            {
                if(x == 460){
                    mut0.lock();
                 }
                if(x < 480){
                    x += 10;
                }
            }

            if(y < 270)
            {
                if(x == 480 && y == 250){
                    mut2.lock();
                }
                if(x == 480){
                    y += 10;
                }
            }

            if(y == 270)
            {
                if(x == 310){
                    mut2.unlock();
                }
                if(x > 210){
                    x -= 10;
                }
                if(x == 360){
                    mut1.lock();
                }
                if(x == 450){
                    mut0.unlock();
                 }
            }

            if(x == 210 && y > 150)
            {
                y-=10;
                if(y == 250)
                    mut1.unlock();
            }

            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2 código sem mutex
            /*if (y == 150 && x <750)
                x+=10;
            else if (x == 750 && y < 270)
                y+=10;
            else if (x > 480 && y == 270)
                x-=10;
            else
                y-=10;*/
            //Trem 2 código com mutex
            if(y == 150)
            {
                if(x == 500){
                    mut0.unlock();
                 }
                if(x < 750){
                    x += 10;
                }
            }

            if(y < 270)
            {
                if(y == 250 && x == 750){
                    mut4.lock();
                }
                if(y == 250 && x == 480){
                    mut3.unlock();
                }
                if(x == 750){
                    y += 10;
                }
            }

            if(y == 270)
            {
                if(x == 590){
                    mut4.unlock();
                }
                if(x == 640){
                    mut0.lock();
                    mut3.lock();
                }
                if(x > 480){
                    x -= 10;
                }
            }

            if(x == 480 && y > 150)
            {
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //Trem 3 código sem mutex
            /*if (y == 270 && x <340)
                x+=10;
            else if (x == 340 && y < 390)
                y+=10;
            else if (x > 70 && y == 390)
                x-=10;
            else
                y-=10;*/
                //Trem 3 código com mutex
            if(y == 270)
            {
                if(x == 320){
                    mut5.lock();
                }

                if(x == 180){
                    mut1.lock();
                }

                if(x < 340)
                    x += 10;
            }

            if(y < 390)
            {
                if(x == 340 && y == 290){
                    mut1.unlock();
                }
                if(x == 340){
                    y += 10;
                }
            }

            if(y == 390)
            {
                if(x == 320){
                    mut5.unlock();
                }

                if(x > 70){
                    x -= 10;
                }
            }

            if(x == 70 && y > 270){
                y -= 10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4: //Trem 4 código sem mutex
            /*if (y == 270 && x <620)
                x+=10;
            else if (x == 620 && y < 390)
                y+=10;
            else if (x > 340 && y == 390)
                x-=10;
            else
                y-=10;*/
                //Trem 4 código com mutex
            if(y == 270)
            {
                if(x == 500)
                    mut2.unlock();

                if(x == 450)
                    mut3.lock();

                if(x == 360)
                    mut5.unlock();

                if(x == 600){
                    mut6.lock();
                }

                if(x < 620)
                    x += 10;
            }

            if(y < 390)
            {
                if(x == 620 && y == 290)
                    mut3.unlock();

                if(x == 620)
                    y += 10;
            }

            if(y == 390)
            {
                if(x == 360)
                {
                    mut2.lock();
                    mut5.lock();
                }

                if(x == 590)
                    mut6.unlock();

                if(x > 340)
                    x -= 10;
            }

            if(x == 340 && y > 270)
            {
                y -= 10;
            }

            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5: //Trem 5 código sem mutex
            /*if (y == 270 && x <890)
                x+=10;
            else if (x == 890 && y < 390)
                y+=10;
            else if (x > 620 && y == 390)
                x-=10;
            else
                y-=10;*/
                //Trem 5 código com mutex
            if(y == 270)
            {
                if(x == 640)
                    mut6.unlock();

                if(x < 890)
                    x += 10;

                if(x == 780)
                    mut4.unlock();
            }

            if(y < 390)
            {
                if(x == 890)
                    y += 10;
            }

            if(y == 390)
            {
                if(x == 640)
                {
                    mut4.lock();
                    mut6.lock();
                }

                if(x > 620)
                    x -= 10;
            }

            if(x == 620 && y > 270)
                y -= 10;

            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }


}




