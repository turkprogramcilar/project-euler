#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> my_first_vector_KEKW;

    my_first_vector_KEKW.push_back(2);

    for(int i = 3; i < 100; i++){
        int elde = 0,temp = 0;

        for(int & j : my_first_vector_KEKW){
            temp = j * i + elde;
            j = temp % 10;
            elde  = temp / 10;
        }


        for(int q = 1; elde != 0; q++){
            my_first_vector_KEKW.push_back(elde % 10);
            elde /= 10;
        }
    }

    int answer = 0;
    for(int &j : my_first_vector_KEKW)
        answer += j;

    cout << answer << endl;
    return 0;
}
