//
//  main.cpp
//  BlackJack
//
//  Created by Ariana Cisneros on 21/08/14.
//  Copyright (c) 2014 ITESM. All rights reserved.
//
#include <iostream>
#include "Deck.h"
#include "Hand.h"
Deck *deck = new Deck(); //deck global
Hand player; //mano del jugador global
Hand dealer; //mano del dealer global
void jugar(char opcion);

void deal()
{
    deck->shuffle(); //barajear baraja
    //mostrar deck barajeado
    cout<<"Deck barajeado: "<<"\n";
    for (int i = 0; i < 52; i++){
        cout<<i<<".) "<<deck->getSuit(i)<<" "<<deck->getValue(i)<<"\n";
    }
    
    //crear cartas para player y dealer
    Card carta1 = deck->dealCard();
    Card carta2 = deck->dealCard();
    Card carta3 = deck->dealCard();
    Card carta4 = deck->dealCard();
    
    
    /*cout<<"Dealed Card Player: "<<carta1.getSuit()<<" "<<carta1.getValue()<<"\n \n";
     cout<<"Dealed Card Player: "<<carta2.getSuit()<<" "<<carta2.getValue()<<"\n \n";
     cout<<"Dealed Card Dealer: "<<carta3.getSuit()<<" "<<carta3.getValue()<<"\n \n";
     cout<<"Dealed Card Dealer: "<<carta4.getSuit()<<" "<<carta4.getValue()<<"\n \n";*/
    
    //Repartir 2 cartas a la mano del player y 2 al dealer
    player.addCard(carta1); //carta1 del player
    player.addCard(carta2); //carta2 del player
    dealer.addCard(carta3); //carta3 del dealer
    dealer.addCard(carta4); //carta4 del dealer
    
    //muestra mano del player y dealer
    cout<<"Mano del player: "<<"\n";
    player.str();
    int manoPlayer = player.getValue();
    cout<<"Puntos en mano del player: "<< manoPlayer<<"\n";
    
    cout<<"Mano del dealer: "<<"\n";
    dealer.str();
    int manoDealer = dealer.getValue();
    cout<<"Puntos en mano del dealer: "<< manoDealer<<"\n";
    
    
    //cout<<"Deck con las cartas eliminadas: "<<"\n";
    //muestra deck con las cartas eliminadas
    //for (int i = 0; i < 52; i++){
      //  cout<<i<<".) "<<deck->getSuit(i)<<" "<<deck->getValue(i)<<"\n";
    //}
    
}

void hit()
{
    if (player.getValue() <= 21) {
        Card newcarta = deck->dealCard();
        player.addCard(newcarta);
    }
    
    if (player.getValue() > 21) {
        cout<<"PERDISTE  " << "\n";
    }
    
    cout<<"Mano del player: "<<"\n";
    player.str();
    int manoPlayer = player.getValue();
    cout<<"Puntos en mano del player: "<< manoPlayer<<"\n";
    
    cout<<"Mano del dealer: "<<"\n";
    dealer.str();
    int manoDealer = dealer.getValue();
    cout<<"Puntos en mano del dealer: "<< manoDealer<<"\n";
    
    //muestra mano del player y dealer
    //player.str();
    //dealer.str();
}

void stand()
{
    //indicar que jugador ya perdio
    if(player.getValue() > 21)
    {
        cout<<"Jugador ya perdio!!! \n";
        return;
    }
    
    //Ejecutar repetidamente dealer haasta que mano tenga valor de 17 o mas
    while(dealer.getValue() < 17 && dealer.getValue() < player.getValue())
    {
        Card carta = deck->dealCard();
        dealer.addCard(carta);
        cout<<"Puntos dealer: "<< dealer.getValue()<<"\n";
    }
    
    if (dealer.getValue() > 21)
    {
        cout<<"Dealer se paso! Jugador Gana!!"<<"\n";
    }else if(player.getValue() <= dealer.getValue())
    {
        cout<<"Dealer gana! Jugador Pierde \n";
        cout<<"Mano de player: "<<player.getValue()<<" Mano dealer:"<<dealer.getValue()<<"\n";
    }else
    {
        cout<<"Jugador Gana!!! \n";
        cout<<"Mano de player: "<<player.getValue()<<" Mano dealer:"<<dealer.getValue()<<"\n";
    }
    
}

void jugar(char opcion)
{
    switch (opcion) {
        case 'Q'  : break; //Quitar el juego
        case 27   : break; //Quitar el juego
        case 'D': //Deal (barajear y repartir 2 cartas a cada quien)
            deal();
            break;
        case 'H': //Hit (Dar una nueva carta a la mano del player)
            hit();
            break;
        case 'S': //Stand (Dar cartas al dealer)
            stand();
            break;
            
        default:
            break;
    }
    
}

int main(int argc, const char * argv[])
{
    int jugando = 0; // El player no esta jugando
    char opcion = 'D'; //por default para que entre al ciclo
    cout << "Bienvenido jugador:) " << endl;
    
    while (opcion != 'Q' ) {
        
        jugando = player.getValue(); // Si es 0 es que no esta jugando, si es != significa que sí esta jugando
        
        cout << "Selecciona una opción D-Deal H-Hit S-Stand Q-Quit" << endl;
        cin >> opcion;
        if (jugando == 0){   // el player no está jugando
            switch (opcion) {
                case 'H' ://H o S
                    cout << "Selecciona D-Deal ó Q-Quit" << endl;
                    break;
                case 'S' ://H o S
                    cout << "Selecciona D-Deal ó Q-Quit" << endl;
                    break;
                    
                default:
                    jugar(opcion);
            }
            
        } else{ //el player sí esta jugando
            switch (opcion) {
                case 'D' :// El jugador pierde el juego
                    cout << "Perdiste el juego  " << endl;
                    break;
                default:
                    jugar(opcion);
            }
            
        }
        
    }
    
    return 0;
}