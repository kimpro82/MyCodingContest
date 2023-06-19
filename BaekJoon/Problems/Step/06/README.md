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
- [4344. Above Average](#4344-above-average)
- [2941. LJESNJAK](#2941-ljesnjak)
- [1316. 그룹 단어 체커](#1316-그룹-단어-체커)
- [25206. 너의 평점은](#25206-너의-평점은)

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


## [4344. Above Average](#list)

```txt
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91
```
```txt
40.000%
57.143%
33.333%
66.667%
55.556%
```

#### Bash (2022.02.04)
```bash
read c

# Operation to grade and output
for ((i = 0; i < c; i++))
do
    # Read an array
    read -a arr

    let "len = arr[0]"
    let "sum = 0"

    # Get the array's sum and average
    for ((j = 1; j < len + 1; j++))
    do
        let "sum += ${arr[j]}"
    done
    let "average = sum * 10 / len"                      # don't forget sum * 10

    # test
    # echo $i $sum $len $average

    # Count freshmen over the average score
    let "count = 0"
    for ((j = 1; j < len + 1; j++))
    do
        let "score = ${arr[j]} * 10"
        if [ $score -gt $average ]; then
            let "count += 1"
        fi
    done

    # Output
    printf "%.3f%%\n" $((count * 10 ** 8 / len))e-6
    # * 10 ** 6 & e-4 : fail (maybe concerned with rounding ……)
done
```

#### C++ (2021.06.13)
```cpp
int main()
{
    int c;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        int n;
        cin >> n;

        // get sum and average
        int scores[n], sum = 0, average;
        for (int j = 0; j < n; j++)
        {
            cin >> scores[j];
            sum += scores[j];
        }
        average = sum / n;

        // get percentage of students whose grade is above average
        double aboveAverage = 0;
        for (int k = 0; k < n; k++)
        {
            if (scores[k] > average)
            {
                aboveAverage += 1;
            }
        }

        // test
        cout << n << " " << sum << " " << average << " " << aboveAverage << endl;

        // ouput
        double aboveAverageRatio = (double) (aboveAverage / n) * 100;
        cout << fixed;      // output 40.000, not 40
        cout.precision(3);  // 3 : 3 ciphers under decimal point
        cout << aboveAverageRatio << '%' << endl;
    }

    return 0;
}
```

#### Golang (2022.04.12)
```golang
func main() {
    var c, n int
    fmt.Scanln(&c)

    for i := 0; i < c; i++ {
        fmt.Scan(&n)

        var score []float32 = make([]float32, n)                            // don't forget make()!
        var sum, average float32
        var aboveAverage int

        // Get sum and average
        sum = 0
        for j := 0; j < n; j++ {
            fmt.Scan(&score[j])
            sum += score[j]
        }
        average = sum / float32(n)

        // test : ok
        // fmt.Println(score, sum, average)

        // Get percentage of students whose grades are above average
        aboveAverage = 0
        for j := 0; j < n; j++ {
            if score[j] > average {
                aboveAverage++
            }
        }

        // test : ok
        // fmt.Println(n, aboveAverage)

        // Output
        fmt.Printf("%.3f%%\n", float32(aboveAverage) / float32(n) * 100)    // not \%, but %%
    }
}
```


## [2941. LJESNJAK](#list)

```txt
ljes=njak
```
```txt
6
```

#### Bash (2022.02.16)
```Bash
# Input
read s
let "len = ${#s}"

# Make an array of specific Croatian alphabets
specific1=("c=" "c-" "d-" "lj" "nj" "s=" "z=")
specific2="dz="

# Count if the string includes specific letters
let "count = 0"
# 1) two letters : specific[0, 6]
for ((i = 0; i < ((len - 1)); i++))
do
    for j in {0..6}
    do
        if [[ ${specific1[j]} =~ ${s:i:2} ]]; then
            ((count++))
        fi

        # test : ok
        # echo $i ${s:i:2} ${specific1[j]} $count
    done
done
# 2) three letters : specific[7]
for ((i = 0; i < ((len - 2)); i++))
do
    if [[ $specific2 == ${s:i:3} ]]; then
        ((count++))                                # don't add 2; to avoid double count 'z=' and 'dz='
    fi

    # test : ok
    # echo $i ${s:i:3} $specific2 $count
done

# Output
echo $((len - count))
```

#### C++ (2021.07.09)
```cpp
#include <iostream>
#include <string>
#include <array>
#include <vector>
```
```cpp
int main()
{
    // Input
    string s;
    cin >> s;

    // Make an array of specific Croatian alphabets
    array<string, 8> specific = {"c=", "c-", "d-", "lj", "nj", "s=", "z=", "dz="};

    // Make substrings from s
    int sLength = s.size();
    // 1) two letters
    vector<string> sSub1;
    for (int i = 0; i < sLength - 1; i++)
    {
        sSub1.push_back(s.substr(i, 2));
    }
    // 2) three letters
    vector<string> sSub2;
    for (int j = 0; j < sLength - 2; j++)
    {
        sSub2.push_back(s.substr(j, 3));
    }

    // Count specific Croatian alphabets
    int count = 0;
    // 1) two letters : specific[0, 6]
    for (int k = 0; k < sLength - 1; k++)
    {
        for (int l = 0; l < 7; l++)
        {
            if (s.substr(k, 2) == specific[l])
            {
                count++;
            }
        }
    }
    // 2) three letters : specific[7]
    for (int m = 0; m < sLength - 2; m++)
    {
        if (s.substr(m, 3) == specific[7])
        {
            count++;
        }
    }

    // Output
    cout << sLength - count << endl;

    return 0;
}
```

#### Golang (2022.06.20)
Use different algorithm from other solvings of `Bash` `C++`
```golang
import (
    "fmt"
    "strings"
)
```
```golang
func main() {

    // Input
    var s string
    var sp2 = [7]string {"c=", "c-", "d-", "lj", "nj", "s=", "z="}
    var sp3 = [1]string {"dz="}
    fmt.Scanln(&s)

    // Count substrings
    var letter string
    var count int = len(s)
    for _, letter = range sp2 {
        count -= strings.Count(s, letter)
    }
    for _, letter = range sp3 {
        count -= strings.Count(s, letter)        // not * 2 because "z-" are already counted
    }

    // Output
    fmt.Println(count)
}
```


## [1316. 그룹 단어 체커](#list)

```txt
3
happy
new
year
3
```
```txt
4
aba
abab
abcabc
a
1
```

#### Bash (2022.02.16)
```Bash
read n

let "count = 0"
for ((i = 0; i < n; i++))
do
    # Input
    read s
    let "len = ${#s}"

    # Initialize arr for counting each alphabet
    for j in {0..25}
    do
        let "alphabet[$j] = 0"
    done

    # Find if there are seperated same idxs
    let "isSeperated = 0"
    for ((k = 0; k < len; k++))
    do
        idx=$(($(printf "%d" "'${s:k:1}'")-97))

        if [[ ${alphabet[$idx]} == 0 ]]; then
            ((alphabet[idx]++))
        elif [[ ${s:k:1} != ${s:$((k-1)):1} ]]; then    # not $s[$k] !!!
            ((isSeperated++))
            break
        fi

        # test : ok
        # echo $i $s $k ${s:k:1} $idx ${alphabet[$idx]} $isSeperated
    done

    # Count
    if [[ $isSeperated == 0 ]]; then
        ((count++))
    fi

    # test : ok
    # echo "isSeperated : ${isSeperated}, count : ${count}"
done

# Output
echo $count
```
> 런타임 에러

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
    int n;
    cin >> n;

    string s;
    int sLength, count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        sLength = s.size();

        // Find if there are seperated same letters
        array<int, 26> alphabet = {0, };
        bool isSeperated = false;
        for (int j = 0; j < sLength; j++)
        {
            if (alphabet[s[j] - 'a'] == 0)
            {
                alphabet[s[j] - 'a']++;
            } else
            {
                if (s[j] != s[j-1])
                {
                    isSeperated = true;
                    break;
                }
            }
        }

        // Count
        if (isSeperated == false)
        {
            count++;
        }

        // test
        cout << s << " " << isSeperated << " " << count << endl;
    }

    // Output
    cout << count << endl;

    return 0;
}
```

#### Golang (2022.06.20)
```golang
func main() {

    var n int
    fmt.Scanln(&n)

    // Determine n times
    var count int = 0
    for i := 0; i < n; i++ {

        // Input
        var s string
        fmt.Scanln(&s)
        var sLen int = len(s)
        var sRune = []rune(s)

        // Find if there are seperated same letters
        var alphabet [26]int                        // initialize as {0, ……, 0}
        var isSeperated bool = false
        for j := 0; j < sLen; j++ {
            if alphabet[sRune[j] - 'a'] == 0 {
                alphabet[sRune[j] - 'a']++
            } else {
                if sRune[j] != sRune[j-1] {
                    isSeperated = true
                    break
                }
            }
        }

        // Count
        if (isSeperated == false) {
            count++
        }
    }

    // Output
    fmt.Println(count)
}
```


## [25206. 너의 평점은](#list)

```txt
ObjectOrientedProgramming1 3.0 A+
IntroductiontoComputerEngineering 3.0 A+
ObjectOrientedProgramming2 3.0 A0
……
ProblemSolving 4.0 P
```
```txt
3.284483
```

#### C++ (2023.06.19)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// #define test
#define endl '\n'

using namespace std;
```
```cpp
double convertGrade(string grade)
{
    const vector<string> grades = {"F", "F", "D0", "D+", "C0", "C+", "B0", "B+", "A0", "A+"};
    int idx;
    for (int i = 0; i < grades.size(); i++)
    {
        if (grade == grades[i])
        {
            idx = i;
            break;
        }
    }
    double convertedGrade = double(idx) * 0.5;

    return convertedGrade;
}
```
```cpp
int main()
{
    // Declare
    string title, sWeight, grade;
    double sum = 0, convertedGrade, ans;
    int cnt = 0, nWeight;

    // Input & Operate
    for (int i = 0; i < 20; i++)
    {
        std::cin >> title >> sWeight >> grade;
        if (grade != "P")
        {
            convertedGrade = convertGrade(grade);
            nWeight = sWeight[0] - '0';
            sum += double(nWeight) * convertedGrade;
            cnt += nWeight;
        }

        #ifdef test
            std::cout << cnt << ' ' << convertedGrade << ' ' << sum << endl;
        #endif
    }

    // Output
    ans = sum / cnt;
    std::cout << ans << endl;

    return 0;
}
```
