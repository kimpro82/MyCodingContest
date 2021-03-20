// AtCoder Beginner Contest 196
// 2021-03-20(Sat) 21:00 - 2021-03-20(Sat) 22:40

// A - Difference Max


using System;
using System.Linq;

namespace ABC0196
{
  class MainClass
  {
    public static void Main (string[] args) 
    {

      var input = Console.ReadLine().Split().Select(int.Parse).ToArray();
      var input2 = Console.ReadLine().Split().Select(int.Parse).ToArray();

      int a = (int)input[0];
      int b = (int)input[1];
      int c = (int)input2[0];
      int d = (int)input2[1];

      Console.WriteLine(b - c);

    }
  }
}