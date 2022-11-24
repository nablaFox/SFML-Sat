#pragma once

#include "Box.hpp"
#include "Collision.hpp"

class Application {
public:
    Application();
    ~Application();

    void Run();

    static Application *Instance;

    RenderWindow Window;
    Event Event;

private:
    Box *box1, *box2;

    void InitWindow();
    void HandleEvents();
    void Update();
    void Render();
    void Menu();
};
