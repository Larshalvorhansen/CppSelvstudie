#pragma once
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : Emoji{
    private:
        Point c;
        int r = 200;
    public:
        Face(Point c, int r);
        virtual void draw(AnimationWindow&) = 0;
};

class EmptyFace : Face{
    private:
    public:
        EmptyFace(Point c, int r);
        void draw(AnimationWindow&) override;
};