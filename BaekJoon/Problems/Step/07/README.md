## BAEKJOON Online Judge

## 문제 > 단계별로 풀어보기 > 7. 문자열
(2021.07.10)  
https://www.acmicpc.net/step/7  

※ C++ codes : **skipped** `main()` function's brace(`{}`) and its outside  
    - Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
    - When any additional header is used, the header block is also noted seperately.  

Very meaningful time to familiarize with `array` `vector` and `string`!


### 11654. 아스키 코드

#### C++ 
```cpp
char x;
cin >> x;

cout << (int) x << endl;

return 0;
```

> A

> 65


### 11720. 숫자의 합

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

> 11  
> 10987654321

> 46 


### 10809. 알파벳 찾기

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

// Declare an array for counting a~z
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

> baekjoon

> 1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1


### 2675. Repeating Characters

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

> 2  
> 3 ABC  
> 5 /HTP

> AAABBBCCC  
> /////HHHHHTTTTTPPPPP


### 1157. 단어 공부

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

// Change all letter to upper case
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

// test
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

> Mississipi

> 4 8 2  
> ?


### 1152. 단어의 개수

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

> The Curious Case of Benjamin Button

> 6 (Maybe, difficult to operate cin.eof() directly)


### 2908. FILIP

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

> 734 893

> 437


### 5622. BAKA

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

> UNUCIC

> U 8 9 9  
> N 6 7 16  
> U 8 9 25  
> C 2 3 28  
> I 4 5 33  
> C 2 3 36  
> 36


### 2941. LJESNJAK

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

> ljes=njak

> 6


### 1316. 그룹 단어 체커

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

> 3  
> happy  
> new  
> year

> happy 0 1  
> new 0 2  
> year 0 3  
> 3