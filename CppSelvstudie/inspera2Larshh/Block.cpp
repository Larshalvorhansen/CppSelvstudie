#include "Block.h"

// TASK
BlockType Block::getBlockType(int n) const
{
    // BEGIN: 1a
    return blockType;
    // END: 1a
}

// TASK
void Block::draw(AnimationWindow &win, Point upperLeftCorner) const
{
    // BEGIN: 1b
    int color = static_cast<int> (blockType);
    win.draw_rectangle(upperLeftCorner, blockSize, blockSize, color);
    // END: 1b 
}