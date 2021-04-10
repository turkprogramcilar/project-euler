#include <iostream>
#include <fstream>
#include "regex"
#include <vector>
using namespace std;
int main() {
    ifstream f;
    f.open(R"(C:\Users\ertug\Desktop\c++\euler\022\p022_names.txt)");
    string x,sum;
    while (f >> x) {
        sum +=x;
    }
    f.close();
    //Yukari kisim dosyayi acip okuma kismi
    regex re{",\\n*"};
    vector<string> nalet_olasi_split_yok{
            sregex_token_iterator(sum.begin(), sum.end(), re, -1),
            sregex_token_iterator()
    };
    //yukarda parcaladim
    sort(nalet_olasi_split_yok.begin(), nalet_olasi_split_yok.end());//Siraladim
    int i = 1,answer = 0;
    for(string &y : nalet_olasi_split_yok){
        y = y.substr(1, y.size()-2);//Tirnaklari attim
        int temp = 0;
        for(int q : y)
            temp += q-64;
        answer += temp * i;
        i++;
    }
    cout << answer;

    return 0;
}
