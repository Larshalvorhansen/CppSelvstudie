#include <iostream>
using namespace std;

void play_game(int array[])
{
    cout << sizeof(array) << endl;
}

int main()
{
    int guesses[10] = {12, 43, 23, 43, 23};
    cout << sizeof(guesses) << endl;
    // int num_elements = 5;
    // int size = sizeof(guesses) / sizeof(guesses[0]);
    print_array(guesses);

    return 0;
}