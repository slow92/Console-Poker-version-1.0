#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <cstdlib>

#include "Card.h"

using namespace std;

class Deck
{
    public:
        Deck();
        virtual ~Deck();

        void shuffle_order();

        void new_deck();

        Card get_card();

    protected:

    private:
        vector<Card> v_cards;
};

#endif // DECK_H
