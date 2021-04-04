"""
Türk Programcılar Discord sunucusu kullanıcıları tarafından gönderilen 
Project Euler soru çözümleri

Türk Programcılar discord sunucusu programlamaya yeni başlayan ve her seviyeden 
insanlara yardım etmeyi hedefleyen bireylerin toplantığı bir platformdur.
Birbirimizi motive ettiğimiz, her gün yeni birşeyler öğrenmeye teşvik ettiğimiz
sunucumuzda; kodlama yarışmaları ve eğlenceli birçok diğer 
aktiviteleri de keşvedebilirsin.

Hemen aramıza katıl!

https://disboard.org/server/698972054740795453

"""

# Çözüm: Ockis#2746
# Project Euler Soru 3
# 04/04/2021
"""
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
"""
# Soru Türkçe çevirisi
"""
13195'in asal bileşenleri 5, 7, 13 ve 19 olduğuna göre
600851475143 sayısının en büyük asal bileşeni kaçtır?
"""

# bulunan asal sayılar dizisi
asallar = [2, 3]

def asal_mi(sayi, asallar):
    karekok = sayi ** (1/2)
    # 5 * 5 = 25
    # 5
    # 2 3 5 <=
    i = 0
    while asallar[i] <= karekok:
        if sayi % asallar[i] == 0:
            return False
        i += 1

    return True

def asal_bul(liste):
    # son asal
    a = liste[-1]
    a+=2
    while asal_mi(a, liste) == False:
        a+=2
    return a

# asal iterator gibi birsey
def asal_al(i, liste):

    if i < len(asallar):
        return asallar[i]

    else:
        fark = i-len(asallar)
        for x in range(fark+1):
            asal = asal_bul(liste)
            asallar.append(asal)
        return asal


# en buyuk faktoru bul
def bul(sayi):
    i = 0
    while True:
        asal = asal_al(i, asallar)
        # bu asal sayinin bir asal faktoru mu
        # 2 2 3 5 5 5 7
        if sayi % asal == 0:
            sayi /= asal
            if sayi == 1:
                return asallar[i]
            continue
        i += 1


sayi = 600851475143

a = bul(sayi)
print (a)