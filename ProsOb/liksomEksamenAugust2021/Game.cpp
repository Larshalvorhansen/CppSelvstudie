#include "Game.h"

Game::Game(int board_size, int win_value)
	: board_size(board_size),
	  board(board_size * board_size),
	  win_value{win_value}
{
	new_game();
}

// TASK
int Game::index(int x, int y) const
{
	// BEGIN: G1
	return board_size*(y)+x;
	// END: G1
}

// TASK
int Game::at(int x, int y) const
{
	// BEGIN: G2
	
	if(x<0||y<0||x>board_size-1||y>board_size-1){
		cout << "unvalid coordinate" << endl;
		return 0;
	}
	return Game::index(x,y);
	// END: G2
};

// TASK
int& Game::at(int x, int y)
{
	// BEGIN: G3
	if(x<0||y<0||x>board_size-1||y>board_size-1){
		cout << "unvalid coordinate" << endl;
		//return 0;
	}
	return board[index(x,y)];
	// END: G3
}

// TASK
void Game::new_game()
{
	// BEGIN: G4
	for(int i = 0; i<board_size*board_size; i++){
		board[i]=0;
	}
	place_new_2();
	place_new_2();
	// END: G4
}

// TASK
// Prerequisites: board does have a free 0-spot
void Game::place_new_2()
{
	// BEGIN: G5
	while(true){
		int r = rand() % (board_size*board_size);   
		if (board[r]==0){
			board[r]=2;
			break;
		}
	}
	// END: G5
}

// TASK
void Game::flip()
{
	// BEGIN: G6
	std::vector<int> board2;
	for(int j = 0; j < board_size; j++){//ittererer igjennom hver rad
		for(int i = 0; i < board_size; i++){//speiler hver enkelt rad horistontalt og setter inn i en ny vektor board2
			board2[(board_size-1-i)+4*j]=board[i+4*j];
		}
	}
	for(int i = 0; i < board_size*board_size; i++){//Setter board lik board2
		board[i]=board2[i];
	}
	
	// END: G6
}

// TASK
void Game::transpose()
{
	// BEGIN: G7
	for(int x = 0; x < board_size; x++){
		for(int y = 0; y < board_size; y++){
			std::swap(at(x,y),at(y,x));
		}
	}
	// END: G7
}

// TASK
void Game::push_right()
{
	// BEGIN: G8
	for(int i = 0; i<board_size; i++){//Gjør alt dette board_size antall ganger for å forsikre at tom ekstremtillfellet [2,0,0,0] blir flyttet helt til høyre
		for(int y = 0; y < board_size; y++){//itterer igjennom hver rad
			for(int x = 0; x < board_size; x++){//itterer igjennom hver kolonne
				if(at(x,y)!=0){//Sjekker om cellen har et tall
					if(at(x+1,y)==0){//Sjekker om cellen til høyre er tom
						std::swap(at(x,y),at(x+1,y));//bytter plass på cellen med tal til venstre og den tomme cellen til høyre
					}
				}
			}
		}
	}
	// END: G8
}

// TASK
void Game::merge_right()
{
	// BEGIN: G9
	for(int i = 0; i<board_size; i++){//Gjør alt dette board_size antall ganger for å forsikre at tom ekstremtillfellet [2,0,0,0] blir flyttet helt til høyre
		for(int y = 0; y < board_size; y++){//itterer igjennom hver rad
			for(int x = 0; x < board_size; x++){//itterer igjennom hver kolonne
				if(at(x,y)!=0){//Sjekker om cellen har et tall
					if(at(x+1,y)==at(x,y)){//Sjekker om cellen til høyre er lik cellen til venstre
						at(x+1,y)=2*at(x+1,y);//Summerer cellene som er det samme som å gange cellen med 2
						at(x,y)=0;//Setter den venstre cellen lik null
					}
				}
			}
		}
	}
	// END: G9
}

