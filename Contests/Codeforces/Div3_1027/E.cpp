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
void dfs(ll v,ll p,vector<ll> &sol,vector<vector<ll> > &adj,vector<ll> &a,ll max_val,ll min_val){
    sol[v]=max(a[v],a[v]-min_val);
    
    ll nx_min=min(a[v],a[v]-max_val);
    ll nx_max=max(a[v],a[v]-min_val);
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        dfs(to,v,sol,adj,a,nx_max,nx_min);
    }
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n+1);
    vector<vector<ll> > adj(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    ll x,y;
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }


    vector<ll> sol(n+1);
    dfs(1,-1,sol,adj,a,0,0);

    for(ll i=1;i<=n;i++){
        cout<<sol[i]<<" ";
    }
    cout<<endl;
    
    

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
