// Facebook Hacker Cup 2023 > Practice Round
// 2023.09.23 02:00, 72 hrs

// Problem A1: Cheeseburger Corollary 1

/* Sample Input & Output
7
1 1 3
0 2 4
5 5 1
0 1 1
1 1 2
97 1 99
97 1 100

Case #1: YES
Case #2: NO
Case #3: YES
Case #4: YES
Case #5: YES
Case #6: YES
Case #7: NO
*/


#include <iostream>
#include <vector>

// #define test
// #define fileio
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
        string inputFileName = "A1_input_full.txt";
        ifstream fin(inputFileName, ios_base::in);
        string line;
    #endif
    int T;
    cin >> T;
    vector<vector<int>> sdk;
    for (int t = 0; t < T; t++)
    {
        vector<int> sdk2;
        int s, d, k;
        cin >> s >> d >> k;

        sdk2.push_back(s);
        sdk2.push_back(d);
        sdk2.push_back(k);
        sdk.push_back(sdk2);
    }
    #ifdef fileio
        fin.close();
    #endif

    // Test T times
    for (int t = 0; t < T; t++)
    {
        int s, d, k;
        s = sdk[t][0];
        d = sdk[t][1];
        k = sdk[t][2];

        int bun, patty;
        bun = (s + d) * 2;
        patty = s + (d * 2);

        // Determine
        string ans;
        if (bun > k && patty >= k) ans = "YES";
        else ans = "NO";

        // test
        #ifdef test
            cout << "t : " << t + 1;
            cout << ", s : " << s;
            cout << ", d : " << d;
            cout << ", k : " << k;
            cout << ", bun : " << bun;
            cout << ", patty : " << patty;
            cout << ", answer : " << ans;
            cout << endl;
        #endif

        // Output
        #ifdef fileio
            ofstream ofs;
            string outputFileName = "A1_output_full.txt";
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