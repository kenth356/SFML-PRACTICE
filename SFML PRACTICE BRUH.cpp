#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;

int main() {
	VideoMode desktopMODE = VideoMode::getDesktopMode();
	RenderWindow window(desktopMODE, "Practice");
	Event yolo;

	while (window.isOpen()) {
		while (window.pollEvent(yolo)) {
			switch (yolo.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (yolo.key.code == Keyboard::Escape)
					window.close();
				    break;
			}
		}
		window.clear(Color::Yellow);
		window.display();
	}
}