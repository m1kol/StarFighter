

#define SIMPLEANIMATION(x) if (Keyboard::isKeyPressed(Keyboard::Left)) { x.move(-5*time, 0); x.setTextureRect(IntRect(0, 96, 96, 96)); }\
if ((Keyboard::isKeyPressed(Keyboard::Right) )) { x.move(5*time, 0); x.setTextureRect(IntRect(0, 192, 96, 96)); }\
if ((Keyboard::isKeyPressed(Keyboard::Up) )) { x.move(0, -5*time); x.setTextureRect(IntRect(0, 288, 96, 96)); }\
if ((Keyboard::isKeyPressed(Keyboard::Down) )) { x.move(0, 5*time); x.setTextureRect(IntRect(0, 0, 96, 96)); }



