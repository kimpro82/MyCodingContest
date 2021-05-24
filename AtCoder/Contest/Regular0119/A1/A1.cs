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

namespace ARC119A1
{
    class MainClass
    {
        public static void Main (string[] args) 
        {

            // Read data
            ulong n = ulong.Parse(Console.ReadLine());

            // Get a, b, c (mod = a * 2^b +c, exp = 2^b)
            ulong a = 0, b = 0, c = 0, exp;
            while (true)                            // get b
            {
                exp = (ulong)Math.Pow(2, b);
                if (exp >= n)
                {
                    exp = (ulong)Math.Pow(2, --b);  // 2^b is already over n
                    break;
                } else {
                    b++;
                }
            }
            a = n / exp;                            // get a
            c = n - a * exp;                        // get c

            Console.WriteLine("a : {0}, b : {1}, exp : {2}, c : {3} ", a, b, exp, c);   // test

            // Output
            Console.WriteLine(a + b + c);

        } // The end of Main method
    }
}