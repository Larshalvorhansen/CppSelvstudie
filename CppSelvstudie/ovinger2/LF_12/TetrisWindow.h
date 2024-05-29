#pragma once
#include "AnimationWindow.h"
#include "Tetromino.h"
#include "GUI.h"
#include <thread>
#include <atomic>

class TetrisWindow : public AnimationWindow {

public:
    TetrisWindow();
    void run();

private:
	
    static constexpr int tetrisGridHeight {18};
    static constexpr int tetrisGridWidth {10};
    static constexpr int startRow {1};
    static constexpr int startColumn {tetrisGridWidth/2-1};

    static constexpr int blockSize {Tetromino::blockSize};
    static constexpr Point startPoint {startColumn, startRow};
    static constexpr int sideBarLength = 120;
    static constexpr int sideBarHeight = 50;
    static constexpr int outBoxOffset = 70;

    //Medlemsvariabler
    Tetromino currentTetromino;
    vector<vector<TetrominoType>> gridMatrix;
    
    int score {0};
    bool playing {true};
    bool paused {false};


    //Logiske funksjoner

    void generateRandomTetromino();
    void moveTetrominoDown();
    void fastenTetromino();

    bool tetrominoCrashesAt(Point location);
    bool hasCrashed();

    void handleInput();
    void drawGridMatrix();
    void drawCurrentTetromino();

    void removeFullRows(); 

    //Grafikk og callbacks
    Fl_Output scoreBox;
    Fl_Output highScoreBox;
    
    Fl_Button quitBtn;
    Fl_Button restartBtn;
    Fl_Button pauseBtn;
    
    Rectangle sideBox;

    Rectangle gameEndBackGround;

    static void cb_quit(Fl_Widget*, Address pw) {static_cast<TetrisWindow*>(pw)->lostGame();}
    static void cb_restart(Fl_Widget*, Address pw) {static_cast<TetrisWindow*>(pw)->restartGame();}
    static void cb_pause(Fl_Widget*, Address pw) {static_cast<TetrisWindow*>(pw)->pauseGame();}

    void lostGame();
    void restartGame();
    void pauseGame();
};







