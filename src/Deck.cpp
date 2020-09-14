#include "Deck.h"

Deck::Deck()
{
    srand(time(NULL));
    for(unsigned char i=3;i<7;i++)
    {
        for(int j=9;j<15;j++)
        {
            Card card(j,i);
            v_cards.push_back(card);
        }
    }
    shuffle_order();
}

Deck::~Deck()
{
    v_cards.clear();
}

void Deck::new_deck()
{
    v_cards.clear();
    for(unsigned char i=3;i<7;i++)
    {
        for(int j=9;j<15;j++)
        {
            Card card(j,i);
            v_cards.push_back(card);
        }
    }
    shuffle_order();
}

void Deck::shuffle_order()
{
    vector<Card> new_deck;
    int pos;

    do
    {
        pos=rand()%v_cards.size();
        new_deck.push_back(v_cards[pos]);
        auto it=v_cards.begin()+pos;
        v_cards.erase(it);
    }while(!v_cards.empty());
    new_deck.swap(v_cards);
}

Card Deck::get_card()
{
    Card C=v_cards.front();
    v_cards.erase(v_cards.begin());
    return C;
}

