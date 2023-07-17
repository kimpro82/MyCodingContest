// 10828. 스택
// 2023.07.17

/* Sample input & output data
14
push 1
push 2
top
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
top

2
2
0
2
1
-1
0
1
-1
0
3
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

    stack<int> stk;
    while (n--)
    {
        string temp;
        cin >> temp;

        if (temp == "push")
        {
            int x;
            cin >> x;
            stk.push(x);
        }
        else if (temp == "pop")
        {
            if (stk.size() > 0)
            {
                cout << stk.top() << endl;
                stk.pop();
            }
            else cout << -1 << endl;
        }
        else if (temp == "size")
        {
            cout << stk.size() << endl;
        }
        else if (temp == "empty")
        {
            cout << (stk.empty() ? 1 : 0 ) << endl;
        }
        else                                                // else if (temp == "top")
        {
            if (stk.size() > 0) cout << stk.top() << endl;
            else cout << -1 << endl;
        }

        #ifdef test
            stack<int> stk2 = stk;
            cout << "(test) ";
            while (stk2.size() > 0)
            {
                cout << stk2.top() << ' ';
                stk2.pop();
            }
            cout << endl;
        #endif
    }

    return 0;
}
