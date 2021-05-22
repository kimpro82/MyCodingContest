// AtCoder Beginner Contest 202
// 2021-05-22(Sat) 21:00 - 22:40, 100 minutes

// A - Three Dice

/* Sample Input & Output
1 4 3
13

5 6 4
6
*/

using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>

namespace ABC0202A
{
    class MainClass
    {
        public static void Main (string[] args) 
        {
            // Read data
            List<int> input = Console.ReadLine().Split().Select(int.Parse).ToList();
            
            // Output
            Console.WriteLine(21 - input.Sum());
        }
    }
}