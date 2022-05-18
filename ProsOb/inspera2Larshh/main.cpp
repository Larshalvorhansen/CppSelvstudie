#include "std_lib_facilities.h"
#include "MiniCraftWindow.h"

void writeToFile(int write){
    ofstream fil;
    fil.open("boat.txt");
    fil << write+"\n";
    cin >> write;
    fil.close();
}

int main()
{
    int c = 0;
    int k = 0;
    int start = 900000003;
    int l = start;
    for (int i = start; i < 1900002003; i+=2)
    {
        for (int j = 3; j < ceil(sqrt(i)); j+=2)
        {
            if (i%j==0)
            {
                c++;
                break;
            }
        }
        ofstream fil;
        fil.open("boat.txt");
        if (c==0)
        {
            cout << i << endl;
            // if(i-l>k){
            //     k=i-l;
            //     fil << k;
            //     fil << "hei";
            // }
            // l = i;
        }
        //fil.close();
        c=0;
    }
    //Alle primtall opp til 1250000003 er funnet
    /*
    srand(static_cast<unsigned int>(time(nullptr)));
    Fl::background(200, 200, 200);
    MiniCraftWindow mw{100, 100, 15, 15};

    //NB! Uncomment this for task 5!
    //mw.playMiniCraft();

    mw.wait_for_close();*/
}