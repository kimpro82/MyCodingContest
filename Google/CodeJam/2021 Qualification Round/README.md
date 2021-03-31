## Google Code Jam 2021 - Qualification Round
2021.3.26 FRI ~28 SUN  
https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a


### Reversort (7pts)

#### Code

```cs
using System;

namespace Reversort
{
    class Program
    {
        static void Main(string[] args)
        {

            /* Sample Input
            3
            4
            4 2 1 3
            2
            1 2
            7
            7 6 5 4 3 2 1
            */

            /* pseudocode
            Reversort(L):
            for i := 1 to length(L) - 1
                j := position with the minimum value in L between i and length(L), inclusive
                Reverse(L[i..j])
            */

            int T = int.Parse(Console.ReadLine()); // 3

            // read each case and print its output
            for (int t = 1; t <= T; t++)
            {
                int N = int.Parse(Console.ReadLine()); // 4

                string[] str = Console.ReadLine().Split(' '); // 4 2 1 3
                int[] L = new int[str.Length];
                for (int h = 0; h < str.Length; h++)
                {
                    L[h] = int.Parse(str[h]);
                }

                int cost = 0;

                // Reversort Algorithm
                for (int i = 0; i < L.Length - 1; i++)
                {

                    // get minumum value and its position → min, minpos
                    int min = L[i];
                    int minpos = i;
                    for (int j = i + 1; j < L.Length; j++)
                    {
                        if (L[j] < min)
                        {
                            min = L[j];
                            minpos = j;
                        }
                    }

                    // Reverse L[i..j]
                    int[] temp = new int[minpos - i + 1];
                    for (int k = 0; k < temp.Length; k++)
                    {
                        temp[k] = L[k+i];
                    }
                    Array.Reverse(temp);
                    for (int l = 0; l < temp.Length; l++)
                    {
                        L[l+i] = temp[l];
                    }

                    // // Reverse L[i..j] // C# Mono doesn't support
                    // int[] temp = new int[minpos - i + 1];
                    // temp = L[i..(minpos+1)];
                    // Array.Reverse(temp);
                    // for (int l = 0; l < temp.Length; l++)
                    // {
                    //     L[l+i] = temp[l];
                    // }

                    // Operate the cost
                    cost += minpos - i + 1;

                    // //test
                    // Console.Write(i.ToString() + " " + minpos.ToString() + " ");    // i, j(=minpos)
                    // Console.Write("[{0}] ", string.Join(", ", temp));               // reversed part
                    // Console.WriteLine(("[{0}] " + cost), string.Join(", ", L));     // sorted array

                } // the end of each case loop

                Console.WriteLine("Case #" + t + ": " + cost);

            } // the end of t loop

        }
    }
}
```

#### Test Output
> Case #1: 6  
> Case #2: 1  
> Case #3: 18

> Test Set 1: Passed


### Moons and Umbrellas (17pts)

#### Code

```cs
using System;
using System.Text;

namespace MoonsAndUmbrellas
{
    class Program
    {
        static void Main(string[] args)
        {

            /* Sample Input
            4
            2 3 CJ?CC?
            4 2 CJCJ
            1 3 C?J
            2 5 ??J???
            */

            int T = int.Parse(Console.ReadLine());              // 4

            // read each case and print its output
            for (int t = 1; t <= T; t++)
            {
                
                // 1. read X, Y, S                
                string[] input = Console.ReadLine().Split(' '); // 2 3 CJ?CC?
                int X = int.Parse(input[0]);
                int Y = int.Parse(input[1]);
                // char[] S = str[2];                           // declare S as an array of char
                StringBuilder S = new StringBuilder(input[2]);  // declare S as a StringBuilder (changeable)
                string s = input[2];                            // declare s as a string for using .IndexOf()

                // 2. find the first position of C or J
                int first;
                int C = s.IndexOf("C");
                int J = s.IndexOf("J");
                if (C < 0 && J < 0)                             // there's neither C nor J (??????)
                {
                    S[0] = 'C';
                    first = 0;
                } else if (C < 0 || J < 0)
                {
                    first = Math.Max(C, J);
                } else {
                    first = Math.Min(C, J);
                }
                // Console.WriteLine("starting prosition> C : {0} / J : {1} / first : {2}", C, J, first);  // test

                // 3. fill ? to C or J
                // Console.WriteLine("(if) {0} {1}", S[0], S[first]);                       // test
                if (first != 0)
                {
                    // S = S.Replace(S[0], S[first]);                                       // change all "?" at once
                    S[0] = S[first];                                                        // it works
                }
                // Console.WriteLine("S.Length : " + S.Length);                             // test
                for (int i = 1; i < S.Length; i++)
                {
                    if (S[i].Equals('?'))
                    {
                        // Console.WriteLine("(for) {0} {1} {2}", i, S[i], S[i-1]);         // test
                        S[i] = S[i-1];                       // doesn't work
                    }
                }

                // 4. calculate payment
                // "CJ" → X, "JC" → Y
                int pay = 0;
                for (int j = 1; j < S.Length; j++)
                {
                    // Console.WriteLine(S[j-1].ToString() + S[j].ToString());              // test
                    if ((S[j-1].ToString() + S[j].ToString()).Equals("CJ"))                 // can't find how to concatenate two char
                    {
                        pay += X;
                    } else if ((S[j-1].ToString() + S[j].ToString()).Equals("JC")) {
                        pay += Y;
                    }
                }

                // Console.WriteLine("{0} {1} [{2}]", X, Y, string.Join(", ", S));          // test

                // 5. final output
                Console.WriteLine("Case #" + t + ": " + pay);

            } // the end of the t loop

        }
    }
}
```

#### Test Output
> Case #1: 5  
> Case #2: 10  
> Case #3: 1  
> Case #4: 0

> Samples: Passed  
> Test Set 1: Passed (5 pts)  
> Test Set 2: Passed (11 pts)  
> Test Set 3: Wrong Answer (1 pts)