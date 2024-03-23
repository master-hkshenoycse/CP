
#include<bits/stdc++.h>
using namespace std;

//dsu in order of edge weights,offlien query handling

class Solution{
	public:
	int get_par(int v,vector<int> &par){
	    if(v==par[v])return v;
	    return get_par(par[v],par);
	}
	
	void dsu(int x,int y,vector<int> &par,vector<int> &sz,int &ans){
	    int px=get_par(x,par);
	    int py=get_par(y,par);
	    if(px==py){
	        return;   
	    }
	    
	    ans-=(sz[px]*sz[px]-sz[px])/2;
	    ans-=(sz[py]*sz[py]-sz[py])/2;
	    
	    if(sz[px]>sz[py]){
	        swap(px,py);
	    }
	    
	    par[px]=py;
	    sz[py]+=sz[px];
	    sz[px]=0;
	    
	    ans+=(sz[py]*sz[py]-sz[py])/2;
	}
	vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
	{
	    // code here
	    int ans=0;
	    
	    vector<int> sol(q);
	    vector<pair<int,int> > query_set;
	    
	    for(int i=0;i<q;i++){
	        query_set.push_back({queries[i],i});
	    }
	    vector<int> par(n+1,-1),sz(n+1,1);
	    
	    for(int i=1;i<=n;i++){
	        par[i]=i;
	    }
	    
	    for(auto &e:edges){
	        swap(e[0],e[2]);
	    }
	    
	    sort(query_set.begin(),query_set.end());
	    sort(edges.begin(),edges.end());
	    
	    int i=0;
	    
	    for(auto q:query_set){
	        while(i<edges.size() and edges[i][0]<=q.first){
	            dsu(edges[i][1],edges[i][2],par,sz,ans);
	            i++;
	        }
	        
	        sol[q.second]=ans;
	    }
	    
	    return sol;
	    
	}
};