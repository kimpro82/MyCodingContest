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
  4
  5
  6
  7
  8
  9
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


## [1904. (재귀함수) 두 수 사이의 홀수 출력하기](#list)

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


## [1905. (재귀함수) 1부터 n까지 합 구하기](#list)

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


## [1912. (재귀함수) 팩토리얼 계산](#list)

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


## [1915. (재귀함수) 피보나치 수열](#list)

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


## [1916. (재귀함수) 피보나치 수열 (Large)](#list)

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
