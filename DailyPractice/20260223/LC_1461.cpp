#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int lim=(1<<k);
        vector<int> is_pres(lim,0);
        int n=s.size();
        
        for(int i=0;i<n;i++){
            
            int v=0;
            if(i-k+1<0)continue;
            
            for(int j=i;j>=i-k+1;j--)v=v+(s[j]-'0')*(1<<(i-j));
            
            is_pres[v]=1;
        }
        
        
        
        
        for(int i=0;i<lim;i++) {
            if(is_pres[i]==0){
                return 0;
            }
        }
        return 1;
    }
};