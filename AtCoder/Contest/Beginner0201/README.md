## AtCoder Beginner Contest 201
2021-05-15(Sat) 21:00 - 22:40, 100 minutes  
https://atcoder.jp/contests/abc201


### A - Tiny Arithmetic Sequence

```cs
using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>
```

```cs
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
```

> Accepted


### B - Do you know the second highest mountain?

```cs
using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>
```

```cs
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
```

> Accepted