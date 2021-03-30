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

            int T = int.Parse(Console.ReadLine());                          // 3

            // read each case and print its output
            for (int t = 1; t <= T; t++)
            {

                Int64 n = Int64.Parse(Console.ReadLine());                  // 1 <= n <= 10^18
                Int64 min = 0;                                              // for calculating gcd

                // loop for finding next n (n++) until gcdsum > 1
                while (min < 2)
                {
                    // 1. read n
                    int len = (char)(n.ToString()).Length;

                    // 2. gcdSum operation
                    int sum = 0;
                    for (int i = 0; i < len; i++)
                    {
                        sum += int.Parse(n.ToString()[i].ToString());       // Parse() only recieves string
                        Console.WriteLine("{0} {1} {2} ", n, i, sum);       // test
                    }

                    // 3. gcd operation (Euclidean algorithm)
                    Int64 max = Math.Max(n, sum);
                    min = Math.Min(n, sum);
                    Int64 mod = max;
                    while(mod != 0)
                    {
                        mod = max % min;
                        max = min;
                        min = mod;
                        Console.WriteLine("{0} {1} {2} ", max, min, mod);   // test
                    } // gcd = min when escape while loop

                    n += 1;

                } // the end of while loop

                // 4. output
                Console.WriteLine("case {0} : {1} {2} ", t, n - 1, min);   // test

            } // the end of t loop

        }
    }
}