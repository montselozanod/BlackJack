//
//  main.cpp
//  BlackJack
//
//  Created by Ariana Cisneros and Maria Montserrat Lozano on 21/08/14.
//  Copyright (c) 2014 ITESM. All rights reserved.
//
#include <iostream>
#include "Deck.h"
#include "Hand.h"

Deck *deck = new Deck(); //deck global
Hand *player; //mano del jugador global
Hand *dealer; //mano del dealer global
int puntajeDealer;
int puntajePlayer;
bool finJuego;

void jugar(char opcion);
void initJuego();

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
    
    //Repartir 2 cartas a la mano del player y 2 al dealer
    player->addCard(carta1); //carta1 del player
    player->addCard(carta2); //carta2 del player
    dealer->addCard(carta3); //carta3 del dealer
    dealer->addCard(carta4); //carta4 del dealer
    
    //muestra mano del player y dealer
    cout<<"Mano del player: "<<"\n";
    player->str();
    int manoPlayer = player->getValue();
    cout<<"Puntos en mano del player: "<< manoPlayer<<"\n";
    
    cout<<"Mano del dealer: "<<"\n";
    dealer->str();
    int manoDealer = dealer->getValue();
    cout<<"Puntos en mano del dealer: "<< manoDealer<<"\n";
    
    //cout<<"Deck con las cartas eliminadas: "<<"\n";
    //muestra deck con las cartas eliminadas
    //for (int i = 0; i < 52; i++){
      //  cout<<i<<".) "<<deck->getSuit(i)<<" "<<deck->getValue(i)<<"\n";
    //}
    
}

void hit()
{
    if (player->getValue() <= 21) {
        Card newcarta = deck->dealCard();
        player->addCard(newcarta);
    }
    
    if (player->getValue() > 21) {
        cout<<"PERDISTE  " << "\n";
        puntajeDealer += 1;
        finJuego = true;
    }
    
    cout<<"Mano del player: "<<"\n";
    player->str();
    int manoPlayer = player->getValue();
    cout<<"Puntos en mano del player: "<< manoPlayer<<"\n";
    
    cout<<"Mano del dealer: "<<"\n";
    dealer->str();
    int manoDealer = dealer->getValue();
    cout<<"Puntos en mano del dealer: "<< manoDealer<<"\n";
    
    //muestra mano del player y dealer
    //player.str();
    //dealer.str();
}

void stand()
{
    
    //indicar que jugador ya perdio
    if(player->getValue() > 21)
    {
        cout<<"Jugador ya perdio!!! \n";
        puntajeDealer += 1;
        finJuego = true;
        return;
    }
    
    //Ejecutar repetidamente dealer haasta que mano tenga valor de 17 o mas
    while(dealer->getValue() < 17 && dealer->getValue() < player->getValue())
    {
        Card carta = deck->dealCard();
        dealer->addCard(carta);
        cout<<"Puntos dealer: "<< dealer->getValue()<<"\n";
    }
    
    if (dealer->getValue() > 21)
    {
        puntajePlayer += 1;
        cout<<"Dealer se paso! Jugador Gana!!"<<"\n";
        
    }else if(player->getValue() <= dealer->getValue())
    {
        puntajeDealer += 1;
        cout<<"Dealer gana! Jugador Pierde \n";
        cout<<"Mano de player: "<<player->getValue()<<" Mano dealer:"<<dealer->getValue()<<"\n";
    }else
    {
        puntajePlayer += 1;
        cout<<"Jugador Gana!!! \n";
        cout<<"Mano de player: "<<player->getValue()<<" Mano dealer:"<<dealer->getValue()<<"\n";
    }
    finJuego = true;
}

void jugar(char opcion)
{
    switch (opcion) {
        case 'Q'  : finJuego = true; exit(0); break; //Quitar el juego
        case 27   : finJuego = true; exit(0); break; //Quitar el juego
        case 'D': cout<< "Nuevo Juego \n";
            initJuego();
            deal();
            break;
        case 'H': //Hit (Dar una nueva carta a la mano del player)
            if(!finJuego)
                hit();
            break;
        case 'S': //Stand (Dar cartas al dealer)
            if(!finJuego)
                stand();
            break;
        default:
            break;
    }
    
}

void initJuego()
{
    deck = new Deck();
    player = new Hand();
    dealer = new Hand();
    finJuego = false;
    
}

int main(int argc, const char * argv[])
{
    puntajeDealer = 0;
    puntajePlayer = 0;
    finJuego = true;
    char opcion = 'D'; //por default para que entre al ciclo
    cout << "Bienvenido jugador:) " << endl;
    //initJuego();
    while (opcion != 'Q' ) {
        
        cout << "Selecciona una opción D-Deal H-Hit S-Stand Q-Quit" << endl;
        cin >> opcion;
        jugar(opcion);
    }
    
    return 0;
}