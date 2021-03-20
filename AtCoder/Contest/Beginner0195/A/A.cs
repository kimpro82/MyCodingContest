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
