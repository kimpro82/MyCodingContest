## AtCoder Regular Contest 117  
2021-04-18(Sun) 21:00 - 23:00, 2 hrs  
https://atcoder.jp/contests/arc117/


### A - God Sequence

```cs
/* Sample Input & Output
1 1
1001 -1001
1 4
-8 -6 -9 120 -97
7 5
323 -320 411 206 -259 298 -177 -564 167 392 -628 151
*/
```

```cs
using System;
using System.Linq; // for .Select()
```

```cs
// Read input data
var input = Console.ReadLine().Split().Select(int.Parse).ToArray();
int a = (int)input[0]; // positive integers
int b = (int)input[1]; // negative integers

int aSum = 0;
int bSum = 0;

// Output for each cases
if (a >= b)
{

    for (int i = 1; i <= a; i++)            // generate positive numbers
    {
        Console.Write(i + " ");
        aSum += i;
    }
    for (int j = 1; j <= b-1; j++)          // generate negative numbers except the last one
    {
        Console.Write(-j + " ");
        bSum -= j;
    }
    Console.Write(-(aSum + bSum) + "\n");

} else {                                    // (b > a)

    for (int j = 1; j <= b; j++)            // generate negative numbers
    {
        Console.Write(-j + " ");
        bSum -= j;
    }
    for (int i = 1; i <= a-1; i++)          // generate positive numbers except the last one
    {
        Console.Write(i + " ");
        aSum += i;
    }
    Console.Write(-(aSum + bSum) + "\n");
```
> Accepted

