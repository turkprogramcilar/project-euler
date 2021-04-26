using System;

namespace ProjectEuler
{
    class Program
    {
        static void Main(string[] args)
        {
            int num1 = 1, num2 = 2, num3 = num1 + num2, total = 2;
            while(num3 <= 4000000)
            {
                num1 = num2; num2 = num3; num3 = num1 + num2;
                if(num3%2 == 0)
                {
                    total+=num3;
                }
            }
            Console.WriteLine(total);
            Console.ReadLine();
        }
    }
}
