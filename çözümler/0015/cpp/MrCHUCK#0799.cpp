#include <iostream>

int main() {
    long long answer = 1;

    for (int i = 40; i > 20;i-=2)
        answer *= (i - 1) *  2;

    for(int i = 1; i < 11; i++)
        answer /= i;

    std::cout << answer << std::endl;
    return 0;
}
