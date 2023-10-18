// 1929 : (재귀함수) 우박수 (3n+1) (reverse)
// 2023.10.16


#include <iostream>
#include <stack>

#define endl '\n'

using namespace std;


stack<int> stk;

void Recursion(int n)
{
    stk.push(n);

    if (n == 1) return;
    else if (n % 2 == 1) Recursion(3 * n + 1);
    else Recursion(n / 2);
}

void stkPop()
{
    if (!stk.empty())
    {
        cout << stk.top() << endl;
        stk.pop();
        stkPop();
    }
    else
        return;
}

int main()
{
    int n;
    cin >> n;

    Recursion(n);
    stkPop();

    return 0;
}
