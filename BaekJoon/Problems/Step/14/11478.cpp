// 11478. 서로 다른 부분 문자열의 개수 성공
// 2023.07.08

/* Sample input & output data
ababc

12
*/


#include <iostream>
#include <set>
#include <algorithm>

// #define test
#define endl '\n'

using namespace std;


int main()
{
    // Input
    string s;
    cin >> s;
    int len = s.size();
    set<string> st;
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            st.insert(s.substr(i, j-i+1));

            #ifdef test
                cout << s.substr(i, j-i+1) << ' ';
            #endif
        }
    }
    #ifdef test
        cout << endl;
    #endif

    // Output
    int cnt = 0;
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cnt++;

        #ifdef test
            cout << *it << ' ';
        #endif
    }
    #ifdef test
        cout << endl;
    #endif
    cout << cnt << endl;

    return 0;
}
