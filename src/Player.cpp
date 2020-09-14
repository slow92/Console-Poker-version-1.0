#include "Player.h"

#include <iostream>

Player::Player()
{
    score=0;
    //ctor
}

Player::~Player()
{
    //dtor
}

//1 pair
//2 pair
//3 straight
//4 triple
//5 colour
//6 full
//7 carriage
//8 poker
int Player::calculate_figure()
{
    int times_number[6];
    int times_colour[4];
    int pair1=0, triple=0, carriage=0, colour=0, straight=0;
    for(int i=0;i<6;i++)
    {
        times_number[i]=static_cast<int>(count_if(cards_5.begin(),cards_5.end(),[i](Card& C){return C.number==(i+9);}));
    }
    for(int i=0;i<4;i++)
    {
        times_colour[i]=static_cast<int>(count_if(cards_5.begin(),cards_5.end(),[i](Card& C){return C.colour==(i+3);}));
    }
    pair1=static_cast<int>(count_if(times_number,times_number+6,[](int& i){return i==2;}));

    triple=static_cast<int>(count_if(times_number,times_number+6,[](int& i){return i==3;}));

    carriage=static_cast<int>(count_if(times_number,times_number+6,[](int& i){return i==4;}));

    colour=static_cast<int>(count_if(times_number,times_number+6,[](int& i){return i==5;}));

    if(!(pair1||triple||carriage))
    {
        int vmin=14,vmax=9;
        for(int i=0 ;i<=cards_5.size();i++)
        {
            if(cards_5[i].number>vmax) vmax=cards_5[i].number;
            if(cards_5[i].number<vmin) vmin=cards_5[i].number;
            //std::cout<<vmax<<" "<<vmin<<"\n";
            if((i==4)&&((vmax-vmin)==4))
            {
                straight=1;
                break;
            }

        }
    }

    if(straight && colour) return 8;//poker
    if(carriage) return 7;//carriage;
    if((pair1==1)&&triple) return 6;//full
    if(colour) return 5;//colour;
    if(triple) return 4;//triple
    if(straight) return 3;// straight
    if(pair1==2) return 2;//2 pair
    if(pair1==1) return 1;//1 pair

    return 0;
}
