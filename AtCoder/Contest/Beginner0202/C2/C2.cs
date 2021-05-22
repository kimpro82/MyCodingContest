// AtCoder Beginner Contest 202
// 2021-05-22(Sat) 21:00 - 22:40, 100 minutes

// C - Made Up

/* Sample Input & Output
3
1 2 2
3 1 2
2 3 2
4

4
1 1 1 1
1 1 1 1
1 2 3 4
16

3
2 3 3
1 3 3
1 1 1
0
*/

using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>

namespace ABC0202C2
{
    class MainClass
    {
        public static void Main (string[] args) 
        {
            int n = int.Parse(Console.ReadLine());                              // 3

            // Read A, B, C
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();   // A
            int[] b = Console.ReadLine().Split().Select(int.Parse).ToArray();   // B
            int[] c = Console.ReadLine().Split().Select(int.Parse).ToArray();   // C

            // Count the number of pairs such that A_i = B_(C_j)
            int sum = 0;
            for (int i = 1; i <= n; i++)                                        // only 3 rows of A, B, C
            {
                for (int j = 1; j <= n; j++)                                    // A1, A2, ..., An
                {
                    if (a[i-1] == b[c[j-1]-1])
                    {
                        sum++;
                    }
                    // Console.WriteLine("({0}, {1}) a[{2}] : {3}, b[{4}] : {5}, count : {6}",
                    //     i, j, i-1, a[i-1], c[j-1]-1, b[c[j-1]-1], sum);         // test
                }
            }

            // Output
            Console.WriteLine(sum);
        }
    }
}