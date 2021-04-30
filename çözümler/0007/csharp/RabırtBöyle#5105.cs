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
            int controller = 0;
            int i = 2;
            while(true){
                if(IsPrime(i)){
                    controller++;
                    if(controller == 10001){
                        Console.WriteLine(i);
                        break;
                    }
                }
                i++;
            }
        }
    }
}
