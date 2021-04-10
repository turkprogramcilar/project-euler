#include <iostream>
#include <string>

//First Way
bool is_palindrom(int number){
    std::string str_number = std::to_string(number);
    int length = str_number.length();
    for(int i = 0;i <length;i++)
        if(str_number[i]!=str_number[length-i-1])
            return false;
    return true;
}

int first_way(){
    int answer = 0;
    for ( int i = 999; i > 100; i--){
        for(int j = i; j > 100 ;j--){
            int temp = i*j;
            if (is_palindrom(temp)){
                if (temp > answer)
                    answer = temp;
                break;
            }
        }
    }
    return answer;
}




int main(){

    std::cout << first_way() << std::endl;
    return 0;
}
