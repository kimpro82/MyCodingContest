// 4949. The Balance of the World(균형잡힌 세상)
// 2023.07.17

/* Sample input & output data
So when I die (the [first] I will see in (heaven) is a score list).
[ first in ] ( first out ).
Half Moon tonight (At least it is better than no Moon at all].
A rope may form )( a trail in a maze.
Help( I[m being held prisoner in a fortune cookie factory)].
([ (([( [ ] ) ( ) (( ))] )) ]).
 .
.

yes
yes
no
no
no
yes
yes
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

    while (true)
    {
        string str;
        getline(cin, str);                                  // getline() : get a line including spaces

        if (str == ".") break;                              // do not need cin.eof()

        stack<char> stk;
        string ans = "yes";
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(' || str[i] == '[')
                stk.push(str[i]);
            else if (str[i] == ')' || str[i] == ']')
            {
                if (str[i] == ')' && !stk.empty() && stk.top() == '(')
                    stk.pop();
                else if (str[i] == ']' && !stk.empty() && stk.top() == '[')
                    stk.pop();
                else
                {
                    ans = "no";
                    break;
                }
            }
            else continue;

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
        if (!stk.empty()) ans = "no";

        // Output
        cout << ans << endl;
    } // The end of while()

    return 0;
}
