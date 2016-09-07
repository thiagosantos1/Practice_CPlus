// All SFML programs will have a clear/draw/display loop like this. It might
// seem wasteful, but don't worry, modern computers can handle it.
//
// This still won't work on all systems, though.

#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(100, 50));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(100, 20);
    
    // pq sem isso vc desenha na tela e display, porem se vc passar uma janela na frente
    // ou algo, a tela pega o print da outra tela, virando uma messy
    // sendo assim, enquando a janela estiver limpa, vc continua limpando 
    // e fazendo o display na tela
    // isso funciona para quase todos os prog em c++
    while (window.isOpen())
    {
        window.clear();
        window.draw(rectangle);
        window.display();    
    }

    return 0;
}
