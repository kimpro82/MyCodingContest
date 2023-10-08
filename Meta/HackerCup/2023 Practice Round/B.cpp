// Facebook Hacker Cup 2023 > Practice Round
// 2023.09.23 02:00, 72 hrs

// Problem B: Dim Sum Delivery

/* Sample Input & Output
3
2 2 1 1
5 2 3 1
4 4 3 3

Case #1: NO
Case #2: YES
Case #3: NO
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
        string inputFileName = "B_input_full.txt";
        ifstream fin(inputFileName, ios_base::in);
        string line;
    #endif
    int T;
    cin >> T;
    vector<vector<int>> rcab;
    for (int t = 0; t < T; t++)
    {
        vector<int> rcab2;
        int r, c, a, b;
        cin >> r >> c >> a >> b;

        rcab2.push_back(r);
        rcab2.push_back(c);
        // rcab2.push_back(a);
        // rcab2.push_back(b);
        rcab.push_back(rcab2);
    }
    #ifdef fileio
        fin.close();
    #endif

    // Test T times
    for (int t = 0; t < T; t++)
    {
        int r, c, a, b;
        r = rcab[t][0];
        c = rcab[t][1];
        // a = rcab[t][2];
        // b = rcab[t][3];

        // Determine
        string ans;
        if (r > c) ans = "YES";
        else ans = "NO";

        // test
        #ifdef test
            cout << "t : " << t + 1;
            cout << ", r : " << r;
            cout << ", c : " << c;
            cout << ", answer : " << ans;
            cout << endl;
        #endif

        // Output
        #ifdef fileio
            ofstream ofs;
            string outputFileName = "B_output_full.txt";
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