#ifndef SFMLHANDLING_H
#define SFMLHANDLING_H
#include <SFML/Graphics.hpp>
#include "Arena.h"
#define SIZE 10
#define MAX_ROW 3
class SFMLHandling
{
public:
    SFMLHandling();
    ~SFMLHandling();

    sf::RenderWindow *window;
    sf::Clock cllogs;

    sf::Event event;
    sf::Clock cl;
    sf::Time tm;
    bool isPause=false;
    bool isPressed[3]= {false,false,false}; ///0-palenie ,1-kamienie,2-niepalace
    bool isSelected[4]= {false,false,false,false}; ///sprawdzamy wykonanie menu 0-styl,1 rozmiar 2-kamienie
    int iterator_=1;
    float time_as_miliseconds=1000;

    int wind_to_string=0;
    int wind=0;
    int pressedTimes=0;
    int simulationType=1;
    int sliderX=0;
    bool mouseClicked=false;

    void updateS();
    void handleEvents_();
    void run();
    void logs();
    void untouched_tree(int i,int j);///drzewo niepalace
    void burning_tree(int i,int j);///palace drzewo
    void rock(int i,int j); /// kamien
    void burning2_tree(int i, int j);
    void burnt_tree(int i, int j);
    void toolkit();
    void toolkitFrame(int x,int y);
    void print_speed(double s,unsigned x);///wypisanie predkosci
    void frame(float rectangle_x,float rectangle_y,int startingposition_x,int startingposition_y,sf::Color Color);///ramki
    void printArena();
    void nextState();
    static void setFire();
    void setStone();
    void screenshot();
    void handleTime(int time_as_miliseconds,bool isPause);
    ///menu symulacji
    void menuSTDraw();///rysowanie menu symulacji
    void moveUpST();
    void moveDownST();
    void menuSTODraw();///rysowanie menu kamieni
    void moveUpSTO();
    void moveDownSTO();
    void menuSIDraw();///rysowanie menu rozmiaru
    void moveUpSI();
    void moveDownSI();
    void menuWDCHDraw();///rysowanie menu rozmiaru
    void moveUpWDCH();
    void moveDownWDCH();
    int selectedItemIndexST=0;
    unsigned selectedItemIndexSTO=0;
    unsigned selectedItemIndexSI=0;
    int selectedItemIndexWDCH=0;
    sf::Font fontMenu;
    sf::Text menuST[MAX_ROW];
    sf::Text menuSTO[MAX_ROW];
    sf::Text menuSI[MAX_ROW];
    sf::Text menuWDCH[5];
    sf::Text menuWIND;
    sf::Text menuSIZE;
    sf::Text menuSIMTYPE;
    sf::Text menuSTONES;
    unsigned stones=0;
    static void createArena();
    void simulationRun();
    void reset();
};
#endif // SFMLHANDLING_H
