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
void dfs(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &deg,ll &ans){

    vector<ll> deg_;
    for(auto to:adj[v]){
        deg_.push_back(deg[to]);
        if(to==p){
            continue;
        }
        dfs(to,v,adj,deg,ans);
    }

    sort(deg_.begin(),deg_.end());
    reverse(deg_.begin(),deg_.end());

    for(ll i=0;i<deg_.size();i++){
        ans=max(ans,(i+1)*(deg_[i]-1)+i+1+1);
    }
}
void solve(ll tc){
    

    ll n;
    cin>>n;

    vector<vector<ll> > adj(n+1);
    vector<ll> deg(n+1);
    ll u,v;
    for(ll i=1;i<=n-1;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }


    ll ans=0;

    dfs(1,-1,adj,deg,ans);
    cout<<n-ans<<endl;
    

}
int main(){
    boost;

    //pre_cum();
    //prec(10);
	//fre;


    ll t=1;
    ll tc=1;
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}