#include <iostream>
//First Way
int first_way(){
    long long number = 600851475143;
    int i = 3;
    for(;number !=1;i+=2){
        while(number % i == 0)
            number /= i;
    }
    return i - 2;
}



int main() {
    std::cout << first_way() << std::endl;
    return 0;
}
