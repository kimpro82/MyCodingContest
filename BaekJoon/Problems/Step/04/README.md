## BAEKJOON Online Judge

## 문제 > 단계별로 풀어보기 > 4. while문
(2021.05.26)  
https://www.acmicpc.net/step/2  
※ C++ codes : **skipped** `main()` function's brace(`{}`) and its outside


### 10952. A+B - 5

#### C++
```cpp
int a, b;

while (true)
{
    cin >> a >> b;
    if (a != 0 || b != 0)       // Readability? vs (a == 0 && b == 0)
    {
        cout << a + b << endl;            
    } else
    {
        break;
    }
}

return 0;
```

> 1 1  
> 2 3  
> 3 4  
> 9 8  
> 5 2  
> 0 0

> 2 5 7 17 7 (vertically)


### 10951. A+B - 4

#### C++
```cpp
int a, b;

while (true)
{

    cin >> a >> b;              // wrong when this line is located after cin.eof()
    if (cin.eof() == true)      // find if the input data finish (EOF; End Of File)
    {
        break;
    } else
    {
        cout << a + b << endl;            
    }
}

return 0;
```

> 1 1  
> 2 3  
> 3 4  
> 9 8  
> 5 2

> 2 5 7 17 7 (vertically)


### 1110. 더하기 사이클

#### C++
```cpp
int n, a, b, ab, t = 0;         // 0 <= n <= 99, n = a * 10 + b, ab = a + b
cin >> n ;                      // n  = 26

ab = n;                         // ab = 26

while (true)
{
    a = ab / 10;                // a  = 2   6
    b = ab % 10;                // b  = 6   8
    ab = a + b;                 // ab = 8   14

    if (ab < 10)
    {
        ab += b * 10;           // ab = 68  

    } else
    {
        ab = b * 10 + ab % 10;  // ab =     84
    }

    t++;

    // Test
    // cout << "n: " << n << " t: " << t << " a: " << a << " b: " << b << " ab: " << ab << '\n';

    if (n == ab)
    {
        break;
    }
}

cout << t << '\n';

return 0;
```

> 26 55 1 0 (vertically)

> 4 3 60 1 (vertically)