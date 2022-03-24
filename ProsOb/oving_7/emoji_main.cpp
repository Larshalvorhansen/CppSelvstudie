#include "AnimationWindow.h"
#include "Emoji.h"
#include "animal.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	testAnimal();

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};
	SuprisedFace({100,300},emojiRadius).draw(win);
	
	/* TODO:
	 *  - initialiser emojiene
	 *  - Tegn emojiene til vinduet
	 **/

    vector<unique_ptr<Emoji>> v;
    v.emplace_back(new Smilingface{{100,100},emojiRadius});
    v.emplace_back(new SadFace{{300,100},emojiRadius});
    v.emplace_back(new AngryFace{{500,100},emojiRadius});
	v.emplace_back(new SuprisedFace{{300,250},emojiRadius});
    for (int i = 0; i < v.size(); i++)
    {
        v[i]->draw(win);
	}
	win.wait_for_close();
}
