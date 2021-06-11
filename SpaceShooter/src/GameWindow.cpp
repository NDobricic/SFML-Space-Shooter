#include "GameWindow.h"
#include "Scenes/SceneManager.h"
#include "Scenes/GameScene.h"

namespace ss
{
    sf::RenderWindow* GameWindow::window = nullptr;
    std::string GameWindow::title;

    void GameWindow::RunGameLoop()
    {
        SceneManager::LoadScene<GameScene>();

        sf::Clock time;
        float lastTime = 0;
        float deltaTime;

        while (window->isOpen())
        {
            sf::Event event;
            while (window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window->close();
            }

            window->clear();

            deltaTime = time.getElapsedTime().asSeconds() - lastTime;
            lastTime += deltaTime;

            SceneManager::CurrentScene()->Update(deltaTime);
            for (int i = 0; i < SceneManager::CurrentScene()->Particles.size(); i++)
                window->draw(SceneManager::CurrentScene()->Particles[i]->GetSprite());
            for (int i = 0; i < SceneManager::CurrentScene()->GameObjects.size(); i++)
                window->draw(SceneManager::CurrentScene()->GameObjects[i]->GetSprite());

            window->setTitle(title +
                "; FPS: " + std::to_string(1.0f / deltaTime) +
                "; Particles: " + std::to_string(SceneManager::CurrentScene()->Particles.size()) +
                "; GameObjects: " + std::to_string(SceneManager::CurrentScene()->GameObjects.size()));

            window->display();
        }
    }

    GameWindow::GameWindow(int width, int height, const std::string& title)
    {
        if (window == nullptr)
            window = new sf::RenderWindow(sf::VideoMode(width, height), title);

        this->title = title;

        RunGameLoop();
    }

    int GameWindow::Width()
    {
        return window->getSize().x;
    }

    int GameWindow::Height()
    {
        return window->getSize().y;
    }
}