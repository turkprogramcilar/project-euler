#include <iostream>

//First Way
int square_sum_formula(int limit){
    return limit * (limit + 1) * (2 * limit + 1) /6;
}
int sum_square_formula(int limit){
    int sum = limit * ( limit + 1) / 2;
    return sum * sum;
}

int main() {
    std::cout <<  sum_square_formula(100) - square_sum_formula(100)  << std::endl;
    return 0;
}
