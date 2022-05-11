#pragma once
#include "AnimationWindow.h"
#include "Block.h"
#include "Player.h"
#include "std_lib_facilities.h"

enum class MouseButton
{
    left = FL_LEFT_MOUSE,
    right = FL_RIGHT_MOUSE,
};

// MiniCraft GUI
class MiniCraftWindow : public AnimationWindow
{
public:

    static constexpr int blockSize = Block::blockSize;
    static constexpr int playerHeight = Player::playerHeight;
    static constexpr int playerWidth = Player::playerWidth;
    static constexpr int widgetWidth = 60;
    static constexpr int widgetHeight = 60;
    const int gridWidth;  // Width in blocks
    const int gridHeight; // Height in blocks

    MiniCraftWindow(int x, int y, int gridWidth, int gridHeight);
    
    // Game loop. Called to start the game
    void playMiniCraft();

    //Test function for 3c)
    void testBlockCreation();
    

private:

    //########################## Grid related ###########################################
    
    // Vector containing the block grid
    // Contains pointers to all blocks
    // Grid positions without a block is nullptr
    vector<shared_ptr<Block>> blockGrid; 


    //Functions for accessing the block grid:

    // Returns pointer to the block at a given position in the block grid
    shared_ptr<Block> &block_at_pos(pair<int, int> pos) { return blockGrid[pos.first + pos.second * gridWidth]; }

    // Returns pointer to the block at a given coordinate (point) in the MiniCraftWindow
    shared_ptr<Block> &block_at_pt(Point pt) { return blockGrid[pt.x / blockSize + (pt.y / blockSize) * gridWidth]; }

    // Converts a coordinate (point) in the MiniCraftWindow to a position in the block-grid
    pair<int, int> pos_at_pt(Point pt) { return pair{pt.x / blockSize, pt.y / blockSize}; }

    // Converts a position in the block-grid to a coordinate (point) in the MiniCraftWindow
    Point pt_at_pos(pair<int, int> pos);

     // Functions for changing and drawing the grid
    void addBlock(pair<int, int> pos, BlockType type);
    void drawGrid();
    void removeBlock(pair<int, int> pos);


    //########################## World creation related ###########################################

    void initializeWorld();
    void generateFlatWorld(int surfaceHeight);
    void generateSteepWorld();
    
    //########################## Player related ###########################################

    // Pointer to the player object
    shared_ptr<Player> player;

    // Position of the upper left corner of the player
    Point playerPoint {0,0}; 

    // Call to initialize the player
    void initializePlayer(Point playerPos);

    //Player movement
    void updatePlayer();
    void moveLeft();
    void moveRight();
    void jump();
    void gravity();

    //Helper functions
    bool isPlayerOnGround(Point playerPos);
    bool isPlayerPosLegal(Point playerPos);
    bool inRange(Point pt) const { return pt.x >= 0 && pt.x < gridWidth * blockSize && pt.y >= 0 && pt.y < gridHeight * blockSize; }

    //########################## Inventory related ###########################################

    map <BlockType, int> inventory;

    int handle(int event) override;
    void getMouseInput();

    void obtainBlock(Point pt);
    void placeBlock(Point pt);
    
    // Inventory GUI
    void updateInventoryList();
    Fl_Multiline_Output inventoryList;
    Fl_Choice markedInventoryType;
};
