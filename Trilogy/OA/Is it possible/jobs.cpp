#include<bits/stdc++.h>
using namespace std;

void print(vector<int> ans) {
    for (auto x: ans) cout<<x<<" ";
    cout<<endl;
}

bool compare(pair<int, vector<int>>& work1, pair<int, vector<int>>& work2) {
    return work1.second[1] < work2.second[1];
}

vector<int> performWork(int A, int M, vector<pair<int, vector<int>>>& works) {
    vector<int> result(A + 1, -1);
    sort(works.begin(), works.end(), compare);

    for (auto &work: works) {
        int workIndex = work.first;
        int startDay = work.second[0];
        int deadline = work.second[1];
        int daysNeeded = work.second[2];

        for (int i=deadline-1; i>=startDay; i--) {
            if (result[i]==-1 and daysNeeded>0) {
                result[i] = workIndex;
                daysNeeded--;
            }
        }
        if (daysNeeded) return {-1};
    }
    for (int i=1; i<A+1; i++) {
        if (result[i] == -1) {
            result[i] = M+1;
        }
    }
    
    return result;
}

int main() {
    int A = 5;
    vector<vector<int>> B = {{1,4,2}, {2,3,1}, {3,5,1}};
    vector<pair<int, vector<int>>> works;
    int M = B.size();
    for (int i=0; i<M; i++) {
        works.push_back(make_pair((i+1), B[i]));
    }

    vector<int> ans = performWork(A, M, works);
    print(ans);
    return 0;
}
