## BAEKJOON Online Judge
문제 > 단계별로 풀어보기 > 3. for문  
https://www.acmicpc.net/step/3  
※ C++ codes : **skipped** `main()` function's brace(`{}`) and its outside


### 2739. 구구단

#### C++
```cpp
int a;
cin >> a;

for (int i = 1; i <= 9; i++)
{
    cout << a << " * " << i << " = " << a * i << endl;
}

return 0;
```
> 2

> 2 * 1 = 2  
> 2 * 2 = 4  
> ……  
> 2 * 9 = 18


### 10950. A+B - 3

#### C++
```cpp
int t, a, b;
cin >> t;

for (int i = 1; i <= t; i++)
{
    cin >> a >> b;
    cout << a + b << endl;
}

return 0;
```

> 5  
> 1 1  
> 2 3  
> 3 4  
> 9 8  
> 5 2

> 2 5 7 17 7 (vertically)


### 8393. Sum

#### C++
```cpp
int a;
cin >> a;

int sum = 0;
for (int i = 1; i <= a; i++)
{
    sum += i;
}
cout << sum << endl;

return 0;
```

> 10

> 55


### 15552. 빠른 A+B

#### C++
```cpp
// make cin/cout faster
cin.tie(NULL);
ios_base::sync_with_stdio(false);

int t, a, b;
cin >> t;

for (int i = 1; i <= t; i++)
{
    cin >> a >> b;
    cout << a + b << '\n';          // \n is faster than endl
}

return 0;
```

> 5  
> 1 1  
> 12 34  
> 5 500  
> 40 60  
> 1000 1000

> 2 46 505 100 2000 (vertically)


### 2741. N 찍기

#### C++
```cpp
// make cin/cout faster
cin.tie(NULL);
ios_base::sync_with_stdio(false);

int a;
cin >> a;

for (int i = 1; i <= a; i++)
{
    cout << i << '\n';              // \n is faster than endl
}

return 0;
```

> 5

> 1 2 3 4 5 (vertically)


### 2742. 기찍 N

#### C++
```cpp
// make cin/cout faster
cin.tie(NULL);
ios_base::sync_with_stdio(false);

int a;
cin >> a;

for (int i = a; i >= 1; i--)
{
    cout << i << '\n';              // \n is faster than endl
}

return 0;
```

> 5

> 5 4 3 2 1 (vertically)


### 11021. A+B - 7

#### C++
```cpp
int t, a, b;
cin >> t;

for (int i = 1; i <= t; i++)
{
    cin >> a >> b;
    cout << "Case #" << i << ": " << a + b << endl;
}

return 0;
```

> 5  
> 1 1  
> 2 3  
> 3 4  
> 9 8  
> 5 2  

> Case #1: 2  
> Case #2: 5  
> ……  
> Case #5: 7


### 11022. A+B - 8

#### C++
```cpp
int t, a, b;
cin >> t;

for (int i = 1; i <= t; i++)
{
    cin >> a >> b;
    cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << endl;
}

return 0;
```

> 5  
> 1 1  
> 2 3  
> 3 4  
> 9 8  
> 5 2  

> Case #1: 1 + 1 = 2  
> Case #2: 2 + 3 = 5  
> ……  
> Case #5: 5 + 2 = 7


### 2438. 별 찍기 - 1

#### C++
```cpp
int a;
cin >> a;

for (int i = 1; i <= a; i++)
{
    // cout << '*' * i << endl;        // calculate ascii code number(42) * i
    for (int j = 1; j <= i; j++)
    {
        cout << '*' ;
    }
    cout << '\n' ;
}

return 0;
```

> 5

> \*  
> \*\*  
> \*\*\*  
> \*\*\*\*  
> \*\*\*\*\*


### 2439. 별 찍기 - 2

#### C++
```cpp
int a;
cin >> a;

for (int i = 1; i <= a; i++)
{
    for (int j = 1; j <= a; j++)
    {
        if (i < a - j + 1)
        {
            cout << ' ' ;
        } else {
            cout << '*' ;
        }
    }
    cout << '\n' ;
}

return 0;
```

> 5

> &nbsp;&nbsp;&nbsp;&nbsp;\*  
> &nbsp;&nbsp;&nbsp;\*\*  
> &nbsp;&nbsp;\*\*\*  
> &nbsp;\*\*\*\*  
> \*\*\*\*\*


### 10871. X보다 작은 수

#### C++
```cpp
int n, x;
int arr[10000];                 // .exe file stops when int arr[n], although compilation succeeded
cin >> n >> x;

for (int i = 0; i < n; i++)
{
    cin >> arr[i];
    if (arr[i] < x)
    {
        cout << arr[i] << ' ';
    }
}
cout << '\n';

return 0;
```

> 10 5  
> 1 10 4 9 2 3 8 5 7 6

> 1 4 2 3