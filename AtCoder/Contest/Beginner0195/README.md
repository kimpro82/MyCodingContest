## AtCoder Beginner Contest 195
2021-03-13 (Sat)  
https://atcoder.jp/contests/abc195/


### A - Health M Death

```cs
using System;
using System.Linq;

class MainClass {
  public static void Main (string[] args) {

    var input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    var M = input[0];
    var H = input[1];

    if (H % M == 0) {
      Console.WriteLine("Yes");
    } else {
      Console.WriteLine("No");
    }

  }
}
```
Accepted


### B - Many Oranges

```cs
using System;
using System.Linq;

class MainClass {
  public static void Main (string[] args) {

    var input = Console.ReadLine().Split().Select(int.Parse).ToArray();

    int A = input[0];
    int B = input[1];
    int W = input[2] * 1000;

    int min = W / B;
    int max = W / A;

    int min2;
    if (W % B == 0) {
      min2 = min;    
    } else {
      min2 = min + 1;
    }

    if (W - A * min2 > B) {
      Console.WriteLine(min2 + " " + max);
    }
    else if (W - B * max < 0 ) {
      Console.WriteLine(min2 + " " + max);
    }
    else {
      Console.WriteLine("UNSATISFIABLE");
    }

  }
}
```
Partially wrong answers


### C - Comma

```cs
using System;
using System.Linq;

class MainClass {
  public static void Main (string[] args) {

    var input = Console.ReadLine().Split().Select(Int64.Parse).ToArray();

    Int64 N = input[0];
    int digit = N.ToString().Length;
    int len3 = digit / 3;
    int residual = (int)(N % 1000);
    int sum = 0;

    //Console.WriteLine(digit + " " + len3 + " " + residual);

    switch (digit) {
      case 1: case 2: case 3:
        break;
      case 4: case 5: case 6:
        sum = ((int)N/(int)(Math.Pow(10, 3)) - 1) * 1 * (int)(Math.Pow(10, 3)) + 1
          + residual;
        break;
      case 7: case 8: case 9:
        sum = ((int)N/(int)(Math.Pow(10, 6)) - 1) * 2 * (int)(Math.Pow(10, 6)) + 1
          + ((int)N/(int)(Math.Pow(10, 3)) - 1) * 1 * (int)(Math.Pow(10, 3)) + 1
          + residual;
        break;
      case 10: case 11: case 12:
        sum = ((int)N/(int)(Math.Pow(10, 9)) - 1) * 3 * (int)(Math.Pow(10, 9)) + 1
          + ((int)N/(int)(Math.Pow(10, 6)) - 1) * 2 * (int)(Math.Pow(10, 6)) + 1
          + ((int)N/(int)(Math.Pow(10, 3)) - 1) * 1 * (int)(Math.Pow(10, 3)) + 1
          + residual;
        break;
      case 13: case 14: case 15:
        sum = ((int)N/(int)(Math.Pow(10, 12)) - 1) * 4 * (int)(Math.Pow(10, 12)) + 1
          + ((int)N/(int)(Math.Pow(10, 9)) - 1) * 3 * (int)(Math.Pow(10, 9)) + 1
          + ((int)N/(int)(Math.Pow(10, 6)) - 1) * 2 * (int)(Math.Pow(10, 6)) + 1
          + ((int)N/(int)(Math.Pow(10, 3)) - 1) * 1 * (int)(Math.Pow(10, 3)) + 1
          + residual;
        break;
      case 16:
        sum = ((int)N/(int)(Math.Pow(10, 15)) - 1) * 5 * (int)(Math.Pow(10, 15)) + 1
          + ((int)N/(int)(Math.Pow(10, 12)) - 1) * 4 * (int)(Math.Pow(10, 12)) + 1
          + ((int)N/(int)(Math.Pow(10, 9)) - 1) * 3 * (int)(Math.Pow(10, 9)) + 1
          + ((int)N/(int)(Math.Pow(10, 6)) - 1) * 2 * (int)(Math.Pow(10, 6)) + 1
          + ((int)N/(int)(Math.Pow(10, 3)) - 1) * 1 * (int)(Math.Pow(10, 3)) + 1
          + residual;
        break;
    }

    Console.WriteLine(sum);

  }
}
```
Partially wrong answers
