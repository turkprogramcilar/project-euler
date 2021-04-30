using System;

namespace ProjectEuler
{
    class Program
    {
        static bool IsPalindrom(string a){
            switch(a.Length){
                case 6:
                    if(a[0] == a[5] && a[1] == a[4] && a[2] == a[3]){
                        return true;
                    }
                    else{
                        return false;
                    }
                case 5:
                    if(a[0] == a[4] && a[1] == a[3]){
                        return true;
                    }
                    else{
                        return false;
                    }
                case 4:
                    if(a[0] == a[3] && a[1] == a[2]){
                        return true;
                    }
                    else{
                        return false;
                    }
                case 3:
                    if(a[0] == a[2]){
                        return true;
                    }
                    else{
                        return false;
                    }
                case 2:
                    if(a[0] == a[1]){
                        return true;
                    }
                    else{
                        return false;
                    }
                case 1:
                    return false;
                default:
                    return false;
            }
        }

        static void Main(string[] args)
        {
            int i = 999 , j = 999;
            int myI=0 , myJ=0;
            int largestPalindrom = 0;
            while(i > 1){
                j = 999;
                while(j > 1){
                    if(IsPalindrom((i*j).ToString())){
                        if(i*j > largestPalindrom){
                            largestPalindrom = i*j;
                            myI = i;
                            myJ = j;
                        }
                    }
                    j--;
                }
                i--;
            }
            Console.Write($"Largest palindrom is {myI}x{myJ}={largestPalindrom}");
            Console.ReadKey();
        }
    }
}
