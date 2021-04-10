#include <iostream>

int main() {
    long long max = 0,answer = 0;
    for (long long i = 10; i < 1000000 ;i++){

        long long temp = i,count = 0;

        while(temp != 1){

            if(temp % 2 == 0)
                temp /= 2;
            else
                temp = 3 * temp + 1;

            count++;
        }

        if(count > max){
            max = count;
            answer = i;

        }
    }
    std::cout << answer;
    return 0;
}
