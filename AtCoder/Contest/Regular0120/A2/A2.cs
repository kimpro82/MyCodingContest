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
using System.Linq;  // for .Select(), Max()

namespace ARC120A2
{
    class MainClass
    {
        public static void Main (string[] args) 
        {

            // Read data
            int n = int.Parse(Console.ReadLine());                                  // 3
            long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();     // 1 2 3

            // f(a) operation of a_0 ~ a_k
            for (int i = 0; i < n; i++)
            {
                long[] aSub = a[0..(i+1)];                   // Initialize a[]'s subset : [1], [1, 2], [1, 2, 3]

                long sum = 0;
                for (int j = 0; j <= i; j++)
                {
                    long max = aSub.Max();                   // Get max of i-th aSub[]
                    sum = 0;

                    // Get sum and update aSub[]
                    aSub[j] += max;
                    sum = aSub.Sum();

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