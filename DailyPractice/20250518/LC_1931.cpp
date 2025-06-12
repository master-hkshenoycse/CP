#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector < vector<int> > poss;
    ll mod=1e9+7;
    
    void rec(int m,int prev,vector<int> c){
        
        if(m==0){
            poss.push_back(c);
            return;
        }
        
        for(int i=0;i<3;i++){
            if(i != prev){
                c.push_back(i);
                rec(m-1,i,c);
                c.pop_back();
            }
        }
        return;
    }
    bool chk(vector<int> a,vector<int> b){
        int sz=a.size();
        for(int i=0;i<sz;i++){
            if(a[i]==b[i]){
                return 0;
            }
        }
        return 1;
    }
    int colorTheGrid(int m, int n) {
        vector<vector<ll> > dp(n,vector<ll>(250,0));
        vector<int> o;
        rec(m,-1,o);
        
        int lim=poss.size();
        for(int i=0;i<lim;i++){
            dp[0][i]=1;
        }
        
        vector<int> adj[lim+1];
        for(int j=0;j<lim;j++){
            for(int k=0;k<lim;k++){
                if(chk(poss[j],poss[k])){
                   adj[j].push_back(k);
                }
            }
        }
        
        
        
        for(int i=1;i<n;i++){
            for(int j=0;j<lim;j++){
                for(auto k:adj[j]){
                    dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<lim;i++){
            
            ans=(ans+dp[n-1][i])%mod;
        }
        

        
        return ans;
    }
};