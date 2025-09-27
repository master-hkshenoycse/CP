#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   
    int maxLen(int n, vector<vector<int>>& edges, string label) {
       static const int MAXN = 14;
       static int dp[1<<MAXN][MAXN][MAXN];

       vector<vector<int> > adj(n);

       for(auto e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
       }

       int M=(1<<n);
       for(int mask=0;mask<M;mask++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[mask][i][j]=-1;
            }
        }
       }

       function<int(int,int,int)> dfs = [&](int mask,int u,int v) -> int {
            int &res = dp[mask][u][v];
            if(res != -1)return res;
            res=0;
            for(int u2: adj[u]){
                if(mask & (1<<u2)){
                    continue;
                }
                for(int v2: adj[v]){
                    if(v2==u2){
                        continue;
                    }

                    if(mask & (1<<v2)){
                        continue;
                    }

                    if(label[u2] != label[v2]){
                        continue;
                    }

                    int n_mask = mask | (1<<u2) | (1<<v2);
                    res=max(res,1+dfs(n_mask,u2,v2));
                }
            }
            return res;
        };

        int best=1;

        //odd- length centers
        for(int u=0;u<n;u++){
            int mask = (1<<u);
            int pairs = dfs(mask,u,u);
            best=max(best,1+2*pairs);
        }

        //even-length seeds
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];

            if(label[u] != label[v]){
                continue;
            }

            int mask = (1<<u) | (1<<v);
            int pairs = dfs(mask,u,v);
            best=max(best,2*(1+pairs));
        }

        return best;
    }
};