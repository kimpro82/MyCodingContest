### Educational Codeforces Round 112 (Rated for Div. 2)

2021.07.30 23:35, 2 hrs  
https://codeforces.com/contest/1555

※ All the codes are written in C++  
    - **skipped** `main()` function or a loop for each test case's brace(`{}`) and its outside  
    - Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
    - When any additional header is used, the header block is also noted seperately.


#### A. PizzaForces

```cpp
using ll = long long;
#define endl '\n'
```

```cpp
// Input data
ll n;
cin >> n;

// Calculate minimum time
ll s10, time = 0;
if (n < 20) s10 = 0;
else {
    s10 = (n / 10) - 1;
    time += s10 * 25;
}
ll res = n - (10 * s10);
if (res <= 6) time += 15;
else if (res <= 8) time += 20;
else if (res <= 10) time += 25;
else if (res <= 12) time += 30;
else if (res <= 14) time += 35;
else if (res <= 16) time += 40;
else if (res <= 18) time += 45;
else time += 50;

// Output
cout << time << endl;
```

> 6  
> 12  
> 15  
> 300  
> 1  
> 9999999999999999  
> 3

> 30  
> 40  
> 750  
> 15  
> 25000000000000000  
> 15

> Accepted


#### B. Two Tables

```cpp
#include <iostream>
#include <cmath>
#include <array>

using namespace std;

#define endl '\n'
```

```cpp
// Input data
int W, H, x1, y1, x2, y2, w, h;
cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

// Calculate distance
int distance, dist1 = -1, dist2 = -1, dist3 = -1, dist4 = -1;   // don't need to declare distance as double
if ((x2 - x1) + w > W && (y2 - y1) + h > H) distance = -1;
else if ((x2 - x1) + w <= W && (y2 - y1) + h > H)
{
    dist1 = max(w - x1, 0);
    dist2 = max((x2 + w) - W, 0);
    distance = min(dist1, dist2);

    // test
    cout << (x2 - x1) + w << ' ' << (y2 - y1) + h << " (else if 1) "  << dist1 << ' ' << dist2 << endl;
}
else if ((x2 - x1) + w > W && (y2 - y1) + h <= H)
{
    dist1 = max(h - y1, 0);
    dist2 = max((y2 + h) - H, 0);
    distance = min(dist1, dist2);

    // test
    cout << (x2 - x1) + w << ' ' << (y2 - y1) + h << " (else if 2) "  << dist1 << ' ' << dist2 << endl;
}
else
{
    dist1 = max(w - x1, 0);
    dist2 = max((x2 + w) - W, 0);
    dist3 = max(h - y1, 0);
    dist4 = max((y2 + h) - H, 0);
    array<int, 3> dist = {dist2, dist3, dist4};
    int minValue = dist1;
    for (int j = 0; j < 3; j++) if (dist[j] < minValue) minValue = dist[j];
    distance = minValue;

    // cout << "An else case exists! {" << i << '}' << endl;    // to find failed test case
    // continue;
}

// Output
// cout.precision(10);
cout << distance << endl;
```

> 5  
> 8 5  
> 2 1 7 4  
> 4 2  
> 5 4  
> 2 2 5 4  
> 3 3  
> ……

> 9 5 (else if 2) 1 1  
> 1  
> -1  
> ……

> Accepted