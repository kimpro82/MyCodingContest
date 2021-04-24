## AtCoder Beginner Contest 199
2021-04-24(Sat) 21:00 - 22:40  
https://atcoder.jp/contests/abc199


### A - Square Inequality

```cs
using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>
```

```cs
// Read data
List<int> input = Console.ReadLine().Split().Select(int.Parse).ToList();

int a = input[0];
int b = input[1];
int c = input[2];

// Output
if (Math.Pow(a, 2) + Math.Pow(b, 2) < Math.Pow(c,2))
{
    Console.WriteLine("Yes");
} else {
    Console.WriteLine("No");
}
```

> Accepted


### B - Intersection

```cs
using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>
```

```cs
// Read data - A, B who are sequences of length N
int n = int.Parse(Console.ReadLine());                                  // 3
List<int> a = Console.ReadLine().Split().Select(int.Parse).ToList();    // 3 2 5
List<int> b = Console.ReadLine().Split().Select(int.Parse).ToList();    // 6 9 8

// Find max and min values from A and B
int max = 1000, min = 0;
for (int i = 0; i < n; i++)
{
    max = Math.Min(max, Math.Max(a[i], b[i]));              // min of each i-th max
    min = Math.Max(min, Math.Min(a[i], b[i]));              // max of each i-th min
    Console.WriteLine("max : {0}, min : {1}", max, min);    // test
}

// Output
int answer = max - min + 1;
if (answer > 0)
{
    Console.WriteLine(answer);
} else {
    Console.WriteLine(0);
}
```

> max : 6, min : 3  
> max : 6, min : 3  
> max : 6, min : 5  
> 2

> Accepted


### C - IPFL

```cs
using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>
using System.Text;                  // for StringBuilder
```
```cs
// Read data - N, S, Q
int n = int.Parse(Console.ReadLine());
StringBuilder s = new StringBuilder(Console.ReadLine());    // declare as mutable
int q = int.Parse(Console.ReadLine());

// Declare arrays for the below for statement
int[] t = new int[q];
int[] a = new int[q];
int[] b = new int[q];
char[] temp1 = new char[q];
char[] temp2 = new char[q * n];

for (int i = 0; i < q; i++)
{

    // Read data - T, A, B
    List<int> tab = Console.ReadLine().Split().Select(int.Parse).ToList();
    t[i] = tab[0];
    a[i] = tab[1];
    b[i] = tab[2];

    // Operation required
    if (t[i] == 1)                                          // t[i] == 1 : swap s[a[i]-1] ↔ s[b[i]-1]
    {
        temp1[i] = s[a[i]-1];
        s[a[i]-1] = s[b[i]-1];
        s[b[i]-1] = temp1[i];
        Console.WriteLine("Q : {0}, S : {1}", i, s);        // test
    } else {                                                // t[i] == 2 : swap a[0..n-1] ↔ b[n..2n-1]
        for (int j = 0; j < n; j++)
        {
            temp2[i*n+j] = s[j];
            s[j] = s[n+j];
            s[n+j] = temp2[i*n+j];
        }
        Console.WriteLine("Q : {0}, S : {1}", i, s);        // test
    } // The end of if~else statement

} // The end of q loop

// Output
Console.WriteLine(s);
```

> Q : 0, S : IPFL  
> Q : 1, S : LPFI  
> LPFI

> Runtime Error