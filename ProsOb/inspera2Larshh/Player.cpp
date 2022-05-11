#include "Player.h"

void Player::draw(AnimationWindow& win, Point upperLeftCorner){
    //hair
    win.draw_rectangle({upperLeftCorner.x, upperLeftCorner.y}, playerWidth, playerHeight/6, 0);

    //head
    win.draw_rectangle({upperLeftCorner.x, upperLeftCorner.y+playerHeight/6}, playerWidth, playerHeight/3, 9);

    //body
    win.draw_rectangle({upperLeftCorner.x+playerWidth/6, upperLeftCorner.y+playerHeight/2}, playerWidth-playerWidth/3, playerHeight/2, 4); 

    //eye1
    win.draw_rectangle({upperLeftCorner.x+playerWidth/6, upperLeftCorner.y+playerHeight/4}, 5, 5, 0);
    
    //eye2
    win.draw_rectangle({upperLeftCorner.x+playerWidth-playerWidth/3, upperLeftCorner.y+playerHeight/4}, 5, 5, 0);
}