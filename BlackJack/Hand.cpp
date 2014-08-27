//
//  Hand.cpp
//  BlackJack
//
//  Created by Ariana Cisneros and Maria Montserrat Lozano on 23/08/14.
//  Copyright (c) 2014 ITESM. All rights reserved.
//

#include "Hand.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


Hand:: Hand()
{
    cont = 0;
    
    for(int i = 0; i < 10; i++)
    {
        hand[i].setSuit('z');
        hand[i].setValue('z');
    }
}

char Hand::getSuit(int k)
{
	//Retorna el suit de la carta
    return hand[k].getSuit();
    
}

char Hand::getValue(int k)
{
	//retorna el valor de la carta k de
    return hand[k].getValue();
    
}

/*char * Hand::str()
 {
 
 char x[] = "";
 return x;
 
 
 }*/

void Hand::str()
{
    for (int i = 0; i < cont; i++) {
        cout<< hand[i].getSuit() << " " << hand[i].getValue()<< "\n" ;
        // cout<<"Dealed Card Player: "<<carta1.getSuit()<<" "<<carta1.getValue()<<"\n \n";
    }
    
}

//añade una carta a la mano de cartas
void Hand::addCard(Card card)
{
    hand[cont] = card;
    cont++;
    
}


//atoi
int atoi (char c )
{
    int entero= 0;
    if(c>='0'&& c<='9')
    {
        entero = c - '0';
    }
    return entero;
}


//retorna el valor total de puntos de la mano
int Hand::getValue()
{
    int as = 0;
    int total = 0;
    int valor = 0;
    
    for (int i = 0; i < cont; i++) {
        
        valor=  hand[i].getValue() ;
        // cout << valor << "\n" ;
        
        switch (valor) {
            case 'A' | 65:
                as = valorAs(total);
                total=total+as;
                break;
            case 'T' | 84:
                total+=10;
                break;
            case 'Q' | 81:
                total+=10;
                break;
            case 'J' | 74:
                total+=10;
                break;
            case 'K':
                total+=10;
                break;
                
            default:
                total += atoi(valor);
                break;
                
        }
    }
    return total;
    
}

//Verificar que valor se debe usar para el As
int Hand::valorAs(int valueTotal)
{
    int valor = ((valueTotal + 11) > 21)? 1: 11;
    return valor;
}

void Hand::draw(int x, int y)
{
    //dibuja todas las cartas desde la posición x,y, dependiendo de la cantidad de cartas
    glColor3ub(0, 0, 255);
    
}