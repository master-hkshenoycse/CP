#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(int v,int p,vector<vector<int> >&adj, string &col){
        int ret=1;

        if(p!=-1 && col[v]==col[p])
            ret=0;


        for(auto to:adj[v]){

            if(to==p)
                continue;

            if(col[to] == col[v])
                ret=0;

            if(p!=-1 && col[to]==col[p])
                ret=0;
            
            if(ret>0 && dfs(to,v,adj,col)==0)
                ret=0;
        }

        return ret;
    }
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=edges.size()+1;
        vector<int> in_deg(n,0),out_deg(n,0);

        map<char,char> next_char;
        next_char['R']='B';
        next_char['B']='W';
        next_char['W']='R';

        for(auto e:edges){
            if(next_char[colors[e[0]]]==colors[e[1]]){
                out_deg[e[0]]++;
                in_deg[e[1]]++;
            }else if(next_char[colors[e[1]]]==colors[e[0]]){
                out_deg[e[1]]++;
                in_deg[e[0]]++;
            }else{
                return -1;
            }
        }
        int root=-1;

        for(int i=0;i<n;i++){
            if(in_deg[i]>1 || out_deg[i]>2)
                return -1;
            
            if(in_deg[i]==0)
                root=i;

        }     
        return root;
    }
};