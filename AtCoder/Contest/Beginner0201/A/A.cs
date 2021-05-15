// AtCoder Beginner Contest 201
// 2021-05-15(Sat) 21:00 - 22:40, 100 minutes

// A - Tiny Arithmetic Sequence

/* Sample Input & Output
5 1 3
Yes

1 4 3
No

5 5 5
No
*/

using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>

namespace ABC0201A
{
    class MainClass
    {
        public static void Main (string[] args) 
        {

            // Read and sort data
            List<int> a = Console.ReadLine().Split().Select(int.Parse).ToList();
            a.Sort();                                                               // ascending order
            // Console.WriteLine(a[0] + " " + a[1] + " " + a[2]);                      // test

            // Output : Yes or No
            if (a[2] - a[1] == a[1] - a[0])
            {
                Console.WriteLine("Yes");
            } else {
                Console.WriteLine("No");
            }

        }
    }
}