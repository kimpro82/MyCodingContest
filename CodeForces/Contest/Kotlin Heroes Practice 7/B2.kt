// Kotlin Heroes: Practice 7
// 2021.06.22(Tue) 22:35, 7 days)

// B. Frog Jumping

/* Sample Input & Output
6
5 2 3
100 1 4
1 10 5
1000000000 1 6
1 1 1000000000
1 1 999999999

8
198
-17
2999999997
0
1
*/


fun main(args: Array<String>)
{
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
}