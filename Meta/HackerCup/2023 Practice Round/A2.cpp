// Facebook Hacker Cup 2023 > Practice Round
// 2023.09.23 02:00, 72 hrs

// Problem A2: Cheeseburger Corollary 2

/* Sample Input & Output
6
2 3 5
2 3 2
2 3 1
5 1 100
1 3 100
1 1 1000000000000

Case #1: 3
Case #2: 1
Case #3: 0
Case #4: 199
Case #5: 100
Case #6: 1999999999999
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
using ll = long long;

int main()
{
    // Input data
    #ifdef fileio
        string inputFileName = "A2_input_full.txt";
        ifstream fin(inputFileName, ios_base::in);
        string line;
    #endif
    int T;
    cin >> T;
    vector<vector<ll>> abc;
    for (int t = 0; t < T; t++)
    {
        vector<ll> abc2;
        ll a, b, c;
        cin >> a >> b >> c;

        abc2.push_back(a);
        abc2.push_back(b);
        abc2.push_back(c);
        abc.push_back(abc2);
    }
    #ifdef fileio
        fin.close();
    #endif

    // Test T times
    for (int t = 0; t < T; t++)
    {
        ll a, b, c;
        a = abc[t][0];
        b = abc[t][1];
        c = abc[t][2];

        // Determine
        ll ans = 0;
        if (a <= c || b <= c)
        {
            if (a * 2 > b)
            {
                if ((c % b) / a > 0) ans = (c / b) * 2 + (c % b) / a;
                else ans = (c / b) * 2 - 1;
            }
            else if (a <= c) ans = (c / a) + (c % a) / b;
        }

        // test
        #ifdef test
            cout << "t : " << t + 1;
            cout << ", a : " << a;
            cout << ", b : " << b;
            cout << ", c : " << c;
            cout << ", answer : " << ans;
            cout << endl;
        #endif

        // Output
        #ifdef fileio
            ofstream ofs;
            string outputFileName = "A2_output_full.txt";
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

// Wrong Answer
