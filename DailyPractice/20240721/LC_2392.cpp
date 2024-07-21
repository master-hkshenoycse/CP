#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> get_order(vector<vector<int> >&conditions,int k){
        vector<vector<int> >adj(k+1);
        vector<int> in_deg(k+1,0);

        for(auto c:conditions){
            adj[c[0]].push_back(c[1]);
            in_deg[c[1]]++;
        }

        vector<int> ret;    
        queue<int> q;

        for(int i=1;i<=k;i++){
            if(in_deg[i]==0){
                q.push(i);
            }
        }

        while(q.size()>0){
            int curr=q.front();
            q.pop();

            ret.push_back(curr);

            for(auto nx:adj[curr]){
                in_deg[nx]--;
                if(in_deg[nx]==0){
                    q.push(nx);
                }
            }
        }



        if(ret.size()<k){
            return {-1};
        }

        return ret;
    }   
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> row_order=get_order(rowConditions,k);
        vector<int> col_order=get_order(colConditions,k);
        
        if(row_order.size()<k or col_order.size()<k){
            return {};
        }

        vector<vector<int> > sol(k,vector<int> (k,0));
        vector<int> row_alloc(k+1),col_alloc(k+1);
        for(int i=0;i<k;i++){
            row_alloc[row_order[i]]=i;
            col_alloc[col_order[i]]=i;
        }

        for(int i=1;i<=k;i++){
            sol[row_alloc[i]][col_alloc[i]]=i;
        }
        

        return sol;
        
    }
};