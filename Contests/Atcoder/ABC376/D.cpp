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
void dfs1(ll v,vector<vector<ll> >&adj,vector<ll> &vis,vector<ll> &dfs_order){
    vis[v]=1;
    

    for(auto to:adj[v]){
        if(vis[to]==0){
            dfs1(to,adj,vis,dfs_order);
        }
    }


    dfs_order.pb(v);

    
}

void dfs2(ll v,vector<vector<ll> >&adj,vector<ll> &vis,vector<ll> &sz_arr){
    vis[v]=sz_arr.size();
    sz_arr.back()++;
    cout<<v<<" ";
    

    for(auto to:adj[v]){
        if(vis[to]==0){
            dfs2(to,adj,vis,sz_arr);
        }
    }
}
void solve(ll tc){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll> >adj(n+1);
    vector<vector<ll> >r_adj(n+1);
    vector<ll> vis(n+1,0),dfs_order;

    ll x,y;
    set<ll> is_conn;
    for(ll i=1;i<=m;i++){
        cin>>x>>y;
        adj[x].pb(y);
        if(y==1){
            is_conn.insert(x);
        }

    }

    vector<ll> dis(n+1,1e9);
    dis[1]=0;
    queue<ll> q;

    q.push(1);
    while(q.size()>0){
        ll v=q.front();
        q.pop();
        for(auto to:adj[v]){
            if(dis[to]>dis[v]+1){
                q.push(to);
                dis[to]=dis[v]+1;
            }
        }

    }

    ll ans=n+1;
    for(ll i=2;i<=n;i++){
        if(dis[i]<1e9 and is_conn.find(i) != is_conn.end()){
            ans=min(ans,dis[i]+1);
        }
    }

    if(ans>n){
        ans=-1;
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}