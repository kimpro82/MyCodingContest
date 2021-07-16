## BAEKJOON Online Judge

### 문제 > 단계별로 풀어보기 > 2. if문
(2021.05.24) - Python, C++  
(2021.07.14) - R  
https://www.acmicpc.net/step/4  

※ The codes of `Python`, `C++` and `R` has the same result  
※ C++ codes : **skipped** `main()` function's brace(`{}`) and its outside


### 1330. 두 수 비교하기

#### C++
```cpp
int a, b;
cin >> a >> b;          // 1 2, 10 2, 5 5

if (a > b)
{
    cout << ">" << endl;
} else if (a < b)
{
    cout << "<" << endl;
} else
{
    cout << "==" << endl;
}

return 0;
```

> <  
> >  
> ==


### 9498. 시험 성적

#### C++
```cpp
int a;
cin >> a;                   // 99, 82, 79, 60, 37

if (a >= 90)
{
    cout << "A" << endl;
} else if (a >= 80)
{
    cout << "B" << endl;
} else if (a >= 70)
{
    cout << "C" << endl;
} else if (a >= 60)
{
    cout << "D" << endl;
} else
{
    cout << "F" << endl;
}

return 0;
```

> A B C D F (vertically)


### 2753. 윤년

#### C++
```cpp
int a;
cin >> a;                                           // 2021, 2000, 1900

if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))
{
    cout << 1 << endl;
} else
{
    cout << 0 << endl;
}

return 0;
```

> 0 1 0 (vertically)


### 14681. Quadrant Selection

#### C++
```cpp
int a, b;
cin >> a >> b;           // 12 5, 9 -13
// A given condition : Neither of the two coordinates will be 0.

if (a > 0 && b > 0)
{
    cout << 1 << endl;
} else if (a < 0 && b > 0)
{
    cout << 2 << endl;
} else if (a < 0 && b < 0)
{
    cout << 3 << endl;
} else
{
    cout << 4 << endl;
}

return 0;
```

> 1  
> 4


### 2884. SPAVANAC

#### C++
```cpp
int a, b;
cin >> a >> b;           // 10 10, 0 30, 23 40

if (b < 45)
{
    a--;
    b += 60;
}
if (a < 0)
{
    a += 24;
}

cout << a << " " << b - 45 << endl;

return 0;
```

> 9 25  
> 23 45  
> 22 55