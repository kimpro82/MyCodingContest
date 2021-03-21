using System;
using System.Linq;


namespace ABC0195C2
{
  class MainClass {
    public static void Main (string[] args) {

      Int64 N = Int64.Parse(Console.ReadLine());                               // Int64 : 1 <= N <= 10^15

      int digit = N.ToString().Length;
      Int64 sum = 0;

      for (int i = 15; i > 2; i -= 3)                                          // 15, 12, 9, 6, 3
      {
        if (digit > i)
        {
          sum += (N - (Int64)Math.Pow(10, i) + 1) * (i/3);
          // Console.WriteLine(digit.ToString() + " " + N.ToString() + " " + i + " " + sum);           // Test
          N = (Int64)Math.Pow(10, i) - 1;
        }
      }

      Console.WriteLine(sum);

    }
  }
}