// [BOJ] 단계별로 풀어보기 > 9. 기본 수학 2

// 3009. 네 번째 점

/* Sample input & output data
5 5
5 7
7 5

7 7

30 20
10 10
10 20

30 10
*/


#include <iostream>
#include <map>

using namespace std;
#define endl '\n'

int main()
{
    // Input data
    map<int, int> x, y;
    int temp1, temp2;
    for (int i = 0; i < 3; i++)
    {
        cin >> temp1 >> temp2;
        x.insert(pair<int, int> (temp1, 1));
        y.insert(pair<int, int> (temp2, 1));
    }

    // test
    map<int, int>::iterator it;
    for (it = x.begin(); it != x.end(); it++)
    {
        cout << it->first << ' ' << it->second << endl;
    }
    
    return 0;
}