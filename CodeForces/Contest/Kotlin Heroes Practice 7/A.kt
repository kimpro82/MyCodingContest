// Kotlin Heroes: Practice 7
// 2021.06.22(Tue) 22:35, 7 days)

// A. A+B (Trial Problem)

/* Sample Input & Output
4
1 5
314 15
-99 99
123 987

6
329
0
1110
*/

fun main(args: Array<String>)
{
    val n : Int = readLine()!!.toInt()

    for (i in 0 until n)
    {
        val (a : Int, b : Int) = readLine()!!.split(' ').map { it.toInt() }
        println(a + b)
    }
}