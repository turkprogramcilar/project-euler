using System;

namespace ProjectEuler
{
    class Program
    {
        static void Main(string[] args)
        {
            ulong sumHundred=0;
            ulong sumSquaresHundred=0;
            for(ulong i = 1; i <= 100; i++){
                sumHundred+=i;
            }
            ulong sumHundredSquare = sumHundred * sumHundred;
            for(ulong i = 1; i <= 100; i++){
                sumSquaresHundred+=i*i;
            }
            Console.WriteLine(sumHundredSquare - sumSquaresHundred);
        }
    }
}
