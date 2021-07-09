## AtCoder Beginner Contest 207

2021-06-26(Sat) 21:00 - 22:40, 100 minutes  
https://atcoder.jp/contests/abc207

※ All the codes are written in C++  
    - **skipped** `main()` function's brace(`{}`) and its outside  
    - Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
    - When any additional header is used, the header block is also noted seperately.



### A - Repression

```cpp
#include <iostream>
#include <vector>
#include <algorithm>    // for sort()
```
```cpp
vector<int> arr;
int temp;
for (int i = 0; i < 3; i++)
{
    cin >> temp;
    arr.push_back(temp);
}
sort(arr.begin(), arr.end());   // by ascending order

cout << arr[1] + arr[2] << endl;

return 0;
```
> 3 4 5

> 9

> Accepted



### B - Hydrate

```cpp
long long a, b, c, d;                   // 1 <= a, b, c, d <= 10^5
cin >> a >> b >> c >> d;

long long cyan = a, red = 0, n = 0;     // n : number of the operation
while (true)
{
    if (cyan <= red * d)
    {
        break;
    } else
    {
        if (b >= c * d)                 // something inefficient ……
        {
            n = -1;
            break;
        }
        cyan += b;
        red += c;
        n++;
    }

    // test
    cout << n << " " << cyan << " " << red * d << " " << cyan - red * d << endl;
}

cout << n << endl;

return 0;
```
> 5 2 3 2

> 1 7 6 1  
> 2 9 12 -3  
> 2

> Accepted



### C - Many Segments


#### Trial 1

```cpp
// input data : n
int n;
cin >> n;

// input data : t, l, r
int interval[n][3];
for (int i = 0; i < n; i++)
{
    cin >> interval[i][0] >> interval[i][1] >> interval[i][2];
}

// determine if intersect
int count = 0;
for (int j = 0; j < n - 1; j++)
{
    for (int k = j + 1; k < n; k++)
    {
        if ((interval[j][0] == 1 || interval[j][0] == 3) && (interval[k][0] == 1 || interval[k][0] == 2))
        // ?j] vs [k?
        {
            if ((interval[j][1] < interval[k][2]) && (interval[j][2] >= interval[k][1]))
            {
                count++;
            }
        }
        else if ((interval[j][0] == 1 || interval[j][0] == 2) && (interval[k][0] == 1 || interval[k][0] == 3))
        // ?k] vs [j?
        {
            if ((interval[j][1] <= interval[k][2]) && (interval[j][2] > interval[k][1]))
            {
                count++;
            }
        }
        else
        // ?j) vs (k? / ?k) vs (j? 
        {
            if ((interval[j][1] < interval[k][2]) && (interval[j][2] > interval[k][1]))
            {
                count++;
            }
        }

        // test
        cout << interval[j][1] << " " << interval[j][2] << " "
            << interval[k][1] << " " << interval[k][2] << " " << count << endl;
    }
}

cout << count << endl;

return 0;
```

> 19  
> 4 210068409 221208102  
> 4 16698200 910945203  
> ……  
> 2 415488246 685203817

> 210068409 221208102 16698200 910945203 1  
> 210068409 221208102 76268400 259148323 2  
> ……  
> 797872271 935850549 415488246 685203817 102  
> 102

> Wrong Answer



#### Trial 2

```cpp
// input data : n
int n;
cin >> n;

// input data : t, l[n], r[n] + reflect brackets with tricky way
int t;
float interval[n][2];
for (int i = 0; i < n; i++)
{
    cin >> t >> interval[i][0] >> interval[i][1];
    if (t == 3 || t == 4)   // (l
    {
        interval[i][0] += 0.1;
    }
    if (t == 2 || t == 4)   // r)
    {
        interval[i][1] -= 0.1;
    }
}

// determine if intersect
int count = 0;
for (int j = 0; j < n - 1; j++)
{
    for (int k = j + 1; k < n; k++)
    {
        // my code
        if ((interval[j][0] <= interval[k][1]) && (interval[j][1] >= interval[k][0]))
        {
            count++;
        }

        // test
        cout << interval[j][0] << " " << interval[j][1] << " "
            << interval[k][0] << " " << interval[k][1] << " " << count << endl;
    }
}

cout << count << endl;

return 0;
```

> Wrong Answer

```cpp
        // my code
        // if ((interval[j][0] <= interval[k][1]) && (interval[j][1] >= interval[k][0]))
        // {
        //     count++;
        // }

        // cheating code
        if (max(interval[j][0], interval[k][0]) <= min(interval[j][1], interval[k][1]))
        {
            count++;
        }
```

> Wrong Answer

```cpp
double interval[n][2];
```

> Accepted