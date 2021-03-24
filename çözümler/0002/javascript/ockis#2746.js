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

// Çözüm: Ockis#2746
// Project Euler Soru 2
// 22/03/2021

console.log( 
    [...Array(11)]
        .map((x,i)=>3*(i+1))
        .map(n => .5+Math.pow(.5+.5*Math.sqrt(5),n)/Math.sqrt(5))
        .map(x=>x-(x%1))
        .reduce((a,c)=>a+=c) 
);

// LaTex form:
//
// F(n) = f(\frac{{(\frac{1+\sqrt{5}}{2}})^{n}}{\sqrt(5)}+\frac{1}{2}), n \leq 0
// f(x) = x-(x\mod{1})
// \sum_{k=1}^{3k\leq33} f(F(k))