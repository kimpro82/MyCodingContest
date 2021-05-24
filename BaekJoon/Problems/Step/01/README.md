## BAEKJOON Online Judge
문제 > 단계별로 풀어보기 > 1. 입출력과 사칙연산  
https://www.acmicpc.net/step/1


### 2557. Hello World

#### Python
```python
print("Hello World!")
```

#### C++
```cpp
cout << "Hello World!" << endl;
return 0;
```


### 10718. We love kriii

#### Python
```python
for i in range(0, 2) :
    print("강한친구 대한육군")
```

#### C++
```cpp
for (int i = 0; i < 2; i++)
{
    cout << "강한친구 대한육군" << endl;
}

return 0;
```


### 10171. Cats

#### Python
```python
print("\    /\\")
print(" )  ( ')")
print("(  /  )")
print(" \\(__)|")
```

#### C++
```cpp
    cout << "\\    /\\" << endl;
    cout << " )  ( ')" << endl;
    cout << "(  /  ) " << endl;
    cout << " \\(__)|" << endl;

    return 0;
```


### 10172. Dogs

#### Python
```python
print("""|\\_/|
|q p|   /}
( 0 )\"\"\"\\
|"^"`    |
||_/=\\\\__|""")
```

#### C++ - trial 1
```cpp
cout << R"(
|\_/|
|q p|   /}
( 0 )"""\
|"^"`    |
||_/=\\__|
)" << endl;

return 0;
```

#### C++ - trial 2
```cpp
//     cout << R"(
// |\_/|
// |q p|   /}
// ( 0 )"""\
// |"^"`    |
// ||_/=\\__|
// )" << endl;

cout << "|\\_/|" << endl;
cout << "|q p|   /}" << endl;
cout << "( 0 )\"\"\"\\" << endl;
cout << "|\"^\"`    |" << endl;
cout << "||_/=\\\\__|" << endl;

return 0;
```


### 1000. A+B

#### Python
```python
a, b = map(int, input().split())
print(a+b)
```

#### C++
```cpp
int a, b;
cin >> a >> b;
cout << a + b << endl;

return 0;
```


### 1001. A-B

#### Python
```python
a, b = map(int, input().split())
print(a-b)
```

#### C++
```cpp
int a, b;
cin >> a >> b;
cout << a - b << endl;

return 0;
```


### 10998. A*B

#### Python
```python
a, b = map(int, input().split())
print(a*b)
```

#### C++
```cpp
int a, b;
cin >> a >> b;
cout << a * b << endl;

return 0;
```


### 1008. A/B

#### Python
```python
a, b = map(float, input().split())
print(a/b)
```

#### C++
```cpp
int a, b;
cin >> a >> b;
cout.precision(10);             // for reducing error < 10^(-9)
cout << (double)a / b << endl;

return 0;
```


### 10869. 사칙연산

#### Python
```python
a, b = map(int, input().split())

print(a+b)
print(a-b)
print(a*b)
print(int(a/b))
print(a%b)
```

#### C++
```cpp
int a, b;
cin >> a >> b;

cout << a + b << endl;
cout << a - b << endl;
cout << a * b << endl;
cout << a / b << endl;
cout << a % b << endl;

return 0;
```


### 10430. 나머지

#### Python
```python
A, B, C = map(int, input().split())

print((A+B)%C)
print(((A%C) + (B%C))%C)
print((A*B)%C)
print(((A%C)*(B%C))%C)
```

#### C++
```cpp
int A, B, C;
cin >> A >> B >> C;

cout << (A+B)%C << endl;
cout << ((A%C)+(B%C))%C << endl;
cout << (A*B)%C << endl;
cout << ((A%C)*(B%C))%C << endl;

return 0;
```


### 2588. 곱셈

#### Python - trial 1
```python
a = int(input())
b = str(input())

for i in range(0,len(b)) :
    print(a*int(b[-i-1]))

print(a*int(b))
```

#### Python - trial 2
```python
a = int(input())
b = str(input())

sum = 0
for i in range(0,len(b)) :
    answer = a * int(b[-i-1])
    print(answer)
    sum += answer * pow(10, i)

print(sum)
```

#### C++
```cpp
#include <iostream>
#include <math.h>
```
```cpp
int a;
// char b[3];                       // trial 1-1 : a = 256 when declare char b[3]
// char b[4];                       // trial 1-2 
string b;                           // trial 1-3 : change char[] to string
cin >> a;                           // 472
cin >> b;                           // 385
// cout << a << " " << b << endl;   // test
int len = b.length();

int sum = 0;
for (int i = 0; i < len; i++)
{
    // Test : get each cipher's integer number, not ascii code
    // cout << "b[" << len-i-1 << "] : " << b.at(len-i-1) << endl;              // b[2], b[1], b[0] / OK
    // cout << "convert to int 1 : " << (int) b.at(len-i-1) << endl;            // failure because output its ascii code
    // cout << "convert to int 2 : " << (int) (b.at(len-i-1) - '0') << endl;    // success
    short digit = (int) (b[3-i-1] - '0');

    // The ways to get 100 by pow(10, 3) (Remove // from only one line)
    // int cipher = pow(10, i);                                                 // trial 2-1 : vanilla double pow() - 99- 180304
    // int cipher = (int) pow(10, i);                                           // trial 2-2 : (int) double pow() - 99 - 180304
    // int cipher = (int) powl(10, i);                                          // trial 2-3 : (int) long double powl() - 99 - 180304
    // int cipher = pow(10, i);                                                 // trial 2-4 : the same with 1 but run by C++17(Clang) - Correct
    // int cipher = pow(10.0, i);                                               // trial 2-5 : use 10.0 - 99 - 180304
    int cipher = round(pow(10, i));                                          // trial 2-6 : round(pow()) - Correct
    // cout << a << " " << (int) digit << " " << cipher << endl;                // test

    // Operation for each cipher
    int prod = a * (int) digit;                                                 // get difference between ascii codes of (b[3-i-1]) and '0'
    sum += prod * cipher;

    // Output
    // cout << prod << " " << sum - prod << " " << sum << endl;    // test
    cout << prod << endl;
}

// Output
// cout << sum + 1 << endl; // can't find why lack of 1 - crazy!
cout << sum << endl;        // go honest

return 0;
```