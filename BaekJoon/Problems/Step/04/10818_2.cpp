/* Sample input & output data
5
20 10 35 30 7

7 35
*/

// I really don't want to use for loop with math.max(), math.min().
// But, consequantially, it was a kind of the lesser evil.

#include <iostream>
// #include <cstdarg>   // for using va_list, but it can't adopt minmax()
// #include <utility>   // likewise, for using pair<> related with minmax()
#include <vector>       // need to understand by comparing with other similar containers
#include <algorithm>    // for using min_element() and max_element()

using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<int> vec;            // not arr[], because vector<> has variable size
    int temp;
    for (int i = 0; i < t; i++)
    {
        cin >> temp;
        vec.push_back(temp);
    }

    // pair <int, int> answer;  // for getting output from minmax()
    // minmax() requires list<>, not va_list
    int minValue = *min_element(vec.begin(), vec.end());    
    int maxValue = *max_element(vec.begin(), vec.end());
    cout << minValue << " " << maxValue << endl;    // inefficient, crazy

    return 0;
}