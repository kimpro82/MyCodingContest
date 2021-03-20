// AtCoder Beginner Contest 196
// 2021-03-20(Sat) 21:00 - 2021-03-20(Sat) 22:40

// B - Round Down


using System;
using System.Linq;
// using System.Math;                   // do not need


namespace ABC0196B
{
    class Program
    {
        static void Main(string[] args)
        {

            string num = Console.ReadLine(); 
            int index = num.IndexOf(".");

            if (!num.Contains("."))
            {
                Console.WriteLine(num);
            }
            else
            {
                Console.WriteLine(num[..index]);
            }

        }
    }
}