// Codeforces Round #717 (Div. 2)
// 2021.04.21(Wed) 22:35, 2.25 hrs

// B. AGAGA XOOORRR

using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>

namespace CFR717Div2B
{
    class MainClass
    {
        static void Main(string[] args)
        {

            /* Sample Input & Output
                2
                3
                0 2 2
                4
                2 3 1 10

                YES
                NO
            */

            int T = int.Parse(Console.ReadLine());                                      // 2

            // Read each case and print its output
            for (int t = 1; t <= T; t++)
            {
                
                int n = int.Parse(Console.ReadLine());                                  // 3
                List<int> a = Console.ReadLine().Split().Select(int.Parse).ToList();    // 0 2 2

                // Bitwise XOR operation
                while (n > 2)
                {
                    a[1] = a[0]^a[1];
                    a.RemoveAt(0);
                    n--;
                }

                // Output when list a's lenth = 2
                if (a[0] == a[1])
                {
                    Console.WriteLine("YES");
                } else {
                    Console.WriteLine("NO");
                }

            } // The end of t loop
        }
    }
}