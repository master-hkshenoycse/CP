#include<bits/stdc++.h>
using namespace std;

/*https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=daily-question&envId=2024-02-23*/
class Solution {
public:
    vector<vector<int> >adj[105];
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int> > dp(n+1,vector<int> (k+2,INT_MAX));
        for(auto e:flights){
            adj[e[0]].push_back({e[1],e[2]});
        }
        
        dp[src][0]=0;
        set<vector<int> > s;
        s.insert({0,src,0});
        
        
        while(s.size()>0){
            int v=(*s.begin())[1];
            int stops=(*s.begin())[2];
            
            s.erase(s.begin());
            //cout<<v<<" "<<stops<<" "<<dp[v][stops]<<endl;
            
            for(auto to:adj[v]){
                int nx=to[0];
                int len=to[1];
                
                if(stops+1<=k+1 and dp[nx][stops+1]>dp[v][stops]+len){
                    dp[nx][stops+1]=dp[v][stops]+len;
                    s.insert({dp[nx][stops+1],nx,stops+1});
                }
            }
        }
        
        
        int ans=INT_MAX;
        for(int i=0;i<=k+1;i++){
            ans=min(ans,dp[dst][i]);
        }
        
        if(ans==INT_MAX){
            ans=-1;
        }
        return ans;      
    }
};