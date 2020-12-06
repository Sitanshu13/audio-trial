#include <C:\Users\sony\Desktop\SFML-2.5.1\include\SFML\Graphics.hpp>
#include <C:\Users\sony\Desktop\SFML-2.5.1\include\SFML\Audio.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow Window(sf::VideoMode(640, 480, 32), "Recording Sounds");

    sf::SoundBufferRecorder recorder;
    sf::SoundBuffer buffer;
    sf::Sound sound;

    while (Window.isOpen())
    {
        sf::Event Event;
        while(Window.pollEvent(Event))
        {
            switch (Event.type)
            {
            case sf::Event::Closed:
                Window.close();
                break;

            case sf::Event::KeyPressed:
                if(Event.key.code == sf::Keyboard::R)
                {
                    recorder.start();
                }
                else if(Event.key.code == sf::Keyboard::S)
                {
                    recorder.stop();
                    buffer = recorder.getBuffer();
                    sound.setBuffer(buffer);
                    sound.play();
                }
            }
        }

        Window.clear(sf::Color(0, 240, 255));
        Window.display();
    }
}
