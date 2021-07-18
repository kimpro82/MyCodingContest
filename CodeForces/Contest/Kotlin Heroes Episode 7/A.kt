// Kotlin Heroes: Episode 7
// 2021.06.29(Tue) 22:35, 2.5 Hrs)

// A. Travel to Bertown

/* Sample Input & Output
3
3 3
1 4
2 6
4 10
2 4
2 3
5 8
2 4
4 4
1 3

4
0
1
*/

fun main(args: Array<String>)
{
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
}