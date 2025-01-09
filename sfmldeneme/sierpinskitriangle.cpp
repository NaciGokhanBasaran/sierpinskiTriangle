#include <iostream>
#include <SFML/Graphics.hpp>

sf::Vector2f midpoint(sf::Vector2f A, sf::Vector2f B) {
    return sf::Vector2f((A.x + B.x) / 2, (A.y + B.y) / 2);
}

void sierpinski(sf::Vector2f A, sf::Vector2f B, sf::Vector2f C, int depth, sf::RenderWindow& window) {
    if (depth != 0) {
        // Draw triangle
        sf::VertexArray triangle(sf::Triangles, 3);
        triangle[0].position = A;
        triangle[1].position = B;
        triangle[2].position = C;

        

        if (depth == 1) {
            triangle[0].color = sf::Color::White;
            triangle[1].color = sf::Color::White;
            triangle[2].color = sf::Color::White;
        }
        else {
            triangle[0].color = sf::Color::Black;
            triangle[1].color = sf::Color::Black;
            triangle[2].color = sf::Color::Black;
        }

        window.draw(triangle);

        sf::Vector2f M_AB = midpoint(A, B);
        sf::Vector2f M_AC = midpoint(A, C);
        sf::Vector2f M_BC = midpoint(B, C);
        depth--;

        sierpinski(A, M_AB, M_AC, depth, window);
        sierpinski(B, M_AB, M_BC, depth, window);
        sierpinski(C, M_AC, M_BC, depth, window);
    }
}

int main() {
    const int WIDTH = 800, HEIGHT = 800;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sierpinski Triangle");

    sf::Vector2f A(0, 0);
    sf::Vector2f B(600, 0); 
    sf::Vector2f C(300, -519.615f);

    sf::View view = window.getDefaultView();
    float zoomFactor = 1.0f;
    sf::Vector2i lastMousePosition; 
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); 
            if(event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    lastMousePosition = sf::Mouse::getPosition(window);
                }
            }

            if (event.type == sf::Event::MouseMoved) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i delta = sf::Mouse::getPosition(window) - lastMousePosition;
                    view.move(-delta.x, -delta.y);  // Görünümü fare hareketine göre kaydır
                    window.setView(view); 
                    lastMousePosition = sf::Mouse::getPosition(window); 
                }
            }
            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.delta > 0) {
                   
                    view.zoom(0.9f);
                }
                else {
                    
                    view.zoom(1.1f);
                }
                window.setView(view);
            } 

           
             
        }

        window.clear(sf::Color::Black);
        sierpinski(A, B, C, 6, window);
        window.display();
    }

    return 0;
}
