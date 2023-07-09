// 10815. 숫자 카드
// 2023.07.07

/* Sample input & output data
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10

1 0 0 1 1 0 0 1
*/


#include <iostream>
#include <set>
#include <vector>

#define endl '\n'

using namespace std;


int main()
{
    // Input 1
    int n;
    set<int> x;
    int temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        x.insert(temp);
    }

    // Input 2 & Operate
    int m;
    vector<int> v;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        if (x.find(temp) != x.end()) v.push_back(1);
        else v.push_back(0);

    }

    // Output
    for (int i = 0; i < m; i++) cout << v[i] << ' ';
    cout << endl;
 
    return 0;
}
