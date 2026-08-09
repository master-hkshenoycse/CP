#include<bits/stdc++.h>
using namespace std;
#define ll long long
class DSU{
    private:
    vector<int> parent,comp_sz;
    public:
    DSU(int n){
        parent.resize(n);
        comp_sz.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            comp_sz[i]=1;
        }
    }

    int get_par(int p){
        if(p==parent[p])return p;
        return get_par(parent[p]);
    }

    void do_union(int x,int y){
        int px=get_par(x);
        int py=get_par(y);
        if(px==py)
            return;
        
        if(comp_sz[px] > comp_sz[py])
            swap(px,py);
        
        parent[px]=py;
        comp_sz[py]+=comp_sz[px];
        comp_sz[px]=0;
    }

    int get_comp_sz(int p){
        return comp_sz[p];
    }
};  
class Solution {
public:
    
    int maxActivated(vector<vector<int>>& points) {
        int n=points.size();
        map<int,vector<int> > adj_x,adj_y;
        DSU dsu(n);

        for(int i=0;i<n;i++){            
            adj_x[points[i][0]].push_back(i);
            adj_y[points[i][1]].push_back(i);
        }

        for(auto it:adj_x){
            int p=it.second[0];
            for(auto x:it.second)
                dsu.do_union(p,x);
        }

        for(auto it:adj_y){
            int p=it.second[0];
            for(auto y:it.second)
                dsu.do_union(p,y);
        }

        int max_sz=0,sec_max_sz=0;
        for(int i=0;i<n;i++){
            int curr_sz=dsu.get_comp_sz(i);
            if(curr_sz>max_sz){
                sec_max_sz=max_sz;
                max_sz=curr_sz;
            }else
                sec_max_sz=max(sec_max_sz,curr_sz);
        }
        return max_sz+sec_max_sz+1;

    }
};