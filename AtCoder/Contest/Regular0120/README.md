## AtCoder Regular Contest 120
2021-05-23(Sun) 20:00 - 22:00, 120 minutes  
https://atcoder.jp/contests/arc120/


### A - Max Add

```cs
/* Sample Input & Output
3
1 2 3

2
8
19
*/
```

#### Trial 1

```cs
using System;
using System.Linq;  // for .Select()
```

```cs
// Read data
int n = int.Parse(Console.ReadLine());
int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();

// f(a) operation of a_0 ~ a_k
for (int i = 0; i < n; i++)
{
    int[] aSub = new int[i+1];              // Initialize for f(a)
    int max = 0, sum = 0;
    for (int j = 0; j <= i; j++)
    {
        max = sum = 0;                      // Initialize for each j-th loop
        for (int k = 0; k <= i; k++)
        {
            if (j == 0)                     // Copy a[] to aSub[] only when j == 0
            {
                aSub[k] = a[k];
            }
            sum += aSub[k];
            max = Math.Max(max, aSub[k]);   // Get max
        }

        // Get sum and update aSub[]
        sum += max;                         // for saving additional loop to calculate sum
        aSub[j] += max;

        // Test
        Console.Write("(k = {0}) max : {1}, aSub : ", i, max);
        Array.ForEach(aSub, Console.Write);
        Console.WriteLine(", sum : {0}", sum);
    }

    // Output
    Console.WriteLine(sum);

} // The end of the i loop
```

> 3  
> 1 2 3

> (k = 0) max : 1, aSub : 2, sum : 2  
> 2  
> (k = 1) max : 2, aSub : 32, sum : 5  
> (k = 1) max : 3, aSub : 35, sum : 8  
> 8  
> (k = 2) max : 3, aSub : 423, sum : 9  
> (k = 2) max : 4, aSub : 463, sum : 13  
> (k = 2) max : 6, aSub : 469, sum : 19  
> 19

> Time Limit Exceeded

#### Trial 2

```cs
using System;
using System.Linq;  // for .Select(), Max()
```

```cs
// Read data
int n = int.Parse(Console.ReadLine());                                  // 3
long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();     // 1 2 3

// f(a) operation of a_0 ~ a_k
for (int i = 0; i < n; i++)
{
    long[] aSub = a[0..(i+1)];                   // Initialize a[]'s subset : [1], [1, 2], [1, 2, 3]

    long sum = 0;
    for (int j = 0; j <= i; j++)
    {
        long max = aSub.Max();                   // Get max of i-th aSub[]
        sum = 0;

        // Get sum and update aSub[]
        aSub[j] += max;
        sum = aSub.Sum();

        // Test
        Console.Write("(k = {0}) max : {1}, aSub : ", i, max);
        Array.ForEach(aSub, Console.Write);
        Console.WriteLine(", sum : {0}", sum);
    }

    // Output
    Console.WriteLine(sum);

} // The end of the i loop
```

> 3  
> 1 2 3

> (k = 0) max : 1, aSub : 2, sum : 2  
> 2  
> (k = 1) max : 2, aSub : 32, sum : 5  
> (k = 1) max : 3, aSub : 35, sum : 8  
> 8  
> (k = 2) max : 3, aSub : 423, sum : 9  
> (k = 2) max : 4, aSub : 463, sum : 13  
> (k = 2) max : 6, aSub : 469, sum : 19  
> 19

> Time Limit Exceeded