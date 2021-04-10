(*
Türk Programcılar Discord sunucusu kullanıcıları tarafından gönderilen 
Project Euler soru çözümleri

Türk Programcılar discord sunucusu programlamaya yeni başlayan ve her seviyeden 
insanlara yardım etmeyi hedefleyen bireylerin toplantığı bir platformdur.
Birbirimizi motive ettiğimiz, her gün yeni birşeyler öğrenmeye teşvik ettiğimiz
sunucumuzda; kodlama yarışmaları ve eğlenceli birçok diğer 
aktiviteleri de keşvedebilirsin.

Hemen aramıza katıl!

https://disboard.org/server/698972054740795453

*)

// Çözüm: 0xdeadc0de#9615
// Project Euler Soru 4
// 11/04/2021

(*
A palindromic number reads the same both ways. The largest palindrome made from 
the product of two 2-digit numbers is 9009 = 91 × 99. Find the largest 
palindrome made from the product of two 3-digit numbers.

Türkçe çeviri:

Sağdan ve soldan okunuşu aynı olan sayılara palindrom sayılar denir. En büyük
iki iki basamaklı sayının çarpımından elde edilen palindrom sayı 91 x 99 = 9009
sayısıdır. Üç basamaklı iki sayının çarpımından oluşabilecek en büyük sayıyı
bulunuz
*)

// dotnet fsi .\0xdeadc0de#9615.fsx

// ters çevirme işlemi
let rec revA xs acc =
    match xs with
    | [] -> acc
    | h::t -> revA t (h::acc)

let rev xs =
    match xs with
    | [] -> xs
    | [_] -> xs
    | h1::h2::t -> revA t [h2;h1]

// palindrom kontrolü
let isPalindrome (number : int) : bool =
    let n = Seq.toList (sprintf "%i" number) 
    let r = (rev <| Seq.toList (sprintf "%i" number))
    n = r

// combinasyon işlemleri
let get n = 
    [(n, n)] @ List.concat [for i in 0..(n-1) -> [(i, n)(*; (n, i)*)]]

let all n =
    List.concat [for i in 0..n -> get i]

// palindrom iteratörleri
let getPalindromes i n =
    [ for (x,y) in get i do if isPalindrome ((n-x)*(n-y)) then (n-x)*(n-y) ]

let allPalindromes i n =
    List.concat [ for i in 0..i -> getPalindromes i n ]

let rec firstPalindrome i n =
    let list = getPalindromes i n
    match list with
    | [] -> firstPalindrome (i+1) n
    | xs -> list |> List.max

let result = List.max (allPalindromes 99 999)
printfn "%d" result