// Kotlin Heroes: Practice 7
// 2021.06.22(Tue) 22:35, 7 days)

// C. Uniform String

/* Sample Input & Output
3
7 3
4 4
6 2

cbcacab
abcd
baabab
*/

fun main(args: Array<String>)
{
    val t : Int = readLine()!!.toInt()

    for (i in 0 until t)
    {
        var (n : Int, k : Int) = readLine()!!.split(' ').map { it.toInt() }
        // n : the length of the string in the i-th query
        // k : the number of characters in the i-th query
        var letter : Char = 'a'
        var letterRepeat : Int = n / k

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
}

// test
// println('a' + 1)    // b