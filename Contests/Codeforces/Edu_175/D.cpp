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
ll mod=998244353;
void dfs(ll v,ll p,ll d,vector<vector<ll> >&adj,vector<vector<ll> >&depth_sorted){
    
    if(depth_sorted.size()==d){
        depth_sorted.pb({});
    }

    depth_sorted[d].pb(v);

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        dfs(to,v,d+1,adj,depth_sorted);
    }
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<vector<ll> > adj(n+1);
    vector<ll> par(n+1);
    for(ll i=2;i<=n;i++){
        cin>>par[i];
        adj[i].pb(par[i]);
        adj[par[i]].pb(i);
    }


    vector<vector<ll> > depth_sorted;
    dfs(1,-1,0,adj,depth_sorted);

    ll sz=depth_sorted.size();
    vector<ll> dp(n+1,0);

    ll sum_other=0;
    for(ll i=sz-1;i>=0;i--){

        for(auto v:depth_sorted[i]){
            dp[v]=1;
            for(auto nx:adj[v]){
                if(nx!=par[v] && (v>1)){
                    dp[v]=(dp[v]-dp[nx])%mod;
                }
            }
            dp[v]=(dp[v]+sum_other)%mod;
            dp[v]=(dp[v]+mod)%mod;
        }

        sum_other=0;
        for(auto v:depth_sorted[i]){
            sum_other=(sum_other+dp[v])%mod;
        }
    }

    cout<<dp[1]<<endl;


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