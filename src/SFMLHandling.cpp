#include "SFMLHandling.h"
#include <fstream>

#include <iostream>
unsigned sizeS=20;
Arena arena(sizeS);
void SFMLHandling::createArena()
{
    arena.create(sizeS);
}
SFMLHandling::SFMLHandling()
{
    window= new sf::RenderWindow(sf::VideoMode(1400,900), "Symulator pozaru lasu");


    if (!fontMenu.loadFromFile("fonts/times-new-roman.ttf"))
    {

    }
    menuST[0].setFont(fontMenu);
    menuST[0].setString("Sasiedztwo Moore'a");
    menuST[0].setFillColor(sf::Color::Red);
    menuST[0].setPosition(sf::Vector2f(300, 30));

    menuST[1].setFont(fontMenu);
    menuST[1].setString("Sasiedztwo von Neumanna");
    menuST[1].setFillColor(sf::Color::Black);
    menuST[1].setPosition(sf::Vector2f(300,70));

    menuST[2].setFont(fontMenu);
    menuST[2].setString("Random");
    menuST[2].setFillColor(sf::Color::Black);
    menuST[2].setPosition(sf::Vector2f(300,110));

    menuSTO[0].setFont(fontMenu);
    menuSTO[0].setString("25");
    menuSTO[0].setFillColor(sf::Color::Red);
    menuSTO[0].setPosition(sf::Vector2f(300, 30));

    menuSTO[1].setFont(fontMenu);
    menuSTO[1].setString("50");
    menuSTO[1].setFillColor(sf::Color::Black);
    menuSTO[1].setPosition(sf::Vector2f(300,70));

    menuSTO[2].setFont(fontMenu);
    menuSTO[2].setString("75");
    menuSTO[2].setFillColor(sf::Color::Black);
    menuSTO[2].setPosition(sf::Vector2f(300,110));

    menuSI[0].setFont(fontMenu);
    menuSI[0].setString("10x10");
    menuSI[0].setFillColor(sf::Color::Red);
    menuSI[0].setPosition(sf::Vector2f(300, 30));

    menuSI[1].setFont(fontMenu);
    menuSI[1].setString("15x15");
    menuSI[1].setFillColor(sf::Color::Black);
    menuSI[1].setPosition(sf::Vector2f(300,70));

    menuSI[2].setFont(fontMenu);
    menuSI[2].setString("20x20");
    menuSI[2].setFillColor(sf::Color::Black);
    menuSI[2].setPosition(sf::Vector2f(300,110));

    menuWDCH[0].setFont(fontMenu);
    menuWDCH[0].setString("Bez wiatru");
    menuWDCH[0].setFillColor(sf::Color::Red);
    menuWDCH[0].setPosition(sf::Vector2f(300,70));

    menuWDCH[1].setFont(fontMenu);
    menuWDCH[1].setString("Wiatr z N");
    menuWDCH[1].setFillColor(sf::Color::Black);
    menuWDCH[1].setPosition(sf::Vector2f(300,110));

    menuWDCH[2].setFont(fontMenu);
    menuWDCH[2].setString("Wiatr z E");
    menuWDCH[2].setFillColor(sf::Color::Black);
    menuWDCH[2].setPosition(sf::Vector2f(300,150));

    menuWDCH[3].setFont(fontMenu);
    menuWDCH[3].setString("Wiatr z S");
    menuWDCH[3].setFillColor(sf::Color::Black);
    menuWDCH[3].setPosition(sf::Vector2f(300,190));

    menuWDCH[4].setFont(fontMenu);
    menuWDCH[4].setString("Wiatr z W");
    menuWDCH[4].setFillColor(sf::Color::Black);
    menuWDCH[4].setPosition(sf::Vector2f(300,230));

}
SFMLHandling::~SFMLHandling()
{

}
void SFMLHandling::handleEvents_()
{
    while(window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            window->close();
        if((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::Escape))
            window->close();
        if((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::F)&&(isSelected[0]==true)&&(isSelected[1]==true)&&(isSelected[2]==true))
        {
            time_as_miliseconds/=2;
        }

        if((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::S)&&(isSelected[0]==true)&&(isSelected[1]==true)&&(isSelected[2]==true))
        {
            time_as_miliseconds*=2;
        }
        if((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::X)&&(isSelected[0]==true)&&(isSelected[1]==true)&&(isSelected[2]==true))
        {
            SFMLHandling::setFire();
        }
        if((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::R)&&(isSelected[0]==true)&&(isSelected[1]==true)&&(isSelected[2]==true))
        {
            reset();
            setStone();
            std::ofstream logs;
            logs.open("Rejestr_zdarzen.txt",std::ios_base::app);
            logs<<"\n\n----------RESTARTOWANIE SYMULACJI----------\n\n";
            logs.close();
        }
        if((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::P)&&(isSelected[0]==true)&&(isSelected[1]==true)&&(isSelected[2]==true))
        {
            if(isPause==false)
                isPause=true;
            else
                isPause=false;
        }
        if((event.type==sf::Event::KeyReleased)&&(event.key.code==sf::Keyboard::E)&&(isSelected[0]==true)&&(isSelected[1]==true)&&(isSelected[2]==true))
        {
            screenshot();
        }
        if((event.type==sf::Event::MouseButtonPressed)&&(event.mouseButton.button==sf::Mouse::Left)&&(isSelected[0]==true)&&(isSelected[1]==true)&&(isSelected[2]==true))
        {
            if(((sf::Mouse::getPosition(*window).x)/35==0)&&((sf::Mouse::getPosition(*window).y)/35)==24)
            {
                if(isPressed[0]==false)
                {
                    isPressed[0]=true;
                    isPressed[1]=false;
                    isPressed[2]=false;

                }
                else
                    isPressed[0]=false;
            }
            if(((sf::Mouse::getPosition(*window).x)/35==1)&&((sf::Mouse::getPosition(*window).y)/35==24)&&(isSelected[0]==true)&&(isSelected[1]==true)&&(isSelected[2]==true))
            {

                if(isPressed[1]==false)
                {
                    isPressed[1]=true;
                    isPressed[0]=false;
                    isPressed[2]=false;
                }
                else
                    isPressed[1]=false;
            }
            if(((sf::Mouse::getPosition(*window).x)/35==2)&&((sf::Mouse::getPosition(*window).y)/35==24)&&(isSelected[0]==true)&&(isSelected[1]==true)&&(isSelected[2]==true))
            {
                if(isPressed[2]==false)
                {
                    isPressed[2]=true;
                    isPressed[0]=false;
                    isPressed[1]=false;
                }
                else
                    isPressed[2]=false;
            }
        }
        if((sf::Mouse::isButtonPressed(sf::Mouse::Left))&&(isSelected[0]==true)&&(isSelected[1]==true)&&(isSelected[2]==true))
        {
            if(isPressed[0]==true&&(sf::Mouse::getPosition(*window).x>30)&&(sf::Mouse::getPosition(*window).x<=30+(int)sizeS*35)&&(sf::Mouse::getPosition(*window).y>30)&&(sf::Mouse::getPosition(*window).y<=30+(int)sizeS*35))
            {
                int xTK=(sf::Mouse::getPosition(*window).x-30)/35;
                int yTK=(sf::Mouse::getPosition(*window).y-30)/35;
                arena(xTK,yTK).setCurrState(field::states::BURNING);
            }
            if(isPressed[1]==true&&(sf::Mouse::getPosition(*window).x>30)&&(sf::Mouse::getPosition(*window).x<=30+(int)sizeS*35)&&(sf::Mouse::getPosition(*window).y>30)&&(sf::Mouse::getPosition(*window).y<=30+(int)sizeS*35))
            {
                int xTK=(sf::Mouse::getPosition(*window).x-30)/35;
                int yTK=(sf::Mouse::getPosition(*window).y-30)/35;
                arena(xTK,yTK).setCurrState(field::states::ROCK);
            }
            if(isPressed[2]==true&&(sf::Mouse::getPosition(*window).x>30)&&(sf::Mouse::getPosition(*window).x<=30+(int)sizeS*35)&&(sf::Mouse::getPosition(*window).y>30)&&(sf::Mouse::getPosition(*window).y<=30+(int)sizeS*35))
            {
                int xTK=(sf::Mouse::getPosition(*window).x-30)/35;
                int yTK=(sf::Mouse::getPosition(*window).y-30)/35;
                arena(xTK,yTK).setCurrState(field::states::UNTOUCHED);
            }
        }
        if((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::Up))
        {
            if(isSelected[1]==false&&isSelected[0]==false&&isSelected[2]==false&&(!selectedItemIndexSI==0))
                moveUpSI();
            if(isSelected[2]==false&&isSelected[1]==true&&isSelected[0]==false&&(!selectedItemIndexSTO==0))
                moveUpSTO();
            if(isSelected[0]==false&&isSelected[1]==true&&isSelected[2]==true)
                moveUpST();
            if(isSelected[3]==false&&isSelected[0]==true)
                moveUpWDCH();
        }
        if((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::Down))
        {
            if(isSelected[1]==false&&isSelected[0]==false&&isSelected[2]==false)
                moveDownSI();
            if(isSelected[2]==false&&isSelected[1]==true&&isSelected[0]==false)
                moveDownSTO();
            if(isSelected[0]==false&&isSelected[1]==true&&isSelected[2]==true)
                moveDownST();
            if(isSelected[3]==false&&isSelected[0]==true)
                moveDownWDCH();
        }
        if((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::Enter))
        {
            pressedTimes++;
            if(pressedTimes==1)
            {
                isSelected[1]=true;
                sizeS=(selectedItemIndexSI+2)*5;
            }
            if(pressedTimes==2)
            {
                isSelected[2]=true;
                setStone();
            }
            if(pressedTimes==3)
            {
                isSelected[0]=true;
                simulationType=selectedItemIndexST+1;
                cllogs.restart();
            }
            if(pressedTimes==4&&simulationType==3)
            {
                isSelected[3]=true;
                wind=selectedItemIndexWDCH;
                cllogs.restart();
            }

        }
        if((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        {
            if(((sf::Mouse::getPosition(*window).x)>=35)&&((sf::Mouse::getPosition(*window).y)>=770)&&((sf::Mouse::getPosition(*window).x)<=235)&&((sf::Mouse::getPosition(*window).y)<=805))
            {
                mouseClicked=true;
                sliderX=(sf::Mouse::getPosition(*window).x);
                wind_to_string=((sliderX-35)/2);
            }
        }
        if((event.type==sf::Event::MouseButtonReleased)&&(event.mouseButton.button==sf::Mouse::Left))
        {
            if(((sf::Mouse::getPosition(*window).x)/35==8)&&((sf::Mouse::getPosition(*window).y)/35==22))
            {
                wind=3;
            }
            if(((sf::Mouse::getPosition(*window).x)/35==9)&&((sf::Mouse::getPosition(*window).y)/35==22))
            {
                wind=1;
            }
            if(((sf::Mouse::getPosition(*window).x)/35==10)&&((sf::Mouse::getPosition(*window).y)/35==22))
            {
                wind=2;
            }
            if(((sf::Mouse::getPosition(*window).x)/35==11)&&((sf::Mouse::getPosition(*window).y)/35==22))
            {
                wind=4;
            }
        }
        if((event.type==sf::Event::MouseButtonPressed)&&(event.mouseButton.button==sf::Mouse::Left))
        {
            if(((sf::Mouse::getPosition(*window).x)/35==3)&&((sf::Mouse::getPosition(*window).y)/35==24))
                time_as_miliseconds*=2;
            if(((sf::Mouse::getPosition(*window).x)/35==4)&&((sf::Mouse::getPosition(*window).y)/35==24)&&(isPause==false))
                isPause=true;
            if(((sf::Mouse::getPosition(*window).x)/35==5)&&((sf::Mouse::getPosition(*window).y)/35==24)&&(isPause==true))
                isPause=false;
            if(((sf::Mouse::getPosition(*window).x)/35==6)&&((sf::Mouse::getPosition(*window).y)/35==24))
                time_as_miliseconds/=2;
        }

    }

}

void SFMLHandling::untouched_tree(int i,int j)
{
    sf::Sprite untouched;
    sf::Texture untouched_tree;
    untouched_tree.loadFromFile("textures/untouched.bmp");
    untouched.setTexture(untouched_tree);
    untouched.setPosition(i*35.f+3*SIZE,j*35.f+3*SIZE);
    window->draw(untouched);
}

void SFMLHandling::burning2_tree(int i,int j)
{
    sf::Sprite burning2;
    sf::Texture burning2_tree;
    burning2_tree.loadFromFile("textures/burning2.bmp");
    burning2.setTexture(burning2_tree);
    burning2.setPosition(i*35.f+3*SIZE,j*35.f+3*SIZE);
    window->draw(burning2);
}

void SFMLHandling::burnt_tree(int i,int j)
{
    sf::Sprite burnt;
    sf::Texture burnt_tree;
    burnt_tree.loadFromFile("textures/burnt.bmp");
    burnt.setTexture(burnt_tree);
    burnt.setPosition(i*35.f+3*SIZE,j*35.f+3*SIZE);
    window->draw(burnt);
}

void SFMLHandling::burning_tree(int i,int j)
{
    sf::Sprite burning;
    sf::Texture burning_tree;
    burning_tree.loadFromFile("textures/burning.bmp");
    burning.setTexture(burning_tree);
    burning.setPosition(i*35.f+3*SIZE,j*35.f+3*SIZE);
    window->draw(burning);

}

void SFMLHandling::toolkit()
{
    sf::Sprite SburningTK;///x-0 y-24
    sf::Texture TburningTK;
    TburningTK.loadFromFile("textures/burning.bmp");
    SburningTK.setTexture(TburningTK);
    SburningTK.setPosition(0,840);
    window->draw(SburningTK);

    sf::Sprite SrockTK;///x-1 y-24
    sf::Texture TrockTK;
    TrockTK.loadFromFile("textures/rock.bmp");
    SrockTK.setTexture(TrockTK);
    SrockTK.setPosition(35,840);
    window->draw(SrockTK);

    sf::Sprite SuntouchedTK;///x-2 y-24
    sf::Texture TuntouchedTK;
    TuntouchedTK.loadFromFile("textures/untouched.bmp");
    SuntouchedTK.setTexture(TuntouchedTK);
    SuntouchedTK.setPosition(70,840);
    window->draw(SuntouchedTK);

    sf::Sprite SslowerTK;///x-2 y-24
    sf::Texture TslowerTK;
    TslowerTK.loadFromFile("textures/slower.bmp");
    SslowerTK.setTexture(TslowerTK);
    SslowerTK.setPosition(105,840);
    window->draw(SslowerTK);

    sf::Sprite SpauseTK;///x-2 y-24
    sf::Texture TpauseTK;
    TpauseTK.loadFromFile("textures/pause.bmp");
    SpauseTK.setTexture(TpauseTK);
    SpauseTK.setPosition(140,840);
    window->draw(SpauseTK);

    sf::Sprite SplayTK;///x-2 y-24
    sf::Texture TplayTK;
    TplayTK.loadFromFile("textures/play.bmp");
    SplayTK.setTexture(TplayTK);
    SplayTK.setPosition(175,840);
    window->draw(SplayTK);

    sf::Sprite SfasterTK;///x-2 y-24
    sf::Texture TfasterTK;
    TfasterTK.loadFromFile("textures/faster.bmp");
    SfasterTK.setTexture(TfasterTK);
    SfasterTK.setPosition(210,840);
    window->draw(SfasterTK);



    sf::Font font;
    if(!font.loadFromFile("fonts/times-new-roman.ttf"))
        ;
    sf::Text textTK;
    textTK.setFont(font);
    textTK.setString("Przybornik");
    textTK.setFillColor(sf::Color::Black);
    textTK.setPosition(0,805);
    window->draw(textTK);
    if(simulationType==3)
    {
        frame(200,35,35,770,sf::Color(158,106,28,100));

        sf::Sprite Sgauche0;
        sf::Texture gauche0;
        gauche0.loadFromFile("textures/zero.bmp");
        Sgauche0.setTexture(gauche0);
        Sgauche0.setPosition(0,770);
        window->draw(Sgauche0);

        sf::Sprite Sgauche100;
        sf::Texture gauche100;
        gauche100.loadFromFile("textures/sto.bmp");
        Sgauche100.setTexture(gauche100);
        Sgauche100.setPosition(235,770);
        window->draw(Sgauche100);

        sf::Sprite SarrowS;
        sf::Texture arrowS;
        arrowS.loadFromFile("textures/arrow_up.bmp");
        SarrowS.setTexture(arrowS);
        SarrowS.setPosition(270,770);
        window->draw(SarrowS);

        sf::Sprite SarrowW;
        sf::Texture arrowW;
        arrowW.loadFromFile("textures/arrow_right.bmp");
        SarrowW.setTexture(arrowW);
        SarrowW.setPosition(375,770);
        window->draw(SarrowW);

        sf::Sprite SarrowE;
        sf::Texture arrowE;
        arrowE.loadFromFile("textures/arrow_left.bmp");
        SarrowE.setTexture(arrowE);
        SarrowE.setPosition(340,770);
        window->draw(SarrowE);

        sf::Sprite SarrowN;
        sf::Texture arrowN;
        arrowN.loadFromFile("textures/arrow_down.bmp");
        SarrowN.setTexture(arrowN);
        SarrowN.setPosition(305,770);
        window->draw(SarrowN);


        sf::Text textA;
        textA.setFont(font);
        textA.setString("Kierunek wiatru:   Sila wiatru:"+std::to_string(wind_to_string));
        textA.setFillColor(sf::Color::Black);
        textA.setPosition(405,765);
        window->draw(textA);
        sf::Sprite SarrowTK;
        sf::Texture arrowTK;
        if(wind==3)
            arrowTK.loadFromFile("textures/arrow_up.bmp");
        if(wind==1)
            arrowTK.loadFromFile("textures/arrow_down.bmp");
        if(wind==2)
            arrowTK.loadFromFile("textures/arrow_left.bmp");
        if(wind==4)
            arrowTK.loadFromFile("textures/arrow_right.bmp");
        SarrowTK.setTexture(arrowTK);
        SarrowTK.setPosition(600,770);
        window->draw(SarrowTK);
    }

}

void SFMLHandling::toolkitFrame(int x,int y)
{
    frame(35.f,35.f,x,y,sf::Color(255, 0, 0,100));
}

void SFMLHandling::rock(int i,int j)
{
    sf::Sprite rockS;
    sf::Texture rock;
    rock.loadFromFile("textures/rock.bmp");
    rockS.setTexture(rock);
    rockS.setPosition(i*35.f+3*SIZE,j*35.f+3*SIZE);
    window->draw(rockS);
}


void SFMLHandling::print_speed(double s,unsigned x)
{
    sf::Font font;
    if(!font.loadFromFile("fonts/times-new-roman.ttf"))
        ;
    sf::Text text;
    text.setFont(font);
    text.setString("Biezaca predkosc spalania\n: "+std::to_string(s)+"milisekund/klatke\nSkroty klawiszowe:\nF- Przyspiesz symulacje (x2)\nS- Zwolnij symulacje (x2)\nX- Podpalenie losowego drzewa\nP- Zatrzymaj symulacje (Ponownie nacisnij P by wznowic)\nR- Restart symulacji\nE- Zrob zrzut ekranu\nZapisane w folderze screenshots");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x*35.f+5*SIZE,52+3*SIZE);
    window->draw(text);
}

void SFMLHandling::frame(float rectangle_x,float rectangle_y,int startingposition_x,int startingposition_y,sf::Color Color)
{
    sf::RectangleShape rectangle(sf::Vector2<float>(rectangle_x,rectangle_y));
    rectangle.setFillColor(Color);
    rectangle.setPosition(startingposition_x,startingposition_y);
    window->draw(rectangle);
}

void SFMLHandling::printArena()
{
    for(unsigned i=0; i<sizeS; i++)
    {
        for(unsigned j=0; j<sizeS; j++)
        {

            if(arena(i,j).getCurrState()==field::states::UNTOUCHED)
                untouched_tree(i,j);

            if(arena(i,j).getCurrState()==field::states::BURNING)
                burning_tree(i,j);

            if(arena(i,j).getCurrState()==field::states::BURNING2)
                burning2_tree(i,j);

            if(arena(i,j).getCurrState()==field::states::BURNT)
                burnt_tree(i,j);

            if(arena(i,j).getCurrState()==field::states::ROCK)
                rock(i,j);

        }
    }
}
float laststep=0;
void SFMLHandling::logs()
{

    int treesBurnt=0;
    for(unsigned i=0; i<sizeS; i++)
    {
        for(unsigned j=0; j<sizeS; j++)
        {
            if(arena(i,j).getCurrState()==field::states::BURNT)
                treesBurnt++;
        }
    }

    if(laststep!=treesBurnt)
    {
        if(tm.asMilliseconds()>=time_as_miliseconds)
        {
            unsigned stones = 0;
            for(unsigned i=0; i<sizeS; i++)
            {
                for(unsigned j=0; j<sizeS; j++)
                {
                    if(arena(i,j).getCurrState() == field::states::ROCK)
                        stones++;

                }
            }
            std::ofstream logs;
            logs.open("Rejestr_zdarzen.txt",std::ios_base::app);
            logs<<"Procent spalonych drzew:"<<(treesBurnt/(sizeS*sizeS-(float)stones))*100.f<<"%\nSpalonych drzew:"<<treesBurnt<<"\nCzas:"<<cllogs.getElapsedTime().asSeconds()<<" s\n"<<"Iloœæ kamieni:"<< stones<<"\n\n";
            logs.close();
        }
        laststep=treesBurnt;
    }
    else if(laststep==treesBurnt)
    {
        if(!tm.asMilliseconds())
            ;
    }

}

void SFMLHandling::nextState()
{
    if(simulationType==1)
        calculateAndSetNextStatesForFieldMatrix(arena.field_matrix,sizeS);
    if(simulationType==2)
        calculateAndSetNextStatesForFieldMatrixSTAR(arena.field_matrix,sizeS);
    if(simulationType==3)
    {
        calculateAndSetNextStatesForFieldMatrixRANDOMandWIND(arena.field_matrix,sizeS);///POZA PETLA
    }
    for(unsigned i=0; i<sizeS; i++)
    {
        for(unsigned j=0; j<sizeS; j++)
        {
            arena(i,j).set_wind_direction(wind);
            arena(i,j).set_wind_power((sliderX-35)/2);
            arena(i,j).forwardState();
        }
    }
}

void SFMLHandling::setFire()
{
    unsigned x = rand()%sizeS;
    unsigned y = rand()%sizeS;
    if(arena(x,y).getCurrState() != field::BURNING && arena(x,y).getCurrState() != field::ROCK && arena(x,y).getCurrState() != field::BURNT && arena(x,y).getCurrState() != field::BURNING2)
        arena(x,y).setCurrState(field::states::BURNING);
    else
        setFire();
}

void SFMLHandling::setStone()
{

    for(unsigned o = 0; o <(selectedItemIndexSTO+1)*25;  o++)
    {
        unsigned x = rand()%sizeS;
        unsigned y = rand()%sizeS;
        if(arena(x,y).getCurrState() != field::states::ROCK)
            arena(x,y).setCurrState(field::states::ROCK);
        else
            o--;
    }
}

void SFMLHandling::screenshot()
{
    sf::Texture t;
    t.create(1400,900);
    t.update(*window);
    sf::Image image=t.copyToImage();
    image.saveToFile("screenshots/screenshot"+std::to_string(iterator_)+".png");
    iterator_++;
}

void SFMLHandling::handleTime(int time_,bool isPause)
{
    if(isPause==false)
        if(tm.asMilliseconds()>=time_)
        {
            nextState();
            tm=cl.restart();
        }
    if(isPause==true)
        if(!tm.asMilliseconds())
        {
            nextState();
        }
}

void SFMLHandling::updateS()
{
    sf::Sprite bsprite;
    sf::Texture btexture;
    btexture.loadFromFile("textures/Back.png");
    bsprite.setTexture(btexture);
    window->draw(bsprite);

    if(isSelected[1]==false)
    {
        menuSIZE.setFont(fontMenu);
        menuSIZE.setString("Podaj rozmiar lasu:");
        menuSIZE.setFillColor(sf::Color::Black);
        menuSIZE.setPosition(sf::Vector2f(300,0));
        window->draw(menuSIZE);
        menuSIDraw();
    }
    else if(isSelected[2]==false)
    {
        menuSTONES.setFont(fontMenu);
        menuSTONES.setString("Podaj ilosc kamieni");
        menuSTONES.setFillColor(sf::Color::Black);
        menuSTONES.setPosition(sf::Vector2f(300,0));
        window->draw(menuSTONES);
        menuSTODraw();
    }
    else if(isSelected[0]==false)
    {
        menuSIMTYPE.setFont(fontMenu);
        menuSIMTYPE.setString("Podaj sposob przeprowadzenia symulacji");
        menuSIMTYPE.setFillColor(sf::Color::Black);
        menuSIMTYPE.setPosition(sf::Vector2f(300,0));
        window->draw(menuSIMTYPE);
        menuSTDraw();

    }
    else if(isSelected[3]==false&&(selectedItemIndexST+1)==3)
    {
        menuWIND.setFont(fontMenu);
        menuWIND.setString("Podaj kierunek wiatru");
        menuWIND.setFillColor(sf::Color::Black);
        menuWIND.setPosition(sf::Vector2f(300,0));
        window->draw(menuWIND);
        menuWDCHDraw();
        cllogs.restart();
    }
    else if(isSelected[0]==true&&isSelected[1]==true&&isSelected[2]==true)
        simulationRun();
    if(mouseClicked==true&&simulationType==3)
        frame(sliderX-35,35,35,770,sf::Color(110, 255, 170,255));

    window->display();

}

void SFMLHandling::run()
{
    window->setFramerateLimit(60);
    mouseClicked=false;
    for(int i=0; i<3; i++)
    {
        isPressed[i]=false;
        isSelected[i]=false;
    }
    isSelected[3]=false;
    isPause=false;
    pressedTimes=0;

    remove("Rejestr_zdarzen.txt");
    while(window->isOpen())
    {
        updateS();
        handleEvents_();
    }
}


void SFMLHandling::menuSTDraw()
{
    for(int i=0; i<MAX_ROW; i++)
        window->draw(menuST[i]);
}
void SFMLHandling::moveUpST()
{
    if(selectedItemIndexST-1>=0)
    {
        menuST[selectedItemIndexST].setFillColor(sf::Color::Black);
        selectedItemIndexST--;
        menuST[selectedItemIndexST].setFillColor(sf::Color::Red);
    }
}

void SFMLHandling::moveDownST()
{
    if(selectedItemIndexST+1<MAX_ROW)
    {
        menuST[selectedItemIndexST].setFillColor(sf::Color::Black);
        selectedItemIndexST++;
        menuST[selectedItemIndexST].setFillColor(sf::Color::Red);
    }
}

void SFMLHandling::menuSTODraw()
{
    for(int i=0; i<MAX_ROW; i++)
        window->draw(menuSTO[i]);
}
void SFMLHandling::moveUpSTO()
{
    if(selectedItemIndexSTO-1>=0)
    {
        menuSTO[selectedItemIndexSTO].setFillColor(sf::Color::Black);
        selectedItemIndexSTO--;
        menuSTO[selectedItemIndexSTO].setFillColor(sf::Color::Red);
    }
}

void SFMLHandling::moveDownSTO()
{
    if(selectedItemIndexSTO+1<MAX_ROW)
    {
        menuSTO[selectedItemIndexSTO].setFillColor(sf::Color::Black);
        selectedItemIndexSTO++;
        menuSTO[selectedItemIndexSTO].setFillColor(sf::Color::Red);
    }
}

void SFMLHandling::menuSIDraw()
{
    for(int i=0; i<MAX_ROW; i++)
        window->draw(menuSI[i]);
}
void SFMLHandling::moveUpSI()
{
    if(selectedItemIndexSI-1>=0)
    {
        menuSI[selectedItemIndexSI].setFillColor(sf::Color::Black);
        selectedItemIndexSI--;
        menuSI[selectedItemIndexSI].setFillColor(sf::Color::Red);
    }
}

void SFMLHandling::moveDownSI()
{
    if(selectedItemIndexSI+1<MAX_ROW)
    {
        menuSI[selectedItemIndexSI].setFillColor(sf::Color::Black);
        selectedItemIndexSI++;
        menuSI[selectedItemIndexSI].setFillColor(sf::Color::Red);
    }
}

void SFMLHandling::menuWDCHDraw()
{
    for(int i=0; i<5; i++)
        window->draw(menuWDCH[i]);
}
void SFMLHandling::moveUpWDCH()
{
    if(selectedItemIndexWDCH-1>=0)
    {
        menuWDCH[selectedItemIndexWDCH].setFillColor(sf::Color::Black);
        selectedItemIndexWDCH--;
        menuWDCH[selectedItemIndexWDCH].setFillColor(sf::Color::Red);
    }
}

void SFMLHandling::moveDownWDCH()
{
    if(selectedItemIndexWDCH+1<5)
    {
        menuWDCH[selectedItemIndexWDCH].setFillColor(sf::Color::Black);
        selectedItemIndexWDCH++;
        menuWDCH[selectedItemIndexWDCH].setFillColor(sf::Color::Red);
    }
}

void SFMLHandling::simulationRun()
{
    ///ramki
    frame(sizeS*35.f+4*SIZE,sizeS*35.f+4*SIZE,SIZE,SIZE,sf::Color(50,123,168,255));
    frame(sizeS*35.f+2*SIZE,sizeS*35.f+2*SIZE,2*SIZE,2*SIZE,sf::Color(50,168,162,255));

    ///bazowa prekdosc wyswietlanie
    print_speed(time_as_miliseconds,sizeS);
    toolkit();
    if(isPressed[0]==true)
        toolkitFrame(0,24*35.f);
    if(isPressed[1]==true)
        toolkitFrame(1*35.f,24*35.f);
    if(isPressed[2]==true)
        toolkitFrame(2*35.f,24*35.f);
    if(isPause==true)
        toolkitFrame(4*35,24*35);
    else
        toolkitFrame(5*35,24*35);
    ///cala symulacja
    tm=cl.getElapsedTime();
    cllogs.getElapsedTime();
    printArena();
    handleTime(time_as_miliseconds,isPause);
    logs();
}

void SFMLHandling::reset()
{
    for(unsigned i=0;i<sizeS;i++)
    {
        for(unsigned j=0;j<sizeS;j++)
            arena(i,j).setCurrState(field::states::UNTOUCHED);
    }
    cllogs.restart();
}
