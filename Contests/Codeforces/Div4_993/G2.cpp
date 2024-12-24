#include<bits/stdc++.h>
#include <iterator>
#include <iostream>
#include <numeric>
#include <math.h>
#define ll long long
#define ull long
#define mpa make_pair
#define pb push_back
#define ff first
#define pii pair<ll,ll>
#define dd long double
#define trace(x) cerr << #x << " : " << x << endl
#define ss second
#define boost ios_base::sync_with_stdio(0)
#define forp(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n)    for(ll i=0;i<n;++i)
#define ren(i,n)    for(ll i=n-1;i>=0;i--)
#define forn(i,a,b) for(ll i=a;i>=b;i--)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end();
#define sc(x) scanf("%lld",&x)
#define clr(x,val) memset(x,val,sizeof(x))
#define pr(x) printf("%lld\n",x) 
#define gc getchar
#define pdd pair<dd,dd>
#define prec(x) cout<<fixed<<setprecision(x)
#define fre freopen("rental.in","r",stdin),freopen("rental.out","w",stdout)
#define arr array 
using namespace std;
void dfs(ll v,vector<ll> &a,vector<ll> &vis,ll &st){

    vis[v]=2;
   


    if(vis[a[v]]==0){
        dfs(a[v],a,vis,st);
    }else if(vis[a[v]]==2){
        st=a[v];
    }

    vis[v]=1;

}
void mark_cycles(ll v,vector<ll> &a,vector<ll> &in_cycle){
    in_cycle[v]=1;
    
    
    if(in_cycle[a[v]]==0){
        mark_cycles(a[v],a,in_cycle);
    }
}

void get_sol(ll v,vector<vector<ll> > &adj,vector<ll> &in_cycle,vector<ll> &dp,vector<ll> &sub_sz){
    
    for(auto to:adj[v]){
        if(in_cycle[to]==0){
            in_cycle[to]=1;
            get_sol(to,adj,in_cycle,dp,sub_sz);
            sub_sz[v]+=sub_sz[to];
            dp[v]=max(dp[v],dp[to]+1);
            dp[v]=max(dp[v],dp[to]+sub_sz[to]-1);
        }
    }

    //dp[v]=max(dp[v],sub_sz[v]);
    sub_sz[v]++;


}
void solve(ll tc){


    ll n;
    cin>>n;

    vector<ll> a(n+1),vis(n+1,0),in_cycle(n+1,0),sub_sz(n+1,0);
    vector<vector<ll> > rev_adj(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        rev_adj[a[i]].pb(i);
    }


    for(ll i=1;i<=n;i++){   
        //cout<<i<<" "<<vis[i]<<endl;
        if(vis[i]==0){
            ll st=-1;
            vis[i]=2;
            dfs(i,a,vis,st);
            if(st!=-1){
                mark_cycles(st,a,in_cycle);
            }
        }
    }


    vector<ll> dp(n+1,1);
    for(ll i=1;i<=n;i++){   
        if(in_cycle[i]==1){
            get_sol(i,rev_adj,in_cycle,dp,sub_sz);
        }
    }

    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans=max(ans,1+dp[i]);
    }

   cout<<ans<<endl;

}
int main(){
    boost;

    //pre_cum();
    //prec(10);
	//fre;


    ll t=1;
    ll tc=1;
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}