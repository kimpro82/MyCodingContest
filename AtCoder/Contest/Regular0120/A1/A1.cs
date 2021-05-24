// AtCoder Regular Contest 120
// 2021-05-23(Sun) 20:00 - 22:00, 120 minutes

// A - Max Add

/* Sample Input & Output
3
1 2 3

2
8
19
*/

using System;
using System.Linq;  // for .Select()

namespace ARC120A1
{
    class MainClass
    {
        public static void Main (string[] args) 
        {

            // Read data
            int n = int.Parse(Console.ReadLine());
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();

            // f(a) operation of a_0 ~ a_k
            for (int i = 0; i < n; i++)
            {
                int[] aSub = new int[i+1];              // Initialize for f(a)
                int max = 0, sum = 0;
                for (int j = 0; j <= i; j++)
                {
                    max = sum = 0;                      // Initialize for each j-th loop
                    for (int k = 0; k <= i; k++)
                    {
                        if (j == 0)                     // Copy a[] to aSub[] only when j == 0
                        {
                            aSub[k] = a[k];
                        }
                        sum += aSub[k];
                        max = Math.Max(max, aSub[k]);   // Get max
                    }

                    // Get sum and update aSub[]
                    sum += max;                         // for saving additional loop to calculate sum
                    aSub[j] += max;

                    // Test
                    Console.Write("(k = {0}) max : {1}, aSub : ", i, max);
                    Array.ForEach(aSub, Console.Write);
                    Console.WriteLine(", sum : {0}", sum);
                }

                // Output
                Console.WriteLine(sum);

            } // The end of the i loop
        } // The end of main()
    }
}