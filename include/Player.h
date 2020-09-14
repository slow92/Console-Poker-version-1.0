#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Card.h"
#include "Deck.h"


using namespace std;


class Player
{
    public:
        Player();
        virtual ~Player();

        vector<Card> cards_5;
        vector<Card> old_cards;

        int figure;
        int score;

        int calculate_figure();


    protected:

    private:

};

#endif // PLAYER_H
