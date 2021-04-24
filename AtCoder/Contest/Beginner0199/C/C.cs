// AtCoder Beginner Contest 199
// 2021-04-24(Sat) 21:00 - 2021-03-20(Sat) 22:40, 100 minutes

// C - IPFL

/* Sample Input & Output
2
FLIP
2
2 0 0
1 1 4

LPFI

2
FLIP
6
1 1 3
2 0 0
1 1 2
1 2 3
2 0 0
1 1 4

ILPF
*/

using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>
using System.Text;                  // for StringBuilder

namespace ABC0199C
{
    class MainClass
    {
        public static void Main (string[] args) 
        {

            // Read data - N, S, Q
            int n = int.Parse(Console.ReadLine());
            StringBuilder s = new StringBuilder(Console.ReadLine());    // declare as mutable
            int q = int.Parse(Console.ReadLine());

            // Declare arrays for the below for statement
            int[] t = new int[q];
            int[] a = new int[q];
            int[] b = new int[q];
            char[] temp1 = new char[q];
            char[] temp2 = new char[q * n];

            for (int i = 0; i < q; i++)
            {

                // Read data - T, A, B
                List<int> tab = Console.ReadLine().Split().Select(int.Parse).ToList();
                t[i] = tab[0];
                a[i] = tab[1];
                b[i] = tab[2];

                // Operation required
                if (t[i] == 1)                                          // t[i] == 1 : swap s[a[i]-1] ↔ s[b[i]-1]
                {
                    temp1[i] = s[a[i]-1];
                    s[a[i]-1] = s[b[i]-1];
                    s[b[i]-1] = temp1[i];
                    Console.WriteLine("Q : {0}, S : {1}", i, s);        // test
                } else {                                                // t[i] == 2 : swap a[0..n-1] ↔ b[n..2n-1]
                    for (int j = 0; j < n; j++)
                    {
                        temp2[i*n+j] = s[j];
                        s[j] = s[n+j];
                        s[n+j] = temp2[i*n+j];
                    }
                    Console.WriteLine("Q : {0}, S : {1}", i, s);        // test
                } // The end of if~else statement

            } // The end of q loop

            // Output
            Console.WriteLine(s);

        } // The end of Main method
    }
}