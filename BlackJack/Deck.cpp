//
//  Deck.cpp
//  BlackJack
//
//  Created by Maria Montserrat Lozano on 19/08/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "Deck.h"

Deck::Deck()
{

}

char Deck::getSuit(int k)
{
    return 'a';
}

char Deck::getValue(int k)
{

}

void Deck::shuffle()
{
    for(int i = 0; i < 52; i++)
    {
        int j = rand()% 52;
        Card tmp = d[i];
        d[i] = d[j];
        d[j] = tmp;
    }
}

Card Deck::dealCard()
{

}

char * Deck::str()
{

}

