// Thiago Santos
// Lab 09
// 07/10/2015
// for this lab, I will draw a person playing Golf

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char const *argv[])
{

	sf::RenderWindow window(sf::VideoMode(1200, 800), "Golf");

	sf::Color color_body(0,0,0);

	// head
    sf::CircleShape head(35);
    head.setPosition(100,320);
    head.setFillColor(color_body);

    // body
    sf::RectangleShape body;
    body.setSize(sf::Vector2f(170, 7));
    body.setFillColor(color_body);
    body.setPosition(135, 390);
    body.rotate(90);

    // Left Arm
    sf::RectangleShape left_arm;
    left_arm.setSize(sf::Vector2f(110, 7));
    left_arm.setFillColor(color_body);
    left_arm.setPosition(135, 410);
    left_arm.rotate(65);

    // right Arm
    sf::RectangleShape right_arm;
    right_arm.setSize(sf::Vector2f(110, 7));
    right_arm.setFillColor(color_body);
    right_arm.setPosition(135, 410);
    right_arm.rotate(55);

     // Left leg
    sf::RectangleShape left_leg;
    left_leg.setSize(sf::Vector2f(110, 7));
    left_leg.setFillColor(color_body);
    left_leg.setPosition(135, 560);
    left_leg.rotate(125);

    // right leg
    sf::RectangleShape right_leg;
    right_leg.setSize(sf::Vector2f(110, 7));
    right_leg.setFillColor(color_body);
    right_leg.setPosition(135, 560);
    right_leg.rotate(55);

    // bet
    sf::RectangleShape bet;
    bet.setSize(sf::Vector2f(200, 4));
    bet.setFillColor(sf::Color::Red);
    bet.setPosition(175, 480);
    bet.rotate(60);


	// botton_Bet
    sf::CircleShape bottonBet(10);
    bottonBet.setPosition(270,640);
    bottonBet.setFillColor(sf::Color::Red);

	// support ball
    sf::RectangleShape support_ball;
    support_ball.setSize(sf::Vector2f(20, 5));
    support_ball.setFillColor(sf::Color::Red);
    support_ball.setPosition(320, 650);
    support_ball.rotate(90);

    // ball
    sf::CircleShape ball(13);
    ball.setPosition(305,620);
    ball.setFillColor(sf::Color::Black);

    // field
    sf::CircleShape field(225);
    field.setPosition(600,100);
    field.setFillColor(sf::Color::Green);

    // hole
    sf::CircleShape hole(20);
    hole.setPosition(800,300);
    hole.setFillColor(sf::Color::Black);

    // Hole flag
    sf::RectangleShape support_flag;
    support_flag.setSize(sf::Vector2f(180, 5));
    support_flag.setFillColor(sf::Color::Blue);
    support_flag.setPosition(860, 340);
    support_flag.rotate(270);

    // flag
    sf::CircleShape flag(30, 3);
    flag.setFillColor(sf::Color::Blue);
    flag.setPosition(820, 180);
    flag.rotate(270);



    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.draw(head);
        window.draw(body);
        window.draw(left_arm);
        window.draw(right_arm);
        window.draw(left_leg);
		window.draw(right_leg);
		window.draw(bet);
		window.draw(bottonBet);
		window.draw(ball);
		window.draw(support_ball);
		window.draw(field);
		window.draw(hole);
		window.draw(support_flag);
		window.draw(flag);

        window.display();    
    }
	
	return 0;
}