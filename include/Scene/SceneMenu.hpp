#ifndef SCENE_MENU_HPP
#define SCENE_MENU_HPP

#include "Scene.hpp"
class App; // Forward declaration

class SceneMenu : public Scene{
    private:
        App *pApp;
        bool areChanged;
    public:
        SceneMenu(App *pApp);
        void draw() override;
        void update() override;
};

#endif