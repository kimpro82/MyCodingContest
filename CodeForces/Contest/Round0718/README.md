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
    
    Int64 n = Int64.Parse(Console.ReadLine());  // 205, 25308639900

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

> k : 2  
> -1

> k : 10  
> n : 25308639900, divisor : 20500000000, ans : 1, sum : 1  
> n : 4808639900, divisor : 2050000000, ans : 2, sum : 3  
> n : 708639900, divisor : 205000000, ans : 3, sum : 6  
> n : 93639900, divisor : 20500000, ans : 4, sum : 10  
> n : 11639900, divisor : 2050000, ans : 5, sum : 15  
> n : 1389900, divisor : 205000, ans : 6, sum : 21  
> n : 159900, divisor : 20500, ans : 7, sum : 28  
> n : 16400, divisor : 2050, ans : 8, sum : 36  
> 36