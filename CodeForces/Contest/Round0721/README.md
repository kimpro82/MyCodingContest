### Codeforces Round #721 (Div. 2)

2021.05.20(Thu) 23:35, 2.00 hrs  
https://codeforces.com/contest/1527/


#### A. And Then There Were K

```
# Sample Input & Output
3
2
5
17

1
3
15
```

```cs
using System;
```

```cs
int T = int.Parse(Console.ReadLine());      // 3

// Read each case t times
for (int t = 1; t <= T; t++)
{
    
    int n = int.Parse(Console.ReadLine());  // 2, 5, 17

    // Bitwise & operation
    int k = n;
    while (n != 0)
    {
        k = n - 1;
        n = n & k;
        // Console.WriteLine("{0} : {1}", k, n);   // test
    }

    // Output
    Console.WriteLine(k);

}
```

> 2  
> 1 : 0  
> 1

> 5  
> 4 : 4  
> 3 : 0  
> 3

> 17  
> 16 : 16  
> 15 : 0  
> 15


#### B1, B2. Palindrome Game (easy/hard version)

```
# Sample Input & Output
2
4
1001
1
0

BOB
BOB
```

```cs
using System;
using System.Text; // for using StringBuilder
```

```cs
int T = int.Parse(Console.ReadLine());                                  // 2

// Read each case t times
for (int t = 1; t <= T; t++)
{
    
    int n = int.Parse(Console.ReadLine());                              // 4, 1
    StringBuilder sb = new StringBuilder(Console.ReadLine());           // 1001, 0

    // Judge if sb is "palindrome"
    StringBuilder sbReverse = new StringBuilder();
    for (int i = 0; i < n; i++)
    {
        sbReverse.Append(sb[n-i-1]);
    }
    bool palindromeScore = true;
    for (int j = 0; j < n; j++)
    {
        if (sb[j] != sbReverse[j])
        {
            palindromeScore = false;
            break;
        }
    }

    // Judge if n is odd and the center is 0
    bool center0 = false;
    if (n > 1 && n % 2 != 0)    // avoid when n = 1
    {
        if (sb[(n-1)/2] == '0')
        {
            center0 = true;
        }
    }

    // Output
    if (palindromeScore)
    {
        if (center0)
        {
            Console.WriteLine("ALICE");
        } else {
            Console.WriteLine("BOB");
        }
    } else {
        if (!center0)
        {
            Console.WriteLine("ALICE");
        } else {
            Console.WriteLine("BOB");
        }
    }

}
```

> B1 - Palindrome Game (easy version)  
> Wrong answer on test 3  
> wrong answer 244th words differ - expected: 'BOB', found: 'ALICE'

> B2 - Palindrome Game (hard version)  
> Wrong answer on test 2  
> wrong answer 5th words differ - expected: 'ALICE', found: 'BOB'