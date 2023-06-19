## BAEKJOON Online Judge

# 문제 > 단계별로 풀어보기 > 1. 입출력과 사칙연산

(2021.05.13) - `Python`, `C++`  
(2021.07.11) - `R`  
(2022.01.26) - `Bash`, `Text` (only possible)  
(2022.03.12) - `Golang`  
(2022.09.05) - `SystemVerilog`

https://www.acmicpc.net/step/1


### List

- [2557. Hello World](#2557-hello-world)
- [1000. A+B](#1000-ab)
- [1001. A-B](#1001-a-b)
- [10998. A*B](#10998-ab)
- [1008. A/B](#1008-ab)
- [10869. 사칙연산](#10869-사칙연산)
- [10926. ??!](#10926-) *(new)*
- [18108. 1998년생인 내가 태국에서는 2541년생?!](#18108-1998년생인-내가-태국에서는-2541년생) *(new)*
- [10430. 나머지](#10430-나머지)
- [11382. 꼬마 정민](#11382-꼬마-정민) *(new)*
- [2588. 곱셈](#2588-곱셈)
- [10171. Cats](#10171-cats)
- [10172. Dogs](#10172-dogs)

#### (Depreciated)
- [3003. BIJELE](#3003-bijele) *(new)*
- [10718. We love kriii](#10718-we-love-kriii)


**※ Note**  

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · `Bash` : `#!/bin/bash`  
&nbsp;&nbsp;&nbsp;&nbsp; · `C++` : `#include <iostream>` `#define endl '\n';` `using namespace std;`  
&nbsp;&nbsp;&nbsp;&nbsp; · `Golang` : `package main` `import "fmt"`  
&nbsp;&nbsp;&nbsp;&nbsp; · `SystemVerilog` : `module` `endmodule`.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; * All the codes run on [JDoodle Online VERILOG Compiler IDE](https://www.jdoodle.com/execute-verilog-online/) as `Verilog` before submitted to [BOJ](https://www.acmicpc.net/) as `SystemVerilog`.  
&nbsp;&nbsp; - `R` : Some answers occur runtime errors with unknowable reason in the BOJ grading machine.  
&nbsp;&nbsp; - `Text` : Only possible problems that do not require input values are solved.  


## [2557. Hello World](#list)

> Hello World!

#### Bash
```Bash
echo "Hello World!"
```

#### C++
```cpp
cout << "Hello World!" << endl;
return 0;
```

#### Golang
```go
fmt.Println("Hello World!")
```

#### Python
```python
print("Hello World!")
```

#### R
```R
# print("Hello World!") # Runtime Error
cat("Hello World!")
```

#### SystemVerilog
```sv
initial begin
    $display("Hello World!");
    $finish;
end
```

#### Text
```txt
Hello World!
```


## [1000. A+B](#list)

> 1 2

> 3

#### Bash
```Bash
read a b
echo $((a + b))

# read
```

#### C++
```cpp
int a, b;
cin >> a >> b;          // 1 2
cout << a + b << endl;

return 0;
```

#### Golang
```go
var a, b int
fmt.Scanln(&a, &b)

fmt.Println(a + b)
```

#### Python
```python
a, b = map(int, input().split())
print(a+b)
```

#### R
```R
num <- scan("stdin")    # recieve num[1], num[2], …… as numeric
cat(num[1] + num[2])
```

#### SystemVerilog
```sv
integer a, b, temp;

initial begin
    temp = $fscanf(32'h8000_0000, "%d %d", a, b);
    // 32'h8000_0000 : descriptor that indicates STDIN
    // $fscanf() (maybe) returns EOF
    $display("%0d", a + b);
    $finish;
end
```


## [1001. A-B](#list)

> 3 2

> 1

#### Bash
```Bash
read a b
echo $((a - b))

# read
```

#### C++
```cpp
int a, b;
cin >> a >> b;          // 3 2
cout << a - b << endl;

return 0;
```

#### Golang
```go
var a, b int
fmt.Scanln(&a, &b)

fmt.Println(a - b)
```

#### Python
```python
a, b = map(int, input().split())
print(a-b)
```

#### R
```R
num <- scan("stdin")    # recieve num[1], num[2], …… as numeric
cat(num[1] - num[2])
```

#### SystemVerilog
```sv
integer a, b, temp;

initial begin
    temp = $fscanf(32'h8000_0000, "%d %d", a, b);
    // 32'h8000_0000 : descriptor that indicates STDIN
    // $fscanf() (maybe) returns EOF
    $display("%0d", a - b);
    $finish;
end
```


## [10998. A*B](#list)

> 3 4

> 12

#### Bash
```Bash
read a b
echo $((a * b))

# read
```

#### C++
```cpp
int a, b;
cin >> a >> b;          // 3 4
cout << a * b << endl;

return 0;
```

#### Golang
```go
var a, b int
fmt.Scanln(&a, &b)

fmt.Println(a * b)
```

#### Python
```python
a, b = map(int, input().split())
print(a*b)
```

#### R
```R
num <- scan("stdin")    # recieve num[1], num[2], …… as numeric
cat(num[1] * num[2])
```

#### SystemVerilog
```sv
integer a, b, temp;

initial begin
    temp = $fscanf(32'h8000_0000, "%d %d", a, b);
    // 32'h8000_0000 : descriptor that indicates STDIN
    // $fscanf() (maybe) returns EOF
    $display("%0d", a * b);
    $finish;
end
```


## [1008. A/B](#list)

> 1 3

> 0.3333333333

#### Bash
```Bash
read a b

# printf "%.9f\n", $a / $b                      # doesn't work
# echo $a $b | awk '{printf "%.9f\n", $1 / $2}' # not adopted at BOJ
# printf "%.9f\n" $(((a * 10**9 / b) / 10**9))  # 1 / 3 = 0.000000000
# printf "%.9f\n" $((a * e+9 / b))e-9           # e-9 works but e+9 doesn't work
printf "%.9f\n" $((a * 10**9 / b))e-9

# read
```

#### C++
```cpp
int a, b;
cin >> a >> b;                  // 1 3
cout.precision(10);             // for reducing error < 10^(-9)
cout << (double)a / b << endl;

return 0;
```

#### Golang
```go
var a, b float64
fmt.Scanln(&a, &b)

fmt.Printf("%.10f\n", a / b)
```
> always marks 10 decimal places

#### Python
```python
a, b = map(float, input().split())
print(a/b)
```

#### R
```R
num <- scan("stdin")    # recieve num[1], num[2], …… as numeric
options(digits = 10)
cat(num[1] / num[2])
```

#### SystemVerilog
```sv
real a, b, temp;

initial begin
    temp = $fscanf(32'h8000_0000, "%d %d", a, b);
    // 32'h8000_0000 : descriptor that indicates STDIN
    // $fscanf() (maybe) returns EOF
    $display("%0.10f", a / b);
    $finish;
end
```


## [10869. 사칙연산](#list)

> 7 3

> 10 4 21 2 1 (vertically)

#### Bash
```Bash
read a b

echo $((a + b))
echo $((a - b))
echo $((a * b))
echo $((a / b))
echo $((a % b))

# read
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

#### Golang
```go
var a, b int
fmt.Scanln(&a, &b)

fmt.Println(a + b)
fmt.Println(a - b)
fmt.Println(a * b)
fmt.Println(a / b)
fmt.Println(a % b)
```

#### Python
```python
a, b = map(int, input().split())

print(a+b)
print(a-b)
print(a*b)
print(int(a/b))
print(a%b)
```

#### R
```R
num <- scan("stdin")                # recieve num[1], num[2], …… as numeric
cat(num[1] + num[2], "\n")
cat(num[1] - num[2], "\n")
cat(num[1] * num[2], "\n")
cat(floor(num[1] / num[2]), "\n")
cat(num[1] %% num[2], "\n")
```

#### SystemVerilog
```sv
integer a, b, temp;

initial begin
    temp = $fscanf(32'h8000_0000, "%d %d", a, b);
    // 32'h8000_0000 : descriptor that indicates STDIN
    // $fscanf() (maybe) returns EOF
    $display("%0d", a + b);
    $display("%0d", a - b);
    $display("%0d", a * b);
    $display("%0d", a / b);
    $finish;
end
```


## [10926. ??!](#list)

> joonas

> joonas??!

#### Bash
```Bash
read id
echo "$id??!"   # How does Bash classify $id and ??! ?

# read
```

#### Golang
```go
var s string
fmt.Scanln(&s)

fmt.Println(s + "??!")
```

#### SystemVerilog
```sv
reg [50*8:0] s;
integer temp;

initial begin
    temp = $fscanf(32'h8000_0000, "%s", s);
    // 32'h8000_0000 : descriptor that indicates STDIN
    // $fscanf() (maybe) returns EOF
    $display("%0s??!", s);
    $finish;
end
```


## [18108. 1998년생인 내가 태국에서는 2541년생?!](#list)

> 2541

> 1998

#### Bash
```Bash
read by

# diff = 2541 - 1998    # doesn't work : should be no space
let "diff = 2541 - 1998"

echo $((by - diff))

# read
```

#### Golang
```go
var by int
fmt.Scanln(&by)

const diff int = 2541 - 1998
fmt.Println(by - diff)
```

#### SystemVerilog
```sv
integer by, diff = 2541 - 1998, temp;

initial begin

    temp = $fscanf(32'h8000_0000, "%d", by);
    // 32'h8000_0000 : descriptor that indicates STDIN
    // $fscanf() (maybe) returns EOF
    $display("%0d", by - diff);
    $finish;
end
```


## [10430. 나머지](#list)

> 5 8 4

> 1 1 0 0 (vertically)

#### Bash
```Bash
read A B C

echo $(((A + B) % C))
echo $((((A % C) + (B % C)) % C))
echo $(((A * B) % C))
echo $((((A % C) * (B % C)) % C))

# read
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

#### Golang
```go
var A, B, C int
fmt.Scanln(&A, &B, &C)

fmt.Println((A + B) % C)
fmt.Println(((A % C) + (B % C)) % C)
fmt.Println((A * B) % C)
fmt.Println(((A % C) * (B % C)) % C)
```

#### Python
```python
A, B, C = map(int, input().split())

print((A+B)%C)
print(((A%C) + (B%C))%C)
print((A*B)%C)
print(((A%C)*(B%C))%C)
```

#### R
```R
num <- scan("stdin")                # recieve num[1], num[2], …… as numeric
# num <- c(5, 8, 4)                 # test

a <- num[1]
b <- num[2]
c <- num[3]

cat((a + b) %% c, "\n")
cat(((a %% c) + (b %% c)) %% c, "\n")
cat((a * b) %% c, "\n")
cat(((a %% c) * (b %% c)) %% c, "\n")
```

#### SystemVerilog
```sv
integer a, b, c, temp;

initial begin
    temp = $fscanf(32'h8000_0000, "%d %d %d", a, b, c);
    // 32'h8000_0000 : descriptor that indicates STDIN
    // $fscanf() (maybe) returns EOF
    $display("%0d", (a + b) % c);
    $display("%0d", ((a % c) + (b % c)) % c);
    $display("%0d", (a * b) % c);
    $display("%0d", ((a % c) * (b % c)) % c);
    $finish;
end
```


## [11382. 꼬마 정민](#list)

(2023.06.17)

> 77 77 7777

> 7931

#### C++
```cpp
using ll = long long;
```
```cpp
ll a, b, c;                                             // 1 ≤ A, B, C ≤ 10^12
cin >> a >> b >> c;
cout << a + b + c << endl;

return 0;
```


## [2588. 곱셈](#list)

> 472  
> 385

> 2360  
> 3776  
> 1416  
> 181720

#### Bash
```Bash
read a
read b
# guaranteed that 100 <= a, b  <= 999

let "sum = 0"
for i in {2..0..-1}
do
    let "prod = $a * ${b:i:1}"          # ${b : i : 1} doesn't work
    echo $prod
    let "sum += $prod * (10 ** (2 - $i))"
done

echo $sum

# read
```
> Accepted

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
```
> 256 385

#### C++ - trial 1-2~3
```cpp
char b[4];                      // trial 1-2 
string b;                       // trial 1-3 : change char[] to string
```
> 472 385

#### C++ - trial 2
```cpp
int len = b.length();

int sum = 0;
for (int i = 0; i < len; i++)
{
    // Test : get each cipher's integer number, not ascii code
    cout << "b[" << len-i-1 << "] : " << b.at(len-i-1) << endl;              // b[2], b[1], b[0] / OK
    cout << "convert to int 1 : " << (int) b.at(len-i-1) << endl;            // trial 2-1 : failure because output its ascii code
    cout << "convert to int 2 : " << (int) (b.at(len-i-1) - '0') << endl;    // trial 2-2 : success
}
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
#include <cmath>    // for using pow()
```
```cpp
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
> Accepted

#### C++ - trial 6 (final)
(2021.05.24)
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

> Accepted

#### C++ - Bonus
```cpp
// Output
cout << sum + 1 << endl; // can't find why lack of 1 - crazy!
```
> ㅋㅋ

#### Golang
```go
package main
import (
    "fmt"
    "math"
)
```
```go
var a int
var b string
fmt.Scanln(&a)
fmt.Scanln(&b)

var sum int = 0
var answer int
for i := 0; i < 3; i++ {
    // test : ok
    // fmt.Println(b[3-i-1] - '0')
    answer = a * int(b[3-i-1] - '0')
    fmt.Println(answer)
    sum += answer * int(math.Pow(10., float64(i)))
}

fmt.Println(sum)
```
> Accepted

#### Python - trial 1
```python
a = int(input())
b = str(input())

for i in range(0,len(b)) :
    print(a*int(b[-i-1]))

print(a*int(b))             // crazy
```
> Accepted

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
> Accepted

#### R
```R
num <- scan("stdin")                            # recieve num[1], num[2], …… as numeric
# num <- c(472, 385)                            # test

a <- num[1]
b <- num[2]

sum = 0
for (i in 1:3)
{
    # cat(floor((b %% 10^i) / 10^(i-1)), "\n")  # test
    ans = a * floor((b %% 10^i) / 10^(i-1))
    cat(ans, "\n")
    sum = sum + ans * 10^(i - 1) 
}

cat(sum, "\n")
```
> Accepted

#### SystemVerilog
```sv
integer a;
reg [3*8:0] b;
integer i, prod, sum = 0, temp;

initial begin
    temp = $fscanf(32'h8000_0000, "%d", a);
    temp = $fscanf(32'h8000_0000, "%s", b);
    // 32'h8000_0000 : descriptor that indicates STDIN
    // $fscanf() (maybe) returns EOF

    for (i = 0; i < 3; i = i + 1) begin
        prod = a * (b[i*8 +: 8] - 48);
        sum = sum + prod * (10**i);

        // test
        // $display("%0d %0d %0d %0d %0d", i, a, b[i*8 +: 8] - 48, prod, sum);

        $display("%0d", prod);
    end
    $display("%0d", sum);
    $finish;
end
```
> Accepted


## [10171. Cats](#list)

```txt
\    /\
 )  ( ')
(  /  )
 \(__)|
```

#### Bash
```Bash
echo "\\    /\\"
echo " )  ( ')"
echo "(  /  )"
echo " \\(__)|"

# read
```

#### C++
```cpp
cout << "\\    /\\" << endl;
cout << " )  ( ')" << endl;
cout << "(  /  ) " << endl;
cout << " \\(__)|" << endl;

return 0;
```

#### Golang
```go
var s string = `\    /\
)  ( ')
(  /  )
\(__)|`

fmt.Println(s)
```

#### Python
```python
print("\    /\\")
print(" )  ( ')")
print("(  /  )")
print(" \\(__)|")
```

#### R
```R
cat("\\    /\\
 )  ( \')
(  /  )
 \\(__)|")
```

#### SystemVerilog
```sv
initial begin
    $display("\\    /\\");
    $display(" )  ( ')");
    $display("(  /  )");
    $display(" \\(__)|");
    $finish;
end
```

#### Text
```txt
\    /\
 )  ( ')
(  /  )
 \(__)|
```


## [10172. Dogs](#list)

```txt
|\_/|
|q p|   /}
( 0 )"""\
|"^"`    |
||_/=\\__|
```

#### Bash
```Bash
echo "|\_/|"
echo "|q p|   /}"
echo "( 0 )\"\"\"\\"
echo "|\"^\"\`    |"
echo "||_/=\\\\__|"

# read
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

#### Golang
```go
fmt.Println("|\\_/|")
fmt.Println("|q p|   /}")
fmt.Println("( 0 )\"\"\"\\")
fmt.Println("|\"^\"`    |")
fmt.Println("||_/=\\\\__|")
```

#### Python
```python
print("""|\\_/|
|q p|   /}
( 0 )\"\"\"\\
|"^"`    |
||_/=\\\\__|""")
```

#### R
```R
cat("|\\_/|
|q p|   /}
( 0 )\"\"\"\\
|\"^\"`    |
||_/=\\\\__|")
```

#### SystemVerilog
```sv
initial begin
    $display("|\\_/|");
    $display("|q p|   /}");
    $display("( 0 )\"\"\"\\");
    $display("|\"^\"`    |");
    $display("||_/=\\\\__|");
    $finish;
end
```

#### Text
```txt
|\_/|
|q p|   /}
( 0 )"""\
|"^"`    |
||_/=\\__|
```


## [3003. BIJELE](#list)

> 2 1 2 1 2 1

> -1 0 0 1 0 7

#### SystemVerilog
```sv
reg [6*8:0] pieces = "112228";                                              // Can I enter this as an integer array?
integer signed data[6:0];
integer temp, i;

initial begin
    // Input
    for (i = 0; i < 6; i = i + 1) begin
        temp = $fscanf(32'h8000_0000, "%d", data[i]);
        // 32'h8000_0000 : descriptor that indicates STDIN
        // $fscan() (maybe) returns EOF
    end

    for (i = 0; i < 6; i = i + 1) begin
        // test
        // $display("%0d %0d", pieces[(6-i)*8 - 8 +: 8] - 48, data[i]);

        $write("%0d ", $signed(pieces[(6-i)*8 - 8 +: 8] - 48) - data[i]);
    end
    $display();
    $finish;
end
```


## [10718. We love kriii](#list)

> 강한친구 대한육군  
> 강한친구 대한육군

#### Bash
```Bash
for i in {0..1}
do
    echo "강한친구 대한육군"
done
```

#### C++
```cpp
for (int i = 0; i < 2; i++)
{
    cout << "강한친구 대한육군" << endl;
}

return 0;
```

#### Golang - trial 1
```go
var s string = "강한친구 대한육군"
fmt.Println(s)
fmt.Println(s)
```

#### Golang - trial 2
```go
var s string = "강한친구 대한육군"
for i := 0; i < 2; i++ {
        fmt.Println(s)
}
```

#### Python
```python
for i in range(0, 2) :
    print("강한친구 대한육군")
```

#### R
```R
for (i in c(0, 1))
{
    cat("강한친구 대한육군\n")
}
```

#### SystemVerilog
```sv
initial begin
    repeat (2) begin
        $display("강한친구 대한육군");
    end
    $finish;
end
```

#### Text
```txt
강한친구 대한육군
강한친구 대한육군
```
