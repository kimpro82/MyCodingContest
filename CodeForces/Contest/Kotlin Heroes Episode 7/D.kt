// Kotlin Heroes: Episode 7
// 2021.06.29(Tue) 22:35, 2.5 Hrs)

// D. String Searching

/* Sample Input & Output
6 3
dba
abd
cbb
ada
add
bdd
5
ccbb
abdd
adba
bada
dddd

1
3
2
1
0
*/


fun main(args: Array<String>)
{
    // Input data : n, m
    val (n : Int, m : Int) = readLine()!!.split(' ').map { it.toInt() }
    // n : the number of strings in the array, m : the length of each string

    // Input data : s
    var s = ArrayList<String> ()
    var temp : String
    for (i in 0 until n)
    {
        temp = readLine()!!
        s.add(temp)
    }
    // println(s.toString())            // test

    // Input data : q
    val q : Int = readLine()!!.toInt()
    // println(q)                       // test

    // Input data : t
    var t = ArrayList<String> ()
    for (j in 0 until q)
    {
        temp = readLine()!!
        t.add(temp)
    }
    // println(t.toString())            // test

    // Operate and output
    var count : Int
    var tSubSet : MutableSet<String>
    for (k in 0 until q)
    {
        // Make subsets from t
        tSubSet = mutableSetOf()
        for (l in 0 until m+1)
        {
            tSubSet.add(t[k].substring(0 until l) + t[k].substring(l+1 until m+1))
        }

        // Count if s in subsets from t
        count = 0
        for (h in 0 until n)
        {
            if (s[h] in tSubSet)
            {
                count++
                // println("$k ${t[k]} $tSubSet $h ${s[h]} $count")    // test
            }
        }

        // Output
        println(count)
    }
}