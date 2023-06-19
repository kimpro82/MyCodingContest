## [BAEKJOON Online Judge](../../../../README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 6. 심화 1

https://www.acmicpc.net/step/52

(2023.06.19) - `C++`  
(2022.09.06) - `SystemVerilog`


### **List**

- [25083. 새싹](#25083-새싹)
- [3003. BIJELE](#3003-bijele)
- [2444. 별 찍기 - 7](#2444-별-찍기---7)
- [10988. 팰린드롬인지 확인하기](#10988-팰린드롬인지-확인하기)
- [1157. 단어 공부](#1157-단어-공부)
- []()
- []()

#### (Depreciated)
- []()


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



## [25083. 새싹](#list)

```txt
         ,r'"7
r`-_   ,'  ,/
 \. ". L_r'
   `~\/
      |
      |
```

#### SystemVerilog (2022.09.05)
```sv
module Q25083();

    initial begin
        $display("         ,r'\"7");
        $display("r`-_   ,'  ,/");
        $display(" \\. \". L_r'");
        $display("   `~\\/");
        $display("      |");
        $display("      |");
        $finish;
    end

endmodule
```


## [3003. BIJELE](#list)

```txt
2 1 2 1 2 1
```
```txt
-1 0 0 1 0 7
```

#### SystemVerilog (2022.09.06)
```sv
module Q3003();

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

endmodule
```


## [2444. 별 찍기 - 7](#list)

```txt
5
```

```txt
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
```

#### C++ (2023.06.19)
```cpp
int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < 2*n-1; i++)
    {
        for (int j = 0; j < 2*n-1; j++)
        {
            if (i < n)
            {
                if (j < n-i-1) std::cout << ' ';
                else if (j < n+i) std::cout << '*';
                else continue;
            }
            else
            {
                if (j < i-n+1) std::cout << ' ';
                else if (j < (2*n-1) -(i-n+1)) std::cout << '*';
                else continue;
                // 머리로 생각하지 말고, 손으로 그리고 식을 쓰고 계산하자.
            }
        }
        std::cout << '\n';
    }

    return 0;
}
```


## [10988. 팰린드롬인지 확인하기](#list)

```txt
level
```

```txt
1
```

#### C++ (2023.06.19)
```cpp
int main()
{
    // Input
    string s;
    std::cin >> s;
    int len = s.size();
    int isPalindrome = 1;

    // Judge
    for (int i = 0; i < len/2; i++)     // robust against if odd or even
    {
        if (s[i] != s[len-i-1])
        {
            isPalindrome = 0;
            break;
        }
    }

    // Output
    std::cout << isPalindrome << endl;

    return 0;
}
```


## [1157. 단어 공부](#list)

```txt
Mississipi
```
```txt
4 8 2
?
```

#### Bash (2022.02.15)
```Bash
# Read a string and get its length
read s
let "len = ${#s}"

# Change all letters to uppercase
S=${s^^}                                # ^^ : uppercase, ,, : lowercase
# let "S = ${s^^}"                      # doesn't work

# Initialize arr
for i in {0..25}
do
    let "arr[$i] = 0"
done

# Count each alphabet
for ((i = 0; i < len; i++))
do
    c=$(printf "%d" "'${S:$i:1}'")
    let "arr[$((c-65))] += 1"

    # test : ok
    # echo $i ${S:$i:1} $(($c-65)) ${arr[$(($c-65))]}
done

# Find the max value
let "max = 0"
for i in {0..25}
do
    let "num = ${arr[$i]}"
    if [ $num -gt $max ]; then
        let "max = $num"
        let "maxIndex = $i"
    fi
done

# Determine if the max value is plural
let "isPlural = 0"
for i in {0..25}
do
    if [ ${arr[$i]} -eq $max ]; then
        ((isPlural++))
        if [ $isPlural -gt 1 ]; then
            break
        fi
    fi

    # test : ok
    # echo $i ${arr[$i]} $isPlural
done

# test : ok
# echo $maxIndex $max $isPlural

# Output
if [ $isPlural -gt 1 ]; then
    echo '?'
else
    printf $(printf '\%o' "$(($maxIndex + 65))")    # crazy; bash requires only \octal(\%o), not \decimal(\%d)
fi
```
> 시간 초과 : The maximum length of the word is 1,000,000

#### C++ (2021.07.09)
```cpp
#include <iostream>
#include <string>
#include <array>
```
```cpp
int main()
{
    // Input
    string s;
    cin >> s;

    // Change all letters to upper case
    const int sLength = s.length();
    for (int i = 0; i < sLength; i++)
    {
        s[i] = toupper(s[i]);
    }
    // cout << s << endl;                   // test

    // Count each alphabet
    array<int, 26> alphabet = {0, };
    for (int j = 0; j < sLength; j++)
    {
        alphabet[s[j]-'A']++;
    }

    // Find the max value
    int maxValue = 0, maxIndex;
    for (int k = 0; k < 26; k++)
    {
        if (alphabet[k] > maxValue)
        {
            maxValue = alphabet[k];
            maxIndex = k;
        }
    }

    // Determine if the max value is unique
    int ifUnique = 0; 
    for (int l = 0; l < 26; l++)
    {
        if (alphabet[l] == maxValue)
        {
            ifUnique++;
        }
    }

    // Test
    cout << maxValue << " " << maxIndex << " " << ifUnique << endl;

    // Output
    if (ifUnique > 1)
    {
        cout << '?' << endl;
    } else
    {
        cout << char ('A' + maxIndex) << endl;
    }

    return 0;
}
```

#### Golang (2022.05.02)
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
    var s string                                // length : < 1,000,000
    fmt.Fscan(reader, &s)

    // Change all letters to upper case
    var length int = len(s)
    // var s2 string = ""                       // string in Golang is immutable
    // for i := 0; i < length; i++ {
    //     s2 += strings.ToUpper(string(s[i]))
    // }
    var s2 string = strings.ToUpper(s)          // can convert just at once

    // Count each alphabet
    var alphabet []int = make([]int, 26)        // [0, 0, ……, 0]
    for j := 0; j < length; j++ {
        alphabet[s2[j]-'A']++
    }

    // Find the max value
    var max int = 0
    var maxIdx int
    for k := 0; k < 26; k++ {
        if alphabet[k] > max {
            max = alphabet[k]
            maxIdx = k
        }
    }

    // Determine if the max value is unique
    var ifUnique int = 0
    for l := 0; l < 26; l++ {
        if alphabet[l] == max {
            ifUnique++
        }
    }

    // test
    // fmt.Println(max, maxIdx, ifUnique)

    // Output
    if ifUnique > 1 {
        fmt.Println("?")                        // not '?'
    } else {
        fmt.Println(string(maxIdx + 'A'))
    }
}
```


## [](#list)

```txt

```

```txt

```

#### C++
```cpp

```

