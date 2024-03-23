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
void dfs(ll v,vector<vector<ll> > &adj,vector<ll> &vis){
    vis[v]=1;
    for(auto to:adj[v]){
        if(vis[to]==0){
            dfs(to,adj,vis);
        }
    }
}
void solve(ll tc){ 
    ll n,x,a;
    cin>>n>>a>>x;

    vector<vector<ll> > adj(n+1);
    vector<ll> vis(n+1,0);


    ll u,v,w;
    for(ll i=0;i<a;i++){
        cin>>u>>v>>w;
        if(w<=x){
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }

    dfs(1,adj,vis);
    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;

}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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