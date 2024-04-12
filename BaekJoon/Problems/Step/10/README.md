## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 10. 기하: 직사각형과 삼각형

https://www.acmicpc.net/step/50

(2023.07.02) - `C++`  


## **List**

- [27323. 長方形 (Rectangle, 직사각형)](#27323-長方形-rectangle-직사각형) *(new)*
- [1085. 직사각형에서 탈출](#1085-직사각형에서-탈출)
- [3009. CETVRTA (네 번째 점)](#3009-cetvrta-네-번째-점)
- [15894. 수학은 체육과목 입니다](#15894-수학은-체육과목-입니다) *(new)*
- [9063. 대지](#9063-대지) *(new)*
- [10101. Triangle Times (삼각형 외우기)](#10101-triangle-times-삼각형-외우기) *(new)*
- [5073. Triangles (삼각형과 세 변)](#5073-triangles-삼각형과-세-변) *(new)*
- [14215. 세 막대](#14215-세-막대) *(new)*


**※ Note**

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · `C++` : `#include <iostream>` `#define endl '\n';` `using namespace std;`  



## [27323. 長方形 (Rectangle, 직사각형)](#list)

```txt
2
3
```
```txt
6
```

<details>
  <summary>C++ (2023.07.02)</summary>

```cpp
int main()
{
    // Input
    int a, b;
    cin >> a >> b;

    // Output
    cout << a * b << endl;
    return 0;
}
```
</details>


## [1085. 직사각형에서 탈출](#list)


```txt
6 2 10 3
```
```txt
1
```

<details>
  <summary>C++ (2021.07.19)</summary>

```cpp
int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int minValue;
    minValue = min(min(x, w-x), min(y, h-y));

    cout << minValue << endl;

    return 0;
}
```
</details>


## [3009. CETVRTA (네 번째 점)](#list)

```txt
5 5
5 7
7 5
```
```txt
7 7
```

<details>
  <summary>C++ - Trial 1 (2021.07.20)</summary>

```cpp
#include <iostream>
#include <map>

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
    // Input data
    map<int, int> x, y;
    int temp1, temp2;
    for (int i = 0; i < 3; i++)
    {
        cin >> temp1 >> temp2;
        x.insert(pair<int, int> (temp1, 1));
        y.insert(pair<int, int> (temp2, 1));
    }

    // test
    map<int, int>::iterator it;
    for (it = x.begin(); it != x.end(); it++)
    {
        cout << it->first << ' ' << it->second << endl;
    }
    
    return 0;
}
```
</details>

> 5 5  
> 5 7  
> 7 5

> 5 1  
> 7 1

<details>
  <summary>C++ - Trial 2 (2021.07.20)</summary>

```cpp
#include <iostream>
#include <array>

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
    // Input data
    array<int, 1001> x = {0, }, y = {0, };
    int temp1, temp2;
    for (int i = 0; i < 3; i++)
    {
        cin >> temp1 >> temp2;
        x[temp1]++;
        y[temp2]++;
    }

    // test
    for (int j = 1; j <= 1000; j++)
    {
        if (x[j] != 0) cout << "x : " << j << ' ' << x[j] << endl;
        if (y[j] != 0) cout << "y : " << j << ' ' << y[j] << endl;
    }     

    // Find the 4th point
    int x4 = 0, y4 = 0;
    for (int k = 1; k <= 1000; k++)
    {
        if (x[k] == 1) x4 = k;
        if (y[k] == 1) y4 = k;
        if (x4 != 0 && y4 != 0) break;  // a little sincere attitude, not much
    }   

    // // Output
    cout << x4 << ' ' << y4 << endl;

    return 0;
}
```
</details>

> x : 5 2  
> y : 5 2  
> x : 7 1  
> y : 7 1  
> 7 7


## [15894. 수학은 체육과목 입니다](#list)

```txt
3
```
```txt
12
```

<details>
  <summary>C++ (2023.07.02)</summary>

```cpp
#include <iostream>

#define endl '\n'

using namespace std;
using ll = long long;
```
```cpp
int main()
{
    // Input
    ll n;
    cin >> n;

    // Output
    cout << n * 4 << endl;

    return 0;
}
```
</details>


## [9063. 대지](#list)

```txt
3
20 24
40 21
10 12
```
```txt
360
```

<details>
  <summary>C++ (2023.07.02)</summary>

```cpp
#include <iostream>

// #define test
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Input
    int n;
    cin >> n ;;

    int x, y;
    int xMin = 10000, yMin = 10000, xMax = -10000, yMax = -10000;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (x < xMin) xMin = x;
        if (x > xMax) xMax = x;
        if (y < yMin) yMin = y;
        if (y > yMax) yMax = y;
    }

    // test
    #ifdef test
        printf("xMax:%d, xMin:%d, yMax:%d, yMin:%d\n", xMax, xMin, yMax, yMin);
        printf("xMax-xMin:%d, yMAx-yMin:%d\n", xMax-xMin, yMax-yMin);
    #endif

    // Output
    int area = (xMax - xMin) * (yMax - yMin);
    cout << area << endl;

    return 0;
}
```
</details>


## [10101. Triangle Times (삼각형 외우기)](#list)

```txt
60
70
50
```
```txt
Scalene
```

<details>
  <summary>C++ (2023.07.02)</summary>

```cpp
int main()
{
    // Input
    int a, b, c;
    cin >> a >> b >> c;

    // Operate
    string ans;
    if (a + b + c == 180)
    {
        if (a == 60 && b == 60) ans = "Equilateral";
        else if (a == b || b == c || c == a) ans = "Isosceles";
        else ans = "Scalene";
    }
    else ans = "Error";

    // Output
    cout << ans << endl;
    return 0;
}
```
</details>


## [5073. Triangles (삼각형과 세 변)](#list)

```txt
7 7 7
6 5 4
3 2 5
6 2 6
0 0 0
```
```txt
Equilateral
Scalene
Invalid
Isosceles
```

<details>
  <summary>C++ (2023.07.02)</summary>

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
    while (true)
    {
        // Input
        vector<int> v;
        int n;
        for (int i = 0; i < 3; i++)
        {
            cin >> n;
            v.push_back(n);
        }
        if (v[0] == 0 && v[1] == 0 && v[2] == 0) break;

        // Operate
        string ans;
        sort(v.begin(), v.end());
        if (v[0] + v[1] > v[2])
        {
            if (v[0] == v[1] && v[1] == v[2]) ans = "Equilateral";
            else if (v[0] == v[1] || v[1] == v[2] || v[2] == v[0]) ans = "Isosceles";
            else ans = "Scalene";
        }
        else ans = "Invalid";

        // Output
        cout << ans << endl;
    }

    return 0;
}
```
</details>


## [14215. 세 막대](#list)

```txt
41 64 16
```
```txt
113
```

<details>
  <summary>C++ (2023.07.02)</summary>

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
    // Input
    vector<int> v;
    int n;
    for (int i = 0; i < 3; i++)
    {
        cin >> n;
        v.push_back(n);
    }

    // Operate
    sort(v.begin(), v.end());
    if (v[0] + v[1] <= v[2]) v[2] = v[0] + v[1] - 1;

    // Output
    int sum = v[0] + v[1] + v[2];
    cout << sum << endl;

    return 0;
}
```
</details>
