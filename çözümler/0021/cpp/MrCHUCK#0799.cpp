#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int number){
    if(number < 2 )
        return false;
    if(number == 2)
        return true;
    else if(number % 2 == 0)
        return false;
    else{
        for(int odd = 3; odd <= pow(number,0.5); odd+=2)
            if (number % odd == 0)
                return false;
    }
    return true;
}


int find_sum_factor(int number,vector<int> *prime){
    double top = 1,bottom = 1,copy = number;

    for(int x: *prime){
        int temp = 0;
        while(number % x == 0){
            number /= x;
            temp++;
        }

        if(temp){
            top *= pow(x,++temp) - 1;
            bottom *= --x;
        }
    }

    if(number != 1){
        top *= number * number - 1;
        bottom *= number - 1;
    }
    return (int)(top / bottom - copy);
}


int main() {
    vector<int> primes;
    primes.push_back(2);

    for(int i = 3;i < 100;i+=2)
        if(is_prime(i))
            primes.push_back(i);

    int answer = 0;
    for(int i = 2;i < 10000;i++){
        int temp = find_sum_factor(i,&primes);
        if(find_sum_factor(temp,&primes) == i && temp != i)
            answer += i;

    }
    cout << answer;
    return 0;
}
