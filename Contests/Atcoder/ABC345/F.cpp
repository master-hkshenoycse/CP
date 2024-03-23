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
ll rem;
void dfs(ll v,vector<ll> &vis,vector<ll> &used,vector<ll> &sol,vector<vector<pair<ll,ll > > > &adj,ll k){

    vis[v]=1;

    for(auto to:adj[v]){
        ll ed_no=to.ss;
        ll nx=to.ff;
        if(vis[nx]){
            continue;
        }

        dfs(nx,vis,used,sol,adj,k);

        if(used[nx]==0 and rem<k){
            rem-=(used[nx] + used[v]);
            used[nx]=1-used[nx];
            used[v]=1-used[v];
            rem+=(used[nx]+used[v]);
            sol.pb(ed_no);
        }
    }

}
void solve(ll tc){ 

    ll n,m,k;
    cin>>n>>m>>k;

    vector<vector<pair<ll,ll > > > adj(n+1);
    vector<ll> vis(n+1,0),used(n+1,0),sol;
    
    ll x,y;
    for(ll i=1;i<=m;i++){
        cin>>x>>y;
        adj[x].pb({y,i});
        adj[y].pb({x,i});
    }

    // using one edge does not change parity of the number of lights bulbs
    // if k is even it is always possible as there will be one istance where total on bulbs will be equal to 0
    rem=0;
    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,vis,used,sol,adj,k);
        }
    }

    if(rem!=k){
        cout<<"No"<<endl;
        return;
    }

    cout<<"Yes"<<endl;
    cout<<sol.size()<<endl;
    for(auto e:sol){
        cout<<e<<" ";
    }



 



}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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