## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 10. 기하: 직사각형과 삼각형

https://www.acmicpc.net/step/50

(2023.07.02) - `C++`  
(2024.04.12) - `Rust`  


## **List**

- [27323. 長方形 (Rectangle, 직사각형)](#27323-長方形-rectangle-직사각형) *(new)*
- [1085. 직사각형에서 탈출](#1085-직사각형에서-탈출)
- [3009. CETVRTA (네 번째 점)](#3009-cetvrta-네-번째-점)
- [15894. 수학은 체육과목 입니다](#15894-수학은-체육과목-입니다) *(new)*
- [9063. 대지](#9063-대지) *(new)*
- [10101. Triangle Times (삼각형 외우기)](#10101-triangle-times-삼각형-외우기) *(new)*
- [5073. Triangles (삼각형과 세 변)](#5073-triangles-삼각형과-세-변) *(new)*
- [14215. 세 막대](#14215-세-막대) *(new)*


**※ Note**

&nbsp;&nbsp; - All the code of any language for the same problem has basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · *C++* : `#include <iostream>` `#define endl '\n';` `using namespace std;`  
&nbsp;&nbsp;&nbsp;&nbsp; · *Rust* : `use std::io;`  



## [27323. 長方形 (Rectangle, 직사각형)](#list)

```txt
2
3
```
```txt
6
```

<details>
  <summary>C++ (2023.07.02)</summary>

```cpp
int main()
{
    // Input
    int a, b;
    cin >> a >> b;

    // Output
    cout << a * b << endl;
    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.12)</summary>

```rust
fn main()
{
    // Input a, b
    let mut a = String::new();
    let mut b = String::new();
    io::stdin().read_line(&mut a).unwrap();
    io::stdin().read_line(&mut b).unwrap();
    let a: i32 = a.trim().parse().unwrap();
    let b: i32 = b.trim().parse().unwrap();

    // Output
    println!("{}", a * b);
}
```
</details>


## [1085. 직사각형에서 탈출](#list)


```txt
6 2 10 3
```
```txt
1
```

<details>
  <summary>C++ (2021.07.19)</summary>

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
</details>
<details>
  <summary>Rust (2024.04.12)</summary>

```rust
……
use std::cmp::min;
```
```rust
fn main()
{
    // Input x, y, w, h
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let x: i32 = iter.next().unwrap().parse().unwrap();
    let y: i32 = iter.next().unwrap().parse().unwrap();
    let w: i32 = iter.next().unwrap().parse().unwrap();
    let h: i32 = iter.next().unwrap().parse().unwrap();

    // Calc.
    let mut ans: i32 = 1_000;
    ans = min(x, ans);
    ans = min(y, ans);
    ans = min(w - x, ans);
    ans = min(h - y, ans);

    // Output
    println!("{}", ans);
}
```
</details>


## [3009. CETVRTA (네 번째 점)](#list)

```txt
5 5
5 7
7 5
```
```txt
7 7
```

<details>
  <summary>C++ - Trial 1 (2021.07.20)</summary>

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
</details>

> 5 5  
> 5 7  
> 7 5

> 5 1  
> 7 1

<details>
  <summary>C++ - Trial 2 (2021.07.20)</summary>

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
</details>

> x : 5 2  
> y : 5 2  
> x : 7 1  
> y : 7 1  
> 7 7

<details>
  <summary>Rust (2024.04.12)</summary>

```rust
……
use std::collections::HashMap;
```
```rust
fn main()
{
    // let test: bool = true;
    let test: bool = false;

    // Input
    let mut x_map = HashMap::new();
    let mut y_map = HashMap::new();
    for _ in 0..3
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let x: i32 = iter.next().unwrap().parse().unwrap();
        let y: i32 = iter.next().unwrap().parse().unwrap();

        if test { println!("{} {}", x, y); }

        if x_map.get(&x) == None { x_map.insert(x, 1); }
        else { x_map.insert(x, 2); }                        // hope cnt + 1, not 2
        if y_map.get(&y) == None { y_map.insert(y, 1); }
        else { y_map.insert(y, 2); }
    }

    // Find the answer
    let mut x_ans: i32 = 0;
    let mut y_ans: i32 = 0;
    for (k, v) in x_map.iter() { if *v == 1 { x_ans = *k; } }
    for (k, v) in y_map.iter() { if *v == 1 { y_ans = *k; } }

    // Output
    println!("{} {}", x_ans, y_ans);
}
```
</details>


## [15894. 수학은 체육과목 입니다](#list)

```txt
3
```
```txt
12
```

<details>
  <summary>C++ (2023.07.02)</summary>

```cpp
#include <iostream>

#define endl '\n'

using namespace std;
using ll = long long;
```
```cpp
int main()
{
    // Input
    ll n;
    cin >> n;

    // Output
    cout << n * 4 << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.12)</summary>

```rust
fn main()
{
    // Input n
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: i64 = n.trim().parse().unwrap();

    // Output
    println!("{}", n * 4);
}
```
</details>


## [9063. 대지](#list)

```txt
3
20 24
40 21
10 12
```
```txt
360
```

<details>
  <summary>C++ (2023.07.02)</summary>

```cpp
#include <iostream>

// #define test
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Input
    int n;
    cin >> n ;;

    int x, y;
    int xMin = 10000, yMin = 10000, xMax = -10000, yMax = -10000;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (x < xMin) xMin = x;
        if (x > xMax) xMax = x;
        if (y < yMin) yMin = y;
        if (y > yMax) yMax = y;
    }

    // test
    #ifdef test
        printf("xMax:%d, xMin:%d, yMax:%d, yMin:%d\n", xMax, xMin, yMax, yMin);
        printf("xMax-xMin:%d, yMAx-yMin:%d\n", xMax-xMin, yMax-yMin);
    #endif

    // Output
    int area = (xMax - xMin) * (yMax - yMin);
    cout << area << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.12)</summary>

```rust
……
use std::cmp;
```
```rust
fn main()
{

    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: i32 = n.trim().parse().unwrap();

    // Input x, y n times
    let mut x_min = 10_000;
    let mut x_max = -10_000;
    let mut y_min = 10_000;
    let mut y_max = -10_000;
    for _ in 0..n
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let x: i64 = iter.next().unwrap().parse().unwrap();
        let y: i64 = iter.next().unwrap().parse().unwrap();

        x_min = cmp::min(x_min, x);
        x_max = cmp::max(x_max, x);
        y_min = cmp::min(y_min, y);
        y_max = cmp::max(y_max, y);
    }

    // Output
    let ans: i64 = (x_max - x_min) * (y_max - y_min);
    println!("{}", ans);
}
```
</details>


## [10101. Triangle Times (삼각형 외우기)](#list)

```txt
60
70
50
```
```txt
Scalene
```

<details>
  <summary>C++ (2023.07.02)</summary>

```cpp
int main()
{
    // Input
    int a, b, c;
    cin >> a >> b >> c;

    // Operate
    string ans;
    if (a + b + c == 180)
    {
        if (a == 60 && b == 60) ans = "Equilateral";
        else if (a == b || b == c || c == a) ans = "Isosceles";
        else ans = "Scalene";
    }
    else ans = "Error";

    // Output
    cout << ans << endl;
    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.12)</summary>

```rust
fn main()
{
    // Input a, b
    let mut a = String::new();
    let mut b = String::new();
    let mut c = String::new();
    io::stdin().read_line(&mut a).unwrap();
    io::stdin().read_line(&mut b).unwrap();
    io::stdin().read_line(&mut c).unwrap();
    let a: i32 = a.trim().parse().unwrap();
    let b: i32 = b.trim().parse().unwrap();
    let c: i32 = c.trim().parse().unwrap();

    // Judge
    let ans: String =
    {
        if a + b + c == 180
        {
            if a == 60 && b == 60              { "Equilateral".to_string() }    // no semicolon (why?)
            else if a == b || b == c || c == a { "Isosceles".to_string() }
            else                               { "Scalene".to_string() }
        }
        else                                   { "Error".to_string() }
    };

    // Output
    println!("{}", ans);
}
```
</details>


## [5073. Triangles (삼각형과 세 변)](#list)

```txt
7 7 7
6 5 4
3 2 5
6 2 6
0 0 0
```
```txt
Equilateral
Scalene
Invalid
Isosceles
```

<details>
  <summary>C++ (2023.07.02)</summary>

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    while (true)
    {
        // Input
        vector<int> v;
        int n;
        for (int i = 0; i < 3; i++)
        {
            cin >> n;
            v.push_back(n);
        }
        if (v[0] == 0 && v[1] == 0 && v[2] == 0) break;

        // Operate
        string ans;
        sort(v.begin(), v.end());
        if (v[0] + v[1] > v[2])
        {
            if (v[0] == v[1] && v[1] == v[2]) ans = "Equilateral";
            else if (v[0] == v[1] || v[1] == v[2] || v[2] == v[0]) ans = "Isosceles";
            else ans = "Scalene";
        }
        else ans = "Invalid";

        // Output
        cout << ans << endl;
    }

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.12)</summary>

```rust
fn main()
{
    loop
    {
        // Input a, b, c
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let a: i32 = iter.next().unwrap().parse().unwrap();
        let b: i32 = iter.next().unwrap().parse().unwrap();
        let c: i32 = iter.next().unwrap().parse().unwrap();

        // Judge and Output
        if a > 0
        {
            if a + b > c && b + c > a && c + a > b
            {
                if a == b && b == c && c == a      { println!("Equilateral"); }
                else if a == b || b == c || c == a { println!("Isosceles"); }
                else                               { println!("Scalene"); }
            }
            else                                   { println!("Invalid"); }
        }
        else                                       { break; }
    }
}
```
</details>


## [14215. 세 막대](#list)

```txt
41 64 16
```
```txt
113
```

<details>
  <summary>C++ (2023.07.02)</summary>

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Input
    vector<int> v;
    int n;
    for (int i = 0; i < 3; i++)
    {
        cin >> n;
        v.push_back(n);
    }

    // Operate
    sort(v.begin(), v.end());
    if (v[0] + v[1] <= v[2]) v[2] = v[0] + v[1] - 1;

    // Output
    int sum = v[0] + v[1] + v[2];
    cout << sum << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.12)</summary>

```rust
fn main()
{
    // let test: bool = true;
    let test: bool = false;

    // Input a, b, c
    let mut nums = String::new();
    io::stdin().read_line(&mut nums).unwrap();
    let mut nums: Vec<i32> = nums.split_whitespace()
                             .map(|s| s.parse().unwrap()).collect();

    // Sort in ascending order
    nums.sort();
    if test { println!("Before : {:?}", nums); }

    // Output
    if nums[0] + nums[1] <= nums[2] { nums[2] = nums[0] + nums[1] - 1; }
    if test { println!("After  : {:?}", nums); }
    println!("{}", nums[0] + nums[1] + nums[2]);
}
```
</details>
