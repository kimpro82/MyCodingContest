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
}