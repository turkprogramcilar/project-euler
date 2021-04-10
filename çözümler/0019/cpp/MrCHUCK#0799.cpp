#include <iostream>

int main() {
    int day = 1,count = 0;
    int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for(int year = 1901; year <= 2000;year++){
        if(year % 4 == 0){
            if(year % 400 == 0 || year % 100 != 0){
                month[1] = 29;
            }
        }

        else{
            month[1] = 28;
        }

        for(int x:month){
            day += x;
            day %= 7;
            if(day == 6){
                count++;
            }
        }
    }
    std::cout << count;
    return 0;
}
