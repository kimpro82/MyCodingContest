// Kotlin Heroes: Practice 7
// 2021.06.22(Tue) 22:35, 7 days)

// E. Good Array

/* Sample Input & Output
5
2 5 1 2 2
3
4 1 5

4
8 3 5 2
2
1 4

5
2 1 2 4 3
0
*/


fun main(args: Array<String>)
{
    // input data into an array
    val n : Int = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map{it.toInt()}.toMutableList()

    // remove i-th element, get the residuals' sum, and determine if good
    var ans = ArrayList<Int>()
    for (i in 0 until n)
    {
        var b = a
        b.removeAt(i)
        if (b.sum() == b.max()!! * 2)
        {
            ans.add(a[i])
        }
    }

    // output
    println(ans.size)
    println(ans)
}