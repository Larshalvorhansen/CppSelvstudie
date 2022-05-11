#pragma once

#include "std_lib_facilities.h"
#include "AnimationWindow.h"

using namespace TDT4102;

enum BlockType {Stone = 8, Grass = 62, Gold = 93, None = 0};



const map <BlockType,string> BlockTypeToStringMap{
    {BlockType::Stone, "Stone"},
    {BlockType::Grass, "Grass"},
    {BlockType::None, "none"}
};

const map <string, BlockType> StringToBlocktypeMap{
    {"Stone", BlockType::Stone},
    {"Grass", BlockType::Grass},
    {"none", BlockType::None}
};

class Block {
public:
    static constexpr int blockSize = 30; // NB! Changing this can lead to errors
    Block(BlockType blockType) : blockType{blockType} {}

    void draw(AnimationWindow& win, Point upperLeftCorner) const;

    BlockType getBlockType() const;

private:
    BlockType blockType;
};