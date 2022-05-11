#include "std_lib_facilities.h"
#include "MiniCraftWindow.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	Fl::background(200, 200, 200);
	MiniCraftWindow mw{100, 100, 15, 15};

	//
	mw.playMiniCraft();

}