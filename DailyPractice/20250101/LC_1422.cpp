#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int t1=0,t0=0,ans=0;
        int c1=0,c0=0;

        for(auto ch:s){
            t1+=(ch=='1');
            t0+=(ch=='0');
        }

        for(int i=0;i+1<n;i++){
            c1+=(s[i]=='1');
            c0+=(s[i]=='0');

            ans=max(ans,c0+t1-c1);
        }
        return ans;
    }
};