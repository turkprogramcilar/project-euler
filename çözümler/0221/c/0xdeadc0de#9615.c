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
// Project Euler Soru 221
// 03/05/2021

/*
We shall call a positive integer A an "Alexandrian integer", if there exist 
integers p, q, r such that:

A = p x q x r

and

1/A = 1/p + 1/q + 1/r

For example, 630 is an Alexandrian integer (5, -7, -18)
In fact, 630 is the 6th Alexandrian integer, 
the first 6 Alexandrian integers being: 6, 42, 120, 156, 420, and 630.

Find the 150000th Alexandrian integer.
*/

/*
Aşağıdaki koşulları sağlayan pozitif A sayılarına iskenderci(açım) 
sayılar diyeceğiz

A = p x q x r

1/A = 1/p + 1/q + 1/r

Mesela 630 iskenderci bir sayıdır (5, -7, -18)
Aslında bu sayı 6. iskendercilerden ilk 6sı şu şekilde
: 6, 42, 120, 156, 420, and 630.

150,000. iskenderci sayıyı bulunuz
*/


/*
Biraz matematik

1/A -> 1/p/q/r

1/p/q/r = 1/p + 1/q + 1/r -> 1 = qr + pr + pq

1 = qr + pr + pq -> 1 = r (p + q) + pq

Son formülün doğru olma koşulu
1) r(p+q) ile pq arasındaki farkın 1 olmasıyla mümkün
2) Sağ ile sol pozitifken toplamları 1 olması gerekiyor

2. yoldan ilerlememizi sağlayan pek sayı yok. p q veya r 0 olamayacağı için
pq çarpımı asla 0 olamaz. burada sol taraf 0 olmalı ve sağ taraf 1 olmalı.
2. yol başka türlü ilerlenemiyor. sağ tarafın 1 olması demek p=q=-1 veya 1 ile
mümkün bu iki durumda da toplam mutlak değer 2 oluyor ve r=0 olamayacağına göre
sol tarafı sıfırlayamıyoruz. 2. yol imkansız

1. yolda arada fark işlemi alabilmemiz için sağ yada solun negatif olması gerek

r(p+q) negatifken pq > 0 
r eksi ise p+q > 0 ise p ve q pozitif, fakat A sayısı negatıf old. bu yol geçersiz
r arti ise p+q < 0 ise p ve q negatif

r(p+q) positifken pq < 0
r eksi ise p+q < 0 ise p ve q zıt işaretli eksi olan büyük
r arti ise p+q > 0 ise p ve q zıt işaretli artı olan büyük, fakat A sayısı negatıf old. bu yol geçersiz
*/

#include <stdio.h> // printf
#include <assert.h>
#include <stdlib.h> // calloc

typedef unsigned long ul;

ul fnv1a(void *d, size_t n) { // FNV-1a_hash
    ul r = 0xcbf29ce484222325;
    for (; n != 0; --n) {
        r ^= *((char*)d++);
        r *= 0x100000001b3;
    }
    return r;
}

typedef struct btree {
    struct btree *l, *r;
    ul n;
} btree;

btree root;
void insert(ul n, btree *bt) {
    if (!bt->n) {
        bt->n = n;
        btree *pair = calloc(sizeof(btree), 2);
        bt->l = pair++;
        bt->r = pair;
    }
    else if (bt->n > n) insert(n, bt->l);
    else                 insert(n, bt->r);
}

#define N 150000*2
ul a[N]; // hash table
void process(ul pqr, size_t n, ul p, ul q, ul r) {
    printf("[%#2i] %#6lu %#6lu %#6lu | %lu\n", n, p, q, r, pqr);
    ul i = fnv1a(&pqr, 8) % N; assert( i < N );
    if ( a[i] ) return;
    a[i] = pqr;
    insert(pqr, &root);
}

int iskender(int p, int q, int r) {
    assert(p != 0 && q != 0 && r != 0);
    return r * (p + q) + p*q == 1;
}

int main() {
    const int l = __INT_MAX__,
              t = N/2;
    int n = 0;
    for (ul p = 1; p <= l && n < t; p++) 
    for (ul q = 1; q <= p; q++) 
    for (ul r = 1; r <= q; r++) {
        if (iskender(-p,-q, r)) process(p*q*r, ++n, p, q, r);
        if (iskender(-p, q,-r)) process(p*q*r, ++n, p, q, r);
        if (iskender( p,-q,-r)) process(p*q*r, ++n, p, q, r);

    }

}