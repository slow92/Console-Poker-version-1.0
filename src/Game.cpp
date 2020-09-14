#include "Game.h"

Game::Game()
{
    //ctor
}

Game::Game(const Game&)
{

}

Game::~Game()
{
    //dtor
}

Game& Game::get_singleton()
{
    static Game singleGame;
    return singleGame;
}

void Game::start_game(Player& P, Player& CPU, Deck& D)
{

    int P_result, CPU_result;
    deal_cards(P,CPU,D);
    system("cls");
    cout<<"Player score: "<<P.score<<endl<<"CPU score: "<<CPU.score<<endl;
    display_cards(P);
    cout<<"Players cards"<<endl;
    P_result=P.calculate_figure();
    cout<<poker_name(P_result)<<endl;
    select_cards(P);
    change_cards(P,D);
    system("cls");
    cout<<"Player score: "<<P.score<<endl<<"CPU score: "<<CPU.score<<endl;
    display_cards(CPU);
    cout<<"CPU cards"<<endl;
    P_result=P.calculate_figure();
    CPU_result=CPU.calculate_figure();
    cout<<poker_name(CPU_result)<<endl;
    display_cards(P);
    cout<<"Players cards"<<endl;
    cout<<poker_name(P_result)<<endl;

    if(P_result!=CPU_result)
    {
        if(P_result>CPU_result)
        {
            P.score++;
            cout<<"You Won!"<<endl;
        }
        else
        {
            CPU.score++;
            cout<<"You Lost!"<<endl;
        }
    }
    else
    {
        cout<<"Dead Heat"<<endl;
    }
    cout<<"Player score: "<<P.score<<endl<<"CPU score: "<<CPU.score<<endl;
    P.cards_5.clear();
    CPU.cards_5.clear();
    D.new_deck();
}

void Game::deal_cards(Player& P, Player& CPU, Deck& D)
{
    for(int i=0; i<5;i++)
    {
        P.cards_5.push_back(D.get_card());
        CPU.cards_5.push_back(D.get_card());
    }
}

void Game::display_cards(Player& P)
{
    for(int i=1;i<=25;i++)
    {
        if((i==1)||(i==5)||(i==6)||(i==10)||(i==11)||(i==15)||(i==16)||(i==20)||(i==21)||(i==25)) cout<<'+';
        else cout<<'-';
    }
    cout<<endl;
    for(int i=1;i<=25;i++)
    {
        if((i==1)||(i==5)||(i==6)||(i==10)||(i==11)||(i==15)||(i==16)||(i==20)||(i==21)||(i==25)) cout<<'|';
        else if(i==2) cout<<P.cards_5[0].cnumber;
        else if(i==7) cout<<P.cards_5[1].cnumber;
        else if(i==12) cout<<P.cards_5[2].cnumber;
        else if(i==17) cout<<P.cards_5[3].cnumber;
        else if(i==22) cout<<P.cards_5[4].cnumber;
        else cout<<' ';
    }
    cout<<endl;
    for(int i=1;i<=25;i++)
    {
        if((i==1)||(i==5)||(i==6)||(i==10)||(i==11)||(i==15)||(i==16)||(i==20)||(i==21)||(i==25)) cout<<'|';
        else if(i==3) cout<<P.cards_5[0].colour;
        else if(i==8) cout<<P.cards_5[1].colour;
        else if(i==13) cout<<P.cards_5[2].colour;
        else if(i==18) cout<<P.cards_5[3].colour;
        else if(i==23) cout<<P.cards_5[4].colour;
        else cout<<' ';
    }
    cout<<endl;
    for(int i=1;i<=25;i++)
    {
        if((i==1)||(i==5)||(i==6)||(i==10)||(i==11)||(i==15)||(i==16)||(i==20)||(i==21)||(i==25)) cout<<'|';
        else if(i==4) cout<<P.cards_5[0].cnumber;
        else if(i==9) cout<<P.cards_5[1].cnumber;
        else if(i==14) cout<<P.cards_5[2].cnumber;
        else if(i==19) cout<<P.cards_5[3].cnumber;
        else if(i==24) cout<<P.cards_5[4].cnumber;
        else cout<<" ";
    }
    cout<<endl;
    for(int i=1;i<=25;i++)
    {
        if((i==1)||(i==5)||(i==6)||(i==10)||(i==11)||(i==15)||(i==16)||(i==20)||(i==21)||(i==25)) cout<<'+';
        else cout<<'-';
    }
    cout<<endl;
}

void Game::select_cards(Player& P)
{
    cout<<"Select card from 1 to 5 with Enter to change or press ESC to go ahead"<<endl;
    unsigned char select;
    vector<unsigned char> selected_cards;
    selected_cards.clear();
    do
    {
        if(!selected_cards.empty())
        {
            for(int i=0;i<5;i++) cout<<selected_cards[i]<<" ";
            cout<<endl;
        }


        select=getch();
        if((select>='1')&&(select<='5'))
        {
            selected_cards.push_back(select);
            cout<<endl;
        }
    }while(select!=27);

    for(unsigned int i=0;i<selected_cards.size();i++)
    {
        if(selected_cards[i]=='1') P.old_cards.push_back(P.cards_5[0]);
        if(selected_cards[i]=='2') P.old_cards.push_back(P.cards_5[1]);
        if(selected_cards[i]=='3') P.old_cards.push_back(P.cards_5[2]);
        if(selected_cards[i]=='4') P.old_cards.push_back(P.cards_5[3]);
        if(selected_cards[i]=='5') P.old_cards.push_back(P.cards_5[4]);
    }
}

void Game::change_cards(Player& P, Deck& D)
{
    for(unsigned int i=0;i<P.old_cards.size();i++)
    {
        auto it=find(P.cards_5.begin(),P.cards_5.end(),P.old_cards[i]);
        P.cards_5.erase(it);
    }
    for(;P.cards_5.size()!=5;)
    {
        P.cards_5.push_back(D.get_card());
    }
    P.old_cards.clear();
}

string Game::poker_name(int result)
{
    if(result==8) return "Poker!";//poker
    if(result==7) return "Carriage!";//carriage;
    if(result==6) return "Full!";//full
    if(result==5) return "Colour";//colour;
    if(result==4) return "Triple";//triple
    if(result==3) return "Straight";// straight
    if(result==2) return "Two pairs";//2 pair
    if(result==1) return "One pair";//1 pair

    return "no figures";
}
