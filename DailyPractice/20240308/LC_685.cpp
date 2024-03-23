#include<bits/stdc++.h>
using namespace std;

class DSU{

    private:
    vector<int> parent;
    
    public:

    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find_parent(int v){
        if(v==parent[v]){
            return v;
        }
        return find_parent(parent[v]);
    }

    int Unite(int x,int y){
        int px=find_parent(x);
        int py=find_parent(y);
        if(px==py){
            return 0;
        }

        parent[px]=py;
        return 1;
    }
    

};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        //two types of issues cycle edges and parent conflice edges
        //parent conflict edges occurs when a node has two parents
        //cycle egdes when the DSU edge is there
        //do dsu only when parent conflict is not there
        //Only three cases possible
        //https://leetcode.com/problems/redundant-connection-ii/solutions/108058/one-pass-disjoint-set-solution-with-explain/



        int n=edges.size();
        DSU dsu(n+1);

        vector<int> direct_parent(n+1,-1);
        for(int i=0;i<=n;i++){
            direct_parent[i]=i;
        }
        int cycle_conflict=-1,parent_conflict=-1;

        for(int i=0;i<n;i++){
            int u=edges[i][0],v=edges[i][1];

            if(direct_parent[v] != v){
                parent_conflict=i;
            }else{
                direct_parent[v]=u;

                if(dsu.Unite(u,v)==0){
                    cycle_conflict=i;
                }
            }
        }

        if(parent_conflict==-1){
            return edges[cycle_conflict];
        }

        if(cycle_conflict==-1){
            return edges[parent_conflict];
        }



        // If a cycle exists when a conflict is found, we return the previous edge that caused the cycle with the conflicting node.
        int v = edges[parent_conflict][1];
        return {direct_parent[v],v};
    }
};