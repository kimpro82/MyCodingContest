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