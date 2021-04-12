{-
Türk Programcılar Discord sunucusu kullanıcıları tarafından gönderilen 
Project Euler soru çözümleri

Türk Programcılar discord sunucusu programlamaya yeni başlayan ve her seviyeden 
insanlara yardım etmeyi hedefleyen bireylerin toplantığı bir platformdur.
Birbirimizi motive ettiğimiz, her gün yeni birşeyler öğrenmeye teşvik ettiğimiz
sunucumuzda; kodlama yarışmaları ve eğlenceli birçok diğer 
aktiviteleri de keşvedebilirsin.

Hemen aramıza katıl!

https://disboard.org/server/698972054740795453

-}

-- Çözüm: 0xdeadc0de#9615
-- Project Euler Soru 6
-- 12.04.2021

{-
    The sum of the squares of the first ten natural numbers is 385
    The square sum of the first ten natural numbers is 3025
    Hence the difference is 3025 - 385 = 2640

    Find the difference between the sum of the squares of the first one hundred
    natural numbers and the square of the sum

    Ilk 10 sayinin karelerinin toplami 385dir
    Ilk 10 sayinin toplaminin karesi 3025dir
    Aradaki fark ise 2640dir

    Bu farki ilk 100 sayi icin bulunuz
-}

{-
    https://en.wikipedia.org/wiki/Summation
    A(n) = ( n(n+1)/2 )^2

    https://en.wikipedia.org/wiki/Square_pyramidal_number
    B(n) = n(n+1)(2n+1)/6

    A(n) - B(n) = R(n), R burada sonuç fonksiyonumuz

    ( n^4 + 2n^3 + n^2 ) /4 - ( 2n^3 + 3n^2 + n) /6 = R(n)
    ( 3n^4 + 2n^3 - 3n^2 - 2n ) / 12 = R(n)
-}

r :: Int -> Int
r n = f `div` 12 where
    f = foldl (\b a -> n * (a + b) ) 0 [3, 2, -3, -2]

main = print $ r 100