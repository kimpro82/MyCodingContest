## [BAEKJOON Online Judge](../../../../README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 7. 2차원 배열

https://www.acmicpc.net/step/2

(2023.06.27) - `C++`  
(2024.03.13) - `Rust`  


### **List**

- [2738. 행렬 덧셈](#2738-행렬-덧셈) *(new)*
- [2566. 최댓값](#2566-최댓값) *(new)*
- [10798. 세로읽기](#10798-세로읽기) *(new)*
- [2563. 색종이](#2563-색종이) *(new)*


**※ Note**

&nbsp;&nbsp; - All the code of any language for the same problem has basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.   
&nbsp;&nbsp;&nbsp;&nbsp; · *C++* : `#include <iostream>` `#define endl '\n';` `using namespace std;`  
&nbsp;&nbsp;&nbsp;&nbsp; · *Rust* : `use std::io;`  


## [2738. 행렬 덧셈](#list)

```txt
3 3
1 1 1
2 2 2
0 1 0
3 3 3
4 4 4
5 5 100
```
```txt
4 4 4
6 6 6
5 6 100
```

<details>
  <summary>C++ (2023.06.26)</summary>

```cpp
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Declare
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M, 0));

    // Input
    int temp;
    for (int i = 0; i < 2; i++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                cin >> temp;
                v[n][m] += temp;
            }
        }
    }

    // Output
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++) cout << v[n][m] << ' ';
        cout << endl;
    }

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.03.12)</summary>

```rust
fn main()
{
    // Input n, m
    let mut nm = String::new();
    io::stdin().read_line(&mut nm).unwrap();
    let mut iter = nm.split_whitespace();
    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();

    // Input arr1, arr2
    let mut arr1: Vec<Vec<i32>> = Vec::new();
    let mut arr2: Vec<Vec<i32>> = Vec::new();
    for i in 0..(n * 2)
    {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let row: Vec<i32> = line.split_whitespace()
            .map(|s| s.parse().unwrap()).collect();

        if i < n { arr1.push(row) }
        else { arr2.push(row) };
    }

    // arr1 + arr2
    let mut sum: Vec<Vec<i32>> = Vec::new();
    for i in 0..n
    {
        let mut row: Vec<i32> = Vec::new();
        for j in 0..m { row.push(arr1[i][j] + arr2[i][j]) };
        sum.push(row);
    }

    // Output
    for i in 0..n
    {
        for j in 0..m { print!("{} ", sum[i][j]) };
        println!();
    }
}
```
</details>


## [2566. 최댓값](#list)

```txt
3 23 85 34 17 74 25 52 65
10 7 39 42 88 52 14 72 63
87 42 18 78 53 45 18 84 53
34 28 64 85 12 16 75 36 55
21 77 45 35 28 75 90 76 1
25 87 65 15 28 11 37 28 74
65 27 75 41 7 89 78 64 39
47 47 70 45 23 65 3 41 44
87 13 82 38 31 12 29 29 80
```
```txt
90
5 7
```

</details>
<details>
  <summary>C++ (2023.06.26)</summary>

```cpp
int main()
{
    // Declare
    int row = 9, col = 9;
    int max = 0, maxRow = 1, maxCol = 1;                    // maxRow, maxCol should also have their initial values againt when max == 0

    // Input
    int temp;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin >> temp;
            if (temp > max)
            {
                max = temp;
                maxRow = i;
                maxCol = j;
                if (max == 100) break;
            }
        }
        if (max == 100) break;
    }

    // Output
    cout << max << endl;
    cout << maxRow << ' ' << maxCol << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.03.12)</summary>

```rust
fn main()
{
    // Declare n, m
    let n: usize = 9;
    let m: usize = 9;

    // Find the max value and its location (max_i, max_j)
    let mut max: i32 = -1;
    let mut max_i: usize = 0;
    let mut max_j: usize = 0;
    for i in 0..n
    {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let row: Vec<i32> = line.split_whitespace()
            .map(|s| s.parse().unwrap()).collect();

        for j in 0..m
        {
            if row[j] > max
            {
                max = row[j];
                max_i = i;
                max_j = j;
            }
        }
    }

    // Output
    println!("{}", max);
    println!("{} {}", max_i + 1, max_j + 1);
}
```
</details>


## [10798. 세로읽기](#list)

```txt
AABCDD
afzz
09121
a8EWg6
P5h3kx
```
```txt
Aa0aPAf985Bz1EhCz2W3D1gkD6x
```

<details>
  <summary>C++ (2023.06.27)</summary>

```cpp
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Declare
    int row = 5, col = 15;
    vector<vector<char>> v(row, vector<char>(col, '.'));

    // Input
    string s;
    int len;
    for (int i = 0; i < row; i++)
    {
        cin >> s;
        len = s.size();
        for (int j = 0; j < len; j++) v[i][j] = s[j];
    }

    // Output
    for (int j = 0; j < col; j++) for (int i = 0; i < row; i++) if (v[i][j] != '.') cout << v[i][j];
    cout << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.03.13)</summary>

```rust
fn main()
{
    // Declare n, m
    let n: usize = 5;
    let m: usize = 15;

    // Input an array
    let mut arr: Vec<Vec<char>> = Vec::new();
    let mut lens: Vec<usize> = Vec::new();
    for i in 0..n
    {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let row: Vec<char> = line.trim().chars().collect();

        lens.push(row.len());
        arr.push(row);
    }

    // Output
    for i in 0..m
    {
        for j in 0..n
        {
            if i < lens[j] { print!("{}", arr[j][i]); }
        }
    }
    println!();
}
```
</details>


## [2563. 색종이](#list)

```txt
3
3 7
15 7
5 2
```
```txt
260
```

<details>
  <summary>C++ (2023.06.27)</summary>

```cpp
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Declare
    int len1 = 100, len2 = 10;
    vector<vector<int>> v(len1, vector<int> (len1, 0));
    int N, a, b;
    cin >> N;

    // Input
    int temp;
    for (int n = 0; n < N; n++)
    {
        cin >> a >> b;
        for (int i = 0; i < len2; i++) for (int j = 0; j < len2; j++) v[a+i][b+j] = 1;
    }

    // Output
    int sum = 0;
    for (int i = 0; i < len1; i++) for (int j = 0; j < len1; j++) if (v[i][j] > 0) sum++;
    cout << sum << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.03.13)</summary>

```rust
fn main()
{
    // Declare r, c
    let r: usize = 100;
    let c: usize = 100;

    // Input the number of rows
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: usize = n.trim().parse().unwrap();

    let mut matrix: Vec<Vec<i32>> = vec![vec![0; c]; r];
    for i in 0..n
    {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();                                 // should be declared as mutable
        let n: usize = iter.next().unwrap().parse().unwrap();
        let m: usize = iter.next().unwrap().parse().unwrap();

        for j in n..n+10
        {
            for k in m..m+10
            {
                matrix[j][k] = 1;
            }
        }
    }

    // Count the number of 1s
    let mut count: i32 = 0;
    for i in 0..r
    {
        for j in 0..c
        {
            count += matrix[i][j];
        }
    }

    // Output
    println!("{}", count);
}
```
</details>
