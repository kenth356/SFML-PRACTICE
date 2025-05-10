#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main() {
	RenderWindow window(VideoMode::getDesktopMode(), "PRACTICE", Style::Fullscreen);
	Event ev;

	Texture backgroundTXT;
	backgroundTXT.loadFromFile("C:\\Users\\samon\\source\\repos\\SFML PRACTICE BRUH\\assets\\background.jpg");

	Sprite backgroundSPRT;
	backgroundSPRT.setTexture(backgroundTXT);

	Vector2u textureSZE = backgroundTXT.getSize();
	Vector2u windowSZE = window.getSize();

	float scale = max(
		static_cast<float>(windowSZE.x) / textureSZE.x,
		static_cast<float>(windowSZE.y) / textureSZE.y
		);
	backgroundSPRT.setScale(scale, scale);

	FloatRect bgBOUND = backgroundSPRT.getGlobalBounds();
	backgroundSPRT.setPosition(
		(windowSZE.x - bgBOUND.width) / 2.f,
		(windowSZE.y - bgBOUND.height) / 2.f
	);

	RectangleShape parihaba(Vector2f(120, 60));
	parihaba.setFillColor(Color::Yellow);
	parihaba.setPosition(840, 400);
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
			parihaba.move(speed, 0);
		if (Keyboard::isKeyPressed(Keyboard::Left))
			parihaba.move(-speed, 0);
		if (Keyboard::isKeyPressed(Keyboard::Up))
			parihaba.move(0, -speed);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			parihaba.move(0, speed);

		window.clear();
		window.draw(backgroundSPRT);
		window.draw(parihaba);
		window.display();
	}
}
