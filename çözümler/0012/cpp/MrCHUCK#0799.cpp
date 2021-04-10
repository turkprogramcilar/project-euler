#include <iostream>
#include <cmath>
//First Way
int get_divisors(int number){
    double limit = sqrt(number);
    int divisors = 0;
    while (number % 2 == 0){
        number /= 2;
        divisors++;
    }
    divisors++;
    for(int i = 3; i < limit;i+=2){
        int temp = 0;
        while (number % i == 0){
            number /= i;
            temp++;
        }
        divisors *= ++temp;
    }
    if (number!=1)
        divisors *=2;
    return divisors;

}

int main() {
    int number = 28;
    for(int i = 8; get_divisors(number)< 500;i++){
        number +=i ;
    }
    std::cout << number << std::endl;
    return 0;
}
