using System;
using System.Linq;


namespace ABC0195B2
{
  class MainClass
  {
    public static void Main (string[] args)
    {

      var input = Console.ReadLine().Split().Select(int.Parse).ToArray();

      int A = input[0];
      int B = input[1];
      int W = input[2] * 1000;

      int min = W / B;
      int max = W / A;

      int min2;                                     // min2 is not yet guaranteed if valid
      if (W % B == 0) {
        min2 = min;    
      } else {
        min2 = min + 1;
      }

      // if (W - A * min2 > B || W - B * max < 0)   // || : or, && : and
      if (W - A * min2 >= A || W - B * max <= 0)
      {
        Console.WriteLine(min2 + " " + max);
      }
      else
      {
        Console.WriteLine("UNSATISFIABLE");
      }

    }
  }
}