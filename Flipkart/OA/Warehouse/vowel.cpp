#include<bits/stdc++.h>
using namespace std;


bool isVowel(char c) {
    return (c=='a' or c=='e' or c=='i' or c=='o' or c=='u');
}

int main() {
    string str;
    cin>>str;

    int k;
    cin>>k;

    int cnt = 0;
    int mx = INT_MIN;

    int n = str.size();
    for (int i=0; i<n; i++) {
        if (i<k) {
            if (isVowel(str[i])) {
                cnt++;
            }
        }
        else if (i>=k) {
            mx = max(mx, cnt);
            if (isVowel(str[i-k])) {
                cnt--;
            }
            if(isVowel(str[i])) cnt++;
        }
    }
    cout<< max(mx, cnt)<<endl;
    return 0;
}
