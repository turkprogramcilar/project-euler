#include <iostream>
#include <vector>
#include <set>
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

    for(int i = 3;i < 175;i+=2)
        if(is_prime(i))
            primes.push_back(i);

    vector<int> abundant;
    for(int i = 2;i < 28123;i++) {
        int temp = find_sum_factor(i, &primes);
        if (temp > i)
            abundant.push_back(i);

    }
    set<int> final;
    for(int i = 0;i < abundant.size();i++){
        for (int j = i; j < abundant.size(); j++){
            int temp = abundant[i]+abundant[j];
            if(temp > 28124)
                break;
            final.insert(temp);
            }

        }
    int answer = 0;
    for(int x:final)
        answer +=x;
    cout << 28125*28124/2 - answer;
    return 0;
}
