#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "funcs.h"
using namespace std;
using namespace sf;


int main()
{

    

    while (window.isOpen()) {
        Draw();
        Speed1();
        Speed();
        
    }
    return 0;
}