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