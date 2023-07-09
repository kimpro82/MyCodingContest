## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 13. 정렬

https://www.acmicpc.net/step/9

(2021.12.16) - `C++`  
(2022.07.11) - `Golang`


## **List**

- [2750. 수 정렬하기](#2750-수-정렬하기)
- [2587. 대표값2](#2587-대표값2) *(new)*
- [25305. 커트라인](#25305-커트라인) *(new)*
- [2751. 수 정렬하기 2](#2751-수-정렬하기-2)
- [10989. 수 정렬하기 3](#10989-수-정렬하기-3)
- [1427. 소트인사이드](#1427-소트인사이드)
- [11650. 좌표 정렬하기](#11650-좌표-정렬하기)
- [11651. 좌표 정렬하기 2](#11651-좌표-정렬하기-2)
- [1181. 단어 정렬](#1181-단어-정렬)
- [10814. 나이순 정렬](#10814-나이순-정렬)
- [18870. 좌표 압축](#18870-좌표-압축)

#### (Depreciated)
- [2108. 통계학](#2108-통계학)


**※ Note**  

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when theere are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · `C++` : `#include <iostream>` `#define endl '\n';` `using namespace std;`  
&nbsp;&nbsp;&nbsp;&nbsp; · `Golang` : `package main` `import "fmt"`  



## [2750. 수 정렬하기](#list)

> 5  
> 5  
> 2  
> 3  
> 4  
> 1

> 1  
> 2  
> 3  
> 4  
> 5

#### C++ (2021.12.11)
```cpp
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'
```
```cpp
int main()
{
    // Input N
    int N;
    cin >> N;

    // Input a vector
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    // Sort (default : ascending order)
    sort(v.begin(), v.end());

    // Output (not in a row)
    for (int i = 0; i < N; i++) cout << v[i] << endl;

    return 0;
}
```

#### Golang (2022.06.22)
```go
package main
import (
    "fmt"
    "sort"
)
```
```go
func main() {

    var n int                                   // n <= 1,000
    fmt.Scanln(&n)
    var num []int

    for i := 0; i < n; i++ {
        // Input
        var temp int
        fmt.Scanln(&temp)
        num = append(num, temp)                 // not slow?
    }

    // Sort
    sort.Ints(num)

    // Output
    for i := 0; i < n; i++ {
        fmt.Println(num[i])
    }
}
```


## [2587. 대표값2](#list)

```txt
10
40
30
60
30
```
```txt
34
30
```

#### C++ (2023.07.06)
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
    // Input & Get sum
    vector<int> v;
    int len = 5, sum = 0;
    for (int i = 0; i < len; i++)
    {
        int temp;
        cin >> temp;

        v.push_back(temp);
        sum += temp;
    }

    // Sort
    sort(v.begin(), v.end());

    // Output
    cout << sum / len  << endl;
    cout << v[2] << endl;

    return 0;
}
```


## [25305. 커트라인](#list)

```txt
5 2
100 76 85 93 98
```
```txt
98
```

#### C++ (2023.07.06)
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
    // Declare
    int n, k;
    vector<int> v;

    // Input
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    // Sort
    sort(v.begin(), v.end());

    // Output
    cout << v[n - k] << endl;

    return 0;
}
```


## [2751. 수 정렬하기 2](#list)

> The same sample with Q.2750

#### C++ (2021.12.11)
```cpp
    //totally the same code with Q.2750
```

#### Golang (2022.06.22)
```go
package main
import (
    "fmt"
    "bufio"
    "os"
    "sort"
)
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int                                   // n <= 1,000,000
    fmt.Scanln(&n)
    var num []int

    // Input
    for i := 0; i < n; i++ {
        var temp int
        fmt.Fscanln(reader, &temp)
        num = append(num, temp)
    }

    // Sort
    sort.Ints(num)

    // Output
    for i := 0; i < n; i++ {
        fmt.Fprintln(writer, num[i])
    }
}
```


## [10989. 수 정렬하기 3](#list)

> 10  
> 5  
> 2  
> 3  
> 1  
> 4  
> 2  
> 3  
> 5  
> 1  
> 7

> 1  
> 1  
> 2  
> 2  
> 3  
> 3  
> 4  
> 5  
> 5  
> 7

#### C++ (2021.12.11)
```cpp
#include <iostream>
#include <array>

using namespace std;

#define endl '\n'
```
```cpp
int main()
{
    // make it faster
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    // Input N
    int N;
    cin >> N;

    // Input an array
    array<int, 10001> arr = {0, };      // memory limit : 8 MB > int(4 byte) * 10,001
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr[temp]++;                    // 3 -> arr[3]++
    }

    // test
    // for (int i = 1; i <= 10000; i++) if (arr[i] > 0) cout << i << ' ' << arr[i] << endl;

    // Output
    for (int i = 1; i <= 10000; i++) for (int j = 0; j < arr[i]; j++) cout << i << endl;

    return 0;
}
```

#### Golang (2022.06.22)
```go
package main
import (
    "fmt"
    "bufio"
    "os"
)
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int                                   // n <= 1,000,000
    fmt.Scanln(&n)
    var num [10001]int

    // Input
    for i := 0; i < n; i++ {
        var temp int
        fmt.Fscanln(reader, &temp)
        num[temp]++
    }

    // Output
    for i := 0; i < 10001; i++ {
        for j := 0; j < num[i]; j++ {
            fmt.Fprintln(writer, i)
        }
    }
}
```


## [1427. 소트인사이드](#list)

> 2143

> 4321

#### C++ (2021.12.15)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'
```
```cpp
int main()
{
    // Input N
    string N;
    cin >> N;
    int len = N.size();

    // Input a vector
    vector<int> v;
    for (int i = 0; i < len; i++) v.push_back(N[i] - '0');

    // Sort (default : descending order)
    sort(v.rbegin(), v.rend());                             // need to practice more various ways to use sort()

    // Output (in a row)
    for (int i = 0; i < len; i++) cout << v[i];
    cout << endl;

    return 0;
}
```

#### Golang (2022.06.22)
```go
package main
import (
    "fmt"
    "strconv"
)
```
```go
func main() {

    // Input
    var n string
    fmt.Scanln(&n)
    var nLen = len(n)

    // Convert n to an array
    var arr [10]int
    for i := 0; i < nLen; i++ {
        arr[n[i] - '0']++
    }

    // Output
    for i := 9; i >= 0; i-- {
        for j := 0; j < arr[i]; j++ {
            fmt.Printf(strconv.Itoa(i))
        }
    }
    fmt.Println()
}
```


## [11650. 좌표 정렬하기](#list)

> 5  
> 3 4  
> 1 1  
> 1 -1  
> 2 2  
> 3 3

> 1 -1  
> 1 1  
> 2 2  
> 3 3  
> 3 4

#### C++ (2021.12.15)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'
```
```cpp
bool comp(pair<int, int> p1, pair<int, int> p2)             // I've just learned a new skill!
{
    if (p1.first == p2.first) return p1.second < p2.second;
    else return p1.first < p2.first;
}
```
```cpp
int main()
{
    // Input N
    int N;
    cin >> N;

    // Input vector<pair<int, int>>
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        int temp1, temp2;
        pair<int, int> p;
        cin >> temp1 >> temp2;
        p.first = temp1;
        p.second = temp2;
        v.push_back(p);
    }

    // Sort
    sort(v.begin(), v.end(), comp);

    // Output
    for (int i = 0; i < N; i++) cout << v[i].first << ' ' << v[i].second << endl;

    return 0;
}
```

#### Golang (2022.07.11)
```go
package main
import (
    "fmt"
    "bufio"
    "os"
    "sort"
)
```
```go
type point struct {
    x int
    y int
}
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int                                               // n <= 100,000
    fmt.Scanln(&n)
    var points []point

    // Input
    for i := 0; i < n; i++ {
        var temp point
        fmt.Fscanln(reader, &temp.x, &temp.y)
        points = append(points, temp)
    }

    // Sort
    sort.SliceStable(points, func(i, j int) bool {
        if points[i].x == points[j].x {
            return points[i].y < points[j].y
        } else {
            return points[i].x < points[j].x
        }
    })

    // Output
    for i := 0; i < n; i++ {
        fmt.Fprintln(writer, points[i].x, points[i].y)
    }
}
```


## [11651. 좌표 정렬하기 2](#list)

> 5  
> 0 4  
> 1 2  
> 1 -1  
> 2 2  
> 3 3

> 1 -1  
> 1 2  
> 2 2  
> 3 3  
> 0 4

#### C++ (2021.12.15)
```cpp
bool comp(pair<int, int> p1, pair<int, int> p2)             // only different part from Q.11650
{
    if (p1.second == p2.second) return p1.first < p2.first;
    else return p1.second < p2.second;
}
```

#### Golang (2022.07.11)
```go
func main() {

    ……

    // Sort : only different part from Q.11650
    sort.SliceStable(points, func(i, j int) bool {
        if points[i].y == points[j].y {
            return points[i].x < points[j].x
        } else {
            return points[i].y < points[j].y
        }
    })

    ……

}
```


## [1181. 단어 정렬](#list)

> 13  
> but  
> i  
> wont  
> hesitate  
> no  
> more  
> no  
> more  
> it  
> cannot  
> wait  
> im  
> yours

> i  
> im  
> it  
> no  
> but  
> more  
> wait  
> wont  
> yours  
> cannot  
> hesitate

#### C++ (2021.12.16)
```cpp
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define endl '\n'
```
```cpp
struct comp                                                                         // should be a struct, refer to less<_Kty>
{
    bool operator() (const pair<int, string> p1, const pair<int, string> p2) const  // need to understand why use 'const'
    {
        if (p1.first != p2.first) return p1.first < p2.first;
        else return p1.second < p2.second;
    }
};                                                                                  // don't miss ';'
```
```cpp
// struct for set<string>
// struct comp                                                                      // should be a struct, refer to less<_Kty>
// {
//     bool operator() (const string s1, const string s2) const
//     {
//         if (s1.size() != s2.size()) return s1.size() < s2.size();
//         else return s1 < s2;
//     }
// };                                                                               // don't miss ';'
```
```cpp
// function for set<string> : an error occurs - 함수 "comp"은(는) 형식 이름이 아닙니다.C/C++(757)
// bool comp(string s1, string s2)
// {
//     if (s1.size() != s2.size()) return s1.size() < s2.size();
//     else return s1 < s2;
// }
```
```cpp
int main()
{
    // Input N
    int N;
    cin >> N;

    // Input set<pair<int, string>> with ordering
    set<pair<int, string>, comp> s;                                                 // declare with indicating how to order
    // template<typename _Key, typename _Compare = std::less<_Key>, typename _Alloc = std::allocator<_Key> >
    // less<_Key> is a struct
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        pair<int, string> p;
        p.first = temp.size();
        p.second = temp;

        s.insert(p);
    }

    // Output
    int len = s.size();
    for (auto it = s.begin(); it != s.end(); it++) cout << (*it).second << endl;

    return 0;
}
```

#### Golang (2022.07.11)
```go
package main
import (
    "fmt"
    "bufio"
    "os"
    "sort"
)
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int                                               // n <= 20,000
    fmt.Scanln(&n)
    var words []string

    // Input
    for i := 0; i < n; i++ {
        var temp string
        fmt.Fscanln(reader, &temp)
        words = append(words, temp)
    }

    // Sort
    sort.SliceStable(words, func(i, j int) bool {
        if len(words[i]) == len(words[j]) {
            return words[i] < words[j]
        } else {
            return len(words[i]) < len(words[j])
        }
    })

    // Output
    for i := 0; i < n; i++ {
        // It would be better to use set but …… (Golang has not set)
        if i == 0 {
            fmt.Fprintln(writer, words[i])
        } else if words[i] != words[i-1] {
            fmt.Fprintln(writer, words[i])
        }
    }
}
```


## [10814. 나이순 정렬](#list)

> 3  
> 21 Junkyu  
> 21 Dohyun  
> 20 Sunyoung

> 20 Sunyoung  
> 21 Junkyu  
> 21 Dohyun

#### C++ (2021.12.16)
```cpp
#include <iostream>
#include <set>
#include <tuple>                                                        // similar with <pair>, but elements are more than 3
#include <algorithm>

using namespace std;

#define endl '\n'
```
```cpp
struct comp
{
    bool operator() (const tuple<int, int, string> t1, const tuple<int, int, string> t2) const
    {
        if (get<1>(t1) != get<1>(t2)) return get<1>(t1) < get<1>(t2);
        else return get<0>(t1) < get<0>(t2);                            // maintain the existing order
    }
};
```
```cpp
int main()
{
    // Input N
    int N;
    cin >> N;

    // Input set<tuple<int, int, string>> with ordering
    set<tuple<int, int, string>, comp> s;
    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;

        s.insert(tuple<int, int, string> (i, age, name));
    }

    // Output
    int len = s.size();
    for (auto it = s.begin(); it != s.end(); it++) cout << get<1>(*it) << ' ' << get<2>(*it) << endl;

    return 0;
}
```

#### Golang (2022.07.11)
```go
package main
import (
    "fmt"
    "bufio"
    "os"
    "sort"
)
```
```go
type member struct {
    no int
    age int
    name string
}
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int                                               // n <= 100,000
    fmt.Scanln(&n)
    var members []member

    // Input
    for i := 0; i < n; i++ {
        var temp member
        temp.no = i
        fmt.Fscanln(reader, &temp.age, &temp.name)
        members = append(members, temp)
    }

    // Sort
    sort.SliceStable(members, func(i, j int) bool {
        if members[i].age != members[j].age {
            return members[i].age < members[j].age
        } else {
            return members[i].no < members[j].no            // maintain the existing order
        }
    })

    // Output
    for i := 0; i < n; i++ {
        fmt.Fprintln(writer, members[i].age, members[i].name)
    }
}
```


## [18870. 좌표 압축](#list)

> 5  
> 2 4 -10 4 -9

> 2 3 0 3 1

#### C++ (2021.12.16)
```cpp
// rather worse performance
// #pragma GCC optimize ("O2")
// #pragma GCC target ("avx")
```
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define endl '\n'
```
```cpp
int main()
{
    // Make it faster
    cin.tie(NULL);
    cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    // Input N
    int N;
    cin >> N;

    // Input vector<int> and map<int, int>
    vector<int> v;
    map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);

        auto it = m.find(x);
        if (it == m.end()) m.insert(pair<int, int>(x, 0));
        else it->second++;
    }

    // Count rank
    int rank = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        it->second = rank;
        rank++;
    }

    // Output
    for (int i = 0; i < N - 1; i++) cout << m.find(v[i])->second << ' ';
    cout << m.find(v[N - 1])->second << endl;

    return 0;
}
```

#### Golang (2022.07.11)
```go
package main
import (
	"bufio"
	"fmt"
	"os"
    "sort"
)
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int                                   // n <= 1,000,000
    fmt.Scanln(&n)

    // Input
    var arr []int
    var m map[int]int = make(map[int]int)
    for i := 0; i < n; i++ {
        var temp int
        fmt.Fscan(reader, &temp)
        arr = append(arr, temp)

        _, exists := m[temp]
        if !exists {
            m[temp] = 0
        }
    }

    // Get a slice sorted by map's key
    var sortKeys []int
    for i := range m {
        sortKeys = append(sortKeys, i)
    }
    sort.Ints(sortKeys)

    // Count rank
    var rank int = 0
    for _, k := range sortKeys {
        m[k] = rank
        rank++
    }

    // Output
    for i := 0; i < n; i++ {
        fmt.Fprint(writer, m[arr[i]], " ")
    }
    fmt.Fprintln(writer)
}
```


## [2108. 통계학](#list)

> 5  
> 1  
> 3  
> 8  
> -2  
> 2

> 2  
> 2  
> 1  
> 10

#### C++ (2021.12.16)
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'
```
```cpp
int main()
{
    // Input N
    int N;
    cin >> N;

    // Input numbers
    vector<int> v, modeCandidate;
    map<int, int> m;
    int sum = 0, modeFreq = 0, max = -4000, min = 4000;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        // 1. Mean
        sum += n;                                                           // 4,000 * 500,000 = 2,000,000,000 < __int_max__

        // 2. Median
        v.push_back(n);

        // 3. Mode
        auto mFind = m.find(n);
        if (mFind == m.end()) m.insert(pair<int, int>(n, 1));
        else mFind->second++;
        mFind = m.find(n);                                                  // avoid mFind == m.end()
        if (mFind->second > modeFreq) modeFreq = mFind->second;

        // test
        // cout << mFind->first << ' ' << mFind->second << ' ' << modeFreq << endl;

        // 4. Max - Min
        if (n < min) min = n;
        if (n > max) max = n;
    }

    // 2. Median : sort by ascending order
    sort(v.begin(), v.end());

    // 3. Mode : the given condition is like trash ……
    int mode;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second == modeFreq) modeCandidate.push_back(it->first);
        if (modeCandidate.size() > 2) break;
    }
    if (modeCandidate.size() == 1) mode = modeCandidate[0];
    else mode = modeCandidate[1];

    // Output
    cout << round((double) sum / N) << endl;                                // 1. Mean
    cout << v[(N - 1) / 2] << endl;                                         // 2. Median
    cout << mode << endl;                                                   // 3. Mode
    cout << max - min << endl;                                              // 4. Max - Min

    return 0;
}
```
> 틀렸습니다 (2022.02.21 재채점)

#### Golang (2022.07.11)
```go
package main
import (
    "fmt"
    "bufio"
    "os"
    "sort"
    "math"
)
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)

    var n int                                   // n <= 500,000
    fmt.Scanln(&n)

    // Input
    var num []int
    for i := 0; i < n; i++ {
        var temp int
        fmt.Fscanln(reader, &temp)
        num = append(num, temp)
    }

    // 1. Mean
    var sum int = 0                             // sum <= 4,000 * 500,000 < int max
    for i := 0; i < n; i++ {
        sum += num[i]
    }
    var mean int = int(math.Round(float64(sum)/float64(n)))

    // 2. Median
    sort.Ints(num)
    var median int = num[(n-1)/2]               // n is aways odd

    // 3. Mode : crazy~~~
    // 3.1 Get a map consists of num and freq.
    var m map[int]int
    m = make(map[int]int)
    for i := 0; i < n; i++ {
        _, exists := m[num[i]]
        if !exists {
            m[num[i]] = 1
        } else {
            m[num[i]]++
        }
    }
    // 3.2 Find the maximum freq.
    var maxFreq int = 0
    for _, v := range m {
        if v > maxFreq {
            maxFreq = v
        }
    }
    // 3.3 Find all the keys with maximum freq.
    var modes []int
    for k, v := range m {
        if v == maxFreq {
            modes = append(modes, k)
        }
    }
    // 3.4 Find the answer
    var mode int
    var length int = len(modes)
    if length > 1 {
        sort.Ints(modes)
        mode = modes[1]
    } else {
        mode = modes[0]
    }

    // 4. Range
    var Range int = num[n-1] - num[0]

    // Output
    fmt.Println(mean)                           // math.Round() requires float64
    fmt.Println(median)
    fmt.Println(mode)
    fmt.Println(Range)
}
```
