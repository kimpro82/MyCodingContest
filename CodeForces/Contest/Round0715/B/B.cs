// Codeforces Round #715 (Div. 2)
// 2021.04.16(Fri) 23:35, 2 hrs

// B. TMT Document

using System;
using System.Text; // for StringBuilder

namespace CFR0715Div2B
{
    class MainClass
    {
        static void Main(string[] args)
        {

            /* Sample Input
                5
                3
                TMT
                3
                MTT
                6
                TMTMTT
                6
                TMTTTT
                6
                TTMMTT
            */

            int T = int.Parse(Console.ReadLine());                                  // 5

            // Read each case and print its output
            for (int t = 1; t <= T; t++)
            {

                int n = int.Parse(Console.ReadLine());                              // 3
                StringBuilder input = new StringBuilder(Console.ReadLine());        // TMT

                // Count T and M
                double tCount = 0;
                double mCount = 0;
                for (int i = 0; i < n; i++)
                {

                    if (input[i] == 'T')
                    {
                        tCount++;
                    } else {
                        mCount++;
                    }

                    if ((tCount < mCount) || ((double)(tCount / mCount) > 2))       // "No"
                    {
                        break;
                    }

                }

                // Output
                if ((tCount < mCount) || ((double)(tCount / mCount) > 2))
                {
                    Console.WriteLine("NO");                    
                } else if ((double)(n / tCount) == 1.5) {
                    Console.WriteLine("YES");
                } else {
                    Console.WriteLine("NO");
                }

            } // The end of t loop
        }
    }
}