// TASK
void Game::move_right()
{
	// BEGIN: G10
	push_right();
	merge_right();
	push_right();
	// END: G10
}

// TASK
void Game::move_down()
{
	// BEGIN: G11
	for(int i = 0; i<board_size; i++){//Gjør alt dette board_size antall ganger for å forsikre at tom ekstremtillfellet [2,0,0,0] blir flyttet helt til høyre
		for(int y = 0; y < board_size; y++){//itterer igjennom hver rad
			for(int x = 0; x < board_size; x++){//itterer igjennom hver kolonne
				if(at(x,y)!=0){//Sjekker om cellen har et tall
					if(at(x+1,y)==at(x,y)){//Sjekker om cellen til høyre er lik cellen til venstre
						at(x+1,y)=2*at(x+1,y);//Summerer cellene som er det samme som å gange cellen med 2
						at(x,y)=0;//Setter den venstre cellen lik null
					}
				}
			}
		}
	}
	// END: G11
}

// TASK
void Game::move_left()
{
	// BEGIN: G12
	// END: G12
}

// TASK
void Game::move_up()
{
	// BEGIN: G13
	// END: G13
}

// TASK
bool Game::free_spots() const
{
	// BEGIN: G14
	return true;
	// END: G14
}

// TASK
void Game::tick()
{
	// BEGIN: G15
	// END: G15
}

// TASK
bool Game::win() const
{
	// BEGIN: G16
	(void)win_value;
	return false;
	// END: G16
}

// TASK
// Prerequisites: all tiles are non-zero
bool Game::legal_moves() const
{
	// BEGIN: G17
	return false;
	// END: G17
}



/**** Provided code ****/

// API version of tile value - const external interface
int Game::value(int x, int y) const { return at(x, y); }

// This function keeps track of changes to the board
// and calls the move function requested by the player
void Game::move(Direction direction)
{
	// We have not moved any tiles yet
	moved = false;

	// Keep the old board matrix for comparison
	std::vector<int> old_board{board};

	if (status() == Status::playing) {
		switch (direction) {
		case Direction::up:
			move_up();
			break;
		case Direction::right:
			move_right();
			break;
		case Direction::down:
			move_down();
			break;
		case Direction::left:
			move_left();
			break;
		}
	}

	// Did we move anything?
	if (board != old_board) {
		moved = true;
	}

	tick();
}

// We use this to figure out if a game
// is won, game over or if the player still
// can play legal moves
Game::Status Game::status() const
{
	if (win()) {
		return Status::win;
	}

	if (free_spots() || legal_moves()) {
		return Status::playing;
	}

	return Status::game_over;
}

bool Game::game_over() const { return status() == Status::game_over; }

std::ostream& operator<<(std::ostream& os, const Game& g)
{
	for (int i = 0; i < g.board_size; ++i) {
		for (int j = 0; j < g.board_size; ++j) {
			std::cout << g.at(j, i) << " ";
		}
		std::cout << '\n';
	}

	return os;
}

// Debug methods - debug API
void Game::debug_all_twos()
{
	static const std::array<int, 16> debug_board_all_twos{
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

	std::copy(debug_board_all_twos.begin(),
	          debug_board_all_twos.end(), 
	          board.begin());
	tick();
}

void Game::debug_increasing()
{
	static const std::array<int, 16> debug_board_increasing{
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

	std::copy(debug_board_increasing.begin(),
	          debug_board_increasing.end(),
	          board.begin());
	tick();
}

void Game::debug_push_merge()
{
	// clang-format off
	static const std::array<int, 16> debug_board_push_merge{
		2,0,2,0,
		0,2,2,4,
		0,2,2,2,
		8,8,8,8
	};
	// clang-format on

	std::copy(debug_board_push_merge.begin(),
	          debug_board_push_merge.end(),
	          board.begin());
	tick();
}

void Game::debug_flip() { flip(); }
void Game::debug_transpose() { transpose(); }

