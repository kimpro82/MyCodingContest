// Facebook Hacker Cup 2023 > Practice Round
// 2023.09.23 02:00, 72 hrs

// Problem C: Two Apples a Day

/* Sample Input & Output
7
3
6 3 1 2 5
2
7 7 7
1
1
3
1 9 1 1 4
4
1 9 1 1 4 9 9
4
1 9 10 1 4 6 9
3
1000000000 2 10 4 999999994

Case #1: 4
Case #2: 7
Case #3: 1
Case #4: -1
Case #5: 6
Case #6: -1
Case #7: 1000000002
*/


#include <iostream>
#include <vector>
#include <algorithm>

#define test
#define fileio
#ifdef fileio
    #include <fstream>
    #define cin fin
#endif
#define endl '\n'

using namespace std;

int main()
{
    // Input data
    #ifdef fileio
        string inputFileName = "C_input_sample.txt";
        ifstream fin(inputFileName, ios_base::in);
        string line;
    #endif

    int T;
    cin >> T;

    vector<vector<int>> oz;
    vector<int> len;
    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        len.push_back(N * 2 - 1);

        vector<int> oz2;
        for (int n = 0; n < len[t]; n++)
        {
            int temp;
            cin >> temp;
            oz2.push_back(temp);
        }
        oz.push_back(oz2);
    }

    #ifdef fileio
        fin.close();
    #endif

    // Test T times
    for (int t = 0; t < T; t++)
    {
        sort(oz[t].begin(), oz[t].end());

        // Operate
        int sum, ans = -1;
        bool added = false;
        if (len[t] == 1)
        {
            sum = oz[t][0];
            ans = 1;
        }
        else if (oz[t][0] + oz[t][len[t]-1] == oz[t][1] + oz[t][len[t]-2])
        {
            sum = oz[t][0] + oz[t][len[t]-1];
            for (int i = 1; i < len[t]/2; i++)
            {
                if (sum != oz[t][i] + oz[t][len[t]-1-i])
                {
                    if (added == false)
                    {
                        added = true;
                        ans = sum - oz[t][i];
                    }
                    else break;
                }
            }
        }

        // test
        #ifdef test
            cout << "t : " << t + 1;
            cout << ", sum : " << sum;
            cout << ", added : " << int(added);
            cout << ", answer : " << ans;
            cout << endl;
        #endif

        // Output
        #ifdef fileio
            ofstream ofs;
            string outputFileName = "C_output_sample.txt";
            ofs.open(outputFileName, ios::app);
            // ios::app : All output operations are performed at the end of the file, appending the content to the current content of the file.
            ofs << "Case #" << t + 1 << ": " << ans << endl;
            ofs.close();
        #else
            cout << "Case #" << t + 1 << ": " << ans << endl;
        #endif
    }

    return 0;
}

// Not completed
