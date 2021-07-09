// Kotlin Heroes: Episode 7
// 2021.06.29(Tue) 22:35, 2.5 Hrs)

// B. Nearest Point Function

/* Sample Input & Output
7
2
1 3
2
1 100
3
1 50 101
2
1 1000000000
2
1 999999999
6
1 2 5 7 9 11
6
1 2 5 8 9 12

YES
NO
NO
NO
YES
YES
NO
*/

fun main(args: Array<String>)
{
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
}