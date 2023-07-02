## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 10. 기하: 직사각형과 삼각형

https://www.acmicpc.net/step/50

() - `C++`  


## **List**

- []()
- [1085. 직사각형에서 탈출](#1085-직사각형에서-탈출)
- [3009. CETVRTA(네 번째 점)](#3009-cetvrta네-번째-점)
- []()
- []()
- []()
- []()
- []()


**※ Note**

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · `C++` : `#include <iostream>` `#define endl '\n';` `using namespace std;`  



## [1085. 직사각형에서 탈출](#list)

> 6 2 10 3

> 1

#### C++ (2021.07.19)
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


## [3009. CETVRTA(네 번째 점)](#list)

> 5 5  
> 5 7  
> 7 5

> 7 7

#### C++ - Trial 1 (2021.07.20)
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
> 5 5  
> 5 7  
> 7 5

> 5 1  
> 7 1

#### C++ - Trial 2 (2021.07.20)
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
> x : 5 2  
> y : 5 2  
> x : 7 1  
> y : 7 1  
> 7 7
