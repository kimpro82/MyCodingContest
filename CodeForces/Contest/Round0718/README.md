### Contest 2050 and Codeforces Round #718 (Div. 1, 2)

2021.04.23(Fri) 23:35, 2.75 hrs  
https://codeforces.com/contest/1517/


#### A. Sum of 2050

```
# Sample Input & Output
6
205
2050
4100
20500
22550
25308639900

-1
1
2
1
2
36
```

```cs
using System;
```

```cs
int T = int.Parse(Console.ReadLine());          // 2

// Read each case and print its output
for (int t = 1; t <= T; t++)
{
    
    Int64 n = Int64.Parse(Console.ReadLine());  // 22550, 22551

    // Find n's length
    int k = (int) Math.Log10(n);
    Console.WriteLine("k : {0}", k);                                                                // test

    // Find if n is 2050-number
    Int64 ans = 0;
    int sum = 0;
    Int64 divisor;
    for (int i = k-3; i >= 0; i--)
    {
        divisor = (Int64) (2050 * Math.Pow(10, i));
        ans = n / divisor;
        sum += (int) ans;
        Console.WriteLine("n : {0}, divisor : {1}, ans : {2}, sum : {3}", n, divisor, ans, sum);    // test
        n %= divisor;

        if ( n < 2050 )
        {
            break;
        }
    }

    // Output
    if (sum > 0 && n == 0)
    {
        Console.WriteLine(sum);
    } else {
        Console.WriteLine(-1);
    }

} // The end of t loop
```

> k : 4  
> n : 22550, divisor : 20500, ans : 1, sum : 1  
> n : 2050, divisor : 2050, ans : 1, sum : 2  
> 2

> k : 4  
> n : 22551, divisor : 20500, ans : 1, sum : 1  
> n : 2051, divisor : 2050, ans : 1, sum : 2  
> -1