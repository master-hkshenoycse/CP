#include<bits/stdc++.h>
using namespace std;
int dfs(int v,int p,vector<vector<int> >&adj,string &S,int &ans){
    
    int ret=0;
    vector<int> max_diff;
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        int tmp=dfs(to,v,adj,S,ans);
        if(S[to]!=S[v]){
            max_diff.push_back(tmp);
            ret=max(ret,tmp);
        }
    }

    sort(max_diff.begin(),max_diff.end());
    reverse(max_diff.begin(),max_diff.end());
    if(max_diff.size()==1){
        ans=max(ans,max_diff[0]+1);
    }else if(max_diff.size()>1){
        ans=max(ans,max_diff[0]+max_diff[1]+1);
    }

    ans=max(ans,ret+1);

    return ret+1;
}
int solution(string &S,vector<int> &P,int N){
    int ans=0;

    vector<vector<int> > adj(N);
    for(int i=0;i<N;i++){
        if(P[i] != -1){
            adj[P[i]].push_back(i);
            adj[i].push_back(P[i]);
        }
    }

    dfs(0,-1,adj,S,ans);

    return ans;
}
int main(){
    string s;
    vector<int> p;

    s="abbab";
    p={-1,0,0,0,2};
    cout<<solution(s,p,5)<<endl;

    s="ab";
    p={-1,0};
    cout<<solution(s,p,2)<<endl;
}