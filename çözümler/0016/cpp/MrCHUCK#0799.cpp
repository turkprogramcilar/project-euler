#include <iostream>
#include <vector>
using namespace std;
// Soru 2 ** 1000 sayisinin tum basamaklarini topla

int main() {
    vector<int> my_first_vector_KEKW; // 2 ** 1000 icine alicak int olmadigi icin vector kullaniyorum

    my_first_vector_KEKW.push_back(2); // 2 ** 1 ile basliyoruz
    // Ek olarak tersten tutuyorum , ugrasmamak icin , 128 degil ==>> 821 gibi

    for(int i = 1; i < 1000;i++){ // Soruda 2 ** 1000 isteniyor o kadar dongu yapiyoruz
        int elde = 0,temp = 0;//Klasik elle toplama yontemi 5 + 8 = 13 temp burda 3 oluyor elde burda 1 oluyor

        for(int & j : my_first_vector_KEKW){ // TUm vectoru donuyoruz
            temp = j*2 + elde;
            j = temp % 10;
            elde  = temp / 10;
        }


        for(int q = 1;elde != 0;q++){ // Eldeyi yazdiriyorum cunku 10 dan buyuk olabilir
            my_first_vector_KEKW.push_back(elde % 10);
            elde /= 10;
        }
    }

    int answer = 0;
    for(int &j : my_first_vector_KEKW) // Hepsini topluyorum
        answer +=j;
    cout << answer << endl;
    return 0;
}
