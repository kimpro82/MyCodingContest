// AtCoder Beginner Contest 199
// 2021-04-24(Sat) 21:00 - 2021-03-20(Sat) 22:40, 100 minutes

// A - Square Inequality

/* Sample Input & Output
2 2 4
Yes

10 10 10
No

3 4 5
No
*/

using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>

namespace ABC0199A
{
    class MainClass
    {
        public static void Main (string[] args) 
        {

            // Read data
            List<int> input = Console.ReadLine().Split().Select(int.Parse).ToList();

            int a = input[0];
            int b = input[1];
            int c = input[2];

            // Output
            if (Math.Pow(a, 2) + Math.Pow(b, 2) < Math.Pow(c,2))
            {
                Console.WriteLine("Yes");
            } else {
                Console.WriteLine("No");
            }

        } // The end of Main method
    }
}