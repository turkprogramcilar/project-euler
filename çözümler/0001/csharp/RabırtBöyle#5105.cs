using System;

namespace ProjectEuler
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Kaça kadar olan sayılardan 3 ve 5'e bölünenlerin toplamını bulmak istiyorsunuz: ");
            int mainNumber = Convert.ToInt32(Console.ReadLine()), total = 0;
            int[] numbers = new int[mainNumber - 1];
            for (int i = 0; i <= mainNumber - 2; i++)
            {
                numbers[i] = i+1;
            }
            foreach (var item in numbers)
            {
                if (item % 3 == 0)
                {
                    total += item;
                }
            }
            foreach (var item in numbers)
            {
                if (item % 5 == 0)
                {
                    total += item;
                }
            }
            foreach (var item in numbers)
            {
                if (item % 15 == 0)
                {
                    total -= item;
                }
            }
            Console.WriteLine(total);
        }
    }
}
