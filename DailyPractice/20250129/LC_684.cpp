#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int par[10005];
    int get_par(int v){
        if(v==par[v]) return v;
        return get_par(par[v]);
    }
    
    bool dsu(int x,int y){
        int a=get_par(x);
        int b=get_par(y);
        
        if(a==b){
            return 0;
        }
        
        par[a]=b;
        return 1;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        
        for(int i=1;i<=n;i++)par[i]=i;
        
        vector<int> sol;
        for(int i=0;i<n;i++){
            int x=edges[i][0];
            int y=edges[i][1];
            
            if(dsu(x,y)==0){
               sol={x,y};
               break;
            }
        }
        return sol;
    }
};