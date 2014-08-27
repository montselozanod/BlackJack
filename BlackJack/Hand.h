//
//  Hand.h
//  BlackJack
//
//  Created by Ariana Cisneros and Maria Montserrat Lozano on 19/08/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __BlackJack__Hand__
#define __BlackJack__Hand__


#include <iostream>
#include <vector>
#include "Card.h"

class Hand
{
    public:
        Hand();
    
        char getSuit(int k); //Retorna el suit de la carta
        char getValue(int k);//retorna el valor de la carta k de
        char * strp(); //retorna en todas las cartas de la mano
        void str();
        void addCard(Card card); //añade una carta a la mano de cartas
        int getValue();//retorna el valor total de puntos de la mano
        void draw(int x, int y);//dibuja todas las cartas desde la posición x,y, dependiendo de la cantidad de cartas
    
    private:
        Card hand[10]=
        {
            Card('z','z'), Card('z','z'),
            Card('z','z'),Card('z','z'),
            Card('z','z'),Card('z','z'),
            Card('z','z'),Card('z','z'),
            Card('z','z'), Card('z','z')
        };
        int valorAs(int value);
    
        int cont=0;  //cantidad de cartas de la mano
};


#endif /* defined(__BlackJack__Hand__) */
