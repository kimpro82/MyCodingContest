// [BOJ] 단계별로 풀어보기 > 12. 정렬

// 10814. 나이순 정렬

/* Sample input & output data
3
21 Junkyu
21 Dohyun
20 Sunyoung

20 Sunyoung
21 Junkyu
21 Dohyun
*/


#include <iostream>
#include <set>
#include <tuple>                                                        // similar with <pair>, but elements are more than 3
#include <algorithm>

using namespace std;

#define endl '\n'


struct comp
{
    bool operator() (const tuple<int, int, string> t1, const tuple<int, int, string> t2) const
    {
        if (get<1>(t1) != get<1>(t2)) return get<1>(t1) < get<1>(t2);
        else return get<0>(t1) < get<0>(t2);                            // maintain the existing order
    }
};


int main()
{
    // Input N
    int N;
    cin >> N;

    // Input set<tuple<int, int, string>> with ordering
    set<tuple<int, int, string>, comp> s;
    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;

        s.insert(tuple<int, int, string> (i, age, name));
    }

    // Output
    int len = s.size();
    for (auto it = s.begin(); it != s.end(); it++) cout << get<1>(*it) << ' ' << get<2>(*it) << endl;

    return 0;
}