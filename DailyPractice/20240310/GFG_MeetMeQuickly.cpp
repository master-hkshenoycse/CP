
#include<bits/stdc++.h>
using namespace std;

/*https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-145/problems*/
class Solution{
 public:
    
    int dfs(int v,int p,vector<vector<int> > &adj,vector<int> &path,int y){
        if(v==y){
            path.push_back(v);
            return 1;
        }
        
        int k=0;
        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            k+=dfs(to,v,adj,path,y);
        }
        
        if(k>0){
            path.push_back(v);
        }
        
        return k;
    }
    int minimumTime(int n, int k, int x, int y, vector<int> &par, vector<int> &arr){
        //Code Here
        
        vector<vector<int> > adj(n+1);
        for(int i=1;i<n;i++){
            adj[i].push_back(par[i]);
            adj[par[i]].push_back(i);
        }
        
        set<int> req;
        for(auto e:arr){
            req.insert(e);
        }
        
        vector<int> path;//stores vertices compulsary needed to visit as these are on path from x to y
        dfs(x,-1,adj,path,y);
        
        int ans=path.size()-1;
        
        //start multisource bfs from these path vertices and add 2* distance from the vertices which belong to freinds
        vector<int> dp(n,INT_MAX);
        queue<int> q;
        
        for(auto p:path){
            dp[p]=0;
            q.push(p);
        }
        
        
        while(q.size()>0){
            int v=q.front();
            q.pop();
            
            for(auto to:adj[v]){
                if(dp[to]>dp[v]+1){
                    
                    dp[to]=dp[v]+1;
                    q.push(to);
                    
                    if(req.find(to) != req.end()){
                        ans=ans+2*dp[to];
                        dp[to]=0;//set it to 0 for next nearest node
                    }
                }
            }
            
        }
        
        
        
        return ans;
    }
};
