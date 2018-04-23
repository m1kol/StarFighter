//
// Created by anna on 23.04.18.
//

void mainloop() {
    while (windowID.isOpen())
    {
        sf::Event event;
        while (windowID.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                windowID.close();
        }

        windowID.clear();
        //когда зароботает это, то if будет проверять массив на наличие Render и запускать отрисовку
        for (int i = 0; i < size; ++i) {
            if (AllObjects[i]) {
                std::cout<<"Объект№"<<i;
            }

        }
        windowID.display();
    }
}
