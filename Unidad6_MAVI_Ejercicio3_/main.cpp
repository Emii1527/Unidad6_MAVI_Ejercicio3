#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Unidad6_MAVI_Ejercicio3");
    sf::CircleShape circle(30.f);
    circle.setFillColor(sf::Color::Yellow);

    // Vectores para posición, velocidad y aceleración
    sf::Vector2f position(400.f, 100.f);
    sf::Vector2f velocity(0.f, 0.f);

    // Gravedad respecto x, y
    const sf::Vector2f grav(0.f, 300.f); 
    const float deltaTime = 0.01f;

    // Rebote (inversión y reducción de velocidad)
    const float FactorRebote = -0.8f; 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Aplicar gravedad
        velocity += grav * deltaTime;

        // Actualizar posición
        position += velocity * deltaTime;

        // Verificar colisión con el suelo
        if (position.y + circle.getRadius() * 2 >= window.getSize().y) {
            position.y = window.getSize().y - circle.getRadius() * 2;

            // Rebote
            velocity.y *= FactorRebote; 
        }

        // Dibujar
        circle.setPosition(position);
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }

    return 0;
}