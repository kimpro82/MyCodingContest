// Codeforces Round #715 (Div. 2)
// 2021.04.16(Fri) 23:35, 2 hrs

// A. Average Height

using System;
using System.Linq;

namespace CFR0715Div2A
{
    class MainClass
    {
        static void Main(string[] args)
        {

            /* Sample Input
                4
                3
                1 1 2
                3
                1 1 1
                8
                10 9 13 15 3 16 9 13
                2
                18 9
            */

            int T = int.Parse(Console.ReadLine());                                  // 4

            // Read each case and print its output
            for (int t = 1; t <= T; t++)
            {
                int n = int.Parse(Console.ReadLine());                              // 8
                var input = Console.ReadLine().Split().Select(int.Parse).ToArray(); // 10 9 13 15 3 16 9 13

                // Seperate odd and even numbers
                int[] array = new int[n];
                int odd = 0;
                int even = 0;
                for (int i = 0; i < n; i++)
                {
                    if (input[i] % 2 == 1)
                    {
                        array[odd] = input[i];
                        odd++;
                    } else {
                        array[n-even-1] = input[i];
                        even++;
                    }
                }

                // Output
                for (int j = 0; j < n; j++)
                {
                    Console.Write(array[j] + " ");
                }
                Console.WriteLine();

            } // The end of t loop
        }
    }
}