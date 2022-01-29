## BAEKJOON Online Judge

# 문제 > 단계별로 풀어보기 > 2. if문

(2021.05.24) - `C++`  
(2021.07.14) - `R`  
(2022.01.29) - `Bash`

https://www.acmicpc.net/step/4

**※ Note**  
&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - `C++` : skipped `main()` function's brace(`{}`) and its outside  
&nbsp;&nbsp; - `R` : Some answers occur runtime errors with unknowable reason in BOJ grading machine  
&nbsp;&nbsp; - `Bash` : skipped the first lines `#!/bin/bash`


### List

- [1330. 두 수 비교하기](#1330-두-수-비교하기)
- [9498. 시험 성적](#9498-시험-성적)
- [2753. 윤년](#2753-윤년)
- [14681. Quadrant Selection](#14681-quadrant-selection)
- [2884. SPAVANAC](#2884-spavanac)


## [1330. 두 수 비교하기](#list)

#### C++
```cpp
int a, b;
cin >> a >> b;          // 1 2, 10 2, 5 5

if (a > b)
{
    cout << ">" << endl;
} else if (a < b)
{
    cout << "<" << endl;
} else
{
    cout << "==" << endl;
}

return 0;
```

#### R
```R
data <- scan("stdin")
# data <- c(1,2)        # test

a <- data[1]
b <- data[2]

if (a > b)
{
    cat(">")
} else if (a < b)
{
    cat("<")
} else 
{
    cat("==")
}
```

#### Bash
```bash
read a b

if [ $a -gt $b ] ; then echo ">"        # gt : >, ge : >=
elif [ $a -lt $b ] ; then echo "<"      # lt : <, le : <=
else echo "=="
fi                                      # fi : (maybe) finish if …… or simply reversed "if"?

# read
```

> 1 2, 10 2, 5 5 (independently)

> \<  
> \>  
> \=\=


## [9498. 시험 성적](#list)

#### C++
```cpp
int a;
cin >> a;                   // 99, 82, 79, 60, 37

if (a >= 90)
{
    cout << "A" << endl;
} else if (a >= 80)
{
    cout << "B" << endl;
} else if (a >= 70)
{
    cout << "C" << endl;
} else if (a >= 60)
{
    cout << "D" << endl;
} else
{
    cout << "F" << endl;
}

return 0;
```

#### R
```R
a <- scan("stdin")
# a <- 100          # test

if (a >= 90)
{
    cat("A\n")
} else if (a >= 80)
{
    cat("B\n")
} else if (a >= 70)
{
    cat("C\n")
} else if (a >= 60)
{
    cat("D\n")
} else 
{
    cat("F\n")
}
```

#### Bash
```bash
# test
# echo [ 3 -gt 2 ]                      # doesn't work
# echo [ 3 -lt 2 ]                      # doesn't work
# echo $((3 > 2))                       # 1
# echo $((3 < 2))                       # 0

read n

# if $(($n >= 90)) ; then echo 'A'      # doesn't work
if [ $n -ge 90 ] ; then echo 'A'
elif [ $n -ge 80 ] ; then echo 'B'
elif [ $n -ge 70 ] ; then echo 'C'
elif [ $n -ge 60 ] ; then echo 'D'
else echo 'F'
fi

# read
```

> 99, 82, 79, 60, 37 (independently)

> A B C D F (vertically)


## [2753. 윤년](#list)

#### C++
```cpp
int a;
cin >> a;                                           // 2021, 2000, 1900

if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))
{
    cout << 1 << endl;
} else
{
    cout << 0 << endl;
}

return 0;
```

#### R
```R
n <- scan("stdin")
# n <- 2000                                             # test

if (n %% 4 == 0 && (n %% 100 != 0 || n %% 400 == 0))    # not %
{
    cat("1\n")
} else
{
    cat("0\n")
}
```
> Runtime Error???

#### Bash
```bash
read n

# Test : all cases works
# if [ $(($n % 4)) == 0 ] ; then
#     echo "success 1"
# fi
# if [ $(($n%100)) == 0 ] ; then
#     echo "success 2"
# fi
# if [ $(($n % 400)) == 0 ] ; then
#     echo "success 3"
# fi

if [ $(($n % 4)) == 0 ] ; then
    if [ $(($n%100)) != 0 ] || [ $(($n % 400)) == 0 ] ; then    # failed to write 3 conditions in a line
        echo 1
    else
        echo 0
    fi
else
    echo 0
fi

# read
```

> 2000 1999 (independently)

> 0 1 0 (vertically)


## [14681. Quadrant Selection](#list)

#### C++
```cpp
int a, b;
cin >> a >> b;           // 12 5, 9 -13
// A given condition : Neither of the two coordinates will be 0.

if (a > 0 && b > 0)
{
    cout << 1 << endl;
} else if (a < 0 && b > 0)
{
    cout << 2 << endl;
} else if (a < 0 && b < 0)
{
    cout << 3 << endl;
} else
{
    cout << 4 << endl;
}

return 0;
```

#### R
```R
data <- scan("stdin")
# data <- c(12, 5)          # test

x <- data[1]
y <- data[2]

if (x > 0 && y > 0)
{
    cat("1\n")
} else if (x < 0 && y > 0)
{
    cat("2\n")
} else if (x < 0 && y < 0)
{
    cat("3\n")
} else 
{
    cat("4\n")
}
```

#### Bash
```bash
read x
read y

if [ $x -gt 0 ] && [ $y -gt 0 ] ; then
    echo 1
elif [ $x -lt 0 ] && [ $y -gt 0 ] ; then
    echo 2
elif [ $x -lt 0 ] && [ $y -lt 0 ] ; then
    echo 3
else
    echo 4
fi
```

> 12 5, 9 -13 (independently)

> 1  
> 4


## [2884. SPAVANAC](#list)

#### C++
```cpp
int a, b;
cin >> a >> b;           // 10 10, 0 30, 23 40

if (b < 45)
{
    a--;
    b += 60;
}
if (a < 0)
{
    a += 24;
}

cout << a << " " << b - 45 << endl;

return 0;
```

#### R
```R
data <- scan("stdin")
# data <- c(10, 10)          # test

a <- data[1]
b <- data[2]

if (b < 45)
{
    a = a - 1
    b = b + 60
}
if (a < 0)
{
    a = a + 24
}

cat(a, b - 45, "\n")
```
> Runtime Error???????

#### Bash
```bash
read h m

if [ $m -lt 45 ] ; then
    let "h -= 1"
    let "m += 60"
fi

if [ $h -lt 0 ] ; then
    let "h += 24"
fi

echo $h $(($m - 45))
```

> 10 10, 0 30, 23 40 (independently)

> 9 25  
> 23 45  
> 22 55