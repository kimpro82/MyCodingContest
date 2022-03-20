// Kotlin Heroes: Practice 8
// 2021.10.01(Fri) 22:35, 7 days)

// B. Yellow Cards

// Unfair ……

/* Sample Input & Output
2
3
5
1
8
0 4

3
1
6
7
25
4 4

6
4
9
10
89
5 9
*/

import kotlin.math.*

fun main(args: Array<String>)
{
    // Input data : Is it the best way?
    val a1 : Int = readLine()!!.toInt()
    val a2 : Int = readLine()!!.toInt()
    val k1 : Int = readLine()!!.toInt()
    val k2 : Int = readLine()!!.toInt()
    val n : Int = readLine()!!.toInt()

    // Get min and max
    var min : Int
    var max : Int
    min = max(0, n - a1*(k1-1) - a2*(k2-1))
    if (k1 <= k2) max = min(a1*k1, n)/k1 + min(a2*k2, max(n-a1*k1, 0))/k2
    else max = min(a2*k2, n)/k2 + min(a1*k1, max(n-a2*k2, 0))/k1
    // crazy

    // Output
    println("$min $max")
}