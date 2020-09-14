#include "Card.h"

Card::Card()
{
}
Card::Card(int xnumber, unsigned char xcolour): number(xnumber), colour(xcolour)
{
    if(number==9) cnumber='9';
    if(number==10) cnumber='0';
    if(number==11) cnumber='J';
    if(number==12) cnumber='D';
    if(number==13) cnumber='K';
    if(number==14) cnumber='A';
}

Card::~Card()
{
}
