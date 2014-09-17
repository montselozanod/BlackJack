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
char * Hand::strp()
{
    if(cont > 0)
    {
        char *str = (char *)malloc(sizeof(char)*cont);
        char *aux = (char *)malloc(sizeof(char)*cont);
        *str = '\0';
        
        for(int i = 0; i < cont; i++)
        {
            *aux= hand[i].getSuit();
            strcat(str, aux);
            *aux = hand[i].getValue();
            strcat(str, aux);
            *aux = ' ';
            strcat(str, aux);
        }
        
        return str;
    }
    else
        return NULL;
}
void Hand::str()
{
    for (int i = 0; i < cont; i++) {
        cout<< hand[i].getSuit() << " " << hand[i].getValue()<< "\n" ;
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
    cout<<cont;
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

void renderBitmapString2(float x,float y,float z,char *string)
{
    int i;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y,z);
    glScalef(.3,.3,1.0);
    //glScaled(0.005, 0.005, 0.0002);
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *string);
    glPopMatrix();
}

void Hand::draw(int x, int y, bool dealer, bool finRonda)
{
    //dibuja todas las cartas desde la posición x,y, dependiendo de la cantidad de cartas
    
    if(dealer){
        for (int i = 0; i < cont; i++) {
            glColor3f(0, 0, 1);
            glRectd( x+(150*i),y,x+(150*i)+100,y+150); //ancho 100 altura 150
            
            if(cont == 2 && i == 1 && !finRonda)
                break; //no mostrar si es dealer la segunda carta
            else
            {
                //TEXTO CARTA
                glColor3f(1, 1, 1);
                char suit = hand[i].getSuit();
                char value = hand[i].getValue();
                renderBitmapString2(x+(150*i)+5, y+10, 1, &suit);
                renderBitmapString2(x+(150*i)+35, y+10, 1, &value);
            }
        }
    }else{
        for (int i = 0; i < cont; i++) {
            glColor3f(0, 0, 1);
            glRectd( x+(150*i),y,x+(150*i)+100,y+150); //ancho 100 altura 150
            
            //TEXTO CARTA
            glColor3f(1, 1, 1);
            char suit = hand[i].getSuit();
            char value = hand[i].getValue();
            renderBitmapString2(x+(150*i)+5, y+10, 1, &suit);
            renderBitmapString2(x+(150*i)+35, y+10, 1, &value);
        }
    }
}