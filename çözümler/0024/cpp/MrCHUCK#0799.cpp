#include <iostream>
#include <algorithm>
using namespace std;


int main () {
    int myints[] = {0,1,2,3,4,5,6,7,8,9};
    int count = 0;
    do {
        count++;
    } while (count != 1000000 && next_permutation(myints,myints +10 ) );

    for(int x : myints)
        cout << x;
    return 0;
}
