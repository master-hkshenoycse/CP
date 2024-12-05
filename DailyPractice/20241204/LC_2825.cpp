#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        
        int j=0;
        for(int i=0;i<n;i++){
            int d=str2[j]-str1[i];
            //cout<<i<<" "<<j<<" "<<d<<endl;
            if(d==1 or d==-25 or d==0){
                j++;
            }
            if(j==m){
                return 1;
            }
        }
        return 0;
    }
};