// Codeforces Round #716 (Div. 2)
// 2021.04.19(Mon) 22:35, 2.25 hrs

// A. Perfectly Imperfect Array

using System;
using System.Linq;

namespace CFR716Div2A
{
    class MainClass
    {
        static void Main(string[] args)
        {

            /* Sample Input & Output
                2
                3
                1 5 4
                2
                100 10000

                YES
                NO
            */

            int T = int.Parse(Console.ReadLine());                                  // 2

            // Read each case and print its output
            for (int t = 1; t <= T; t++)
            {
                
                int n = int.Parse(Console.ReadLine());                              // 3
                var input = Console.ReadLine().Split().Select(int.Parse).ToArray(); // 1 5 4

                // Calculate product and its sqrt
                int product = 1;
                for (int i = 0; i < n; i++)
                {
                    product *= input[i];
                }
                float sqrt = (float) Math.Sqrt(product);

                // Output
                if (sqrt != Math.Floor(sqrt))
                {
                    Console.WriteLine("YES");
                } else {
                    Console.WriteLine("NO");
                }

            } // The end of t loop
        }
    }
}