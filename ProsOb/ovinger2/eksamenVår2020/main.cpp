#include "std_lib_facilities.h"

void add_to_vector(vector<int> v, int n){
    v.push_back(n);
}

int main()
{
    vector<int> vec{3};
    add_to_vector(vec&, 5);
    for(auto v : vec){
        cout << v << endl;
    }
    return 0;
}