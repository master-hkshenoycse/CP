#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_cost(string &s){
        int n=s.size();
        int cost=n;
        
        if(n==1){
            return 1e9;
        }
        for(int i=1;i<n;i++){
            if(n%i==0){
                int curr=0;
                for(int j=0;j<i;j++){
                    
                    
                    
                    string tmp;
                    for(int k=j;k<n;k+=i){
                        tmp+=s[k];    
                    }
                    
                    int sz=tmp.size();
                    
                    for(int k=0;k<sz/2;k++){
                        curr=curr+(tmp[k] != tmp[sz-k-1]);
                    }
                    
                }
                
                cost=min(cost,curr);
            }
        }
        
        return cost;
    }
    int minimumChanges(string s, int k) {
        int n=s.size();
        
        vector<vector<int> >dp(n+1,vector<int> (k+1,1e9));
        vector<vector<int> > cost(n+1,vector<int> (n+1,1e9));
        
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                string tmp=s.substr(i-1,j-i+1);
                cost[i][j]=get_cost(tmp);
                //cout<<i<<" "<<j<<" "<<tmp<<" "<<cost[i][j]<<endl;
            }
        }
        
        dp[0][0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                for(int p=1;p<=i;p++){
                    dp[i][j]=min(dp[i][j],dp[p-1][j-1]+cost[p][i]);  
                }
            }
        }
        
        return dp[n][k];
    }
};