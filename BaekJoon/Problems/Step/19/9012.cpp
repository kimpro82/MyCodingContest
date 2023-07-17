// 9012. Parenthesis(괄호)
// 2023.07.17

/* Sample input & output data
6
(())())
(((()())()
(()())((()))
((()()(()))(((())))()
()()()()(()()())()
(()((())()(

NO
NO
YES
NO
YES
NO
*/


#include <iostream>
#include <stack>

// #define test
#define endl '\n'

using namespace std;


int main()
{
    // Faster I/O
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    while (n--)
    {
        string str;
        cin >> str;

        stack<char> stk;
        string ans = "YES"; 
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(') stk.push(str[i]);
            else if (!stk.empty()) stk.pop();               // && str[i] == ')'
            else                                            // stk.empty() == true && stk[i] == ')'
            {
                ans = "NO";
                break;
            }

            #ifdef test
                stack<char> stk2 = stk;
                cout << "(test) ";
                while (!stk2.empty())
                {
                    cout << stk2.top() << ' ';
                    stk2.pop();
                }
                cout << endl;
            #endif
        }
        if (!stk.empty()) ans = "NO";

        // Output
        cout << ans << endl;
    }

    return 0;
}
