// Codeforces Round #721 (Div. 2)
// 2021.05.20(Thu) 23:35, 2.00 hrs

// B1. Palindrome Game (easy version)
// B2. Palindrome Game (hard version)

using System;
using System.Text; // for using StringBuilder

namespace CFR721B2
{
    class MainClass
    {
        static void Main(string[] args)
        {

            /* Sample Input & Output
                2
                4
                1001
                1
                0

                BOB
                BOB
            */

            int T = int.Parse(Console.ReadLine());                                  // 2

            // Read each case t times
            for (int t = 1; t <= T; t++)
            {
               
                int n = int.Parse(Console.ReadLine());                              // 4, 1
                StringBuilder sb = new StringBuilder(Console.ReadLine());           // 1001, 0

                // Judge if sb is "palindrome"
                StringBuilder sbReverse = new StringBuilder();
                for (int i = 0; i < n; i++)
                {
                    sbReverse.Append(sb[n-i-1]);
                }
                bool palindromeScore = true;
                for (int j = 0; j < n; j++)
                {
                    if (sb[j] != sbReverse[j])
                    {
                        palindromeScore = false;
                        break;
                    }
                }

                // Judge if n is odd and the center is 0
                bool center0 = false;
                if (n > 1 && n % 2 != 0)    // avoid when n = 1
                {
                    if (sb[(n-1)/2] == '0')
                    {
                        center0 = true;
                    }
                }

                // Output
                if (palindromeScore)
                {
                    if (center0)
                    {
                        Console.WriteLine("ALICE");
                    } else {
                        Console.WriteLine("BOB");
                    }
                } else {
                    if (!center0)
                    {
                        Console.WriteLine("ALICE");
                    } else {
                        Console.WriteLine("BOB");
                    }
                }

            }

        }
    }
}