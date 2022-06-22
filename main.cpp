#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;

struct row
{
    int x;
    int h;
} rows[360];


int main()
{
    RenderWindow window(VideoMode(360, 240), "sort");
    RectangleShape rectangle;
    Event event;

    bool isCreated = false;
    int index = 0;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (isCreated) 
        {
             while (rows[index].h < rows[index-1].h) {
                if (rows[index].h == 0)
                    rows[index++].h;
                if (rows[index].h >= rows[index - 1].h)
                    rows[index++].h;
               else {
                    std::swap(rows[index].h, rows[index - 1].h);
                    rows[index--].h;
                

                }
            }
        }
        if (!isCreated)
        {
            for (int i = 0; i < 360; ++i)
            {
                rows[i].x = i;
                rows[i].h = 1 + rand() % 160;
            }
            isCreated = true;
        }

        window.clear(Color::White);
        for (int i = 0; i < 360; ++i)
        {
            rectangle.setSize(Vector2f(1, rows[i].h));
            rectangle.setPosition(Vector2f(i++, 240));
            rectangle.setRotation(180);
            rectangle.setFillColor(Color::Green);
            if (i == index) rectangle.setFillColor(Color::Red);
            window.draw(rectangle);
        }
        window.display();

        index++;
        if (index >= 360)
            index = 0;
    }
    cout << count << endl;
    return 0;
}
