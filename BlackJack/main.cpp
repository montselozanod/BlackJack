//
//  main.cpp
//  BlackJack
//
//  Created by Maria Montserrat Lozano on 19/08/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>
#include "Deck.h"

using namespace std;



int main(int argc, const char * argv[])
{
    Deck *deck = new Deck();
    deck->shuffle();
    
    for (int i = 0; i < 52; i++){
        cout<<i<<".) "<<deck->getSuit(i)<<" "<<deck->getValue(i)<<"\n";
    }
    
    Card carta1 = deck->dealCard();
    Card carta2 = deck->dealCard();
    
    cout<<"Dealed Card: "<<carta1.getSuit()<<" "<<carta1.getValue()<<"\n \n";
    
      cout<<"Dealed Card: "<<carta2.getSuit()<<" "<<carta2.getValue()<<"\n \n";
    
    for (int i = 0; i < 52; i++){
        cout<<i<<".) "<<deck->getSuit(i)<<" "<<deck->getValue(i)<<"\n";
    }
    
    
}


