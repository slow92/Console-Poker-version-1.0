#include <iostream>

#include "Game.h"

using namespace std;

int main()
{
    Deck D;
    Player P, CPU;
    Game& singleGame=Game::get_singleton();
    unsigned char user;
    do
    {
        system("cls");
        singleGame.start_game(P,CPU,D);
        cout<<"Press any key to play again or ESC to EXIT"<<endl;
        user=getch();
    }while(user!=27);

    return 0;
}
