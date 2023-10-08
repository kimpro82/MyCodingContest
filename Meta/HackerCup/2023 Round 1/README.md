# [Meta(Facebook) Hacker Cup 2023 - Round 1](/README.md#metafacebook-hacker-cup)

2023.10.08 02:00 ~ 10.08 05:00, 3 hrs

https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-1


## \<List>

- [Problem A: Here Comes Santa Claus (10 pts)](#problem-a-here-comes-santa-claus-10-pts)
- [Problem B1: Sum 41 (Chapter 1) (11 pts)](#problem-b1-sum-41-chapter-1-11-pts)
- [Problem B2: Sum 41 (Chapter 2) (4 pts)](#problem-b2-sum-41-chapter-2-4-pts)
- [Problem C1: Back in Black (Chapter 1) (11 pts)](#problem-c1-back-in-black-chapter-1-11-pts)
- [Problem C2: Back in Black (Chapter 2) (8 pts)](#problem-c2-back-in-black-chapter-2-8-pts)
- [Problem D: Today is Gonna be a Great Day (24 pts)](#problem-d-today-is-gonna-be-a-great-day-24-pts)
- [Problem E: Bohemian Rap-sody (32 pts)](#problem-e-bohemian-rap-sody-32-pts)


## [Problem A: Here Comes Santa Claus (10 pts)](#list)

not attempted


## [Problem B1: Sum 41 (Chapter 1) (11 pts)](#list)

<details open="">
    <summary>Test Input & Output</summary>

  #### Input
  ```
  7
  2023
  114
  41
  175
  434
  666
  1872
  ```
  #### Output
  ```
  Case #1: 3 7 17 17
  Case #2: 2 3 38
  Case #3: 1 41
  Case #4: 3 1 5 35
  Case #5: 4 1 2 7 31
  Case #6: -1
  Case #7: 5 1 2 6 6 26
  ```
</details>
<details>
    <summary>Codes</summary>

  #### C++
  ```cpp
  #include <iostream>
  #include <vector>
  #include <cmath>
  #include <algorithm>

  #define test
  #define fileio
  #ifdef fileio
      #include <fstream>
      #define cin fin
  #endif

  using namespace std;
  #define endl '\n'
  ```
  ```cpp
  void dfs(vector<int>& div, int idx, int cnt, int n, int k, vector<int>& ans, vector<int>& temp, int p)
  {
      int prod = 1, sum = 0;
      for (int i = 0; i < temp.size(); i++)
      {
          prod *= temp[i];
          sum += temp[i];
      }
      if (prod > p || sum > 41) return;

      if (cnt == k)
      {
          if (prod == p && sum == 41) ans = temp;
          return;
      }

      for (int i = idx; i < n; i++)
      {
          temp.push_back(div[i]);
          dfs(div, i, cnt + 1, n , k, ans, temp, p);
          temp.pop_back();
      }
  }
  ```
  ```cpp
  int main()
  {
      // Input data
      #ifdef fileio
          string inputFileName = "B2_input_full.txt";
          ifstream fin(inputFileName, ios_base::in);
          string line;
      #endif
      int T;
      cin >> T;
      vector<int> P;
      for (int t = 0; t < T; t++)
      {
          int p;
          cin >> p;

          P.push_back(p);
      }
      #ifdef fileio
          fin.close();
      #endif

      // Test T times
      for (int t = 0; t < T; t++)
      {
          int p = P[t];

          // Get divisors <= 41
          vector<int> div;
          for (int i = 1; i <= min(p, 41); i++) if (p % i == 0) div.push_back(i);
          int n = div.size();
          #ifdef test
              cout << "t: " << t + 1;
              cout << ", p: " << p;
              cout << ", n: " << n << ' ';
              for (int i = 0; i < div.size(); i++) cout << div[i] << ' ';
              cout << endl;
          #endif

          // Find the 1st combination of product == P[t] and sum == 41
          vector<int> ans {}, temp {};
          for (int k = 1; k <= 100; k++)                      // "most 100 positive integers"
          // for (int k = 1; k <= div.size(); k++)            // Wrong Answer
          {
              dfs(div, 0, 0, n, k, ans, temp, p);
              if (!ans.empty()) break;
          }
          if (ans.empty()) ans.push_back(-1);

          // Output
          #ifdef fileio
              ofstream ofs;
              string outputFileName = "B2_output_full.txt";
              ofs.open(outputFileName, ios::app);
              // ios::app : All output operations are performed at the end of the file, appending the content to the current content of the file.
              ofs << "Case #" << t + 1 << ": ";
              if (ans[0] != -1) ofs << ans.size() << ' ';
              for (int i = 0; i < ans.size(); i++) ofs << ans[i] << ' ';
              ofs << endl;
              ofs.close();
          #else
              cout << "Case #" << t + 1 << ": ";
              if (ans[0] != -1) cout << ans.size() << ' ';
              for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
              cout << endl;
          #endif
      }

      return 0;
  }
  ```
  </details>

#### Submissions
> Samples : Passed  
> Validation Submussion : Wrong Answer  
> Full Submission (Upsolving) : Accepted


## [Problem B2: Sum 41 (Chapter 2) (4 pts)](#list)

  <details>
      <summary>Test Input & Output</summary>

  #### Input
  ```
  7
  2023
  114
  41
  175
  434
  666
  1872
  ```
  #### Output
  ```
  Case #1: 3 7 17 17
  Case #2: 2 3 38
  Case #3: 1 41
  Case #4: 3 1 5 35
  Case #5: 4 1 2 7 31
  Case #6: -1
  Case #7: 4 2 4 9 26
  ```
  </details>

#### Codes
entirely the same with `B1`

#### Submissions
> Samples (Upsolving) : Passed  
> Full Submission (Upsolving) : Accepted


## [Problem C1: Back in Black (Chapter 1) (11 pts)](#list)

not attempted


## [Problem C2: Back in Black (Chapter 2) (8 pts)](#list)

not attempted


## [Problem D: Today is Gonna be a Great Day (24 pts)](#list)

not attempted


## [Problem E: Bohemian Rap-sody (32 pts)](#list)

not attempted
