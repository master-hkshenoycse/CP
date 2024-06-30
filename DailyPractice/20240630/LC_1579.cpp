#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define pb push_back
class Solution {
public:
    class disjoint_union{
     
    public:int par[100005];
    public:int cnt[100005];
    
   
        
    public: disjoint_union(int n){
         
        for(int i=1;i<=n;i++){
            this->par[i]=i;
            this->cnt[i]=1;
        }
    }
        
    int find_par(int v){
        if(v!=par[v]) return find_par(par[v]);
        return v;
    }
    
    int union_dsu(int x,int y){
        int a=find_par(x);
        int b=find_par(y);
        
        if(a==b){
            return 1;
        }
        
        if(cnt[a]>cnt[b]){
            par[b]=a;
            cnt[a]+=cnt[b];
            cnt[b]=0;
        }else{
            par[a]=b;
            cnt[b]+=cnt[a];
            cnt[a]=0;
        }
       return 0;
    }
        
    };
    
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
            int m=edges.size();
            vector<pair<int,int> > ed_ty[5];
            
        
           for(int i=0;i<m;i++){
               int ty,x,y;
               ty=edges[i][0];
               x=edges[i][1];
               y=edges[i][2];
               ed_ty[ty].pb(make_pair(x,y));
           }
          disjoint_union ds1(n),ds2(n);
         int ans=0;
         for(int i=0;i<ed_ty[3].size();i++){
             int x=ed_ty[3][i].first;
             int y=ed_ty[3][i].second;
             
             ans+=ds1.union_dsu(x,y);
             ds2.union_dsu(x,y);
             
        }
        
        for(int i=0;i<ed_ty[1].size();i++){
             int x=ed_ty[1][i].first;
             int y=ed_ty[1][i].second;
             ans+=ds1.union_dsu(x,y);
        }
        
        for(int i=0;i<ed_ty[2].size();i++){
             int x=ed_ty[2][i].first;
             int y=ed_ty[2][i].second;
             ans+=ds2.union_dsu(x,y);
        }
        
        int mx1=0,mx2=0;
        for(int i=1;i<=n;i++){
            mx1=max(mx1,ds1.cnt[i]);
            mx2=max(mx2,ds2.cnt[i]);
        }
        if(mx1<n or mx2<n)return -1;
        return ans;
            
        
            
            
    }
};