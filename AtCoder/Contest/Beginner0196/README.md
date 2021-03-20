## AtCoder Beginner Contest 196
2021-03-20(Sat) 21:00 - 2021-03-20(Sat) 22:40  
https://atcoder.jp/contests/abc196/


### A - Difference Max

```cs
using System;
using System.Linq;

namespace ABC0196A
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
```
Accepted


### B - Round Down

```cs
using System;
using System.Linq;
// using System.Math;                   // do not need


namespace ABC0196B
{
    class Program
    {
        static void Main(string[] args)
        {

            string num = Console.ReadLine(); 
            int index = num.IndexOf(".");

            if (!num.Contains("."))
            {
                Console.WriteLine(num);
            }
            else
            {
                Console.WriteLine(num[..index]);
            }

        }
    }
}
```
Accepted