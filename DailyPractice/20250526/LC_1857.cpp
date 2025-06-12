#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> adj[100005];
        int largestPathValue(string colors, vector<vector<int>>& edges) {
            int n=colors.size();
            vector<int> orig_deg(n+1,0);
            
            queue<int> q;
            
            for(auto e:edges){
                adj[e[0]].push_back(e[1]);
                orig_deg[e[1]]++;
            }
            
            int ch=0;
            int ans=1;
            
            while(ch<26){
                vector<int> dp(n+1,0);
                vector<int> deg=orig_deg;
                
                for(int i=0;i<n;i++){
                    if(deg[i]==0){
                        q.push(i);
                        dp[i]=(colors[i]-'a'==ch);
                    }
                }
                
                if(q.size()==0){
                    return -1;
                }
                
                while(q.size()){
                    int v=q.front();
                    q.pop();
                    
                    
                    for(auto to:adj[v]){
                        
                        deg[to]--;
                        if(deg[to]==0){
                            q.push(to);
                        }
                        dp[to]=max(dp[to],dp[v]+(colors[to]-'a'==ch));
                        ans=max(ans,dp[to]);
                    }
                }
                
                
                for(int i=0;i<n;i++){
                    if(deg[i]>0){
                        return -1;
                    }
                }
                ch++;
         
        
            }
            
            return ans;
            
            
        }
    };