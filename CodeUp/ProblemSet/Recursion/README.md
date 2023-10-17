### [CodeUp > ProblemSet](/README.md#codeup)

# Recursion

2023.10.16

https://codeup.kr/problemsetsol.php?psid=21


## \<List>

- [1901. (재귀 함수) 1부터 n까지 출력하기](#list)
- [1902. (재귀 함수) 1부터 n까지 역순으로 출력하기](#list)
- [1904. (재귀함수) 두 수 사이의 홀수 출력하기](#list)
- [1905. (재귀함수) 1부터 n까지 합 구하기](#list)
- [1912. (재귀함수) 팩토리얼 계산](#list)
- [1915. (재귀함수) 피보나치 수열](#list)
- [1916. (재귀함수) 피보나치 수열 (Large)](#list)
- [1920. (재귀함수) 2진수 변환](#list)
- [1928. (재귀함수) 우박수 (3n+1) (basic)](#list)
- [1929. (재귀함수) 우박수 (3n+1) (reverse)](#list)
- [1930. SuperSum](#list)
- [1953. (재귀함수) 삼각형 출력하기 1](#list)
- [3702. 파스칼의 삼각형 2](#list)
- [3704. 계단 오르기 2](#list)
- [3733. 우박수 길이 (3n+1) (large)](#list)
- [4564. 계단 오르기](#list)


## [1901. (재귀 함수) 1부터 n까지 출력하기](#list)

<details open="">
    <summary>Test Input & Output</summary>

  #### Input
  ```txt
  10
  ```
  #### Output
  ```txt
  1
  2
  3
  ……
  10
  ```
</details>
<details>
    <summary>Codes (C++)</summary>

  #### C++
  ```cpp
  #include <iostream>

  #define endl '\n'

  using namespace std;
  ```
  ```cpp
  void recursion(int n, int cnt)
  {
      cout << cnt << endl;

      if (n == cnt)
          return;
      else
          recursion(n, cnt + 1);
  }
  ```
  ```cpp
  int main()
  {
      int n, cnt = 1;
      cin >> n;

      recursion(n, cnt);

      return 0;
  }
  ```
</details>

#### Submissions
> 정확한 풀이


## [1902. (재귀 함수) 1부터 n까지 역순으로 출력하기](#list)

<details open="">
    <summary>Test Input & Output</summary>

  #### Input
  ```txt
  10
  ```
  #### Output
  ```txt
  10
  9
  8
  ……
  1
  ```
</details>
<details>
    <summary>Codes (C++)</summary>

  #### C++
  ```cpp
  #include <iostream>

  #define endl '\n'

  using namespace std;
  ```
  ```cpp
  void recursion(int n, int cnt)
  {
      cout << cnt << endl;

      if (cnt == 1)
          return;
      else
          recursion(n, cnt - 1);
  }
  ```
  ```cpp
  int main()
  {
      int n;
      cin >> n;

      int cnt = n;
      recursion(n, cnt);

      return 0;
  }
  ```
</details>

#### Submissions
> 정확한 풀이


## [1904. (재귀함수) 두 수 사이의 홀수 출력하기](#list)

<details open="">
    <summary>Test Input & Output</summary>

  #### Input
  ```txt
  2 7
  ```
  #### Output
  ```txt
  3 5 7 
  ```
</details>
<details>
    <summary>Codes (C++)</summary>

  #### C++
  ```cpp
  #include <iostream>

  #define endl '\n'

  using namespace std;
  ```
  ```cpp
  void recursion(int a, int b)
  {
      if (a % 2 == 1)
          cout << a << ' ';

      if (a >= b)
      {
          cout << endl;
          return;
      }
      else
          recursion(a + 1, b);
  }
  ```
  ```cpp
  int main()
  {
      int a, b;
      cin >> a >> b;

      recursion(a, b);

      return 0;
  }
  ```
</details>

#### Submissions
> 정확한 풀이


## [1905. (재귀함수) 1부터 n까지 합 구하기](#list)

<details open="">
    <summary>Test Input & Output</summary>

  #### Input
  ```txt
  100
  ```
  #### Output
  ```txt
  5050
  ```
</details>
<details>
    <summary>Codes (C++)</summary>

  #### C++
  ```cpp
  #include <iostream>

  #define endl '\n'

  using namespace std;
  ```
  ```cpp
  void recursion(int n, int m, int sum)
  {
      sum += m;

      if (n == m)
      {
          cout << sum << endl;
          return;
      }
      else
          recursion(n, m + 1, sum);
  }
  ```
  ```cpp
  int main()
  {
      int n;
      cin >> n;

      int m = 1, sum = 0;
      recursion(n, m, sum);

      return 0;
  }
  ```
</details>

#### Submissions
> 정확한 풀이


## [1912. (재귀함수) 팩토리얼 계산](#list)

<details open="">
    <summary>Test Input & Output</summary>

  #### Input
  ```txt
  5
  ```
  #### Output
  ```txt
  120
  ```
</details>
<details>
    <summary>Codes (C++)</summary>

  #### C++
  ```cpp
  #include <iostream>

  #define endl '\n'

  using namespace std;
  ```
  ```cpp
  void factorial(int n, int prod)
  {
      prod *= n;

      if (n == 1)
      {
          cout << prod << endl;
          return;
      }
      else
          factorial(n - 1, prod);
  }
  ```
  ```cpp
  int main()
  {
      int n;
      cin >> n;

      int prod = 1;
      factorial(n, prod);

      return 0;
  }
  ```
</details>

#### Submissions
> 정확한 풀이


## [1915. (재귀함수) 피보나치 수열](#list)

<details open="">
    <summary>Test Input & Output</summary>

  #### Input
  ```txt
  7
  ```
  #### Output
  ```txt
  13
  ```
</details>
<details>
    <summary>Codes (C++)</summary>

  #### C++
  ```cpp
  #include <iostream>

  #define endl '\n'

  using namespace std;
  ```
  ```cpp
  int Fibonacci(int n)
  {
      if (n <= 2)
          return 1;
      else
          return Fibonacci(n - 1) + Fibonacci(n - 2);
  }
  ```
  ```cpp
  int main()
  {
      int n;
      cin >> n;

      cout << Fibonacci(n) << endl;

      return 0;
  }
  ```
</details>

#### Submissions
> 정확한 풀이


## [1916. (재귀함수) 피보나치 수열 (Large)](#list)

<details open="">
    <summary>Test Input & Output</summary>

  #### Input
  ```txt
  7
  ```
  #### Output
  ```txt
  13
  ```
</details>
<details>
    <summary>Codes (C++) - Trial 1</summary>

  #### C++
  ```cpp
  #include <iostream>

  #define endl '\n'

  using namespace std;
  ```
  ```cpp
  int Fibonacci(int n)
  {
      if (n <= 2)
          return 1;
      else
          return (Fibonacci(n - 1) % 10009 + Fibonacci(n - 2) % 10009) % 10009;
  }
  ```
  ```cpp
  int main()
  {
      int n;
      cin >> n;

      cout << Fibonacci(n) << endl;

      return 0;
  }
  ```
</details>
<details>
    <summary>Codes (C++) - Trial 2</summary>

  Use *Memoization*
  #### C++
  ```cpp
  ……
  #include <vector>

  ……
  ```
  ```cpp
  vector<int> memo;
  ```
  ```cpp
  int Fibonacci(int n)
  {
      if (memo[n] > -1)
          return memo[n];
      else if (n <= 2)
          return 1;
      else
          return (Fibonacci(n - 1) + Fibonacci(n - 2)) % 10009;
  }
  ```
  ```cpp
  int main()
  {
      ……

      memo.assign(n + 1, -1);             // not 0 but -1 (∵ 100009 % 100009 = 0)
      ……
  }
  ```
</details>
<details>
    <summary>Codes (C++) - Trial 3</summary>

  Use legacy array (crazy)
  #### C++
  ```cpp
  ……
  ```
  ```cpp
  int memo[201];
  ```
  ```cpp
  int Fibonacci(int n)
  {
      ……
  }
  ```
  ```cpp
  int main()
  {
      ……

      fill(memo, memo + 201, -1);         // not 0 but -1 (∵ 100009 % 100009 = 0)
      ……
  }
  ```
</details>
<details>
    <summary>Codes (C++) - Trial 4</summary>

  Use the bottom-up method
  #### C++
  ```cpp
  ……
  #include <vector>

  ……
  #define test

  ……
  ```
  ```cpp
  vector<int> bottomUp;
  ```
  ```cpp
  int Fibonacci(int n, int m)
  {
      if (m <= 2)
          bottomUp[m] = 1;
      else
          bottomUp[m] = (bottomUp[m-1] + bottomUp[m-2]) % 10009;

      #ifdef test
          cout << m << ' ' << bottomUp[m] << endl;
      #endif

      if (m == n)
          return bottomUp[m];
      else
          Fibonacci(n, m + 1);
  }
  ```
  ```cpp
  int main()
  {
      ……

      bottomUp.assign(n + 1, -1);         // not 0 but -1 (∵ 10009 % 10009 = 0)
      cout << Fibonacci(n, 1) << endl;

      ……
  }
  ```
</details>

#### Submissions
- Tial 1 : `시간 초과`
- Tial 2 : `시간 초과`
- Tial 3 : `시간 초과`
- Tial 4 : `실행 중 에러(Runtime Error:Segmentation fault)`

때려치워!


## [1920. (재귀함수) 2진수 변환](#list)

<details open="">
    <summary>Test Input & Output</summary>

  #### Input
  ```txt

  ```
  #### Output
  ```txt

  ```
</details>
<details>
    <summary>Codes (C++)</summary>

  #### C++
  ```cpp

  ```
  ```cpp

  ```
  ```cpp

  ```
</details>

#### Submissions
> 정확한 풀이


## [1928. (재귀함수) 우박수 (3n+1) (basic)](#list)

<details open="">
    <summary>Test Input & Output</summary>

  #### Input
  ```txt

  ```
  #### Output
  ```txt

  ```
</details>
<details>
    <summary>Codes (C++)</summary>

  #### C++
  ```cpp

  ```
  ```cpp

  ```
  ```cpp

  ```
</details>

#### Submissions
> 정확한 풀이


## [1929. (재귀함수) 우박수 (3n+1) (reverse)](#list)

<details open="">
    <summary>Test Input & Output</summary>

  #### Input
  ```txt

  ```
  #### Output
  ```txt

  ```
</details>
<details>
    <summary>Codes (C++)</summary>

  #### C++
  ```cpp

  ```
  ```cpp

  ```
  ```cpp

  ```
</details>

#### Submissions
> 정확한 풀이


## [1930. SuperSum](#list)

not attempted


## [1953. (재귀함수) 삼각형 출력하기 1](#list)

<details open="">
    <summary>Test Input & Output</summary>

  #### Input
  ```txt

  ```
  #### Output
  ```txt

  ```
</details>
<details>
    <summary>Codes (C++)</summary>

  #### C++
  ```cpp

  ```
  ```cpp

  ```
  ```cpp

  ```
</details>

#### Submissions
> 정확한 풀이


## [3702. 파스칼의 삼각형 2](#list)

not attempted


## [3704. 계단 오르기 2](#list)

not attempted


## [3733. 우박수 길이 (3n+1) (large)](#list)

not attempted


## [4564. 계단 오르기](#list)

not attempted
