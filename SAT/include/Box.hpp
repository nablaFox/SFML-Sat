#pragma once

#include "Utilities.hpp"

class Box : public Drawable {
public:
    Box(Vector2f pos, RenderWindow *window, int size = 100);
    ~Box();

    // set
    void move();
    void setRotation(float angle);
    void setTraslation(const Vector2f& pos);
    void setOrigin(const Vector2f& pos);
    float rotSpeed = 1, speed = 1;

    // get
    float getRotation(), getSize();
    Vector2f& dot(int n);
    Vector2f edge(int n);

private:
    VertexArray rect;
    Vector2f p[4], pos;
    RenderWindow *satSpace;

    bool isClicked = false;
    float rot = 0, size;

    void translation(float speed);
    void rotation(float speed);

    virtual void draw(RenderTarget &target, RenderStates states) const;
};