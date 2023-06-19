// 25206. 너의 평점은
// 2023.06.19

/* Sample input & output data
ObjectOrientedProgramming1 3.0 A+
IntroductiontoComputerEngineering 3.0 A+
ObjectOrientedProgramming2 3.0 A0
……
ProblemSolving 4.0 P

3.284483
*/

#include <iostream>
#include <vector>
#include <algorithm>

// #define test
#define endl '\n'

using namespace std;

double convertGrade(string grade)
{
    const vector<string> grades = {"F", "F", "D0", "D+", "C0", "C+", "B0", "B+", "A0", "A+"};
    int idx;
    for (int i = 0; i < grades.size(); i++)
    {
        if (grade == grades[i])
        {
            idx = i;
            break;
        }
    }
    double convertedGrade = double(idx) * 0.5;

    return convertedGrade;
}

int main()
{
    // Declare
    string title, sWeight, grade;
    double sum = 0, convertedGrade, ans;
    int cnt = 0, nWeight;

    // Input & Operate
    for (int i = 0; i < 20; i++)
    {
        std::cin >> title >> sWeight >> grade;
        if (grade != "P")
        {
            convertedGrade = convertGrade(grade);
            nWeight = sWeight[0] - '0';
            sum += double(nWeight) * convertedGrade;
            cnt += nWeight;
        }

        #ifdef test
            std::cout << cnt << ' ' << convertedGrade << ' ' << sum << endl;
        #endif
    }

    // Output
    ans = sum / cnt;
    std::cout << ans << endl;

    return 0;
}