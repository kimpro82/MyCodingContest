// AtCoder Beginner Contest 199
// 2021-04-24(Sat) 21:00 - 2021-03-20(Sat) 22:40, 100 minutes

// B - Intersection

/* Sample Input & Output
2
3 2
7 5
3

3
1 5 3
10 7 3
0

3
3 2 5
6 9 8
2
*/

using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>

namespace ABC0199B
{
    class MainClass
    {
        public static void Main (string[] args) 
        {

            // Read data - A, B who are sequences of length N
            int n = int.Parse(Console.ReadLine());
            List<int> a = Console.ReadLine().Split().Select(int.Parse).ToList();
            List<int> b = Console.ReadLine().Split().Select(int.Parse).ToList();

            // Find max and min values from A and B
            int max = 1000, min = 0;
            for (int i = 0; i < n; i++)
            {
                max = Math.Min(max, Math.Max(a[i], b[i]));              // min of each i-th max
                min = Math.Max(min, Math.Min(a[i], b[i]));              // max of each i-th min
                Console.WriteLine("max : {0}, min : {1}", max, min);    // test
            }

            // Output
            int answer = max - min + 1;
            if (answer > 0)
            {
                Console.WriteLine(answer);
            } else {
                Console.WriteLine(0);
            }

        } // The end of Main method
    }
}