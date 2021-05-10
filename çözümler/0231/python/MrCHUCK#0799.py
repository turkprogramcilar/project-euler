def prime_count(factorial : int,p : int):
    """Verilen faktoriyeldeki icindeki p asal faktor sayisini bulur"""
    if factorial < p :
        return 0
    
    factorial //= p
    return factorial + prime_count(factorial,p)


def sieve_with_prime_count(top,down):
    
    # Verilen limiite ici dolu liste olusturuyoruz
    primes = [True] * top
    
    # Index 0 ve 1 Asal degil o yuzde False yapiyoruz
    primes[0:1] = False,False
    
    # TUm cift indexleri sifirliyoruz 2 haric
    primes[4::2] = ((top - 4) // 2 + 1) * [False]

    for i in range(3, int(top ** 0.5) + 1, 2):
        
        # Siradaki index bos ise devam et
        if not primes[i]:
            continue
    
        #Dolu ise tum katlarini bosalt
        for j in range(i * i, top, i):
            primes[j] = False
    
    
    total = 2 * (prime_count(top,2) - prime_count(down,2) - prime_count(top - down,2))
    
    for x in range(3,top,2):
        if not primes[x]:continue
        
        total += x  * (prime_count(top,x) - prime_count(down,x) - prime_count(top - down,x))
    return total

print(sieve_with_prime_count(20_000_000,15_000_000))
