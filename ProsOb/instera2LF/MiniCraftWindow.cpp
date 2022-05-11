#include "MiniCraftWindow.h"
#include <cmath>

MiniCraftWindow::MiniCraftWindow(int x, int y, int gridWidth, int gridHeight)
    : AnimationWindow{x, y, gridWidth * blockSize + widgetWidth * 4, gridHeight * blockSize, "MiniCraft"},
    gridWidth{gridWidth}, gridHeight{gridHeight},
    inventoryList{gridWidth * blockSize + blockSize + widgetWidth, 0, widgetWidth + widgetWidth / 2, widgetHeight, "Inventory"},
    markedInventoryType{gridWidth * blockSize + widgetWidth * 3, 0, widgetWidth, widgetHeight, ""}
    
    
{
    // Initialize the world to the correct size
    initializeWorld();

    // Add and activate the GUI elements
    add(inventoryList);
    add(markedInventoryType);
   
    /**
        You can call functions in the block below
    */

    // START OF BLOCK

    // testBlockCreation(); // 3 c)

    //generateFlatWorld(); //4 a)
    generateSteepWorld(); //4 b)

    initializePlayer({30,0}); //5 a)

    // END OF BLOCK
}

//########################## Game loop ###########################################

// The game loop
// Constantly called to handle user input and redraw the game window
// You do not have to change anything in this function
void MiniCraftWindow::playMiniCraft()
{
    keep_previous_frame(false);
    while (!this->should_close())
    {
        this->next_frame();
        updatePlayer();
        drawGrid();
    }
}

//########################## Test function ###########################################

// Creates a test world with two blocks, figure 2.
void MiniCraftWindow::testBlockCreation()
{
    pair<int, int> block1pos{2, 2};
    pair<int, int> block2pos{3, 4};

    addBlock(block1pos, BlockType::Grass);
    addBlock(block2pos, BlockType::Stone);

    block_at_pos(block1pos)->draw(*this, pt_at_pos(block1pos));
    block_at_pos(block2pos)->draw(*this, pt_at_pos(block2pos));
}

//########################## Grid related ###########################################


// TASK
Point MiniCraftWindow::pt_at_pos(pair<int, int> pos)
{
    // BEGIN: 3a
    return Point{pos.first * blockSize, pos.second * blockSize};
    // END: 3a
}

// TASK
void MiniCraftWindow::addBlock(pair<int, int> pos, BlockType type)
{
    // BEGIN: 3b
    block_at_pos(pos) = make_shared<Block>(type);
    // END: 3b
}

// TASK
void MiniCraftWindow::drawGrid()
{
    // BEGIN: 3d
    for (int height = 0; height < gridHeight; height++)
    {
        for (int width = 0; width < gridWidth; width++)
        {
            shared_ptr<Block> block = block_at_pos({width, height});
            if (block)
            {
                block->draw(*this, pt_at_pos({width, height}));
            }
        }
    }
    // END: 3d
}


// TASK
void MiniCraftWindow::removeBlock(pair<int, int> pos)
{
    // BEGIN: 3e
    block_at_pos(pos) = nullptr;
    // END: 3e
}

//########################## World creation related ###########################################

// Initializes the game to the correct size
void MiniCraftWindow::initializeWorld()
{
    blockGrid = vector<shared_ptr<Block>>(gridWidth * gridHeight);
}


// TASK
void MiniCraftWindow::generateFlatWorld(int surfaceHeight)
{
    // BEGIN: 4a
    BlockType type = BlockType::Grass;
    for (int height = gridHeight - surfaceHeight; height < gridHeight; height++)
    {
        for (int width = 0; width < gridWidth; width++)
        {
            addBlock({width, height}, type);
        }
        type = BlockType::Stone;
    }
    // END: 4a
}


// TASK
void MiniCraftWindow::generateSteepWorld()
{
    // BEGIN: 4b
    int height = 3 + rand() / (gridHeight - 5); // Choose a start location. Can be done in many ways
    for (int column = 0; column < gridWidth; ++column)
    {
        height += (rand() % 5) - 2; // Between -2 and +2
        if (height < 3)
            height = 3;
        if (height > gridHeight - 2)
            height = gridHeight - 3;
        BlockType bType = BlockType::Grass;
        for (int row = height; row < gridHeight; ++row)
        {
            addBlock({column, row}, bType);
            bType = BlockType::Stone;
        }
    }
    // END: 4b
}

//########################## Player related ###########################################

// TASK
void MiniCraftWindow::initializePlayer(Point playerPos)
{
    // BEGIN: 5a
    player = make_shared<Player>(Player());
    playerPoint = playerPos;
    // END: 5a
}

// Wrapper function for player movement
// The function draws the player, if the player exists
// This function is already called in the game loop function playMiniCraft()
// Functions called in this function will therefore constantly be called
// Call the functions from task 5 b,c,d,e here when they are implemented
void MiniCraftWindow::updatePlayer()
{
    
    if(player != nullptr){
        /**
            You can call functions in the block below
        */
        // START OF BLOCK

        gravity();
        moveLeft();
        moveRight();
        jump();

        // END OF BLOCK

        // This function call draws the player, if it exist
        player->draw(*this, playerPoint);
    }

    
    
    
}


