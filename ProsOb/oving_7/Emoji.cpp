#include "Emoji.h"

void Face::draw(AnimationWindow& win) {
    win.draw_circle(c, r, Color::yellow);
}

void EmptyFace::draw(AnimationWindow& win){
    Face::draw(win);
    win.draw_circle({(c.x-r/2),(c.y-r/2)+10}, r/5, Color::blue);
    win.draw_circle({(c.x+r/2),(c.y-r/2)+10}, r/5, Color::blue);
}

void Smilingface::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc(c, 55, 55, 225, 315, Color::black);
}

void SadFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc({c.x,c.y+40}, 55, 30, 45, 135, Color::black);
}

void AngryFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc({c.x+r/2-10,c.y-r+10}, 20, 35, 270, 360, Color::black);
    win.draw_arc({c.x-r/2+10,c.y-r+10}, 20, 35, 180, 270, Color::black);
    win.draw_arc({c.x,c.y+40}, 55, 30, 45, 135, Color::black);
}

void SuprisedFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_circle({c.x,c.y+r/2-10}, r/3, Color::black);
}