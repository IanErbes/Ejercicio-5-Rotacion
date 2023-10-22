#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    // Crear la ventana
    sf::RenderWindow App(sf::VideoMode(800, 600), "Ejercicio 5 rotacion");

    // Cargar una textura (reemplaza la ruta con tu propia imagen)
    Texture texture;
    texture.loadFromFile("cuad_yellow.png");

    // Crear el sprite
    Sprite sprite;
    sprite.setTexture(texture);

    // Posición inicial del sprite
    sprite.setPosition(400, 300);

    // Ángulo de rotación inicial
    float angulo = 0;

    // Velocidad de rotación
    float velocidadRotacion = 0.1f;

    // Loop principal
    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed) {
                App.close();
            }
        }

        // Rotar el sprite
        angulo += velocidadRotacion;
        if (angulo >= 360) {
            angulo = 0;
        }
        sprite.setRotation(angulo);

        // Limpiar la ventana
        App.clear();

        // Dibujar el sprite
        App.draw(sprite);

        // Mostrar la ventana
        App.display();
    }

    return 0;
}
