#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>  
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#define PI 3.14159265358979323846

void updateArc(sf::ConvexShape& shape, const sf::Vector2f& center, float radius, float startAngle, float endAngle) {
    int pointCount = shape.getPointCount();

    float angleStep = (startAngle <= endAngle)
        ? (endAngle - startAngle) / (pointCount - 2)
        : (360.0f - (startAngle - endAngle)) / (pointCount - 2);

    float angle = startAngle;
    for (int i = 0; i <= pointCount - 2; i++) {
        float radian = angle * (PI / 180.0f);
        shape.setPoint(i + 1, sf::Vector2f(radius * cos(radian), -radius * sin(radian)));
        angle += angleStep;
    }
    shape.setPoint(0, sf::Vector2f(0, 0));
    shape.setPosition(center);
    shape.setFillColor(sf::Color::Green);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Snake", sf::Style::Default);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);


    sf::Clock clock;
    sf::Time timePerFrame = sf::seconds(1.f / 80.f);


    sf::ConvexShape arc(30);
    sf::Vector2f center(400, 300);
    float radius = 100.f;
    float startAngle = 0.f;
    float endAngle = 90.0f;

    updateArc(arc, center, radius, startAngle, endAngle);




    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Time elapsedTime = clock.restart();

        while (elapsedTime > timePerFrame) {


            elapsedTime -= timePerFrame;
        }

        window.clear();

        window.draw(arc);

        window.display();
    }

    return 0;
}
