#include <SFML/Graphics.hpp>


using namespace sf;

struct row
{
    int x;
    int h;
} rows[200];


int main()
{
    RenderWindow window(VideoMode(240, 180), "sort");
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
            for(int i = 1;i < rows[index].h; i++){
                for (int j = i; j > 0 && rows[index].h - 1 > rows[index].h; j--)
                {
                    std::swap(rows[index].h, rows[index - 1].h);
                }
        }

        }
        if (!isCreated)
        {
            for (int i = 0; i < 200; ++i)
            {
                rows[i].x = i;
                rows[i].h = 1 + rand() % 180;
            }
            isCreated = true;
        }

        window.clear(Color::Black);
        for (int i = 0; i < 200; ++i)
        {
            rectangle.setSize(Vector2f(1, rows[i].h));
            rectangle.setPosition(Vector2f(i, 180));
            rectangle.setRotation(180);
            rectangle.setFillColor(Color::Blue);
            if (i == index) rectangle.setFillColor(Color::Red);
            window.draw(rectangle);
        }
        window.display();

        index++;
        if (index >= 199)
            index = 0;
    }

    return 0;
}
