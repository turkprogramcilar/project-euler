/*
Türk Programcılar Discord sunucusu kullanıcıları tarafından gönderilen 
Project Euler soru çözümleri

Türk Programcılar discord sunucusu programlamaya yeni başlayan ve her seviyeden 
insanlara yardım etmeyi hedefleyen bireylerin toplantığı bir platformdur.
Birbirimizi motive ettiğimiz, her gün yeni birşeyler öğrenmeye teşvik ettiğimiz
sunucumuzda; kodlama yarışmaları ve eğlenceli birçok diğer 
aktiviteleri de keşvedebilirsin.

Hemen aramıza katıl!

https://disboard.org/server/698972054740795453

*/

// Çözüm: 0xdeadc0de#9615
// Project Euler Soru 5
// 11.04.2021

/*
    2520 is the smallest number that can be divided by each of the numbers from 
    1 to 10 without any remainder. What is the smallest positive number that is 
    evenly divisible by all of the numbers from 1 to 20?

    2520 sayısı 1den 10a kadar olan sayılara kalansız bölünebilen en küçük
    sayıdır. 1den 20ye kadar sayılara tam olarak bölünebilen en küçük sayı
    kaçtır?
*/

#include <iostream>
#include <vector>

uint64_t gcd(uint64_t a, uint64_t b);

// least common multiple -> ortak katlarin en kucugu
// https://en.wikipedia.org/wiki/Least_common_multiple
uint64_t lcd(uint64_t a, uint64_t b) {

    // |a * b| / OBEB (a, b)
    std::cout << "a: " << a << " b: " << b << std::endl;
    uint64_t m = (a > b ? a : b) / gcd(a, b);
    m *= (a < b ? a : b);
    return m;
}

// greatest common divisor -> ortak bölenlerin en büyüğü
// https://en.wikipedia.org/wiki/Greatest_common_divisor
uint64_t gcd(uint64_t a, uint64_t b) {
    
    // Öklit algoritması:
    // birbirine eşit olmayan a ve b pozitif sayıları için a ve b nin EBOB u
    // a - b ile b nin ortak bölenine eşittir
    if (a == b) 
        return a;
    else
        return gcd(a > b ? a - b : b - a, a > b ? b : a);
}

uint64_t reduce_lcd(std::vector<uint64_t> numbers) {
    
    if (numbers.empty())
        return 0;
    else {
        auto sz = numbers.size();
        if (sz == 1) {
            return numbers.at(0);
        }
        else {
            std::vector<uint64_t> new_numbers;
            
            if (sz % 2 != 0) {
                new_numbers.push_back(
                  numbers.at(sz-1)  
                );
            }
            for (auto i = 0; i < sz/2; i++) {
                new_numbers.push_back(
                    lcd(numbers.at(i*2), numbers.at(i*2+1)) );
            }

            return reduce_lcd(new_numbers);
        }
    }
}

int main() {
    std::vector<uint64_t> v =
        {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    auto r = reduce_lcd(v);
    std::cout << r;
}