#include<bits/stdc++.h>
using namespace std;

void print(vector<int> ans) {
    for (auto x: ans) cout<<x<<" ";
    cout<<endl;
}

int sumOfbitwiseAndSubArray(vector<int> &A, int l, int r) {
    int ans = 0;
    for (int i=l; i<=r; i++) {
        int AND = A[i];
        ans += AND;
        for (int j=i+1; j<=r; j++) {
            AND &= A[j];
            ans += AND;
        }
    }
    return ans;
}

void initializeWithV(vector<int> &A, int l, int r, int v) {
    for (int i=l; i<=r; i++) A[i]=v;
}

void orWithV(vector<int> &A, int l, int r, int v) {
    for (int i=l; i<=r; i++) A[i] |= v;
}

int main() {
    int N = 5;
    vector<int> A = {5, 4, 3, 2, 1};
    int Q = 5;
    int B[Q][4] = {{3, 2, 4, 0}, {1, 1, 2, 8}, {2, 2, 4, 2}, {3, 1, 3, 0}, {3, 3, 5, 0}};
    // int N = 4;
    // vector<int> A = {1, 0, 2, 5};
    // int Q = 4;
    // vector<vector<int>> B = {{3,1,3,0}, {1,1,2,4},{2,2,4,5},{3,1,4,0}};
    vector<int> ans;
    for (int i=0; i<Q; i++) {
        int q = B[i][0];
        int l = B[i][1]-1;
        int r = B[i][2]-1;
        int v = B[i][3];

        if (q==1) 
            initializeWithV(A, l, r, v);
        else if (q==2) 
            orWithV(A, l, r, v);
        else
            ans.push_back(sumOfbitwiseAndSubArray(A, l, r));
    }

    print(ans);
    return 0;
}
