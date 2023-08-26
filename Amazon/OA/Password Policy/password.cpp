#include <bits/stdc++.h>
using namespace std;

int LCS(string oldP, string newP, int n1, int n2, vector<vector<int>> &dp)
{
  if (n1 == 0 or n2 == 0)
    return 0;
  if (dp[n1][n2] != -1)
    return dp[n1][n2];

  if (newP[n2 - 1] == 'z' and oldP[n1 - 1] == 'a' or oldP[n1 - 1] == 'z')
  {
    return dp[n1][n2] = 1 + LCS(oldP, newP, n1 - 1, n2 - 1, dp);
  }

  if (oldP[n1 - 1] == newP[n2 - 1] or oldP[n1 - 1] - 'a' == newP[n2 - 1] - 'a' + 1)
  {
    return dp[n1][n2] = 1 + LCS(oldP, newP, n1 - 1, n2 - 1, dp);
  }

  return dp[n1][n2] = LCS(oldP, newP, n1, n2 - 1, dp);
}

int main()
{
  int n = 4;
  vector<string> oldP = {"abdbc", "ach", "abb", "azb"};
  vector<string> newP = {"baacbab", "accdb", "baacba", "zza"};

  vector<string> result;
  for (int i = 0; i < n; i++)
  {
    int n1 = oldP[i].size(), n2 = newP[i].size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

    bool flag = n1 == LCS(oldP[i], newP[i], n1, n2, dp) ? 1 : 0;
    if (flag)
      result.push_back("YES");
    else
      result.push_back("NO");
  }

  for (auto x : result)
    cout << x << endl;

  return 0;
}
