### Codeforces Round #715 (Div. 2)
2021.04.16(Fri) 23:35(UTC+9), 2.25 hrs  
https://codeforces.com/contest/1509


#### A. Average Height

```
# Example Input
4
3
1 1 2
3
1 1 1
8
10 9 13 15 3 16 9 13
2
18 9

# Example Output
1 1 2 
1 1 1 
13 9 13 15 3 9 16 10 
9 18
```

```cs
using System;
using System.Linq;
```

```cs
int T = int.Parse(Console.ReadLine());                                  // 4

// Read each case and print its output
for (int t = 1; t <= T; t++)
{
    int n = int.Parse(Console.ReadLine());                              // 8
    var input = Console.ReadLine().Split().Select(int.Parse).ToArray(); // 10 9 13 15 3 16 9 13

    // Seperate odd and even numbers
    int[] array = new int[n];
    int odd = 0;
    int even = 0;
    for (int i = 0; i < n; i++)
    {
        if (input[i] % 2 == 1)
        {
            array[odd] = input[i];
            odd++;
        } else {
            array[n-even-1] = input[i];
            even++;
        }
    }

    // Output
    for (int j = 0; j < n; j++)
    {
        Console.Write(array[j] + " ");
    }
    Console.WriteLine();

} // The end of t loop
```
> Accepted


#### B. TMT Document

```
# Example Input
5
3
TMT
3
MTT
6
TMTMTT
6
TMTTTT
6
TTMMTT

# Example Output
YES
NO
YES
NO
YES
```

```cs
using System;
using System.Text; // for StringBuilder
```

```cs
int T = int.Parse(Console.ReadLine());                                  // 5

// Read each case and print its output
for (int t = 1; t <= T; t++)
{

    int n = int.Parse(Console.ReadLine());                              // 3
    StringBuilder input = new StringBuilder(Console.ReadLine());        // TMT

    // Count T and M
    double tCount = 0;
    double mCount = 0;
    for (int i = 0; i < n; i++)
    {

        if (input[i] == 'T')
        {
            tCount++;
        } else {
            mCount++;
        }

        if ( (tCount < mCount) || (tCount - mCount > (n/3)) )           // "No" ex1) MTT, MMT ex2) TTTTMM
        {
            break;
        }

    }

    // Output
    if ( (tCount < mCount) || (tCount - mCount > (n/3)) )
    {
        Console.WriteLine("NO");                    
    } else if ((double)(n / tCount) == 1.5) {
        Console.WriteLine("YES");
    } else {
        Console.WriteLine("NO");
    }

} // The end of t loop
```
> Accepted