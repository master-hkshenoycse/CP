#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void dfs(int v,int p,int d,vector<vector<int> >&adj_1,int lim,int &upd){
            if(d<=lim){
                upd++;
            }
    
            for(auto to:adj_1[v]){
                if(to==p){
                    continue;
                }
                dfs(to,v,d+1,adj_1,lim,upd);
            }
    
        }
        vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
            int n=edges1.size()+1;
            int m=edges2.size()+1;
    
            vector<int> dis_from_tree_1(n,0);
            vector<int> dis_from_tree_2(m,0);
    
            vector<vector<int> > adj_1(n),adj_2(m);
    
    
            for(auto e:edges1){
                adj_1[e[0]].push_back(e[1]);
                adj_1[e[1]].push_back(e[0]);
            } 
    
            for(auto e:edges2){
                adj_2[e[0]].push_back(e[1]);
                adj_2[e[1]].push_back(e[0]);
            }
    
            for(int i=0;i<n;i++){
                dfs(i,-1,0,adj_1,k,dis_from_tree_1[i]);
            }
    
            int ma=0;
            for(int i=0;i<m;i++){
                dfs(i,-1,0,adj_2,k-1,dis_from_tree_2[i]);
                ma=max(ma,dis_from_tree_2[i]);
            }
    
            vector<int> ans(n);
            for(int i=0;i<n;i++){
                ans[i]=dis_from_tree_1[i]+ma;
            }
            return ans;
    
    
        }
    };