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
void dfs(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &in_time,vector<ll> &low_time,vector<vector<arr<ll,2 > > >&dfs_tree,ll &timer){
    timer++;
    in_time[v]=timer;
    low_time[v]=timer;

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        if(in_time[to]==0){
            dfs(to,v,adj,in_time,low_time,dfs_tree,timer);
            low_time[v]=min(low_time[v],low_time[to]);
            ll is_bridge=0;

            if(low_time[to]>in_time[v]){
                is_bridge=1;
            }

            dfs_tree[v].push_back({to,is_bridge});

        }else{
            low_time[v]=min(low_time[v],low_time[to]);
        }
    }
}

ll dfs_sol(ll v,ll p,vector<vector<arr<ll,2> > >&dfs_tree,ll n,ll &ans){

    ll subtree_size=1;

    for(auto to:dfs_tree[v]){
        ll nx=to[0];
        ll bridge=to[1];
        if(nx==p){
            continue;
        }else{
            ll sz=dfs_sol(nx,v,dfs_tree,n,ans);
            if(bridge)ans=max(ans,sz*(n-sz));
            subtree_size+=sz;
        }
    }

    return subtree_size;

}
void solve(ll tc){
    //finding bridge edges 
    ll n,m;
    cin>>n>>m;
    vector<vector<ll> > adj(n+1);
    vector<vector<arr<ll,2> > > dfs_tree(n+1);
    vector<ll> in_time(n+1,0),low_time(n+1,0);

    ll x,y;
    for(ll i=1;i<=m;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ll timer=0;
    dfs(1,-1,adj,in_time,low_time,dfs_tree,timer);

    ll ans=0;
    dfs_sol(1,-1,dfs_tree,n,ans);

    cout<<(n*n-n)/2ll-ans<<endl;



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