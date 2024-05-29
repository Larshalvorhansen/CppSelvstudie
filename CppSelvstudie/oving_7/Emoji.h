#pragma once
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji{
    public:
        virtual void draw(AnimationWindow&) = 0;
        virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji{
    protected:
        Point c {};
        int r {};
        Face(Point c, int r): c{c},r{r} {}
        void draw(AnimationWindow& win) override = 0;
};

class EmptyFace : public Face{
    public:
        EmptyFace(Point c, int r): Face{c,r}{}
        void draw(AnimationWindow& win) override;
};

class Smilingface : public EmptyFace{
    public:
        Smilingface(Point c, int r): EmptyFace{c,r}{}
        void draw(AnimationWindow& win) override;
};

class SadFace : public EmptyFace{
    public:
        SadFace(Point c, int r): EmptyFace{c,r}{}
        void draw(AnimationWindow& win) override;
};
class AngryFace : public SadFace{
    public:
        AngryFace(Point c, int r): SadFace{c,r}{}
        void draw(AnimationWindow& win) override;
};

class SuprisedFace : public EmptyFace{
    public:
        SuprisedFace(Point c, int r): EmptyFace{c,r}{}
        void draw(AnimationWindow& win) override;
};