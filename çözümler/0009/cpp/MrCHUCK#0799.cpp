#include <iostream>

//First Way
int first_way(){
    for(int i = 500; i > 250 ; i--)
        for(int j = i; j > 100 ; j--)
            if (500 + (float)i * j / 1000 == i + j)
                return  i * j * (1000 - i - j);
}


int main() {

    std::cout << first_way() << std::endl;
    return 0;
}
