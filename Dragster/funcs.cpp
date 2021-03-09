#include "funcs.h"
#include "globals.h"
#include <iostream>
#include <sstream>


//Car 1: control

void Speed() {
    while (t < 20) {
        t++;
    }

    if ((Keyboard::isKeyPressed(Keyboard::Space)) && (Keyboard::isKeyPressed(Keyboard::D)))
    {
        if (t == 20)
        {
            at = 1.3;
            speed = speed* at;
            t = 21;
        }
        else {
            at = 1;
        }
    }


    //Фикс откаты машины за карту
    xPos = s.getPosition().x;
    if ((xPos < -1) && (Keyboard::isKeyPressed(Keyboard::A)) || ((xPos > width - 150) && (Keyboard::isKeyPressed(Keyboard::D)))) {
        k = 0;
        speed = 0;
    }
    else {
        k = 1;
    }

    if (Keyboard::isKeyPressed(Keyboard::A))
    {


        s.move(-0.4 * k, 0);
        x--;
    }

    if (Keyboard::isKeyPressed(Keyboard::D))
    {


        speed += 0.3 ;
        s.move(speed * k, 0);
        x++;
    }
}

//Car 2: control

void Speed1() {
   
    //Фикс откаты машины за карту
    xPos1 = s1.getPosition().x;
    if ((xPos1 < -1) && (Keyboard::isKeyPressed(Keyboard::Left)) || ((xPos1 > width - 150) && (Keyboard::isKeyPressed(Keyboard::Right)))) {
        k1 = 0;
        speed1 = 0;
    }
    else {
        k1 = 1;
    }

    if (Keyboard::isKeyPressed(Keyboard::Left))
    {


        s1.move(-0.4 * k1, 0);

    }

    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
       
            speed1 += 0.35;
        
        s1.move(speed1 * at * k1, 0);

    }
}



void Draw() {

    offsetX = xPos/2 ;

    Font font;
    font.loadFromFile("times.ttf");
    Text text("", font, 20);
    text.setFillColor(Color::Red);
    text.setStyle(Text::Bold);

    font.loadFromFile("times.ttf");
    Text text1("", font, 20);
    text1.setFillColor(Color::Green);
    text1.setStyle(Text::Bold);


    
    Text timer("", font, 20);
    timer.setFillColor(Color::Red);
    timer.setStyle(Text::Bold);

    Text timer1("", font, 20);
    timer1.setFillColor(Color::Green);
    timer1.setStyle(Text::Bold);
    
    Texture background; 
    background.loadFromFile("prerender.png");
    bg.setTexture(background);

    Texture car;
   
    

    car.loadFromFile("car.png");
    s.setTexture(car);
    s.setPosition(x, y);
  
    Texture car1;

    car1.loadFromFile("car2.png");
        s1.setTexture(car1);
    s1.setPosition(x, y - 70);

  

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                    window.close();
            }

            Speed();
            Speed1();
        
            window.clear(Color::Magenta);
            

            

            //Спидометр car1
            ostringstream carSpeedString;
            carSpeedString << speed;
            text.setString("Speed:" + carSpeedString.str());
            text.setPosition(30, 80);

            //Спидометр car2

            ostringstream carSpeedString1;
            carSpeedString1 << speed1;
            text1.setString("Speed:" + carSpeedString1.str());
            text1.setPosition(30, 30);


            //Boost time car 1
            ostringstream carTimeString;
            carTimeString << t;
            timer.setString("Boost time:" + carTimeString.str());
            timer.setPosition(145, 80);

            //Boost time car 2 
            timer1.setString("Boost time: None");
            timer1.setPosition(145, 30);

            bg.setPosition(0 - offsetX, 0);
            window.draw(bg);
                
            window.draw(s);
            window.draw(s1);

            window.draw(text1);
            window.draw(text);
            window.draw(timer);
            window.draw(timer1);
            window.display();
        }
    }

}





