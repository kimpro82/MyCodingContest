// AtCoder Beginner Contest 202
// 2021-05-22(Sat) 21:00 - 22:40, 100 minutes
 
// B - 180°
 
/* Sample Input & Output
0601889
6881090
 
86910
01698
 
01010
01010
*/
 
using System;
using System.Text;  // for using StringBuilder;
 
namespace ABC0202B
{
    class MainClass
    {
        public static void Main (string[] args) 
        {
            // Read data
            StringBuilder s = new StringBuilder(Console.ReadLine());    // 0601889
            int n = s.Length;                                           // 7
 
            // Rotate S 180 degrees
            StringBuilder sReverse = new StringBuilder();
            for (int i = 0; i < n; i++)
            {
                if (s[n-i-1] == '6')
                {
                    s[n-i-1] = '9';
                } else if (s[n-i-1] == '9')
                {
                    s[n-i-1] = '6';
                }
                sReverse.Append(s[n-i-1]);
            }
 
            // Output
            Console.WriteLine(sReverse);
        }
    }
}