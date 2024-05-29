#include "std_lib_facilities.h"

int main(){
	time_t start, end;
    /* You can call it like this : start = time(NULL);
     in both the way start contain total time in seconds 
     since the Epoch. */
    time(&start);
  
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
	bool c=true;
	unsigned long long l=0;
	cout << 2 << endl;
	for(unsigned long long int i = 18446744073709541615; i<1844674407370955161  5; i+=2){
		for(unsigned long long int j = 3; j<=round(sqrt(i)); j+=2){
			if(i%j==0){
				c=false;
				break;
			}
		}
		if(c==true){
			cout << i << "  " << i-l << endl;
			l=i;
		}
		c=true;
	}
  
  
    // Recording end time.
    time(&end);
  
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}