#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void dfs(int v,int p,vector<vector<int> > &adj,vector<int> &cp,int d,int &d_even,int &d_odd){
            cp[v]=(d%2);
            if(d%2==0){
                d_even++;
            }else{
                d_odd++;
            }
    
            for(auto to:adj[v]){
                if(to==p){
                    continue;
                }
                dfs(to,v,adj,cp,d+1,d_even,d_odd);
            }
    
        }
        vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
            int n=edges1.size()+1,m=edges2.size()+1,d1_odd=0,d1_even=0,d2_odd=0,d2_even=0;
            vector<vector<int> > adj_1(n),adj_2(m);
            for(auto e:edges1){
                adj_1[e[0]].push_back(e[1]);
                adj_1[e[1]].push_back(e[0]);
            }
    
            for(auto e:edges2){
                adj_2[e[0]].push_back(e[1]);
                adj_2[e[1]].push_back(e[0]);
            }
    
            vector<int> cp_1(n),cp_2(m);
    
            dfs(0,-1,adj_1,cp_1,0,d1_even,d1_odd);
            dfs(0,-1,adj_2,cp_2,0,d2_even,d2_odd);
            vector<int> sol(n);
            for(int i=0;i<n;i++){
                if(cp_1[i]%2==0){
                    sol[i]=d1_even+max(d2_even,d2_odd);
                }else{
                    sol[i]=d1_odd+max(d2_even,d2_odd);
                }
            }
    
            return sol;
    
        }
    };