## AtCoder Beginner Contest 213

2021-08-08(Sat) 21:00 - 22:40, 100 minutes  
https://atcoder.jp/contests/abc213

※ All the codes are written in C++


### A - Bitwise Exclusive Or

#### C++
```cpp
#include <iostream>

#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    int A, B, C;
    cin >> A >> B;

    C = A ^ B;

    cout << C << endl;

    return 0;
}
```

> 3 6

> 5

> Accepted


### B - Booby Prize

#### C++
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Input data
    int N;
    cin >> N;

    int temp;
    vector<int> v;
    for (int n = 0; n < N; n++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    // Copy vector v and sort
    vector<int> v2 = v;
    sort(v2.begin(), v2.end());

    // Find the index in v that is the same with the [N-1]-th element in v2
    int prize = v2[N-2], ans;
    for (int i = 0; i < N; i++)
    {
        if (v[i] == prize)
        {
            ans = i + 1;
            break;
        }
    }

    // Output
    cout << ans << endl;

    return 0;
}
```

> 6  
> 1 123 12345 12 1234 123456

> 3

> Accepted


### C - Reorder Cards

#### C++
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Input data
    int H, W, N;
    cin >> H >> W >> N;

    int temp1, temp2;
    vector<vector<int>> v = {vector<int> {0, 0}};
    for (int n = 0; n < N; n++)
    {
        cin >> temp1 >> temp2;
        v.push_back(vector<int> {temp1, temp2});
    }

    // test
    for (int n = 0; n <= N; n++)cout << v[n][0] << ' ' << v[n][1] << endl;

    // Get rank and output
    int rank1, rank2, max1, max2;
    for (int i = 1; i <= N; i++)
    {
        rank1 = 1;
        rank2 = 1;
        max1 = 0;
        max2 = 0;

        for (int j = 1; j <= N; j++)
        {
            if (v[j][0] > max1)
            {
                max1 = v[j][0];
                rank1++;
            }
            if (v[j][1] > max2)
            {
                max2 = v[j][1];
                rank2++;
            }
        }

        cout << rank1 << ' ' << rank2 << endl;
    }

    return 0;
}
```

> 

> 

> 