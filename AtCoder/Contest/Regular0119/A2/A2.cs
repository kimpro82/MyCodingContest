// AtCoder Regular Contest 119
// 2021-05-16(Sun) 21:00 - 23:00, 120 minutes

// A - 119 × 2^23 + 1

/* Sample Input & Output
998244353
143

1000000007
49483

1
1

998984374864432412
2003450165
*/

using System;

namespace ARC119A2
{
    class MainClass
    {
        public static void Main (string[] args) 
        {

            // Read data declare variables
            ulong n = ulong.Parse(Console.ReadLine());
            ulong a = 0, c = 0, sum = 0, minSum = n, exp;   // sum = a + b + c, exp = 2^b, b doesn't be used

            // Get max of b first
            int maxB = 0;
            while (true)
            {
                exp = (ulong)Math.Pow(2, maxB);
                if (exp > n)
                {
                    break;
                } else {
                    maxB++;
                }
            }

            // Get a, b, c and sum and find min of sum
            for (int i = 0; i < maxB; i++)
            {
                exp = (ulong)Math.Pow(2, i);
                a = n / exp;                                // get a
                c = n - a * exp;                            // get c
                sum = a + (ulong)i + c;                     // get sum, b = i

                // Find min of sum
                if (sum < minSum)
                {
                    minSum = sum;
                }

                // Test
                Console.WriteLine("a : {0}, b : {1}, exp : {2}, c : {3}, sum : {4}, minSum : {5}",
                    a, i, exp, c, sum, minSum);
            }

            // Output
            Console.WriteLine(minSum);

        } // The end of Main method
    }
}