#include "Emoji.h"

Face::Face(Point c, int r): c{c}, r{r}{}
EmptyFace::EmptyFace(Point c, int r) : Face{c, r}{}
//Card::Card(Suit suit, Rank rank): s{suit}, r{rank}{}

void EmptyFace::draw(AnimationWindow& win){
    win.draw_circle({50,50} ,100, Color::blue);
    win.draw_circle({150,50} ,100, Color::blue);
}