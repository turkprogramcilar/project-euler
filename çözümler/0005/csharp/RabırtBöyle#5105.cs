using System;

namespace ProjectEuler
{
    class Program
    {
        static bool IsSmallestMultiple(int i){
            int controller = 0;
            for(int j = 1; j <=20 ;j++){
                if(i%j != 0){
                    controller++;
                }
            }
            if(controller == 0){
                return true;
            }
            else{
                return false;
            }
        }
        static void Main(string[] args)
        {
            int i = 1;
            while(true){
                if(IsSmallestMultiple(i)){
                    Console.WriteLine(i);
                    break;
                }
                i++;
            }
        }
    }
}
