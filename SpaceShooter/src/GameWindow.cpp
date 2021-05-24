#include "GameWindow.h"
#include "AnimatedSprite.h"
#include "SceneManager.h"
#include "GameScene.h"

namespace ss
{
    void GameWindow::RunGameLoop()
    {
        SceneManager::LoadScene<GameScene>();

        sf::Clock time;
        float lastTime = 0;
        float deltaTime;

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();

            deltaTime = time.getElapsedTime().asSeconds() - lastTime;
            lastTime += deltaTime;

            SceneManager::CurrentScene()->Update(deltaTime);
            for (int i = 0; i < SceneManager::CurrentScene()->GameObjects.size(); i++)
                window.draw(SceneManager::CurrentScene()->GameObjects[i]->GetSprite());

            window.display();
        }
    }

    GameWindow::GameWindow(int width, int height, const std::string& title)
        : window(sf::VideoMode(width, height), title)
    {
        RunGameLoop();
    }
}