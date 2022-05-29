#include <SFML/Graphics.hpp>


using namespace sf;

struct row
{
    int x;
    int h;
} rows[240];


int main()
{
    RenderWindow window(VideoMode(240, 200), "sort");
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
            //int z;
            //int j;

            //while (rows[index].h > rows[index - 1].h)
             //if(rows[index].h>rows[index+1].h)//for (int i = 1; i < rows[index].h; i++)
            
                 
                //for (int i = 1; i < rows[index].h; i++) {
                    //z = i;
                    //j = i - 1;
                    //while (i > rows[index - 1].h > z)

                    //std::swap(rows[index].h, rows[index + 1].h);
                    //z = rows[index].h;
                    while (rows[index].h > rows[index + 1].h) {
                        std::swap(rows[index].h, rows[index + 1].h);
                    }
                    //rows[j + 1].h = rows[index].h;
                    //j = j - 1;
                
            

            /*int i;
            while (i=1 < rows[index].h)
            {
                if (i == 0)
                    i++;
                if (rows[index].h >= rows[index - 1].h)
                    i++;
                else {
                    std::swap(rows[index].h, rows[index - 1].h);
                    i--;
                }
            }*/


            //rows[j + 1].h = z;
            //std::swap(rows[index].h, rows[index+1].h);

        }

        }
        if (!isCreated)
        {
            for (int i = 0; i < 240; ++i)
            {
                rows[i].x = i;
                rows[i].h = 1 + rand() % 100;
            }
            isCreated = true;
        }

        window.clear(Color::Black);
        for (int i = 0; i < 240; ++i)
        {
            rectangle.setSize(Vector2f(1, rows[i].h));
            rectangle.setPosition(Vector2f(i++, 200));
            rectangle.setRotation(180);
            rectangle.setFillColor(Color::Blue);
            if (i == index) rectangle.setFillColor(Color::Red);
            window.draw(rectangle);
        }
        window.display();

        index++;
        if (index >= 240)
            index = 0;
    }

    return 0;
}
