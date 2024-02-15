## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 5. 문자열

https://www.acmicpc.net/step/7

(2021.07.09, 2023.06.18) - `C++`  
(2022.02.15) - `Bash`  
(2022.06.19) - `Golang`  
(2024.02.15) - `Rust`


## **List**
- [27866. 문자와 문자열](#27866-문자와-문자열) *(new)*
- [2743. 단어 길이 재기](#2743-단어-길이-재기) *(new)*
- [9086. 문자열](#9086-문자열) *(new)*
- [11654. 아스키 코드](#11654-아스키-코드)
- [11720. 숫자의 합](#11720-숫자의-합)
- [10809. 알파벳 찾기](#10809-알파벳-찾기)
- [2675. Repeating Characters](#2675-repeating-characters)
- [1152. 단어의 개수](#1152-단어의-개수)
- [2908. FILIP](#2908-filip)
- [5622. BAKA](#5622-baka)
- [11718. 그대로 출력하기](#11718-그대로-출력하기) *(new)*


**※ Note**  

&nbsp;&nbsp; - All the code of any language for the same problem has basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · *Bash* : `#!/bin/bash`  
&nbsp;&nbsp;&nbsp;&nbsp; · *C++* : `#include <iostream>` `#define endl '\n';` `using namespace std;`  
&nbsp;&nbsp;&nbsp;&nbsp; · *Golang* : `package main` `import "fmt"`  
&nbsp;&nbsp;&nbsp;&nbsp; · *Rust* : `use std::io;`  
&nbsp;&nbsp; ※ `C++` : Very meaningful time to familiarize with `array` `vector` and `string`!  


## [27866. 문자와 문자열](#list)

> Sprout  
> 3

> r

#### C++ (2023.06.18)
```cpp
int main()
{
    // Input
    string s;
    int idx;
    std::cin >> s >> idx;

    // Output
    std::cout << s[idx-1] << endl;

    return 0;
}
```

#### Rust (2024.01.16)
```rust
fn main()
{
    let mut input1 = String::new();
    let mut input2 = String::new();
    io::stdin().read_line(&mut input1).unwrap();
    io::stdin().read_line(&mut input2).unwrap();

    let i:usize = input2.trim().parse().unwrap();
    // trim `\n` caused by read_line()

    if let Some(chr) = input1.chars().nth(i - 1) { println!("{}", chr) };
}
```


## [2743. 단어 길이 재기](#list)

> pulljima

> 8

#### C++ (2023.06.18)
```cpp
int main()
{
    // Input
    string s;
    std::cin >> s;

    // Output
    std::cout << s.size() << endl;

    return 0;
}
```

#### Rust (2024.01.16)
```rust
fn main()
{
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();

    let len = str.trim().len();
    println!("{}", len);
}
```


## [9086. 문자열](#list)

> 3  
> ACDKJFOWIEGHE  
> O  
> AB

> AE  
> OO  
> AB

#### C++ (2023.06.18)
```cpp
int main()
{
    // Input
    int t;
    string s;
    std::cin >> t;

    // Output
    for (int i = 0; i < t; i++)
    {
        std::cin >> s;
        std::cout << s[0] << s[s.size()-1] << endl;
    }

    return 0;
}
```

#### Rust (2024.02.15)
```rust
fn main()
{
    let mut t = String::new();
    io::stdin().read_line(&mut t).unwrap();

    let t:usize = t.trim().parse().unwrap();
    for _ in 0..t
    {
        let mut str = String::new();
        io::stdin().read_line(&mut str).unwrap();
        let len = str.trim().len();

        println!("{}{}", str.chars().nth(0).unwrap(), str.chars().nth(len - 1).unwrap()); 
    }  
}
```


## [11654. 아스키 코드](#list)

> A

> 65

#### Bash (2022.02.14)
```Bash
read char                   # ex) a

# printf "%d\n" $char       # printf: a: invalid number
# printf "%d\n" "$char"     # printf: a: invalid number; it doesn't matter if use "" or not
# printf "%d\n" '$char'     # printf: $char: invalid number; regard $char itself as a string

printf "%d\n" "'$char'"     # 97; regard a as a string
# printf "%d\n" "'$char"    # 97; the closing quotes(') may be omitted
```

#### C++ (2021.07.09)
```cpp
int main()
{
    char x;
    cin >> x;

    cout << (int) x << endl;

    return 0;
}
```

#### Golang (2022.04.18)
```golang
func main() {
    var x string
    fmt.Scanln(&x)

    fmt.Println(x[0])
}
```

#### Rust (2024.02.15)
```rust
fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    if let Some(char) = input.trim().chars().next()
    {
        let ascii_code = char as u8;
        println!("{}", ascii_code);
    }
}
```


## [11720. 숫자의 합](#list)

> 11  
> 10987654321

> 46 

#### Bash (2022.02.14)
```Bash
read n
read num

let "sum = 0"

for ((i = 0; i < n; i++))
do
    let "sum += ${num:i:1}"

    # test : ok
    # echo ${num:i:1}
done

echo $sum
```

#### C++ (2021.07.09)
```cpp
#include <iostream>
#include <string>
```
```cpp
int main()
{
    // Input
    int n;
    string x;
    cin >> n >> x;

    // Operate and output
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (int) x[i] - '0';
        // cout << x[i] << " " << sum << endl;  // test
    }
    cout << sum << endl;

    return 0;
}
```

#### Golang (2022.04.18)
```golang
func main() {

    // Input
    var n int
    var num string
    fmt.Scanln(&n)
    fmt.Scanln(&num)

    // Calculate sum
    var sum int = 0
    var digit rune
    for _, digit = range num {
        sum += int(digit - '0')
    }

    // Output
    fmt.Println(sum)
}
```

#### Rust (2024.02.15)
```rust
fn main()
{
    let mut n = String::new();
    let mut num = String::new();
    io::stdin().read_line(&mut n).unwrap();
    io::stdin().read_line(&mut num).unwrap();

    let n:usize = n.trim().parse().unwrap();
    let mut sum:u32 = 0;
    for i in 0..n
    {
        let digit:u32 = num.chars().nth(i).unwrap().to_digit(10).unwrap();
        sum += digit;
    }

    println!("{}", sum);
}
```


## [10809. 알파벳 찾기](#list)

> baekjoon

> 1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

#### Bash (2022.02.15)
```Bash
# Input string
read s
let "len = ${#s}"

# Initialize arr
for i in {0..25}
do
    let "arr[$i] = -1"
    # echo ${arr[$i]}                       # test : ok
done

# Search each alphabet's first location
for ((i = 0; i < len; i++))
do
    c=$(printf "%d" "'${s:i:1}'")           # I don't want to lose my precious 'let' but ……
    if [ ${arr[$((c-97))]} -lt 0 ]; then
        let "arr[$((c-97))] = $i"
    fi
done

# Output
for i in {0..25}
do
    echo -n "${arr[$i]} "                   # -n : without line replacement
done
echo
```

#### C++ (2021.07.09)
```cpp
#include <iostream>
#include <string>
#include <vector>
```
```cpp
int main()
{
    // Input
    string s;
    cin >> s;

    // Declare an array for counting a ~ z
    vector<int> alphabet (26, -1);

    // Count
    for (int i = 0; i < s.length(); i++)
    {
        if (alphabet[s[i] - 'a'] == -1)
        {
            alphabet[s[i] - 'a'] = i;
        }
    }

    // Output
    for (int j = 0; j < 25; j++)    // a ~ y
    {
        cout << alphabet[j] << " ";
    }
    cout << alphabet[25] << endl;   // z

    return 0;
}
```

#### Golang (2022.04.18)
```golang
func main() {

    // Input
    var s string
    fmt.Scanln(&s)

    // Declare an array for alphabet
    var alphabet []int
    for i := 0; i < 26; i++ {
        alphabet = append(alphabet, -1)
    }
    // fmt.Println(alphabet)                     // test : ok

    // Find the location
    for i := 0; i < len(s); i++ {
        // fmt.Print(s[i] - 'a')                 // test : ok

        if alphabet[s[i] - 'a'] == -1 {
            alphabet[s[i] - 'a'] = i
        }
    }

    // Output
    // fmt.Println(alphabet)                     // test : [……]
    for i := 0; i < 25; i++ {                    // a ~ y
        fmt.Print(alphabet[i], " ")
    }
    fmt.Println(alphabet[25])                    // z
}
```

#### Rust (2024.02.15)
```rust
fn main()
{
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();

    let mut v: Vec<i32> = vec![-1; 26];

    let len:usize = str.trim().len();
    for i in 0..len
    {
        let c:char = str.chars().nth(i).unwrap();
        if v[c as usize - 'a' as usize] < 0 { v[c as usize - 'a' as usize] = i as i32}
    }

    for i in 0..26 { print!("{} ", v[i]); }
    println!();
}
```


## [2675. Repeating Characters](#list)

> 2  
> 3 ABC  
> 5 /HTP

> AAABBBCCC  
> /////HHHHHTTTTTPPPPP

#### Bash (2022.02.15)
```Bash
read t

for ((i = 0; i < t; i++))
do
    # Read each data
    read r s
    let "len = ${#s}"

    # Repeat each char r times
    for ((j = 0; j < len; j++))
    do
        for ((k = 0; k < r; k++))
        do
            echo -n "${s:j:1}"
        done
    done
    echo
done
```

#### C++ (2021.07.09)
```cpp
#include <iostream>
#include <string>
```
```cpp
int main()
{
    int p;
    cin >> p;

    int n;
    string s;
    for (int i = 0; i < p; i++)
    {
        cin >> n >> s;

        for (int j = 0; j < s.length(); j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << s[j];
            }
        }
        cout << endl;
    }

    return 0;
}
```

#### Golang (2022.04.18)
```golang
func main() {

    var t, r int
    var s string
    fmt.Scanln(&t)

    for i := 0; i < t; i++ {
        fmt.Scanln(&r, &s)

        for j := 0; j < len(s); j++ {
            for k := 0; k < r; k++ {
                fmt.Print(string(s[j]))
            }
        }
        fmt.Println()
    }
}
```

#### Rust (2024.02.15)
```rust
fn main()
{
    let mut p = String::new();
    io::stdin().read_line(&mut p).unwrap();
    let p:usize = p.trim().parse().unwrap();

    for _ in 0..p
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut inputs = input.trim().split_whitespace();

        let n:usize = inputs.next().unwrap().parse().unwrap();
        let str:String = inputs.next().unwrap().to_string();
        let len:usize = str.len();
        for i in 0..len
        {
            for _ in 0..n
            {
                print!("{}", str.chars().nth(i).unwrap());
            }
        }
        print!("\n");
    }
}
```


## [1152. 단어의 개수](#list)

> The Curious Case of Benjamin Button

> 6 (Maybe, difficult to operate `cin.eof()` directly in **C++**)

#### Bash (2022.02.15)
```Bash
read -a s

echo ${#s[@]}
```

#### C++ (2021.07.09)
```cpp
#include <iostream>
#include <string>
#include <vector>
```
```cpp
int main()
{
    // Input
    vector<string> s;
    string temp;
    while (true)
    {
        cin >> temp;
        if (cin.eof() == true)
        {
            break;
        } else
        {
            s.push_back(temp);
        }
    }

    cout << s.size() << endl;

    return 0;
}
```

#### Golang (2022.06.18)
```golang
import (
    "fmt"
    "bufio"
    "os"
    "strings"
)
```
```golang
func main() {

    // Input data (faster)
    var reader = bufio.NewReader(os.Stdin)

    var s string
    s, _ = reader.ReadString('\n')                    // not "\n"

    // Split the string and count
    words := strings.Fields(s)
    // reference ☞ https://pkg.go.dev/strings#Fields

    // Output
    fmt.Println(len(words))
}
```

#### Rust (2024.02.15)
```rust
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let words: Vec<&str> = input.trim().split_whitespace().collect();

    let cnt = words.len();
    println!("{}", cnt);
}
```


## [2908. FILIP](#list)

> 734 893

> 437

#### Bash (2022.02.15)
```Bash
# Input
read a b

# Reverse digits of a and b
for i in {2..0..-1}
do
    a2+="${a:i:1}"
    b2+="${b:i:1}"
done

# Output
if [ $a2 -gt $b2 ]; then
    echo $a2
else
    echo $b2
fi
```

#### C++ (2021.07.09)
```cpp
#include <iostream>
#include <string>
```
```cpp
int main()
{
    // Input a, b : two three digit numbers
    string a, b;
    cin >> a >> b;

    // Reverse a, b
    char aReverse[4], bReverse[4];
    for (int i = 0; i < 3; i++)
    {
        aReverse[3 - i - 1] = a[i];
        bReverse[3 - i - 1] = b[i];
    }
    // cout << aReverse << " " << bReverse << endl; // test

    // Comepare aReverse with bReverse as int and find the larger
    if (stoi(aReverse) > stoi(bReverse))            // A and B will not be equal
    {
        cout << aReverse << endl;
    } else
    {
        cout << bReverse << endl;
    }

    return 0;
}
```

#### Golang (2022.06.19)
```golang
import (
    "fmt"
    "strconv"
)
```
```golang
func main() {

    // Input a, b as string
    var a, b string
    fmt.Scanln(&a, &b)

    // Reverse a, b
    var aRev, bRev string = "", ""
    for i:= 0; i < 3; i++ {
        aRev += string([]rune(a)[3 - i - 1])    // crazy
        bRev += string([]rune(b)[3 - i - 1])
    }

    // Output
    var aInt, bInt int
    aInt, _ = strconv.Atoi(aRev)
    bInt, _ = strconv.Atoi(bRev)
    if aInt > bInt {                            // a != b
        fmt.Println(aInt)
    } else {
        fmt.Println(bInt)
    }
}
```

#### Rust (2024.02.15)
```rust
fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut nums = input.trim().split_whitespace();

    let num1: i32 = nums.next().unwrap().chars().rev().collect::<String>().parse().unwrap();
    let num2: i32 = nums.next().unwrap().chars().rev().collect::<String>().parse().unwrap();

    let max: i32 = if num1 > num2 { num1 } else { num2 };
    println!("{}", max);
}
```


## [5622. BAKA](#list)

> UNUCIC

> 36

#### Bash (2022.02.15)
```Bash
# Input
read s
let "len = ${#s}"

# Count time to turn the dial
let "sum = 0"
for ((i = 0; i < len; i++))
do
    letter=$(printf "%d" "'${s:i:1}'")
    if [ $letter -le $(printf "%d" "'R'") ]; then
        let "sum += $(($(($letter - 65)) / 3 + 2 + 1))"
    elif [ $letter -le $(printf "%d" "'X'") ]; then
        let "sum += $(($(($letter - 65 - 1)) / 3 + 2 + 1))"
    else
        let "sum += $(($(($letter - 65 - 2)) / 3 + 2 + 1))"
    fi
done

echo $sum
```

#### C++ (2021.07.09)
```cpp
#include <iostream>
#include <string>
```
```cpp
int main()
{
    // Input
    string s;
    cin >> s;

    // Operate
    int sLength = s.size();
    int dial, time, sum = 0;
    for (int i = 0; i < sLength; i++)
    {
        if (s[i] <= 'R')
        {
            dial = (s[i] - 'A') / 3 + 2;
        } else if (s[i] >= 'S' && s[i] <= 'X')
        {
            dial = (s[i] - 'A' - 1) / 3 + 2;
        } else
        {
            dial = (s[i] - 'A' - 2) / 3 + 2;
        }

        time = dial + 1;
        sum += time;
        cout << s[i] << " " << dial << " " << time << " " << sum << endl;   // test
    }

    // Output
    cout << sum << endl;

    return 0;
}
```

#### Golang (2022.06.19)
```golang
func main() {

    // Input string s
    var s string
    fmt.Scanln(&s)
    var sRune []rune = []rune(s)

    // Operate
    var sLen int = len(s)
    var dial, time, sum int = 0, 0, 0
    for i := 0; i < sLen; i++ {
        if sRune[i] <= 'R' {
            dial = int(sRune[i] - 'A') / 3 + 2
        } else if sRune[i] >= 'S' && sRune[i] <= 'X' {
            dial = int(sRune[i] - 'A' - 1) / 3 + 2
        } else {
            dial = int(sRune[i] - 'A' - 2) / 3 + 2
        }

        time = dial + 1
        sum += time
    }

    // Output
    fmt.Println(sum)
}
```

#### Rust (2024.02.15)
```rust
fn main()
{
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();

    let len:usize = str.trim().len();
    let mut sum:i32 = len as i32;
    for i in 0..len
    {
        let c:char = str.chars().nth(i).unwrap();
        match c                                             // All possible cases should be handled in `match` statement!
        {
            'A' | 'B' | 'C' => sum += 2,
            'D' | 'E' | 'F' => sum += 3,
            'G' | 'H' | 'I' => sum += 4,
            'J' | 'K' | 'L' => sum += 5,
            'M' | 'N' | 'O' => sum += 6,
            'P' | 'Q' | 'R' | 'S' => sum += 7,
            'T' | 'U' | 'V' => sum += 8,
            _ => sum += 9
        }
    }

    println!("{}", sum);
}
```


## [11718. 그대로 출력하기](#list)

> Hello  
> Baekjoon  
> Online Judge

> Hello  
> Baekjoon  
> Online Judge

#### C++ (2023.06.18)
```cpp
int main()
{
    string s;

    while (true)
    {
        getline(std::cin, s);
        if (std::cin.eof() == true) break;
        else std::cout << s << endl;            
    }
    return 0;
}
```

#### Rust (2024.02.15)
```rust
fn main()
{
    loop
    {
        let mut str = String::new();
        io::stdin().read_line(&mut str).unwrap();

        if str.len() == 0 { break; }                        // EOF
        else { print!("{}", str); };
    }
}
```
