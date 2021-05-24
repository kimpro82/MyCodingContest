## BAEKJOON Online Judge
문제 > 단계별로 풀어보기 > 1. 입출력과 사칙연산  
https://www.acmicpc.net/step/1  
※ The codes of `Python` and `C++` has the same result  
※ C++ codes : Skipped main() function's brace and its outside


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

> Hello World!


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

> 강한친구 대한육군  
> 강한친구 대한육군


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

> \    /\  
>  )  ( ')  
> (  /  )   
>  \\(__)|  


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
cout << "|\\_/|" << endl;
cout << "|q p|   /}" << endl;
cout << "( 0 )\"\"\"\\" << endl;
cout << "|\"^\"`    |" << endl;
cout << "||_/=\\\\__|" << endl;

return 0;
```

> |\\_/|  
> |q p|   /}  
> ( 0 )"""\  
> |"^"`    |  
> ||_/=\\\\__|  


### 1000. A+B

#### Python
```python
a, b = map(int, input().split())
print(a+b)
```

#### C++
```cpp
int a, b;
cin >> a >> b;          // 1 2
cout << a + b << endl;

return 0;
```

> 3


### 1001. A-B

#### Python
```python
a, b = map(int, input().split())
print(a-b)
```

#### C++
```cpp
int a, b;
cin >> a >> b;          // 3 2
cout << a - b << endl;

return 0;
```

> 1


### 10998. A*B

#### Python
```python
a, b = map(int, input().split())
print(a*b)
```

#### C++
```cpp
int a, b;
cin >> a >> b;          // 3 4
cout << a * b << endl;

return 0;
```

> 12


### 1008. A/B

#### Python
```python
a, b = map(float, input().split())
print(a/b)
```

#### C++
```cpp
int a, b;
cin >> a >> b;                  // 1 3
cout.precision(10);             // for reducing error < 10^(-9)
cout << (double)a / b << endl;

return 0;
```

> 0.3333333333


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
cin >> a >> b;          // 7 3

cout << a + b << endl;
cout << a - b << endl;
cout << a * b << endl;
cout << a / b << endl;
cout << a % b << endl;

return 0;
```

> 10 4 21 2 1 (vertically)


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
cin >> A >> B >> C;             // 5 8 4

cout << (A+B)%C << endl;
cout << ((A%C)+(B%C))%C << endl;
cout << (A*B)%C << endl;
cout << ((A%C)*(B%C))%C << endl;

return 0;
```

> 1 1 0 0 (vertically)


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

#### C++ - trial 1-1
```cpp
#include <iostream>
```
```cpp
int a;
char b[3];                      // trial 1-1 : a = 256 when declare char b[3]
cin >> a;                       // 472
cin >> b;                       // 385
cout << a << " " << b << endl;  // test

return 0;
```
> 256 385

#### C++ - trial 1-2
```cpp
int a;
// char b[3];                   // trial 1-1 : a = 256 when declare char b[3]
char b[4];                      // trial 1-2 
cin >> a;                       // 472
cin >> b;                       // 385
cout << a << " " << b << endl;  // test

return 0;
```
> 472 385

#### C++ - trial 1-3
```cpp
int a;
// char b[3];                   // trial 1-1 : a = 256 when declare char b[3]
// char b[4];                   // trial 1-2 
string b;                       // trial 1-3 : change char[] to string
cin >> a;                       // 472
cin >> b;                       // 385
cout << a << " " << b << endl;  // test

return 0;
```
> 472 385

#### C++ - trial 2
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
    cout << "b[" << len-i-1 << "] : " << b.at(len-i-1) << endl;              // b[2], b[1], b[0] / OK
    cout << "convert to int 1 : " << (int) b.at(len-i-1) << endl;            // trial 2-1 : failure because output its ascii code
    cout << "convert to int 2 : " << (int) (b.at(len-i-1) - '0') << endl;    // trial 2-2 : success
}

return 0;
```
> b[2] : 5  
> convert to int 1 : 53  
> convert to int 2 : 5  
> b[1] : 8  
> convert to int 1 : 56  
> convert to int 2 : 8  
> b[0] : 3  
> convert to int 1 : 51  
> convert to int 2 : 3

#### C++ - trial 3-1
```cpp
#include <iostream>
#include <cmath>
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
    short digit = (int) (b[3-i-1] - '0');

    // The ways to get 100 by pow(10, 3) (Remove // from only one line)
    int cipher = pow(10, i);                                                 // trial 3-1 : vanilla double pow() - 99- 180304
    cout << a << " " << (int) digit << " " << cipher << endl;                // test

    // Operation for each cipher
    int prod = a * (int) digit;                                              // get difference between ascii codes of (b[3-i-1]) and '0'
    sum += prod * cipher;

    // Output
    cout << prod << " " << sum - prod << " " << sum << endl;    // test
    // cout << prod << endl;
}

return 0;
```
> 472 5 1  
> 2360 0 2360  
> 472 8 10  
> 3776 36344 40120  
> 472 3 99  
> 1416 178888 180304  

#### C++ - trial 3-2~4
```cpp
int cipher = (int) pow(10, i);  // trial 3-2 : (int) double pow() - 99 - 180304
int cipher = (int) powl(10, i); // trial 3-3 : (int) long double powl() - 99 - 180304
int cipher = pow(10.0, i);      // trial 3-4 : use 10.0 - 99 - 180304
```
> The same result with trial 3-1

#### C++ - trial 5
```cpp
int cipher = pow(10, i);        // trial 3-5 : the same with 1 but run by C++17(Clang) - Correct
```
> Accept

#### C++ - trial 6 (final)
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
    // cout << "convert to int 1 : " << (int) b.at(len-i-1) << endl;            // trial 2-1 : failure because output its ascii code
    // cout << "convert to int 2 : " << (int) (b.at(len-i-1) - '0') << endl;    // trial 2-2 : success
    short digit = (int) (b[3-i-1] - '0');

    // The ways to get 100 by pow(10, 3) (Remove // from only one line)
    // int cipher = pow(10, i);                                                 // trial 3-1 : vanilla double pow() - 99- 180304
    // int cipher = (int) pow(10, i);                                           // trial 3-2 : (int) double pow() - 99 - 180304
    // int cipher = (int) powl(10, i);                                          // trial 3-3 : (int) long double powl() - 99 - 180304
    // int cipher = pow(10.0, i);                                               // trial 3-4 : use 10.0 - 99 - 180304
    // int cipher = pow(10, i);                                                 // trial 3-5 : the same with 1 but run by C++17(Clang) - Correct
    int cipher = round(pow(10, i));                                          // trial -6 : round(pow()) - Correct
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
> 472 5 1  
> 2360 0 2360  
> 472 8 10  
> 3776 36344 40120  
> 472 3 100  
> 1416 180304 181720  
> 181720

#### Bonus.
```cpp
// Output
cout << sum + 1 << endl; // can't find why lack of 1 - crazy!
```
> ㅋㅋ