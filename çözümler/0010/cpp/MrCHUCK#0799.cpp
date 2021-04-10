#include <iostream>
#include <cstring>

using namespace std;

//First Way
long long first_way(int limit){
    long long answer = 0;

    bool* prime = (bool*)malloc(sizeof(bool)*(limit + 1));
    memset(prime,true,sizeof(bool) * (limit + 1));

    for (int x = 2; x * x <= limit ; x++){
        if(prime[x]){
            for(int temp = x * x;temp <= limit;temp += x){
                prime[temp] = false;
            }
        }
    }
    for(int i = 2; i < limit + 1;i++){
        if (prime[i])
            answer += i;
    }
    return answer;
}

int main() {
    std::cout << first_way(2000000) << std::endl;
    return 0;
}
