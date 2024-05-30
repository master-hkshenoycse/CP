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


void dfs_dist(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &dist){
    if(p>=1){
        dist[v]=dist[p]+1;
    }

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        dfs_dist(to,v,adj,dist);
    }
}

void dfs(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &depth){
    
    depth[v]=0;
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }

        dfs(to,v,adj,depth);
        depth[v]=max(depth[v],depth[to]+1);
    }
}

void dfs_dp(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &depth,ll prev){
    depth[v]=max(depth[v],prev);

    vector<ll> pref_depth,suff_depth;

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        pref_depth.push_back(depth[to]+2);
        suff_depth.push_back(depth[to]+2);
    }

    ll sz=pref_depth.size();
    for(ll i=1;i<sz;i++){
        pref_depth[i]=max(pref_depth[i-1],pref_depth[i]);
    }

    for(ll i=sz-2;i>=0;i--){
        suff_depth[i]=max(suff_depth[i],suff_depth[i+1]);
    }


    ll c=0;
    for(auto to:adj[v]){

        if(to==p){
            continue;
        }
        ll nx_prev=prev+1;
        if(c-1>=0){
            nx_prev=max(nx_prev,pref_depth[c-1]);
        }

        if(c+1<sz){
            nx_prev=max(nx_prev,suff_depth[c+1]);
        }

        dfs_dp(to,v,adj,depth,nx_prev);

        c++;

    }
}
void solve(ll tc){

    ll n;
    cin>>n;
    vector<vector<ll> > adj(n+1);

    ll a,b;
    cin>>a>>b;

    vector<ll> dist_a(n+1),dist_b(n+1);
    vector<ll> max_depth(n+1);

    ll x,y;
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);

    }

    dist_a[a]=0;
    dfs_dist(a,-1,adj,dist_a);

    dist_b[b]=0;
    dfs_dist(b,-1,adj,dist_b);

    dfs(1,-1,adj,max_depth);
    dfs_dp(1,-1,adj,max_depth,0);

    ll ans=1e9;

    //brute force over all the vertex
    //max depth will not be traversed twice. else all will travlled twice
    for(ll i=1;i<=n;i++){

        ll extra=0;
        if(dist_a[i]<=dist_b[i]){
            extra=dist_b[i];
        }else{
            if((dist_a[i]%2) == (dist_b[i]%2)){
                extra=dist_a[i];
            }else{
                extra=1e9;
            }
        }

        //cout<<i<<" "<<extra<<" "<<max_depth[i]<<endl;
        ans=min(ans,extra+2*(n-1)-max_depth[i]);
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