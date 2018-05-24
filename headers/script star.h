

#define SIMPLEANIMATION(x) if (Keyboard::isKeyPressed(Keyboard::Left)) { x.move(-5*time, 0); x.setTextureRect(IntRect(0, 96, 96, 96)); }\
if ((Keyboard::isKeyPressed(Keyboard::Right) )) { x.move(5*time, 0); x.setTextureRect(IntRect(0, 192, 96, 96)); }\
if ((Keyboard::isKeyPressed(Keyboard::Up) )) { x.move(0, -5*time); x.setTextureRect(IntRect(0, 288, 96, 96)); }\
if ((Keyboard::isKeyPressed(Keyboard::Down) )) { x.move(0, 5*time); x.setTextureRect(IntRect(0, 0, 96, 96)); }

#define DIFFICULTANIMATION(x) if (Keyboard::isKeyPressed(Keyboard::Left)) {\
 CurrentFrame += 2.5*time; \
if (CurrentFrame > 3) CurrentFrame -= 3; \
x.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96)); \
x.move(-5*time, 0);\
}\
if (Keyboard::isKeyPressed(Keyboard::Right)) {\
CurrentFrame += 2.5*time;\
if (CurrentFrame > 3) CurrentFrame -= 3; \
x.setTextureRect(IntRect(96 * int(CurrentFrame), 192, 96, 96)); \
x.move(5*time, 0);\
}\
if (Keyboard::isKeyPressed(Keyboard::Up)) {\
CurrentFrame += 2.5*time;\
if (CurrentFrame > 3) CurrentFrame -= 3;\
x.setTextureRect(IntRect(96 * int(CurrentFrame), 288, 96, 96));\
x.move(0, -5*time);\
}\
if (Keyboard::isKeyPressed(Keyboard::Down)) {\
CurrentFrame += 2.5*time; \
if (CurrentFrame > 3) CurrentFrame -= 3; \
x.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96)); \
x.move(0, 5*time);\
}

