#include<bits/stdc++.h>
using namespace std;
int main(){
     vector<int> marks = {4, 2, 45, 23, 70};
    int lowerBound = 1;
    int upperBound = 75;
    sort(marks.begin(),marks.end());
    int prev=lowerBound-1;
    string s="";
    for(auto mark:marks){
        if(mark>prev+1){
           if(prev+1==mark-1){
                s=s+to_string(prev+1)+" ";

           }
           else{
            s+=to_string(prev+1)+"->";
            s+=to_string(mark-1)+" ";
           }
           

        }
            prev=mark;
    }
    if(marks.back()<upperBound){
        if(marks.back()+1==upperBound)
          s=s+to_string(upperBound)+" ";
        else
        {
            s=s+to_string(marks.back()+1)+"->"; 
             s=s+to_string(upperBound)+" ";
        }
    }
     cout << s;
}
