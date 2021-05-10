from math import log


def M(p : int, q : int, number : int, limit : int)  :
    """Asal faktorleri sadece p ve q olan verilen limitten kucuk en buyuk sayiyi bulur"""
    
    
    # Limite en yakin carpim =  temp * number 
    temp = limit // number
    
    # Limite en yakin caprimin icinde olabilcek tekli asal faktor katlari
    # Ve onu numara ile caprpiyoruz
    temp_p = number * p ** int(log(temp,p))
    temp_q = number * q ** int(log(temp,q))
    
    #Aralarindan maximumu aliyoruz
    return max( max(temp_p, temp_q), M(p, q, number * p, limit) if number * p < limit else 0)


def sieve_with_M(limit : int):
    
    # Bulmamniz gerek assalar verilen limitin yarisi kadar
    prime_limit = limit // 2
    
    # Verilen limiite ici dolu liste olusturuyoruz
    primes = [True] * prime_limit
    
    # Index 0 ve 1 Asal degil o yuzde False yapiyoruz
    primes[0:1] = False,False
    
    # TUm cift indexleri sifirliyoruz 2 haric
    primes[4::2] = ((prime_limit - 4) // 2 + 1) * [False]
    
    for i in range(3, int(prime_limit ** 0.5) + 1, 2):
        
        # Siradaki index bos ise devam et
        if not primes[i]:
            continue
        
        #Dolu ise tum katlarini bosalt
        for j in range(i * i, prime_limit, i):
            primes[j] = False
    
    # Simdi sirayla indexlerdeki asallari bulup M ' leri bulucaz
    find = [2]
    
    #M'lerin toplami
    total = 0
    
    for x in range(3,prime_limit,2):
        
        # Index dolumu kontrol
        if primes[x]:
            
            # Bulunan tum asallar ile M bul
            for pr in find:
                
                # Eger ki limiti gecmisse birak yeni asala gec
                if pr * x > limit:
                    break
                
                total += M(pr, x, pr * x , limit)
            
            # Bulunan asallara ekle
            find.append(x)

    return total

print(sieve_with_M(10_000_000))
