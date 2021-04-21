### Codeforces Round #717 (Div. 2)

2021.04.21(Wed) 22:35, 2.25 hrs  
https://codeforces.com/contest/1516


#### B. AGAGA XOOORRR

```
# Sample Input & Output
2
3
0 2 2
4
2 3 1 10

YES
NO
```

##### Trial 1
```cs
using System;
using System.Linq;                  // for .Select()
using System.Collections.Generic;   // for List<>
```
```cs
int T = int.Parse(Console.ReadLine());                                      // 2

// Read each case and print its output
for (int t = 1; t <= T; t++)
{
    
    int n = int.Parse(Console.ReadLine());                                  // 3
    List<int> a = Console.ReadLine().Split().Select(int.Parse).ToList();    // 0 2 2

    // Bitwise XOR operation
    while (n > 2)
    {
        a[1] = a[0]^a[1];
        a.RemoveAt(0);
        n--;
    }

    // Output when list a's length = 2
    if (a[0] == a[1])
    {
        Console.WriteLine("YES");
    } else {
        Console.WriteLine("NO");
    }

} // The end of t loop
```
> Wrong answer on test 3

##### Trial 2
```cs
while (n > 2)                                                           // can't use a.Length
{

    // Bitwise XOR operation
    a[1] = a[0]^a[1];
    a.RemoveAt(0);
    n--;

    // Check if all elements of a are equal
    int max = 0;
    int min = (int) Math.Pow(2, 30);                                    // should be converted to integer type
    for (int i=0; i < n; i++)
    {
        max = Math.Max(a[i], max);
        min = Math.Min(a[i], min);
    }
    Console.WriteLine("({0}) max : {1}, min : {2}", n, max, min);       // test
    if (max == min)
    {
        break;
    }

}

// Output
Console.WriteLine("a[0] : {0}, a[1] : {1}", a[0], a[1]);                // test
if (a[0] == a[1])
{
    Console.WriteLine("YES");
} else {
    Console.WriteLine("NO");
}
```
> Wrong answer on test 3

##### Trial 3
```cs
while (n > 2)                                                           // can't use a.Length
{

    // Check if all elements of a are equal
    int max = 0;
    int min = (int) Math.Pow(2, 30);                                    // should be converted to integer type
    for (int i=0; i < n; i++)
    {
        max = Math.Max(a[i], max);
        min = Math.Min(a[i], min);
    }
    // Console.WriteLine("({0}) max : {1}, min : {2}", n, max, min);       // test
    if (max == min)
    {
        break;
    }

    // Bitwise XOR operation
    a[1] = a[0]^a[1];
    a.RemoveAt(0);
    n--;

}

// Output
// Console.WriteLine("({0}) a[0] : {1}, a[1] : {2}", n, a[0], a[1]);       // test
if (a[0] == a[1])
{
    Console.WriteLine("YES");
} else {
    Console.WriteLine("NO");
}
```
> Wrong answer on test 4

I hate you!