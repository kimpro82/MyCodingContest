// AtCoder Beginner Contest 212
// 2021-07-31(Sat) 21:00 - 22:40, 100 minutes

// D - Querying Multiset

/* Sample Input & Output
5
1 3
1 5
3
2 2
3

3
7

6
1 1000000000
2 1000000000
2 1000000000
2 1000000000
2 1000000000
3

5000000000
*/


#include <iostream>
#include <map>

#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    // Input data
    int Q, p, x;
    ll temp, min;
    cin >> Q;
    map<ll, int> m;
    for (int q = 0; q < Q; q++)
    {
        cin >> p;

        // test
        cout << "[q : " << q + 1 << ", p : " << p << ']' << endl;

        if (p == 1)
        {
            cin >> x;

            if (m.find(x) == m.end()) m.insert(pair<ll, int> (x, 1));
            else m.find(x)->second++;
        }
        else if (p == 2)
        {
            cin >> x;

            map<ll, int> m2;
            for (auto it = m.begin(); it != m.end(); it++)
            {
                // 이러한 피연산자와 일치하는 "+" 연산자가 없습니다. -- 피연산자 형식이 std::pair<const ll, int> + int입니다.
                // if (m.find(*it + x)->second == 0) m.insert(pair<ll, int> (*it + x, 1));
                // else m.find(*it + x)->second++;

                temp = it->first + x;
                m2.insert(pair<ll, int> (temp, it->second));
            }
            m = m2;
        }
        else    // p == 3
        {
            min = INT64_MAX;
            for (auto it = m.begin(); it != m.end(); it++)
            {
                if (it->first < min) min = it->first;
            }
            cout << min << endl;

            if (m.find(min)->second > 1) m.find(min)->second--;
            else m.erase(min);
        }

        // test
        for (auto it = m.begin(); it != m.end(); it++) cout << it->first << ' ';
        cout << endl;
        for (auto it = m.begin(); it != m.end(); it++) cout << it->second << ' ';
        cout << endl;
    }

    return 0;
}