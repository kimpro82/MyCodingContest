## Kotlin Heroes: Episode 7

2021.06.29(Thu) 23:35, 2.5 Hrs  
https://codeforces.com/contest/1533  

※ All the codes are written in `Kotlin`  
    - **skipped** `main()` function's brace(`{}`) and its outside


### A. Travel to Bertown

```kotlin
val t : Int = readLine()!!.toInt()

for (i in 0 until t)
{
    val (n : Int, k : Int) = readLine()!!.split(' ').map { it.toInt() }
    var maxValue : Int = 0

    for (j in 0 until n)
    {
        val (l : Int, r : Int) = readLine()!!.split(' ').map { it.toInt() }
        var temp : Int
        if (k >= l && k <= r)
        {
            temp = r - k + 1
            if (temp > maxValue)
            {
                maxValue = temp
            }
        }
    }

    println(maxValue)
}
```

> 3  
> 3 3  
> 1 4  
> 2 6  
> 4 10  
> 2 4  
> 2 3  
> 5 8  
> 2 4  
> 4 4  
> 1 3

> 4  
> 0  
> 1

> Accepted


### B. Nearest Point Function

```kotlin
val t : Int = readLine()!!.toInt()

for (i in 0 until t)
{
    var n : Int = readLine()!!.toInt()
    var x = readLine()!!.split(' ').map { it.toInt() }
    var ifCrash : Boolean = false

    // find if at least one crash occurs
    for (j in 1 until n)
    {
        if ((x[j] - x[j-1]) % 2 == 0)
        {
            ifCrash = true
            break
        }
    }

    // output
    if (ifCrash == true)
    {
        println("YES")
    } else
    {
        println("NO")
    }
}
```

> 7  
> 2  
> 1 3  
> 2  
> 1 100  
> 3  
> 1 50 101  
> 2  
> 1 1000000000  
> 2  
> 1 999999999  
> 6  
> 1 2 5 7 9 11  
> 6  
> 1 2 5 8 9 12

> YES  
> NO  
> NO  
> NO  
> YES  
> YES  
> NO

> Accepted


### C. Sweets

I hate sweets.


### D. String Searching

```kotlin
// Input data : n, m
val (n : Int, m : Int) = readLine()!!.split(' ').map { it.toInt() }
// n : the number of strings in the array, m : the length of each string

// Input data : s
var s = ArrayList<String> ()
var temp : String
for (i in 0 until n)
{
    temp = readLine()!!
    s.add(temp)
}
// println(s.toString())            // test

// Input data : q
val q : Int = readLine()!!.toInt()
// println(q)                       // test

// Input data : t
var t = ArrayList<String> ()
for (j in 0 until q)
{
    temp = readLine()!!
    t.add(temp)
}
// println(t.toString())            // test
```

```kotlin
// Operate and output
var count : Int
var tSubSet : MutableSet<String>
for (k in 0 until q)
{
    // Make subsets from t
    tSubSet = mutableSetOf()
    for (l in 0 until m+1)
    {
        tSubSet.add(t[k].substring(0 until l) + t[k].substring(l+1 until m+1))
    }

    // Count if s in subsets from t
    count = 0
    for (h in 0 until n)
    {
        if (s[h] in tSubSet)
        {
            count++
            println("$k ${t[k]} $tSubSet $h ${s[h]} $count")    // test
        }
    }

    // Output
    println(count)
}
```

> 6 3  
> dba  
> abd  
> cbb  
> ada  
> add  
> bdd  
> 5  
> ccbb  
> abdd  
> adba  
> bada  
> dddd

> 0 ccbb [cbb, ccb] 2 cbb 1  
> 1  
> 1 abdd [bdd, add, abd] 1 abd 1  
> 1 abdd [bdd, add, abd] 4 add 2  
> 1 abdd [bdd, add, abd] 5 bdd 3  
> 3  
> 2 adba [dba, aba, ada, adb] 0 dba 1  
> 2 adba [dba, aba, ada, adb] 3 ada 2  
> 2  
> 3 bada [ada, bda, baa, bad] 3 ada 1  
> 1  
> 0

> Time limit exceeded on test 5