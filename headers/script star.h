

#define SIMPLEANIMATION(x) if (Keyboard::isKeyPressed(Keyboard::Left)) { x.move(-0.5*time, 0); x.setTextureRect(IntRect(0, 96, 96, 96)); }\
if ((Keyboard::isKeyPressed(Keyboard::Right) )) { x.move(0.5*time, 0); x.setTextureRect(IntRect(0, 192, 96, 96)); }\
if ((Keyboard::isKeyPressed(Keyboard::Up) )) { x.move(0, -0.95*time); x.setTextureRect(IntRect(0, 288, 96, 96)); }\
if ((Keyboard::isKeyPressed(Keyboard::Down) )) { x.move(0, 2*time); x.setTextureRect(IntRect(0, 0, 96, 96)); }

#define FOO(x) if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { (x).move(-0.1*time, 0); (x).setTextureRect(sf::IntRect(0, 96, 96, 96)); }

