#ifndef BLACK_JACK_GAME_H
#define BLACK_JACK_GAME_H

#include <iostream>
#include <vector>


enum card_suit
{
    spades, clubs, tambourines, hearts
};

enum card_dignity{
    ace1 = 1 ,
    two = 2 ,
    three = 3 ,
    four = 4 ,
    five = 5 ,
    six = 6 ,
    seven = 7 ,
    eight = 8 ,
    nine = 9 ,
    ten = 10,
    king = 10,
    queen = 10,
    jack =10
    ace11 = 11
};


class Card
{
private:
    card_suit CardSuti;
    card_dignity CardDignity;
    std::vector<std::pair<card_suit, card_dignity>> card_deck;//по замыслу, тут будет перемешанная колода
    const static uint16_t number_card = 52;
    //перемешиваем карты
    static void fill_card_deck()
    {

    }
};

class Player
{

};

class HumanPlayer : Player
{

};

class VirtualPlayer: Player
{

};
class Dealer: HumanPlayer
{

};

class SinglePlayer : HumanPlayer
{

};

#endif // BLACK_JACK_GAME_H
