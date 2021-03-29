using System;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {

            /* Sample Input
                3
                11
                31
                75
            */

            int T = int.Parse(Console.ReadLine());              // 3

            // read each case and print its output
            for (int t = 1; t <= T; t++)
            {
                
                // 1. read n
                string[] input = Console.ReadLine();            // 1 <= n <= 18
                int len = input.Length;


                // 2. gcd operation


                // test
                Console.WriteLine("case {0} : {1}", t, len);

                // 3. output

            }
        }
    }
}
