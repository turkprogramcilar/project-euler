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
-- Project Euler Soru 7
-- 12.04.2021

{-
    By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
    that the 6th prime is 13.

    What is the 10 001st prime number?
    
    6. asal sayi 13 oldugunda gore 10.001'inci asal sayi kaçtır?
-}


primes :: [Integer]
primes = 
    let
        limitPrimes :: Integer -> [Integer]
        limitPrimes n = takeWhile (<=isqrtn) primes where
            isqrtn = floor . sqrt . fromIntegral $ n

        ifPrime :: Integer -> Bool
        ifPrime n = all (\a -> (n `mod` a) /= 0) (limitPrimes n)
    in
        2 : filter ifPrime [3, 5..]

main = print $ primes !! (10001 - 1)
