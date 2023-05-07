#include <SFML/Graphics.hpp>
#include <iostream>

class AnimatedText {
private:
    std::string m_text;
    double m_duration;
public:
    AnimatedText(const std::string& text, double duration) : m_text(text), m_duration(duration){}
    const std::string getText(int currentTime) {
        return m_text.substr(0,currentTime);
    }
};
class Window {
private:
    sf::RenderWindow* m_window;
    sf::Clock m_timer;
    sf::Event m_event;
public:
    Window(int width, int height, const std::string& caption) : m_window(new sf::RenderWindow(sf::VideoMode(width, height), caption)){}
    ~Window() {
        if (m_window != nullptr) {
            delete m_window;
        }
    }
    void Run(){
        AnimatedText animatedText = AnimatedText("Hello, World!", 14);
        sf::Font font;
        if (!font.loadFromFile("../font.ttf")) {
            std::cout << "You can't load from file";
        }
        while (m_window->isOpen()) {
            sf::Event m_event;
            while (m_window->pollEvent(m_event)) {
                if (m_event.type == sf::Event::Closed) {
                    m_window->close();
                }
            }
            m_window->clear();
            int timerSec = m_timer.getElapsedTime().asSeconds();
            sf::Text text;
            text.setString(animatedText.getText(timerSec));
            text.setFont(font);
            text.setFillColor(sf::Color::Blue);
            text.setPosition(0, 0);

            m_window->draw(text);
            m_window->display();
        }
    }
};


int main()
{
    Window window = Window(1080, 720, "title");
    window.Run();
    std::string str = "vggvvbhgfdxd";
    return 0;
}