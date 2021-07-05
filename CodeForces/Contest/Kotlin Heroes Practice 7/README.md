## Kotlin Heroes: Practice 7

2021.06.22(Thu) 22:35, 7 days  
https://codeforces.com/contest/1532

※ All the codes are written in `Kotlin`  
    - **skipped** `main()` function's brace(`{}`) and its outside



### A. A+B (Trial Problem)


```kotlin
val n : Int = readLine()!!.toInt()

for (i in 0 until n)
{
    val (a : Int, b : Int) = readLine()!!.split(' ').map { it.toInt() }
    println(a + b)
}
```

> 4  
> 1 5  
> 314 15  
> -99 99  
> 123 987

> 6  
> 329  
> 0  
> 1110

> Accepted



### B. Frog Jumping


#### Trial 1

```kotlin
val n : Int = readLine()!!.toInt()

for (i in 0 until n)
{
    val (a : Int, b : Int, k : Int) = readLine()!!.split(' ').map { it.toInt() }
    var pos : Long = 0

    for (j in 0 until k)
    {
        if (j % 2 == 0)
        {
            pos += a
        } else
        {
            pos -= b
        }

        // test
        // println("$a $b $k $i $j $pos")
    }

    println(pos)
}
```

> 6  
> 5 2 3  
> 100 1 4  
> 1 10 5  
> 1000000000 1 6  
> 1 1 1000000000  
> 1 1 999999999

> 8  
> 198  
> -17  
> 2999999997

> Time limit exceeded on test 1


#### Trial 2

```kotlin
val n : Int = readLine()!!.toInt()

for (i in 0 until n)
{
    val (a : Long, b : Long, k : Long) = readLine()!!.split(' ').map { it.toLong() }
    var pos : Long = 0

    if (k.toInt() % 2 == 0)
    {
        pos = (a - b) * (k / 2)
    } else
    {
        pos = (a - b) * ((k - 1) / 2) + a
    }

    println(pos)
}
```

> Accepted



### C. Uniform String


```kotlin
// test
// println('a' + 1)    // b
```

```kotlin
val t : Int = readLine()!!.toInt()

for (i in 0 until t)
{
    var (n : Int, k : Int) = readLine()!!.split(' ').map { it.toInt() }
    // n : the length of the string in the i-th query
    // k : the number of characters in the i-th query
    var letter : Char = 'a'

    for (j in 0 until n)
    {
        print(letter)
        if (letter < 'a' + k - 1)
        {
            letter++
        } else
        {
            letter = 'a'
        }    
    }
    println()
}
```

> 3  
> 7 3  
> 4 4  
> 6 2

> abcabca  
> abcd  
> ababab

> Accepted



### D. Teams Forming


```kotlin
// input data into an array
val n : Int = readLine()!!.toInt()
var a = readLine()!!.split(' ').map{it.toInt()}.toIntArray()

// sort array
a.sort()                                // cool
// for (element in a) println(element)  // test

// get sum of a[2i+1] - a[2i]
var sum : Int = 0
for (i in 0..n-2 step 2)   // n-2 → finish with a[n-1] - a[n-2]
{
    sum += a[i+1].toInt() - a[i].toInt()
}

// output
println(sum)
```

> 6  
> 5 10 2 3 14 5

> 5

> Accepted



### E. Good Array

```kotlin
// input data into an array
val n : Int = readLine()!!.toInt()
var a = readLine()!!.split(' ').map{it.toInt()} // Is there no way to make it an ArrayList directly?
var aArr = ArrayList<Int>()
for (i in 0 until n)
{
    aArr.add(a[i])
}
// println(aArr.toString()) // test

// find elements that make it "good"
var ans = ArrayList<Int>()
for (j in 0 until n)
{
    var temp = ArrayList<Int>()
    temp.addAll(aArr)
    temp.removeAt(j)
    if (temp.sum() == temp.maxOrNull()!! * 2)   // 'max(): Int?' is deprecated
    {
        ans.add(j+1)
    }
}

// output
println(ans.size)
for (item in ans)
{
    print("$item ")
}
println()
```

> 5  
> 2 5 1 2 2

> 3  
> 1 4 5 

> Time limit exceeded on test 4