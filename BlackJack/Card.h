// Matriculas:
// Montserrat Lozano Dieck A01088686
// Ariana Cisneros A01138381
//  Card.h
//  BlackJack
//
//  Created by Ariana Cisneros and Maria Montserrat Lozano on 19/08/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __BlackJack__Card__
#define __BlackJack__Card__

#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace  std;

class Card
{
public:
    // Constructor
    Card(char ss, char vv);
    
    // metodos modificadores
    void setSuit(char ss);
    void setValue(char vv);
    
    // metodos de acceso
    char getSuit();
    char getValue();
    
    
    // otros métodos
    void muestra();
    static void dibujaPoligono(int xMin, int xMax, int yMin, int yMax);
    void draw(int x, int y);
    
    
private:
    // Atributos
    char s, v;
};

#endif