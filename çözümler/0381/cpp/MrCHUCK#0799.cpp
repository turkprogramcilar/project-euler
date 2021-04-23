#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    bool * primes = new bool[100000001];
    memset(primes,true,sizeof(bool) * 100000001);
    for(long i = 4; i < 100000001;i+=2)
        primes[i] = false;

    for(long i = 3;i <10001;i+=2 )
        if(primes[i])
            for(long j = i * i; j < 100000001;j+=i)
                primes[j] = false;
    long long total = 0;
    for(long i = 5; i < 100000001;i+=2)
    {
        if(!primes[i])
            continue;
        long temp1,temp2,temp3 = i / 2;
        if(temp3 % 3 == 0)
            temp2 = i - temp3/3;
        else
            temp2 = (i - temp3)/3;
        temp1 = i - temp2;

        if (temp1 % 4 == 0)
            temp1 /= 4;
        else if ((temp1 + i) % 4 == 0)
            temp1 = (temp1 + i) / 4;
        else if ((temp1 + i * 2) % 4 == 0)
            temp1 = (temp1 + i * 2) / 4;
        else
            temp1 = (temp1 + i * 3) / 4;
        total += (temp1 + temp2 + temp3) % i;
    }
    cout << total << endl;
    return 0;
}
