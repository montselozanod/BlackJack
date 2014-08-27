//
//  Deck.cpp
//  BlackJack
//
//  Created by Maria Montserrat Lozano on 19/08/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include <string.h>
#include "Deck.h"

Deck::Deck()
{
    cont = 52;
    
    _deck.push_back(Card('C','A'));
    _deck.push_back(Card('C','2'));
    _deck.push_back(Card('C','3'));
    _deck.push_back(Card('C','4'));
    _deck.push_back(Card('C','5'));
    _deck.push_back(Card('C','6'));
    _deck.push_back(Card('C','7'));
    _deck.push_back(Card('C','8'));
    _deck.push_back(Card('C','9'));
    _deck.push_back(Card('C','T'));
    _deck.push_back(Card('C','J'));
    _deck.push_back(Card('C','Q'));
    _deck.push_back(Card('C','K'));
    
    _deck.push_back(Card('S','A'));
    _deck.push_back(Card('S','2'));
    _deck.push_back(Card('S','3'));
    _deck.push_back(Card('S','4'));
    _deck.push_back(Card('S','5'));
    _deck.push_back(Card('S','6'));
    _deck.push_back(Card('S','7'));
    _deck.push_back(Card('S','8'));
    _deck.push_back(Card('S','9'));
    _deck.push_back(Card('S','T'));
    _deck.push_back(Card('S','J'));
    _deck.push_back(Card('S','Q'));
    _deck.push_back(Card('S','K'));
    
    _deck.push_back(Card('H','A'));
    _deck.push_back(Card('H','2'));
    _deck.push_back(Card('H','3'));
    _deck.push_back(Card('H','4'));
    _deck.push_back(Card('H','5'));
    _deck.push_back(Card('H','6'));
    _deck.push_back(Card('H','7'));
    _deck.push_back(Card('H','8'));
    _deck.push_back(Card('H','9'));
    _deck.push_back(Card('H','T'));
    _deck.push_back(Card('H','J'));
    _deck.push_back(Card('H','Q'));
    _deck.push_back(Card('H','K'));
    
    _deck.push_back(Card('D','A'));
    _deck.push_back(Card('D','2'));
    _deck.push_back(Card('D','3'));
    _deck.push_back(Card('D','4'));
    _deck.push_back(Card('D','5'));
    _deck.push_back(Card('D','6'));
    _deck.push_back(Card('D','7'));
    _deck.push_back(Card('D','8'));
    _deck.push_back(Card('D','9'));
    _deck.push_back(Card('D','T'));
    _deck.push_back(Card('D','J'));
    _deck.push_back(Card('D','Q'));
    _deck.push_back(Card('D','K'));

}

char Deck::getSuit(int k)
{
    return _deck[k].getSuit();
}

char Deck::getValue(int k)
{
    return _deck[k].getValue();
}

void Deck::shuffle()
{
    srand (time(NULL) );
    
    for(int i = 0; i < 52; i++)
    {
        int j = rand()% 52;
        Card tmp = _deck[i];
        _deck[i] = _deck[j];
        _deck[j] = tmp;
    }

}

Card Deck::dealCard()
{
    Card dealed = _deck.front();
    _deck.erase(_deck.begin());
    cont--;
    return dealed;
}

char * Deck::str()
{
    if(cont > 0)
    {
        char *str = (char *)malloc(sizeof(char)*cont);
        *str = '\0';
        
        for(int i = 0; i < cont; i++)
        {
            char *aux;
            *aux= _deck[i].getSuit();
            strcat(str, aux);
            *aux = _deck[i].getValue();
            strcat(str, aux);
            *aux = ' ';
            strcat(str, aux);
        }
        
        return str;
    }
    else
        return NULL;
}




