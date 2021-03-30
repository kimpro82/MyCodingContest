### CodeCraft-21 and Codeforces Round #711 (Div. 2)
2021.03.29 23:35(UTC+9), 2 hrs  
https://codeforces.com/contest/1498/


#### A. GCD Sum

```
# Example Input
3
11
31
75

# Example Output
12
33
75
```

```cs
int T = int.Parse(Console.ReadLine());                          // 3

// read each case and print its output
for (int t = 1; t <= T; t++)
{

    Int64 n = Int64.Parse(Console.ReadLine());                  // 1 <= n <= 10^18
    Int64 max = 0;                                              // for getting gcd from while loop

    // loop for finding next n (n++) until gcdsum > 1
    while (max < 2)
    {
        // 1. read n
        int len = (char)(n.ToString()).Length;

        // 2. gcdSum operation
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += int.Parse(n.ToString()[i].ToString());       // Parse() only recieves string
            // Console.WriteLine("gcdSum op. : {0} {1} {2} ", n, i, sum);       // test
        }

        // 3. gcd operation (Euclidean algorithm)
        max = Math.Max(n, sum);
        Int64 min = Math.Min(n, sum);
        Int64 mod = max;
        while(mod != 0)
        {
            mod = max % min;
            // Console.WriteLine("gcd op. : {0} {1} {2} ", max, min, mod);   // test
            max = min;
            min = mod;
        } // gcd = min when escape while loop

        n += 1; // should be subtracted 1 when escape while loop

    } // the end of while loop

    // 4. output
    // Console.WriteLine("case {0} : {1} {2} ", t, max, n - 1);   // test
    Console.WriteLine(n - 1);


} // the end of t loop
```
> Accepted