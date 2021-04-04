// Codeforces Round #710 (Div. 3)
// 2021.4.4 (Virtual Participation)

// A. Strange Table

/* Example input
5
1 1 1
2 2 3
3 5 11
100 100 7312
1000000 1000000 1000000000000
*/

using System;
using System.Linq; // for Select()

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {

            int T = int.Parse(Console.ReadLine());

            // read each case and print its output
            for (int t = 1; t <= T; t++)
            {

                var input = Console.ReadLine().Split().Select(Int64.Parse).ToArray();
                Int64 n = input[0];
                Int64 m = input[1];
                Int64 x = input[2];

                Int64 divisor = x / n;
                Int64 remainder = x % n;

                if (remainder == 0) {
                    Console.WriteLine(m * (n - 1) + divisor);
                } else {
                    Console.WriteLine((m * (remainder - 1)) + (divisor + 1));
                }

            }

        }
    }
}