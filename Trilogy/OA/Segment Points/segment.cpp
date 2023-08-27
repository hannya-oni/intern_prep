#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr) {
    for (auto i: arr) cout<<i<<" ";
    cout<<endl;
}

vector<int> countInteger(vector<vector<int>> &A) {
    int n = A.size();
    unordered_map<int, int> mp;
    for (int i=0; i<n; i++) {
        int L = A[i][0], R = A[i][1];
        while (L<=R)
            mp[L++]++;
    }

    vector<int> ans(n+1, 0);
    for (auto x: mp)
        ans[x.second]++;

    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> A(n, vector<int>(2));

    for (int i=0; i<n; i++)
        for (int j=0; j<2; j++)
            cin>>A[i][j];

    vector<int> ans = countInteger(A);
    print(ans);
    return 0;
}
