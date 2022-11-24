#include "Application.hpp"
#include "Utilities.hpp"

Application *Application::Instance = nullptr;

Application::Application() 
{
    InitWindow();

    box1 = new Box(Vector2f(100, 400), &Window, 80);
    box2 = new Box(Vector2f(400, 400), &Window, 120);
}

Application::~Application()
{
    delete box1, box2;
}

void Application::Run() 
{
    while(Window.isOpen())
    {
        HandleEvents();
        Update();

        Window.clear();
        Render();
        Window.display();
    }
}

void Application::InitWindow()
{
    VideoMode mode;
    mode.width = WINDOW_WIDTH;
    mode.height = WINDOW_HEIGHT;

    ContextSettings settings;
    settings.antialiasingLevel = 8;

    Window.create(mode, "SAT Collision", Style::Default, settings);
    Window.setFramerateLimit(144);
}

void Application::HandleEvents()
{
    while(Window.pollEvent(Event))
       if (Event.type == Event::Closed)
           Window.close();
}

void Application::Update()
{
    box1->move();
    box2->move();
    if (Collision::Instance.SATCollision(*box1, *box2))
        Collision::Instance.CollisionAction(*box1, *box2);
}

void Application::Render()
{
    Window.draw(*box1);
    Window.draw(*box2);
}
