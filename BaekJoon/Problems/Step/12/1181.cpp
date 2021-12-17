// [BOJ] 단계별로 풀어보기 > 12. 정렬

// 1181. 단어 정렬

/* Sample input & output data
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours

i
im
it
no
but
more
wait
wont
yours
cannot
hesitate
*/


#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define endl '\n'


struct comp                                                                         // should be a struct, refer to less<_Kty>
{
    bool operator() (const pair<int, string> p1, const pair<int, string> p2) const  // need to understand why use 'const'
    {
        if (p1.first != p2.first) return p1.first < p2.first;
        else return p1.second < p2.second;
    }
};                                                                                  // don't miss ';'

// struct for set<string>
// struct comp                                                                      // should be a struct, refer to less<_Kty>
// {
//     bool operator() (const string s1, const string s2) const
//     {
//         if (s1.size() != s2.size()) return s1.size() < s2.size();
//         else return s1 < s2;
//     }
// };                                                                               // don't miss ';'

// function for set<string> : an error occurs - 함수 "comp"은(는) 형식 이름이 아닙니다.C/C++(757)
// bool comp(string s1, string s2)
// {
//     if (s1.size() != s2.size()) return s1.size() < s2.size();
//     else return s1 < s2;
// }


int main()
{
    // Input N
    int N;
    cin >> N;

    // Input set<pair<int, string>> with ordering
    set<pair<int, string>, comp> s;                                                 // declare with indicating how to order
    // template<typename _Key, typename _Compare = std::less<_Key>, typename _Alloc = std::allocator<_Key> >
    // less<_Key> is a struct
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        pair<int, string> p;
        p.first = temp.size();
        p.second = temp;

        s.insert(p);
    }

    // Output
    int len = s.size();
    for (auto it = s.begin(); it != s.end(); it++) cout << (*it).second << endl;

    return 0;
}