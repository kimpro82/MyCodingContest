// Kotlin Heroes: Practice 7
// 2021.06.22(Tue) 22:35, 7 days)

// D. Teams Forming

/* Sample Input & Output
6
5 10 2 3 14 5
5

2
1 100
99
*/


fun main(args: Array<String>)
{
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
}