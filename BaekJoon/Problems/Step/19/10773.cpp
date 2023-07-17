// 10773. Zero That Out(제로)
// 2023.07.17

/* Sample input & output data
10
1
3
5
4
0
0
7
0
0
6

7
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
    int sum = 0;
    while (n--)
    {
        int temp;                                           // temp >= 0
        cin >> temp;
        
        if (temp > 0)
        {
            sum += temp;
            stk.push(temp);
        }
        else
        {
            sum -= stk.top();
            stk.pop();
        }

        #ifdef test
            stack<int> stk2 = stk;
            cout << "(test) ";
            while (stk2.size() > 0)
            {
                cout << stk2.top() << ' ';
                stk2.pop();
            }
            cout << "\tsum = " << sum << endl;
        #endif
    }

    // Output
    cout << sum << endl;

    return 0;
}
