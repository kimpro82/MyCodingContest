### Codeforces Round #732 (Div. 2)

2021.07.11(Sun) 23:05, 2.5 hrs  
https://codeforces.com/contest/1546


#### A. AquaMoon and Two Arrays

```cpp
#include <iostream>
#include <array>
```

```cpp
int t;
cin >> t;

for (int i = 0; i < t; i++)
{
    // following codes
}

return 0;
```

```cpp
    // Input data
    int n;
    cin >> n;

    array<int, 100> a = {0, };  // the arrays' sizes are tricky
    array<int, 100> b = {0, };
    int temp;
    for (int j = 0; j < n; j++)
    {
        cin >> temp;
        a[j] = temp;
    }
    for (int k = 0; k < n; k++)
    {
        cin >> temp;
        b[k] = temp;
    }
```

```cpp
    // Make a vector of differences between a and b
    array<int, 100> diff = {0, };
    int sum = 0;
    for (int l = 0; l < n; l++)
    {
        diff[l] = a[l] - b[l];
        sum += diff[l];
    }
```

```cpp
    // Stop if a and b can't be equal to each other
    if (sum != 0)
    {
        cout << -1 << endl;
        continue;
    }
```

```cpp
    // Output m : the number of operations
    int m = 0;
    for (int o = 0; o < n; o++)
    {
        m += abs(diff[o]);
    }
    cout << m / 2 << endl;
```

```cpp
    // Find non-zero numbers / operate positive - 1 & negative + 1  
    int posIdx, negIdx, isRemained = 0;
    while (true)
    {
        for (int idx1 = 0; idx1 < n; idx1++)
        {
            if (diff[idx1] > 0)
            {
                posIdx = idx1;
                isRemained++;
                break;
            }
        }
        for (int idx2 = 0; idx2 < n; idx2++)
        {
            if (diff[idx2] < 0)
            {
                negIdx = idx2;
                isRemained++;
                break;
            }
        }

        if (isRemained == 0) break;         // Operations are done

        cout << posIdx + 1 << " " << negIdx + 1 << endl;

        diff[posIdx]--;
        diff[negIdx]++;
        
        isRemained = 0;
    } // The end of while loop
```

> 4  
> 4  
> 1 2 3 4  
> 3 1 2 4  
> 2  
> 1 3  
> 2 1  
> 1  
> 0  
> 0  
> 5  
> 4 3 2 1 0  
> 0 1 2 3 4

> 2  
> 2 1  
> 3 1  
> -1  
> 0  
> 6  
> 1 4  
> 1 4  
> 1 5  
> 1 5  
> 2 5  
> 2 5

> Accepted