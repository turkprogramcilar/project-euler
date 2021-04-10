#include <iostream>
//First Way
int first_way(int first,int second){
    int answer = 0;
    while (second < 4000000){
        if (second % 2 == 0)
            answer += second;
        int temp = second;
        second +=first;
        first = temp;

    }
    return answer;
}

//SecondWay
int second_way(int first,int second){
    int answer = 0,count = 2;

    while (second < 4000000){
        if (count == 3){
            count = 0;
            answer += second;
        }
        count++;
        int temp = second;
        second +=first;
        first = temp;

    }
    return answer;
}

int main() {
    std::cout <<first_way(1,1) << std::endl;
    std::cout <<second_way(1,1) << std::endl;
    return 0;
}
