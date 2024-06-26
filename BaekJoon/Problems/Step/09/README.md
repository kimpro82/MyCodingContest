## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 약수, 배수와 소수

https://www.acmicpc.net/step/10

(2021.07.19, 2023.07.02) - `C++`  
(2024.04.06) - `Rust`  


## **List**

- [5086. Factors And Multiples (배수와 약수)](#5086-factors-and-multiples-배수와-약수) *(new)*
- [2501. 약수 구하기](#2501-약수-구하기) *(new)*
- [9506. Federation Favorites (약수들의 합)](#9506-federation-favorites-약수들의-합) *(new)*
- [1978. 소수 찾기](#1978-소수-찾기)
- [2581. 소수](#2581-소수)
- [11653. 소인수분해](#11653-소인수분해)

#### (Depreciated)
- [9020. Goldbach’s Conjecture (골드바흐의 추측)](#9020-goldbachs-conjecture-골드바흐의-추측)
- [4153. Egypt (직각삼각형)](#4153-egypt-직각삼각형)
- [3053. HERMAN (택시 기하학)](#3053-herman-택시-기하학)
- [1002. 터렛](#1002-터렛)


**※ Note**

&nbsp;&nbsp; - All the code of any language for the same problem has basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line. 
&nbsp;&nbsp;&nbsp;&nbsp; · *C++* : `#include <iostream>` `#define endl '\n';` `using namespace std;`  
&nbsp;&nbsp;&nbsp;&nbsp; · *Rust* : `use std::io;`  


## [5086. Factors And Multiples (배수와 약수)](#list)

```txt
8 16
32 4
17 5
0 0
```
```txt
factor
multiple
neither
```

<details>
  <summary>C++ (2023.07.02)</summary>

```cpp
int main()
{
    int a, b;
    while (true)
    {
        // Input
        cin >> a >> b;

        if (a == 0 && b == 0) break;
        else if (a < b && b % a == 0) cout << "factor" << endl;
        else if (a > b && a % b == 0) cout << "multiple" << endl;
        else cout << "neither" << endl;
    }

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.05)</summary>

```rust
fn main()
{
    loop
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let a: i32 = iter.next().unwrap().parse().unwrap();
        let b: i32 = iter.next().unwrap().parse().unwrap();

        if a == 0 && b == 0 { break; }
        else
        {
            if a > b && a % b == 0 { println!("multiple") }
            else if a < b && b % a == 0 { println!("factor") }
            else { println!("neither") }
        };
    }
}
```
</details>


## [2501. 약수 구하기](#list)

```txt
6 3
```
```txt
3
```

<details>
  <summary>C++ (2023.07.02)</summary>

```cpp
int main()
{
    int a, b;

    // Input
    cin >> a >> b;

    int cnt = 0;
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0)
        {
            cnt++;

            // Test
            #ifdef test
                printf("i:%d remainder:%d cnt:%d\n", i, a%i, cnt);
            #endif

            // Operate and Output
            if (cnt == b)
            {
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.05)</summary>

```rust
fn main()
{
    // Input n, k
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let n: i32 = iter.next().unwrap().parse().unwrap();
    let k: i32 = iter.next().unwrap().parse().unwrap();

    // Calc. and Output
    let mut cnt: i32 = 0;
    for i in 1..=n
    {
        if n % i == 0
        {
            cnt += 1;
            if cnt == k
            {
                println!("{}", i);                          // i, not cnt
                return;
            }
        }
    }

    // Output when k is not in [1, n]
    println!("0");
}
```
</details>


## [9506. Federation Favorites (약수들의 합)](#list)

```txt
6
12
28
-1
```
```txt
6 = 1 + 2 + 3
12 is NOT perfect.
28 = 1 + 2 + 4 + 7 + 14
```

<details>
  <summary>C++ (2023.07.02)</summary>

```cpp
#include <iostream>
#include <vector>

// #define test
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    while (true)
    {
        // Input
        int n;
        cin >> n;
        if (n == -1) break;

        // Operate
        vector<int> v;
        int sum = 0;
        for (int i = 1; i <= n/2; i++)
        {
            if (n % i == 0)
            {
                v.push_back(i);
                sum += i;
            }

            if (n < sum) break;
        }

        // Output
        if (sum == n)
        {
            cout << n << " = 1";
            for (int i = 1; i < v.size(); i++) cout << " + " << v[i];
        }
        else cout << n << " is NOT perfect.";
        cout << endl;
    }

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.05)</summary>

```rust
fn main()
{
    // let test: bool = true;
    let test: bool = false;

    loop
    {
        // Input n
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let n: i32 = input.trim().parse().unwrap();

        if n == -1 { break; }
        else
        {
            // Calc.
            let mut sum: i32 = 1;
            let mut str: String = format!("{} = 1", n);
            for i in 2..=n/2
            {
                if n % i == 0
                {
                    sum += i;
                    str += &format!(" + {}", i);
                }
                // Test
                if test { println!("{} : {} {}", i, sum, n); }

                if sum > n { break; }
            }

            // Output
            if sum == n { println!("{}", str); }
            else { println!("{} is NOT perfect.", n)}
        }
    }
}
```
</details>


## [1978. 소수 찾기](#list)

```txt
4
```
```txt
1 3 5 7
```

<details>
  <summary>C++ (2023.07.19)</summary>

```cpp
#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
    // Input data
    int n;          // n <= 100
    cin >> n;
    vector<int> v;  // v_i <= 1000
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    // Determine if each number of v is a prime number
    int count = 0, prime;
    for (int j = 0; j < n; j++)
    {
        if (v[j] == 1) continue;

        prime = 1;
        for (int k = 2; k < v[j]/2 + 1; k++)
        {
            if (v[j] % k  == 0)
            {
                prime = 0;
                break;
            }
        }
        if (prime == 1) count++;

        // test
        cout << j << " " << v[j] << " " << count << endl;
    }

    // Output
    cout << count << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.05)</summary>

```rust
fn is_prime(num: i32, test: bool) -> bool
{
    if num == 1 { return false; }
    else if num == 2 { return true; }                       // crazy
    else
    {
        for i in 2..=(num as f32).sqrt().ceil() as i32
        {
            if test { println!("{} % {} = {}", num, i, num % i); }
            if num % i == 0 { return false; }
        }
        return true;
    }
}
```
```rust
fn main()
{
    // let test: bool = true;
    let test: bool = false;

    // Input n and n numbers
    let mut n = String::new();                              // not use
    let mut nums = String::new();
    io::stdin().read_line(&mut n).unwrap();
    io::stdin().read_line(&mut nums).unwrap();
    let nums: Vec<i32> = nums.split_whitespace()
        .map(|s| s.parse().unwrap()).collect();

    // Count the number of prime numbers
    let mut cnt: i32 = 0;
    for i in 0..nums.len()
    {
        if is_prime(nums[i], test) { cnt += 1; }
    }

    // Output
    println!("{}", cnt);
}
```
</details>


## [2581. 소수](#list)

```txt
60
100
```
```txt
620
61
```

<details>
  <summary>C++ (2023.07.19)</summary>

```cpp
int main()
{
    // Input data
    int m, n;                           // 1 <= m <= n <= 10,000
    cin >> m >> n;

    // Determine if each number between m and n is a prime number
    int sum = 0, min = 10000, prime;
    if (m == 1) m++;                    // don't need to consider 1
    for (int i = m; i <= n; i++)
    {
        prime = 1;

        for (int j = 2; j <= i/2; j++)
        {
            if (i % j  == 0)
            {
                prime = 0;
                break;
            }
        }

        if (prime == 1)
        {
            sum += i;
            if (i < min) min = i;       // enough to operate just once first but ……

            // test
            cout << i << " " << sum << " " << min << endl;
        }
    }

    // Output
    if (sum > 0) cout << sum << '\n' << min << endl;
    else cout << -1 << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.05)</summary>

```rust
fn is_prime(num: i32, test: bool) -> bool
{
    // The same with the above answer
    ……
}
```
```rust
fn main()
{
    // let test: bool = true;
    let test: bool = false;

    // Input m, n
    let mut m = String::new();
    let mut n = String::new();
    io::stdin().read_line(&mut m).unwrap();
    io::stdin().read_line(&mut n).unwrap();
    let m: i32 = m.trim().parse().unwrap();
    let n: i32 = n.trim().parse().unwrap();

    // Calc.
    let mut sum: i32 = 0;
    let mut min: i32 = 0;
    for i in m..=n
    {
        if is_prime(i, test)
        {
            sum += i;
            if min == 0 { min = i; }
        }
    }

    // Output
    if sum > 0 { println!("{}\n{}", sum, min); }
    else       { println!("-1"); }
}
```

</details>


## [11653. 소인수분해](#list)

```txt
72
```
```txt
2
2
2
3
3
```

<details>
  <summary>C++ (2023.07.19)</summary>

```cpp
int main()
{
    // Input data
    int n;                           // 1 <= n <= 10,000,000
    cin >> n;

    // Prime factorization
    int divisor = 2;
    while (n > 1)
    {
        if (n % divisor == 0)
        {
            cout << divisor << endl;
            n /= divisor;
        }
        else divisor++;
    }

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.05)</summary>

```rust
fn main()
{
    // let test: bool = true;
    let test: bool = false;

    // Input n
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let mut n: i32 = n.trim().parse().unwrap();

    // Calc. and Output
    let m: i32 = (n as f32).sqrt().ceil() as i32;
    for mut i in 2..=n
    {
        if i > m { i = n; }                                 // for performance
        loop
        {
            if n % i == 0
            {
                n /= i;
                
                if test { println!("{} : {}", i, n); }
                else    { println!("{}", i); }
            }
            else { break; }
        }
        if n == 1 { return; }
    }
}
```
</details>


## [9020. Goldbach’s Conjecture (골드바흐의 추측)](#list)

```txt
3
8
10
16
```
```txt
3 5
5 5
5 11
```

<details>
  <summary>C++ (2023.07.19)</summary>

```cpp
int main()
{
    // maybe better than nothing?
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    // T test cases
    for (int t = 0; t < T; t++)
    {
        int n, m, prime;
        cin >> n;

        for (int i = n/2; i > 1; i--)
        {
            prime = 1;

            // Find the first prime number
            for (int j = 2; j <= i/j; j++)      // magic to avoid TLE! 
            {
                if (i % j  == 0)
                {
                    prime = 0;
                    break;
                }
            }

            // Find if (n - i) is also a prime number
            if (prime == 1)
            {
                m = n - i;
                for (int k = 2; k <= m/k; k++)
                {
                    if (m % k  == 0)
                    {
                        prime = 0;
                        break;
                    }
                }
            }

            // When both of the numbers are prime ones
            if (prime == 1)
            {
                cout << i << ' ' << m << endl;
                break;                          // need only once
            }
        } // The end of i loop
    } // The end of t loop

    return 0;
}
```
</details>


## [4153. Egypt (직각삼각형)](#list)

```txt
6 8 10
25 52 60
5 12 13
0 0 0
```
```txt
right
wrong
right
```

<details>
  <summary>C++ (2023.07.20)</summary>

```cpp
#include <iostream>
// #include <array>     // not used, but use legacy array
#include <algorithm>    // sort()
#include <cmath>        // pow()

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
    int arr[3];
    // array<int, 3> arr                            // causes crazy compile time error when apply to sort()
    while (true)
    {
        // Input data
        for (int i = 0; i < 3; i++) cin >> arr[i];
        if (arr[0] == 0) break;                     // enough to check just one line segment

        // Sort : not sure if data will be sorted
        sort(arr, arr + 3);                         // not sort(arr[0], arr[3])

        // Output
        if ((int) pow(arr[0], 2) + (int) pow(arr[1], 2) == (int) pow(arr[2], 2))
        {
            cout << "right" << endl;
        } else
        {
            cout << "wrong" << endl;
        }
    }

    return 0;
}
```
</details>


## [3053. HERMAN (택시 기하학)](#list)

```txt
21
```
```txt
1385.442360
882.000000
```

<details>
  <summary>C++ (2023.07.20)</summary>

```cpp
#define _USE_MATH_DEFINES   // for using the exact pi value(M_PI)

#include <iostream>
#include <cmath>            // pow(), M_PI

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
    int r;
    cin >> r;

    double euclidian = M_PI * pow(r, 2);            // find the exact value of M_PI : F12 (VS Code)
    double taxicab = 2 * pow(r, 2);

    cout << fixed;
    cout.precision(6);
    cout << euclidian << '\n' << taxicab << endl;

    return 0;
}
```
</details>


## [1002. 터렛](#list)

```txt
3
0 0 13 40 0 37
0 0 3 0 7 4
1 1 1 1 1 5
```
```txt
1600 2500 576
2
49 49 1
1
0 36 16
0
```

<details>
  <summary>C++ (2023.07.20)</summary>

```cpp
#include <iostream>
#include <cmath>        // pow()

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
    int T;
    cin >> T;

    // T Test cases
    for (int t = 0; t < T; t++)
    {
        // Input data
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        // Find square of distance : sqrt() can cause error
        int distanceSquare = (int) (pow(x2 - x1, 2) + pow(y2 - y1, 2));
        int rangeSquare1 = (int) pow(r1 + r2, 2), rangeSquare2 = (int) pow(r2 - r1, 2);

        // test
        cout << distanceSquare << ' ' << rangeSquare1 << ' ' << rangeSquare2 << endl;

        // Output
        if (distanceSquare == 0 && rangeSquare2 == 0) cout << -1 << endl;   // infinitely cross
        else if (distanceSquare > rangeSquare1 || distanceSquare < rangeSquare2) cout << 0 << endl;
        else if (distanceSquare == rangeSquare1 || distanceSquare == rangeSquare2 ) cout << 1 << endl;
        else cout << 2 << endl;
    }

    return 0;
}
```
</details>
