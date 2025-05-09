#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;

int main() {
	VideoMode desktop = VideoMode::getDesktopMode();
	RenderWindow window(desktop, "PRACTICE GAME");
	Event ev;
	CircleShape bilog(80);
	RectangleShape parihaba(Vector2f(150, 75));
	bilog.setFillColor(Color::Yellow);
	bilog.setPosition(855, 410);
	parihaba.setFillColor(Color::Cyan);
	parihaba.setPosition(855, 410);
	float speed = 3.0f;

	while (window.isOpen()) {
		while (window.pollEvent(ev)) {
			switch (ev.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (ev.key.code == Keyboard::Escape)
					window.close();
				    break;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
			bilog.move(speed, 0);
		if (Keyboard::isKeyPressed(Keyboard::Left))
			bilog.move(-speed, 0);
		if (Keyboard::isKeyPressed(Keyboard::Up))
			bilog.move(0, -speed);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			bilog.move(0, speed);

		if (Keyboard::isKeyPressed(Keyboard::D))
			parihaba.move(speed, 0);
		if (Keyboard::isKeyPressed(Keyboard::A))
			parihaba.move(-speed, 0);
		if (Keyboard::isKeyPressed(Keyboard::W))
			parihaba.move(0, -speed);
		if (Keyboard::isKeyPressed(Keyboard::S))
			parihaba.move(0, speed);


		window.clear();
		window.draw(bilog);
		window.draw(parihaba);
		window.display();
	}
}
