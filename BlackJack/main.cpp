#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Deck.h"
#include "Hand.h"

using namespace std;

GLsizei winWidth = 800, winHeight =600; // Tamaño inicial de la ventana
GLint xRaster = -770, yRaster= 200;
string texto = "D-Deal H-Hit S-Stand Esc-Salir";
string textoBlackjack ="BlackJack =>";
char textoScore[25];
char textoScoreDealer[30];
char textoPointsDealer[50];
char textoPointsPlayer[50];
string textoDealer = "Dealer";
string textoPlayer = "Player";
string nombreMontse = "Montserrat Lozano A01088686";
string nombreAriana = "Ariana Cisneros A01138381";
string hitStand = "Hit or Stand?";
string dealString = "New Deal?";
string win = "You WIN!!";
string lose = "You LOSE :(";
int deltaRect = 30; // delta del ancho de cada rectangulo
int deltaHeight = 200;
GLdouble scaleX = .3;
GLdouble scaleY = .3;
int turno = 0;
bool ayuda = false;
Deck *deck = new Deck(); //deck global
Hand *player; //mano del jugador global
Hand *dealer; //mano del dealer global
int puntajeDealer;
int puntajePlayer;
bool finJuego;
void jugar(char opcion);
void initJuego();
bool dealPlay;
bool hitPlay;
bool youWin;
bool newDealSign;

