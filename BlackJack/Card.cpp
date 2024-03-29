// Matriculas:
// Montserrat Lozano Dieck A01088686
// Ariana Cisneros A01138381
//  Card.cpp
//  BlackJack
//
//  Created by Ariana Cisneros and Maria Montserrat Lozano on 19/08/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

Card:: Card(char ss, char vv)
{
    s = ss;
    v = vv;
}

// metodos modificadores
void Card::setSuit(char ss)
{
    s=ss;
}
void Card::setValue(char vv)
{
    v=vv;
}


char Card::getSuit()
{
    return s;
}

char Card::getValue()
{
    return v;
}




void Card::muestra()
{
    cout << s << ":" << v << endl;
}


void Card::dibujaPoligono(int xMin, int xMax, int yMin, int yMax)
{
    glBegin(GL_POLYGON);
    glVertex2d( xMin,yMin);
    glVertex2d( xMax,yMin );
    glVertex2d( xMax,yMax);
    glVertex2d( xMin,yMax);
    glEnd();
    
}
void Card::draw(int x, int y)
{
    glColor3ub(0, 0, 255);
    dibujaPoligono(x, x+50, y, y+100);
    
}



