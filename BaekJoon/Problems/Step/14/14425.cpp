// 14425. 문자열 집합
// 2023.07.07

/* Sample input & output data
5 11
baekjoononlinejudge
startlink
codeplus
sundaycoding
codingsh
baekjoon
codeplus
codeminus
startlink
starlink
sundaycoding
codingsh
codinghs
sondaycoding
startrink
icerink

4
*/


#include <iostream>
#include <set>
#include <vector>

#define endl '\n'

using namespace std;


int main()
{
    // Input 1
    int n, m;
    cin >> n >> m;
    set<string> x;
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        x.insert(temp);
    }

    // Input 2 & Operate
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        if (x.find(temp) != x.end()) cnt++;
    }

    // Output
    cout << cnt << endl;
 
    return 0;
}
