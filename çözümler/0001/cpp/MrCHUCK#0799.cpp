#include <iostream>
//First Way
int first_way(){
    int answer = 0;
    for(int i = 0; i < 1000;i++){
        if ( i % 3 == 0 || i % 5 == 0)
            answer += i;
    }
    return answer;
}

//Second Way
int formula(int first,int last,int sub){
    int terms = (last - first) / sub + 1;
    return terms * (first + last) / 2;
}

int second_way(){
    return formula(3,999,3) + formula(5,995,5) - formula(15,990,15);
}


int main() {

    std::cout << first_way() << std::endl;
    std::cout << second_way() << std::endl;
    return 0;
}
