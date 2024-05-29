#pragma once
#include "AnimationWindow.h"
#include "std_lib_facilities.h"
#include "Block.h"

class Player {
public:
    static constexpr int playerHeight = Block::blockSize * 2; // The player is two blocks high
    static constexpr int playerWidth = Block::blockSize - Block::blockSize/5; // The player is almost a block width

    Player() {}

    void draw(AnimationWindow& win, Point upperLeftCorner);
};