#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> adj[505];
    int col[505];
    int d[505];
    vector<int> comp[505];
    
    bool chkBipartite(int v,int c_no){
        col[v]=1;
        queue<int> q;
        q.push(v);
        
        while(q.size()>0){
            int curr=q.front();
            comp[c_no].push_back(curr);
            q.pop();
            
            for(auto to:adj[curr]){
                if(col[to]==0){
                    col[to]=3-col[curr];
                    q.push(to);
                }else{
                    if(col[to]==col[curr]){
                        return 0;
                    }
                }
            }
        }
        
        return 1;
    }
    
    int getMax(int v,int c_no){
        for(auto e:comp[c_no]){
            d[e]=INT_MAX;
        }
        
        int ans=0;
        d[v]=0;
        queue<int> q;
        q.push(v);
        
        while(q.size()>0){
            int sz=q.size();
            ans++;
            
            for(int i=0;i<sz;i++){
                int curr=q.front();
                q.pop();
                
                for(auto to:adj[curr]){
                    
                    if(d[to]>d[curr]+1){
                        d[to]=d[curr]+1;
                        q.push(to);
                    }
                }
            }
            
        }
        
        return ans;
        
        
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        for(int i=1;i<=n;i++){
            adj[i].clear();
            col[i]=0;
            comp[i].clear();
        }
        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int c_no=0;
        for(int i=1;i<=n;i++){
            if(col[i]==0){
                c_no++;
                if(chkBipartite(i,c_no)==0){
                    return -1;
                }
            }
        }
        
        int ans=0;
        
        for(int i=1;i<=c_no;i++){
            int ma=0;
            for(auto e:comp[i]){
                ma=max(ma,getMax(e,i));
                
            }
            ans+=ma;
        }
        
        return ans;
        
        
        
        
        
    }
};