void init()
{
    deck = new Deck();
    player = new Hand();
    dealer = new Hand();
    newDealSign = true;
    puntajeDealer = 0;
    puntajePlayer = 0;
    finJuego = true;
    dealPlay = false;
    hitPlay= false;
    glClearColor(1.0,.6,0,0); //background del display naranja
}
void renderBitmapString(float x,float y,float z,char *string)
{
    int i;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y,z);
    glScalef(scaleX,scaleY,1.0);
    //glScaled(0.005, 0.005, 0.0002);
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *string);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    //TEXTO BLACKJACK
    glColor3f(0, 0, 0);
    for(int i= 0; textoBlackjack[i]!='\0'; i++)
    {
        renderBitmapString(-(winWidth/5-(deltaRect*i)), winHeight-100, 1, &textoBlackjack[i]);
    }
    
    //TEXTO SCORE
    sprintf(textoScore, "Score= %d", puntajePlayer);
    glColor3f(0, 0, 0);
    for(int i= 0; textoScore[i]!='\0'; i++)
    {
        renderBitmapString(-(winWidth-(deltaRect*i)), winHeight-200, 1, &textoScore[i]);
    }

    //TEXTO SCOREDealer
    sprintf(textoScoreDealer, "ScoreDealer= %d", puntajeDealer);
    glColor3f(0, 0, 0);
    for(int i= 0; textoScoreDealer[i]!='\0'; i++)
    {
        renderBitmapString((winWidth-(winWidth/1.4)+(deltaRect*i)), winHeight-200, 1, &textoScoreDealer[i]);
    }
    //TEXTO DEALER
    glColor3f(0, 0, 0);
    for(int i= 0; textoDealer[i]!='\0'; i++)
    {
        renderBitmapString(-(winWidth-(deltaRect*i)), 250, 1, &textoDealer[i]);
    }
    
    if (dealPlay) {
        //CARTAS DEALER
        dealer -> draw(-600, 150, true, finJuego);
        //CARTAS PLAYER
        player -> draw(-600, -150, false, finJuego);
    }
    
    
    //TEXTO PLAYER
    glColor3f(0, 0, 0);
    for(int i= 0; textoPlayer[i]!='\0'; i++)
    {
        renderBitmapString(-(winWidth-(deltaRect*i)), -20, 1, &textoPlayer[i]);
    }
    
    //TEXTO TECLADO
    glColor3f(0, 0, 0);
    for(int i= 0; texto[i]!='\0'; i++)
    {
        renderBitmapString(-(winWidth-(deltaRect*i)), -winHeight/1.33, 1, &texto[i]);
    }
    
    //NOMBRES
    glColor3f(100, 24, 100);
    for(int i= 0; nombreMontse[i]!='\0'; i++)
    {
        renderBitmapString(-(winWidth-(deltaRect*i)), -winHeight/1.15, 1, &nombreMontse[i]);
    }
    
    glColor3f(100, 24, 100);
    for(int i= 0; nombreAriana[i]!='\0'; i++)
    {
        renderBitmapString(-(winWidth-(deltaRect*i)), -winHeight/1.08, 1, &nombreAriana[i]);
    }
    
    if(finJuego)
    {
        
        glColor3f(100, 24, 100);
        if(youWin){
            for(int i= 0; win[i]!='\0'; i++)
            {
                renderBitmapString(200+(deltaRect*i), winHeight-100, 1, &win[i]);
            }
        }else if(newDealSign)
        {
            for(int i= 0; dealString[i]!='\0'; i++)
            {
                renderBitmapString(200+(deltaRect*i), winHeight-100, 1, &dealString[i]);
            }
        }else
        {
            for(int i= 0; lose[i]!='\0'; i++)
            {
                renderBitmapString(200+(deltaRect*i), winHeight-100, 1, &lose[i]);
            }
        }
        
        //TEXTO POINTSDEALER
        sprintf(textoPointsDealer, "PointsDealer= %d", dealer->getValue());
        glColor3f(1, 1, 1);
        for(int i= 0; textoPointsDealer[i]!='\0'; i++)
        {
            renderBitmapString(((deltaRect*i)+winWidth/3), 250, 1, &textoPointsDealer[i]);
        }
        
        
        //TEXTO POINTSPLAYER
        sprintf(textoPointsPlayer, "Points Player= %d", player->getValue());
        glColor3f(1, 1, 1);
        for(int i= 0; textoPointsPlayer[i]!='\0'; i++)
        {
            renderBitmapString(((deltaRect*i)+winWidth/3), -20, 1, &textoPointsPlayer[i]);
        }
    }else{
        glColor3f(100, 24, 100);
        for(int i= 0; hitStand[i]!='\0'; i++)
        {
            renderBitmapString(200+(deltaRect*i), winHeight-100, 1, &hitStand[i]);
        }
    }
    
    glutSwapBuffers();
}
void ChangeSize(GLsizei w, GLsizei h){
    GLfloat aspectRatio;
    
    if(h==0)  h=1; //si la altura que llego es 0. Forzamos a que la altura sea minimo 0
    
    glViewport (0,0,w,h);
    //cambiar deltas con proporcion al nuevo tamaño de pantalla
    deltaRect = (30*w)/800;
    deltaHeight = (200*h)/600;
    xRaster = (-770*w)/800;
    yRaster = (200*h)/600;
    scaleX = (.3*w)/800;
    scaleY = (.3*h)/600;
    winWidth = w;
    winHeight = h;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //limpiar matriz de proyeccion
    gluOrtho2D(-winWidth,winWidth, -winHeight, winHeight);
    glMatrixMode(GL_MODELVIEW);//dejar activa son todas las traslaciones, escalaciones
    glLoadIdentity();//que no tenga ninguna transformación
    
}
void initJuego()
{
    deck = new Deck();
    player = new Hand();
    dealer = new Hand();
    finJuego = false;
    dealPlay = true;
    youWin = false;
    newDealSign = false;
    glutPostRedisplay();
    
}
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
void fin()
{
    cout<<"***************** FIN DE JUEGO!! ****************\n";
}
void hit()
{
    hitPlay =true;
    if (player->getValue() <= 21) {
        Card newcarta = deck->dealCard();
        player->addCard(newcarta);
        glutPostRedisplay();
    }
    
    cout<<"Mano del player: "<<"\n";
    player->str();
    int manoPlayer = player->getValue();
    cout<<"Puntos en mano del player: "<< manoPlayer<<"\n";
    
    cout<<"Mano del dealer: "<<"\n";
    dealer->str();
    int manoDealer = dealer->getValue();
    cout<<"Puntos en mano del dealer: "<< manoDealer<<"\n";
    
    if (player->getValue() > 21) {
        glutPostRedisplay();
        cout<<"PERDISTE  " << "\n";
        puntajeDealer += 1;
        finJuego = true;
        fin();
    }
    
    glutPostRedisplay();
    
}
void stand()
{
    
    //indicar que jugador ya perdio
    if(player->getValue() > 21)
    {
        glutPostRedisplay();
        cout<<"Jugador ya perdio!!! \n";
        puntajeDealer += 1;
        finJuego = true;
        fin();
        glutPostRedisplay();
        return;
    }
    
    //Ejecutar repetidamente dealer haasta que mano tenga valor de 17 o mas
    while(dealer->getValue() < 17 && dealer->getValue() < player->getValue())
    {
        Card carta = deck->dealCard();
        dealer->addCard(carta);
        glutPostRedisplay();
        cout<<"Puntos dealer: "<< dealer->getValue()<<"\n";
    }
    
    if (dealer->getValue() > 21)
    {
        puntajePlayer += 1;
        glutPostRedisplay();
        cout<<"Dealer se paso! Jugador Gana!!"<<"\n";
        youWin = true;
        
    }else if(player->getValue() <= dealer->getValue())
    {
        puntajeDealer += 1;
        glutPostRedisplay();
        cout<<"Dealer gana! Jugador Pierde \n";
        cout<<"Mano de player: "<<player->getValue()<<" Mano dealer:"<<dealer->getValue()<<"\n";
    }else
    {
        puntajePlayer += 1;
        glutPostRedisplay();
        cout<<"Jugador Gana!!! \n";
        cout<<"Mano de player: "<<player->getValue()<<" Mano dealer:"<<dealer->getValue()<<"\n";
        youWin = true;
    }
    finJuego = true;
    fin();
}
void keyboardFunc(unsigned char key, int mouseX, int mouseY)
{
    switch (key) {
            
        case 'q':
        case 'Q':
        case 27 :
            finJuego = true;
            exit(0); break; //Quitar el juego
            
        case 'd':
        case 'D':
            if(!finJuego)
            {
                finJuego = true;
                puntajeDealer++;
            }else
            {
                cout<< "Nuevo Juego \n";
                initJuego();
                deal();
            }
            glutPostRedisplay();
            break;
        case 'h':
        case 'H': //Hit (Dar una nueva carta a la mano del player)
            if(!finJuego)
                hit();
            else{
                newDealSign = true;
                glutPostRedisplay();
            }
            break;
            
        case 's':
        case 'S': //Stand (Dar cartas al dealer)
            if(!finJuego)
                stand();
            break;
        default:
            break;
    }
    
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(winWidth,winHeight);
    glutInitWindowPosition(200, 400); // 100, 100
    glutCreateWindow("BlackJack");
    init();
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardFunc);
    glutMainLoop();
    return 0;
}