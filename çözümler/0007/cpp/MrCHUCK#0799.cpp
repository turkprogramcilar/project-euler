#include <iostream>
#include <cmath>
bool is_prime(int number){
    double limit = sqrt(number);
    for (int i = 3;i <= limit; i+=2)
        if (number % i == 0)
            return false;
    return true;
}

int first_way(){
    int count = 1,number = 3;
    for(;count != 10001;number+=2)
        if (is_prime(number))
            count++;
    return number - 2;
}

int main() {
    std::cout << first_way() << std::endl;
    return 0;
}
