#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> parent, xr;

    int find(int x){
        if(parent[x] != x){
            int root=find(parent[x]);
            xr[x]=(xr[x] ^ xr[parent[x]]);
            parent[x]=root;
        }
        return parent[x];
    }
    
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        xr.assign(n,0);

        for(int i=0;i<n;i++)
            parent[i]=i;

        int res=0;

        for(auto &e: edges){
            int u=e[0],v=e[1],w=e[2];
            int ru=find(u);
            int rv=find(v);

            if(ru != rv){
                parent[ru]=rv;
                xr[ru]=(xr[u] ^ xr[v] ^ w);
                res++;
            }else{
                if((xr[u] ^ xr[v] ^ w)==0)
                    res++;
            }
        }

        return res;    
    }
};