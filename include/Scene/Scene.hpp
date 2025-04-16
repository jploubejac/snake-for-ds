#ifndef SCENE_HPP  
#define SCENE_HPP

class Scene{
    public:
        Scene() = default;
        virtual void draw();
        virtual void update();
};
#endif