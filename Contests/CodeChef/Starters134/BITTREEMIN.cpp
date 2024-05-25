#include <bits/stdc++.h>
using namespace std;

void dfs(int v,int p,vector<vector<int> >&adj,vector<int> &level,vector<int> &par){
    if(p>=0){
        level[v]=level[p]+1;
    }
    
    par[v]=p;
    
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        dfs(to,v,adj,level,par);
    }
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--){
        int n,q;
        cin>>n>>q;
        
        vector<vector<int> > adj(n+1);
        vector<int> par(n+1),level(n+1,0),value(n+1);

        
        int x,y;
        for(int i=1;i<n;i++){
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        for(int i=1;i<=n;i++){
            cin>>value[i];
            value[i]/=2;
        }
        
        dfs(1,-1,adj,level,par);
        
        //expression simplified to xor.
        
        int ty;
        
        while(q--){
            cin>>ty;
            
            if(ty==1){
                int u,x;
                cin>>u>>x;
                
                value[u]=x/2;
                
            }else{
                int u,v;
                cin>>u>>v;
                
                int ans=1e9;
                
                vector<int> cnt(1001,0);
                
                
                while(u!=v){
                    
                    //cout<<u<<" "<<v<<endl;
                    if(level[u] >level[v]){
                        cnt[value[u]]++;
                        
                        if(cnt[value[u]]>1){//piegonhole principle
                            ans=0;
                            break;
                        }
                        
                        u=par[u];
                    }else{
                        cnt[value[v]]++;
                        
                        if(cnt[value[v]]>1){//piegonhole principle
                            ans=0;
                            break;
                        }
                        
                        v=par[v];
                    }
                    
                }
                
                cnt[value[u]]++;
                
                
                int prev=-1;
                for(int i=0;i<=1000;i++){
                    
                    if(cnt[i]>1){
                        ans=0;
                        break;
                    }
                    if(cnt[i]>0){
                        if(prev != -1){
                            ans=min(ans,i ^ prev);//adajcent number xor minimum
                        }
                        
                        prev=i;
                    }
                }
                
                cout<<ans<<endl;
                
                
                
            }
        }
        
    }
}
