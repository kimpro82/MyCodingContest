// Codeforces Round #721 (Div. 2)
// 2021.05.20(Thu) 23:35, 2.00 hrs

// A. And Then There Were K

using System;

namespace CFR721A
{
    class MainClass
    {
        static void Main(string[] args)
        {

            /* Sample Input & Output
                3
                2
                5
                17

                1
                3
                15
            */

            int T = int.Parse(Console.ReadLine());      // 3

            // Read each case t times
            for (int t = 1; t <= T; t++)
            {
               
                int n = int.Parse(Console.ReadLine());  // 2, 5, 17

                // Bitwise & operation
                int k = n;
                while (n != 0)
                {
                    k = n - 1;
                    n = n & k;
                    // Console.WriteLine("{0} : {1}", k, n);   // test
                }

                // Output
                Console.WriteLine(k);

            }

        }
    }
}