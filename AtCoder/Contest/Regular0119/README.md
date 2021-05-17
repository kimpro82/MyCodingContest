## AtCoder Regular Contest 119
2021-05-16(Sun) 21:00 - 23:00, 120 minutes  
https://atcoder.jp/contests/arc119/


### A - 119 × 2^23 + 1

```cs
/* Sample Input & Output
998244353
143

1000000007
49483

1
1

998984374864432412
2003450165
*/
```

#### Trial 1

```cs
using System;
```

```cs
// Read data
ulong n = ulong.Parse(Console.ReadLine());

// Get a, b, c (mod = a * 2^b +c, exp = 2^b)
ulong a = 0, b = 0, c = 0, exp;
while (true)                            // get b
{
    exp = (ulong)Math.Pow(2, b);
    if (exp >= n)
    {
        exp = (ulong)Math.Pow(2, --b);  // 2^b is already over n
        break;
    } else {
        b++;
    }
}
a = n / exp;                            // get a
c = n - a * exp;                        // get c

Console.WriteLine("a : {0}, b : {1}, exp : {2}, c : {3} ", a, b, exp, c);   // test

// Output
Console.WriteLine(a + b + c);
```

> 998244353

> a : 1, b : 29, exp : 536870912, c : 461373441  
> 461373471

#### Trial 2

```cs
using System;
```

```cs
// Read data declare variables
ulong n = ulong.Parse(Console.ReadLine());
ulong a = 0, c = 0, sum = 0, minSum = n, exp;   // sum = a + b + c, exp = 2^b, b doesn't be used

// Get max of b first
int maxB = 0;
while (true)
{
    exp = (ulong)Math.Pow(2, maxB);
    if (exp > n)
    {
        break;
    } else {
        maxB++;
    }
}

// Get a, b, c and sum and find min of sum
for (int i = 0; i < maxB; i++)
{
    exp = (ulong)Math.Pow(2, i);
    a = n / exp;                                // get a
    c = n - a * exp;                            // get c
    sum = a + (ulong)i + c;                     // get sum, b = i

    // Find min of sum
    if (sum < minSum)
    {
        minSum = sum;
    }

    // Test
    Console.WriteLine("a : {0}, b : {1}, exp : {2}, c : {3}, sum : {4}, minSum : {5}",
        a, i, exp, c, sum, minSum);
}

// Output
Console.WriteLine(minSum);
```

> 998244353

> a : 998244353, b : 0, exp : 1, c : 0, sum : 998244353, minSum : 998244353  
> a : 499122176, b : 1, exp : 2, c : 1, sum : 499122178, minSum : 499122178  
> a : 249561088, b : 2, exp : 4, c : 1, sum : 249561091, minSum : 249561091  
> ……  
> a : 119, b : 23, exp : 8388608, c : 1, sum : 143, minSum : 143  
> ……  
> a : 1, b : 29, exp : 536870912, c : 461373441, sum : 461373471, minSum : 143  
> 143

> Accepted