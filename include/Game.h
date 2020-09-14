#ifndef GAME_H
#define GAME_H

#include "Card.h"
#include "Deck.h"
#include "Player.h"

#include <iostream>
#include <conio.h>

using namespace std;


class Game
{
    public:

        static Game& get_singleton();

        void start_game(Player& P, Player& CPU, Deck& D);

        void deal_cards(Player& P, Player& CPU, Deck& D);

        void display_cards(Player& P);

        void select_cards(Player& P);

        void change_cards(Player& P, Deck& D);

        string poker_name(int result);

    protected:

    private:
        Game();
        Game(const Game&);
        virtual ~Game();
};

#endif // GAME_H
