#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool check(set<int> &a,set<int> &b,int k){
            for(auto e:a){
                if(b.find(e) != b.end()){
                    k--;
                }
                
                if(k==0){
                    return 1;
                }
            }
            
            return 0;
        }
        
        void dfs(int v,vector<vector<int> >&adj,vector<int> &vis){
            vis[v]=1;
            for(auto to:adj[v]){
                if(vis[to]==0){
                    dfs(to,adj,vis);
                }
            }
        }
        int numberOfComponents(vector<vector<int>>& properties, int k) {
            int n=properties.size();
            vector<vector<int> > adj(n);
            vector<int> vis(n,0);
            
            vector<set<int> > props(n);
            
            for(int i=0;i<n;i++){
                for(auto e:properties[i]){
                    props[i].insert(e);
                }
            }
            
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(check(props[i],props[j],k)){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
            
            
            int ans=0;
            
            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    ans++;
                    dfs(i,adj,vis);
                }
            }
            
            return ans;
            
        }
    };