// TASK
void MiniCraftWindow::gravity()
{
    // BEGIN: 5b
    if (!isPlayerOnGround(playerPoint))
    {
        Point newPoint = playerPoint;
        newPoint.y += 3 * 2;

        if (isPlayerPosLegal(newPoint))
        {
            playerPoint = newPoint;
        }
    }
    // END: 5b
}

// TASK
void MiniCraftWindow::moveRight()
{
    // BEGIN: 5c
    if (is_key_down(KeyboardKey::RIGHT))
    {
        Point newPoint = playerPoint;
        newPoint.x += 2;

        if (isPlayerPosLegal(newPoint))
        {
            playerPoint = newPoint;
        }
    }
    // END: 5c
}

// TASK
void MiniCraftWindow::moveLeft()
{
    // BEGIN: 5d
    if (is_key_down(KeyboardKey::LEFT))
    {
        Point newPoint = playerPoint;
        newPoint.x -= 2;

        if (isPlayerPosLegal(newPoint))
        {
            playerPoint = newPoint;
        }
    }
    // END: 5d
}

// TASK
void MiniCraftWindow::jump()
{
    // BEGIN: 5e
    if (is_key_down(KeyboardKey::UP) && isPlayerOnGround(playerPoint))
    {
        Point newPoint = playerPoint;
        newPoint.y -= blockSize * 3;
        if (isPlayerPosLegal(newPoint))
        {
            playerPoint = newPoint;
        }
    }
    // END: 5e
}

// To be used in task 5 b)
// Returns true if a player located in playerPos touches the ground
// Returns false otherwise
bool MiniCraftWindow::isPlayerOnGround(Point playerPos)
{
    for (int i = 0; i < 2; i++)
    {
        Point point = Point{playerPos.x + i * playerWidth - 1, playerPos.y + playerHeight};
        if (!inRange(point))
        {
            return true;
        }
        if (block_at_pt(point) != nullptr)
        {
            return true;
        }
    }
    return false;
}

// To be used in task 5 c,d,e)
// Returns true if playerPos correspond a legal player position.
// Returns false otherwise
bool MiniCraftWindow::isPlayerPosLegal(Point playerPos)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            Point point = Point{playerPos.x + i * (playerWidth - 1), playerPos.y + j * playerHeight - 1};

            if (!inRange(point))
            {
                return false;
            }

            if (block_at_pt(point) != nullptr)
            {
                return false;
            }
        }
    }
    return true;
}

//########################## Inventory related ###########################################

// Overloads the FLTK handle() function
// You do NOT have to understand this function
int MiniCraftWindow::handle(int event)
{
    // Handle a potential mouse click
    if (event == FL_PUSH)
    {
        getMouseInput();
    }

    // Secures that we do not overwrite existing functionality 
    return AnimationWindow::handle(event);
}

// Called by the handle function. Handles what to do when the mouse is clicked.
void MiniCraftWindow::getMouseInput()
{

    Point p = get_mouse_coordinates();
    MouseButton mb = static_cast<MouseButton>(Fl::event_button());

    switch (mb)
    {
    case MouseButton::left:
        obtainBlock(p); // If the left mouse button is pushed, obtainBlock(p) is called
        break;
    case MouseButton::right:
        placeBlock(p); // If the right mouse button is pushed, placeBlock(p) is called
        break;
    default:
        break;
    }
    updateInventoryList(); // Updating the graphics
}

void MiniCraftWindow::obtainBlock(Point pt)
{
    //BEGIN: 6a
    shared_ptr<Block> block = block_at_pt(pt);
    if (block != nullptr)
    {
        BlockType bType = block->getBlockType();

        if (!inventory.count(bType)){
            markedInventoryType.add(BlockTypeToStringMap.at(bType).c_str());
        }
        inventory[bType]++;

        pair<int, int> pos = pos_at_pt(pt);
        removeBlock(pos);
    }
    //END: 6a
}

void MiniCraftWindow::updateInventoryList()
{
    //BEGIN: 6b
    stringstream ss;
    for (auto elem : inventory)
    {
        ss << BlockTypeToStringMap.at(elem.first) << ": " << elem.second << '\n';
    }
    inventoryList.value(ss.str().c_str());
    inventoryList.show();
    //END: 6b
}

void MiniCraftWindow::placeBlock(Point pt)
{
    //BEGIN: 6c
    pair<int, int> pos = pos_at_pt(pt);
    
    if (block_at_pos(pos) == nullptr)
    {
        int markedPos = markedInventoryType.value();
        if(markedPos != -1) {
            string blockTypeText = markedInventoryType.text(markedPos);
            BlockType type = StringToBlocktypeMap.at(blockTypeText);

            inventory[type]--;
            addBlock(pos, type);

            if(inventory.at(type) <= 0){
                inventory.erase(type);

                markedInventoryType.remove(markedPos);
                markedInventoryType.show();
            }
            
        }
        
    }
    //END: 6c
}

