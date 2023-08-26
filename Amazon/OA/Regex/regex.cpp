#include <bits/stdc++.h>

using namespace std;

int main()
{
  // Note: a,b,c should be of same length and Upper case characters
  string a = "AB", b = "AB", c = "AB";
  // cin >> a >> b >> c;
  string res;

  int n = a.length();
  int smallest = -1;

  //Calculate lexicographically smallest charcter to remove
  for (int i = 0; i < n; i++)
  {
    if (a[i] == c[i] || b[i] == c[i])
      continue;

    if (smallest == -1)
    {
      smallest = i;
    }
    else if (c[smallest] > c[i])
    {
      smallest = i;
    }
  }

  //If smallest -1 i.e to potential candidate to remove, return -1
  if (smallest == -1)
  {
    cout << "-1";
    // return "-1";
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      res += "[";
      for (int j = 'A'; j <= 'Z'; j++)
      {
        if (i == smallest)
        {
          if (c[smallest] != j)
          {
            res += (char)j;
          }
        }
        else
        {
          res += (char)j;
        }
      }
      res += "]";
    }

    cout << res;
    // return res;
  }
  return 0;
}
