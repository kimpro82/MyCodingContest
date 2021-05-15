// AtCoder Beginner Contest 201
// 2021-05-15(Sat) 21:00 - 2021-05-15(Sat) 22:40, 100 minutes

// B - Do you know the second highest mountain?

/* Sample Input & Output
3
Everest 8849
K2 8611
Kangchenjunga 8586

K2

4
Kita 3193
Aino 3189
Fuji 3776
Okuhotaka 3190

Kita

4
QCFium 2846
chokudai 2992
kyoprofriends 2432
penguinman 2390

QCFium
*/

using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>

namespace ABC0201B
{
    class MainClass
    {
        public static void Main (string[] args) 
        {
            // Read data
            int n = int.Parse(Console.ReadLine());
            Dictionary<string, int> dic = new Dictionary<string, int>();
            for (int i = 0; i < n; i++)
            {
                string[] row = Console.ReadLine().Split();
                dic.Add(row[0], int.Parse(row[1]));
            }

            // Sort : make a list for sorting
            var height = new List<int>(dic.Values);
            height.Sort();

            // Output
            var answer = dic.Where(c => c.Value == height[n-2]).First();    // First() : choose the first one when the same values are many
            Console.WriteLine(answer.Key);                                  // answer without `.Key` returns both of the key and value
        }
    }
}