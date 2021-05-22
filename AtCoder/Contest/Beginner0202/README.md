## AtCoder Beginner Contest 202
2021-05-22(Sat) 21:00 - 22:40, 100 minutes  
https://atcoder.jp/contests/abc202


### A - Three Dice

```cs
using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>
```

```cs
// Read data
List<int> input = Console.ReadLine().Split().Select(int.Parse).ToList();

// Output
Console.WriteLine(21 - input.Sum());
```

> 1 4 3  
> 13

> 5 6 4  
> 6

> Accepted


### B - 180°

```cs
using System;
using System.Text;  // for using StringBuilder;
```

```cs
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
```

> 0601889  
> 6881090

> 86910  
> 01698

> 01010  
> 01010

> Accepted


### C - Made Up

```cs
using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>
```

```cs
int n = int.Parse(Console.ReadLine());                                  // 3

// Read A, B, C
List<int> a = Console.ReadLine().Split().Select(int.Parse).ToList();    // A
List<int> b = Console.ReadLine().Split().Select(int.Parse).ToList();    // B
List<int> c = Console.ReadLine().Split().Select(int.Parse).ToList();    // C

// Count the number of pairs such that A_i = B_(C_j)
int sum = 0;
for (int i = 1; i <= n; i++)                                            // only 3 rows of A, B, C
{
    for (int j = 1; j <= n; j++)                                        // A1, A2, ..., An
    {
        if (a[i-1] == b[c[j-1]-1])
        {
            sum++;
        }
        Console.WriteLine("({0}, {1}) a[{2}] : {3}, b[{4}] : {5}, count : {6}",
            i, j, i-1, a[i-1], c[j-1]-1, b[c[j-1]-1], sum);             // test
    }
}

// Output
Console.WriteLine(sum);
```

> 3  
> 1 2 2  
> 3 1 2  
> 2 3 2

> (1, 1) a[0] : 1, b[1] : 1, count : 1  
> (1, 2) a[0] : 1, b[2] : 2, count : 1  
> ……  
> (3, 3) a[2] : 2, b[1] : 1, count : 4  
> 4

> Time Limit Exceeded