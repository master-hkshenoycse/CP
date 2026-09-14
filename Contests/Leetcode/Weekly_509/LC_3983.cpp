#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.size(),m=t.size();

        if(n>m) return 0;
        if(n==0) return 1;
        
        vector<int> left_(n,-1),right_(n,-1);

        int p=0;
        for(int i=0;i<n;i++){
            while(p<m && t[p]!=s[i])p++;
            if(p==m)
                break;
            left_[i]=p++;
        }
        if(left_[n-1]!=-1)
            return 1;
        p=m-1;
        for(int i=n-1;i>=0;i--){
            while(p>=0 && t[p] != s[i])p--;
            if(p<0)
                break;
            right_[i]=p--;
        }   

        for(int i=0;i<n;i++){
            if((i==0 || left_[i-1] != -1) && (i==n-1 || right_[i+1] !=-1)){
                int L=(i==0)?-1:left_[i-1];
                int R=(i==n-1)?m:right_[i+1];
                if(L+1<R)
                    return 1;
            }
        }

        return 0;
    }
};