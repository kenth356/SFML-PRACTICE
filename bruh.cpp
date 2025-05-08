#include <SFML/Graphics.hpp>

int main() {
    // Get the desktop mode (resolution)
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Create a window with the desktop resolution
    sf::RenderWindow window(desktopMode, "SFML Window");

    // Create a circle shape
    sf::CircleShape circle(50); // radius of 50
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(desktopMode.width / 2 - circle.getRadius(), desktopMode.height / 2 - circle.getRadius()); // center the circle in the window

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Close the window when the close event is triggered
        }

        // Clear the window
        window.clear(sf::Color::Black);

        // Draw the circle
        window.draw(circle);

        // Display what has been drawn
        window.display();
    }

    return 0;
}
