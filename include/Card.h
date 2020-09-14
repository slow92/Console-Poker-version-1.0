#ifndef CARD_H
#define CARD_H


class Card
{
    public:
        Card();
        Card(int xnumber, unsigned char xcolour);
        virtual ~Card();

        int number;
        unsigned char colour;
        unsigned char cnumber;

        bool operator == (const Card& another) {return (this->number==another.number)&&(this->colour==another.colour);}

    protected:

    private:

};

#endif // CARD_H
