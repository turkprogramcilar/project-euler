using System;

namespace ProjectEuler
{
    class Program
    {
        static bool IsPrime(long isPrimeNumber)
        {
            long j = 2;
            long controller = 0;
            while (j < isPrimeNumber)
            {
                if(isPrimeNumber%j == 0)
                {
                    controller++;
                }
                j++;
            }
            if(controller == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        static void Main(string[] args)
        {
            long number = 600851475143;
            long i = 1;
            long lastPrime = 2;
            while (i <= number)
            {
                if(number%i == 0)
                {
                    if (IsPrime(i))
                    {
                        lastPrime = i;
                        Console.WriteLine(i);
                    }
                }
                i++;
            }
            Console.WriteLine(lastPrime);
            Console.ReadKey();
        }
    }
}
