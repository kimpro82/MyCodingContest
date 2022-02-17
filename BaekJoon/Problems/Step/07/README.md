## BAEKJOON Online Judge

# 문제 > 단계별로 풀어보기 > 7. 문자열

https://www.acmicpc.net/step/7

(2021.07.10) - `C++`  
(2022.02.16) - `Bash`


## **List**

- [11654. 아스키 코드](#11654-아스키-코드)
- [11720. 숫자의 합](#11720-숫자의-합)
- [10809. 알파벳 찾기](#10809-알파벳-찾기)
- [2675. Repeating Characters](#2675-repeating-characters)
- [1157. 단어 공부](#1157-단어-공부)
- [1152. 단어의 개수](#1152-단어의-개수)
- [2908. FILIP](#2908-filip)
- [5622. BAKA](#5622-baka)
- [2941. LJESNJAK](#2941-ljesnjak)
- [1316. 그룹 단어 체커](#1316-그룹-단어-체커)


**※ Note**  

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - `Bash` : skipped the first line; `#!/bin/bash`  
&nbsp;&nbsp; - `C++` : skipped `main()` function's brace(`{}`) and its outside(`<iostream>` header and namespace `std`).  
&nbsp;&nbsp;&nbsp;&nbsp; · Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
&nbsp;&nbsp;&nbsp;&nbsp; · When any additional header is used, the header block is also noted seperately.  
&nbsp;&nbsp;&nbsp;&nbsp; ※ Very meaningful time to familiarize with `array` `vector` and `string`!


## [11654. 아스키 코드](#list)

> A

> 65

#### Bash
```Bash
read char                   # ex) a

# printf "%d\n" $char       # printf: a: invalid number
# printf "%d\n" "$char"     # printf: a: invalid number; it doesn't matter if use "" or not
# printf "%d\n" '$char'     # printf: $char: invalid number; regard $char itself as a string

printf "%d\n" "'$char'"     # 97; regard a as a string
# printf "%d\n" "'$char"    # 97; the closing quotes(') may be omitted
```

#### C++ 
```cpp
char x;
cin >> x;

cout << (int) x << endl;

return 0;
```


## [11720. 숫자의 합](#list)

> 11  
> 10987654321

> 46 

#### Bash
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

#### C++ 
```cpp
#include <iostream>
#include <string>
```
```cpp
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
```


## [10809. 알파벳 찾기](#list)

> baekjoon

> 1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

#### Bash
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

#### C++ 
```cpp
#include <iostream>
#include <string>
#include <vector>
```
```cpp
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
```


## [2675. Repeating Characters](#list)

> 2  
> 3 ABC  
> 5 /HTP

> AAABBBCCC  
> /////HHHHHTTTTTPPPPP

#### Bash
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

#### C++ 
```cpp
#include <iostream>
#include <string>
```
```cpp
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
```


## [1157. 단어 공부](#list)

> Mississipi

> 4 8 2  
> ?

#### Bash
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

#### C++ 
```cpp
#include <iostream>
#include <string>
#include <array>
```
```cpp
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
```


## [1152. 단어의 개수](#list)

> The Curious Case of Benjamin Button

> 6 (Maybe, difficult to operate `cin.eof()` directly in **C++**)

#### Bash
```Bash
read -a s

echo ${#s[@]}
```

#### C++ 
```cpp
#include <iostream>
#include <string>
#include <vector>
```
```cpp
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
```


## [2908. FILIP](#list)

> 734 893

> 437

#### Bash
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

#### C++ 
```cpp
#include <iostream>
#include <string>
```
```cpp
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
```


## [5622. BAKA](#list)

> UNUCIC

> 36

#### Bash
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

#### C++ 
```cpp
#include <iostream>
#include <string>
```
```cpp
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
```


## [2941. LJESNJAK](#list)

> ljes=njak

> 6

#### Bash
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

#### C++ 
```cpp
#include <iostream>
#include <string>
#include <array>
#include <vector>
```
```cpp
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
```


## [1316. 그룹 단어 체커](#list)

> 5  
> ab  
> aa  
> aca  
> ba  
> bb

> 4

#### Bash
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

#### C++ 
```cpp
#include <iostream>
#include <string>
#include <array>
```
```cpp
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
```