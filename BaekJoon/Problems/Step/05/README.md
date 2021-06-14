## BAEKJOON Online Judge

## 문제 > 단계별로 풀어보기 > 5. 1차원 배열
(2021.05.29)  
https://www.acmicpc.net/step/6  

※ C++ codes : **skipped** `main()` function's brace(`{}`) and its outside  
    - Basically, all the codes has the following header and namespace even if there's no mention.  
    `#include <iostream>`  
    `using namespace std;`  
    - When any additional header is used, header block is also noted seperately.


### 10818. 최소, 최대

#### C++ (Trial 1)
```cpp
#include <iostream>
#include <cmath>    // for using min() & max(), but I really hate it
```
```cpp
int t;
cin >> t;

int arr[t];
int minValue = 1000000, maxValue = -1000000, temp;

for (int i = 0; i < t; i++)
{
    cin >> temp;
    arr[i] = temp;
    maxValue = max(maxValue, arr[i]);
    minValue = min(minValue, arr[i]);        
}

cout << minValue << " " << maxValue << endl;

return 0;
```

> 5  
> 20 10 35 30 7

> 7 35

#### C++ (Trial 2)
```cpp
// I really don't want to use for loop with math.max(), math.min().  
// But, consequantially, it was a kind of the lesser evil.
```
```cpp
#include <iostream>
// #include <cstdarg>   // for using va_list, but it can't adopt minmax()
// #include <utility>   // likewise, for using pair<> related with minmax()
#include <vector>       // need to understand by comparing with other similar containers
#include <algorithm>    // for using min_element() and max_element()
```
```cpp
int t;
cin >> t;

vector<int> vec;            // not arr[], because vector<> has variable size
int temp;
for (int i = 0; i < t; i++)
{
    cin >> temp;
    vec.push_back(temp);
}

// pair <int, int> answer;  // for getting output from minmax()
// minmax() requires list<>, not va_list
int minValue = *min_element(vec.begin(), vec.end());    
int maxValue = *max_element(vec.begin(), vec.end());
cout << minValue << " " << maxValue << endl;    // inefficient, crazy

return 0;
```

> 5  
> 20 10 35 30 7

> 7 35


### 2562. 최댓값

#### C++
```cpp
const int length = 9;       // the length of arr[] is fixed as 9
int arr[length];
int maxValue = 0, temp, loc = 0;

for (int i = 0; i < length; i++)
{
    cin >> temp;
    arr[i] = temp;

    if (arr[i] > maxValue)  // all elements of arr[] are different from each other
    {
        maxValue = arr[i];
        loc = i + 1;
    }
}

cout << maxValue << "\n" << loc << endl;

return 0;
```

> 3  
> 29  
> 38  
> 12  
> 57  
> 74  
> 40  
> 85  
> 61

> 85  
> 8


### 2577. 숫자의 개수

#### C++
```cpp
int a, b, c;                        // 100 <= a, b, c < 1000
cin >> a >> b >> c;

string prod = to_string(a * b * c); 
int length = sizeof(prod);
int arr[length] = {};               // initialize arr[] as {0, 0, ……, 0}

for (int i = 0; i < length; i++)
{
    arr[prod[i]-'0']++;             // I did this amazing code! 
}

for (int j = 0; j < 10; j++)
{
    cout << arr[j] << endl;
}

return 0;
```

> 150  
> 266  
> 427

> 3 1 0 2 0 0 0 2 0 0 (vertically)


### 3052. MODULO

#### C++
```cpp
// modulo : 나머지
// distinct number : 서로 다른 숫자 ≒ 중복되지 않는 숫자
```
```cpp
#include <iostream>
#include <set>
```
```cpp
const int length = 10;
int input[length];
set<int> modulo;

for (int i = 0; i < length; i++)
{
    cin >> input[i];
    modulo.insert(input[i] % 42);
}

cout << modulo.size() << endl;

return 0;
```

> 39  
> 40  
> 41  
> 42  
> 43  
> 44  
> 82  
> 83  
> 84  
> 85

> 6


### 1546. 평균

#### C++
```cpp
int t;
cin >> t;

double score[t], maxValue = 0, sum = 0;
for (int i = 0; i < t; i++)
{
    cin >> score[i];
    maxValue = max(maxValue, score[i]);
}

for (int j = 0; j < t; j++)
{
    score[j] *= (1 / maxValue) * 100;
    sum += score[j];
}

cout << sum / t << endl;

return 0;
```

> 3  
> 40 80 60

> 75


### 8958. Score

#### C++
```cpp
int t;
cin >> t;

string input[t];

for (int i = 0; i < t; i++)
{
    cin >> input[i];

    int score = 0, combo = 0;
    for (int j = 0; j < input[i].length(); j++)
    // sizeof() : get memory size of array, not length that I mean
    {
        if (input[i][j] == 'O')
        {
            combo += 1;
            score += combo;
        } else
        {
            combo = 0;
        }

        // test
        cout << "(" << i << ", " << j << ") " 
            << input[i][j] << " " << combo << " " << score << endl;
    }

    cout << score << endl;

}

return 0;
```

> 5  
> OOXXOXXOOO  
> OOXXOOXXOO  
> OXOXOXOXOXOXOX  
> OOOOOOOOOO  
> OOOOXOOOOXOOOOX  

> (0, 0) O 1 1  
> (0, 1) O 2 3  
> (0, 2) X 0 3  
> (0, 3) X 0 3  
> (0, 4) O 1 4  
> (0, 5) X 0 4  
> (0, 6) X 0 4  
> (0, 7) O 1 5  
> (0, 8) O 2 7  
> (0, 9) O 3 10  
> ……

> 10  
> ……


### 4344. Above Average

#### C++
```cpp
int c;
cin >> c;

for (int i = 0; i < c; i++)
{
    int n;
    cin >> n;

    // get sum and average
    int scores[n], sum = 0, average;
    for (int j = 0; j < n; j++)
    {
        cin >> scores[j];
        sum += scores[j];
    }
    average = sum / n;

    // get percentage of students whose grade is above average
    double aboveAverage = 0;
    for (int k = 0; k < n; k++)
    {
        if (scores[k] > average)
        {
            aboveAverage += 1;
        }
    }

    // test
    cout << n << " " << sum << " " << average << " " << aboveAverage << endl;

    // ouput
    double aboveAverageRatio = (double) (aboveAverage / n) * 100;
    cout << fixed;      // output 40.000, not 40
    cout.precision(3);  // 3 : 3 ciphers under decimal point
    cout << aboveAverageRatio << '%' << endl;
}

return 0;
```

> 5  
> 5 50 50 70 80 100  
> 7 100 95 90 80 70 60 50  
> 3 70 90 80  
> 3 70 90 81  
> 9 100 99 98 97 96 95 94 93 91

> 5 350 70 2  
> 7 545 77 4.000  
> ……

> 40.000%  
> 57.143%  
> ……