#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numTilings(int n) {
            vector<int> dom(n+1,0),tom(n+1,0);
            
            if(n<3) return n;
            
            
            dom[0]=0;
            dom[1]=1;
            dom[2]=2;
            
            tom[0]=0;
            tom[1]=1;
            tom[2]=2;
        
            int mod=1e9+7;
            
            
            for(int i=3;i<=n;i++){
               dom[i]=(dom[i-1]+dom[i-2])%mod;
               dom[i]=(dom[i]+(2*tom[i-2])%mod)%mod;
               tom[i]=(tom[i-1]+dom[i-1])%mod;
            }
            return dom[n];
        }
    };