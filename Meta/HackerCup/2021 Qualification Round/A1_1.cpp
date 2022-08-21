// Facebook Hacker Cup 2021 > Qualification Round
// 2021.08.28 02:00, 72 hrs

// Problem A1: Consistency - Chapter 1

/* Sample Input & Output
6
ABC
F
BANANA
FBHC
FOXEN
CONSISTENCY

Case #1: 2
Case #2: 0
Case #3: 3
Case #4: 4
Case #5: 5
Case #6: 12
*/


#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

int main()
{
    // Find vowels' indices : 0, 4, 8, 14 , 20
    string AEIOU = "AEIOU";
    vector<int> vowel;
    int temp;
    for (int i = 0; i < 5; i++)
    {
        temp = AEIOU[i]-'A';
        vowel.push_back(temp);
    }
    // test
    // for (int i = 0; i < 5; i++) cout << vowel[i] << endl;

    int T;
    cin >> T;

    // Input vector<string> S
    vector<string> S;
    for (int t = 0; t < T; t++)
    {

        string s;
        cin >> s;
        S.push_back(s);
    }

    // Test T times
    for (int t = 0; t < T; t++)
    {
        // Make vector v to count each alphabet from string S[t]
        int len = S[t].size();
        vector<int> v (26, 0);
        for (int i = 0; i < len; i++) v[S[t][i] - 'A']++;

        // Count each of sum from vowels and consonants
        int vw = 0, cs = 0, vwMax = 0, csMax = 0;
        bool ifVw = false;
        for (int i = 0; i < 26; i++)
        {
            if (v[i] > 0)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (i == vowel[j])
                    {
                        vw += v[i];
                        if (v[i] > vwMax) vwMax = v[i];
                        ifVw = true;
                        break;
                    }
                }
                if (ifVw == false)
                {
                    cs += v[i];
                    if (v[i] > csMax) csMax = v[i];
                }
            }
            ifVw = false;
        }
        // test
        // cout << "vw : " << vw << ", vwMax : " << vwMax << ", cs : " << cs << ", csMax : " << csMax << endl;

        // Determine where operate A and B - Trial 1
        // int answer;
        // if (vw - vwMax >= cs - csMax) answer = vw + (cs - csMax) * 2;
        // else answer = cs + (vw - vwMax) * 2;

        // Determine where operate A and B - Trial 2 (Upsolving)
        int answer;
        if (vw == 0)
        {
            if (cs - csMax == 0) answer = 0;
            else answer = min(cs, (cs - csMax) * 2);
        }
        else if (cs == 0)
        {
            if (vw - vwMax == 0) answer = 0;
            else answer = min(vw, (vw - vwMax) * 2);
        }
        else if (vw - vwMax >= cs - csMax) answer = vw + (cs - csMax) * 2;
        else answer = cs + (vw - vwMax) * 2;

        // Output
        cout << "Case #" << t + 1 << ": " << answer << endl;
    }

    return 0;
}


/* Wrong Case - Trial 1
UFOVKZEOUTPUJSWEITEUAIYDRIBGUIUIOEII
43
*/

/* Wrong Case - Trial 2
OXEOURJOEUEJUUTUEIEQORXSBGLUIIARAVUBPUICEIJAIILEQDBIIQONE
72
UFOVKZEOUTPUJSWEITEUAIYDRIBGUIUIOEII
43
*/