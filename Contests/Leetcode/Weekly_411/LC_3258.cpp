#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            int c1=0,c0=0;
            for(int j=i;j<n;j++){
                c1+=(s[j]=='1');
                c0+=(s[j]=='0');
                
                if(c1<=k or c0<=k){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};