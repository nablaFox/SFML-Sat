#include "Box.hpp"

Box::Box(Vector2f pos, RenderWindow *window, int size)
{
    satSpace = window;
    rect = VertexArray(Quads, 4);
    this->pos = pos;
    this->size = size;

    p[0] = rect[0].position = Vector2f(pos.x - size / 2, pos.y - size / 2);
    p[1] = rect[1].position = Vector2f(pos.x + size / 2, pos.y - size / 2);
    p[2] = rect[2].position = Vector2f(pos.x + size / 2, pos.y + size / 2);
    p[3] = rect[3].position = Vector2f(pos.x - size / 2, pos.y + size / 2);
}

Box::~Box()
{
    delete satSpace;
}

void Box::move()
{
    // check if the object is clicked, then rotate or traslate

    if (Mouse::isButtonPressed(Mouse::Left))
    {
        int x = Mouse::getPosition(*satSpace).x;
        int y = Mouse::getPosition(*satSpace).y;

        isClicked = true;

        for (int i = 1; i < 5; i++)
        {
            int j = i + 1;
            if (i == 4) j = 1;

            float D = (dot(j).x - dot(i).x) * (y - dot(j).y) - (dot(j).y - dot(i).y) * (x - dot(j).x);
            if (D >= 0)
                continue;
            else
                isClicked = false;
        }
    }

    if (isClicked)
    {
        rotation(rotSpeed);
        translation(speed);
    }
}

void Box::setRotation(float angle)
{
    float rad = angle * M_PI / 180;
    for (int i = 0; i < 4; i++) 
    {
        int x = cos(rad) * (p[i].x - pos.x) - sin(rad) * (p[i].y - pos.y) + pos.x;
        int y = sin(rad) * (p[i].x - pos.x) + cos(rad) * ( p[i].y - pos.y) + pos.y;

        rect[i].position = Vector2f(x, y);
    }
    rot = angle;
}

void Box::rotation(float speed)
{
    if (Keyboard::isKeyPressed(Keyboard::D)) 
    {
        rot += speed;
        setRotation(rot);
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) 
    {
        rot -= speed;
        setRotation(rot);
    }
    if (Keyboard::isKeyPressed(Keyboard::Space))
    {
        setRotation(0);
        setOrigin(pos);
    }

    if (rot == 360) rot = 0;
}

void Box::setTraslation(const Vector2f& pos)
{
    this->pos = VectSum(this->pos, pos);
    
    for (int i = 0; i < 4; i++)
    {
        rect[i].position = VectSum(rect[i].position, pos);
        p[i] = VectSum(p[i], pos);
    }
}

void Box::translation(float speed)
{
    if (Keyboard::isKeyPressed(Keyboard::Right))
        setTraslation(Vector2f(speed, 0));
    else if (Keyboard::isKeyPressed(Keyboard::Left))
        setTraslation(Vector2f(-speed, 0));
    else if (Keyboard::isKeyPressed(Keyboard::Up))
        setTraslation(Vector2f(0, -speed));
    else if (Keyboard::isKeyPressed(Keyboard::Down))
        setTraslation(Vector2f(0, speed));
}

void Box::setOrigin(const Vector2f& pos) { this->pos = pos; }

float Box::getRotation() { return rot; }
float Box::getSize() { return size; }

Vector2f& Box::dot(int n)
{
    switch(n) {
        case 0:
            return pos;
            break;
        case 1:
            return rect[0].position;
            break;
        case 2:
            return rect[1].position;
            break;
        case 3:
            return rect[2].position;
            break;
        case 4:
            return rect[3].position;
            break;
    }
}

Vector2f Box::edge(int n)
{
    switch(n) {
        case 0:
            return VectSum(rect[1].position, -rect[0].position);
            break;
        case 1:
            return VectSum(rect[2].position, -rect[1].position);
            break;
        case 2:
            return VectSum(rect[3].position, -rect[2].position);
            break;
        case 3:
            return VectSum(rect[0].position, -rect[3].position);
            break;
    }
}

void Box::draw(RenderTarget& target, RenderStates states) const { target.draw(rect); }
