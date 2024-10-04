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
void bfs(ll st,vector<ll> &vis,vector<ll> &value,vector<vector<pair<ll,ll> > > &adj){
    queue<ll> q;
    vis[st]=1;

    q.push(st);

    while(q.size()>0){
        ll v=q.front();
        q.pop();

        for(auto to:adj[v]){
            ll nx=to.first;
            ll wt=to.second;
            if(vis[nx]==0){
                vis[nx]=1;
                value[nx]=value[v]+wt;
                q.push(nx);
            }
        }
    }
    
}   
void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<vector<pair<ll,ll> > > adj(n+1);
    ll x,y,w;
    for(ll i=1;i<=m;i++){
        cin>>x>>y>>w;
        adj[x].pb({y,w});
        adj[y].pb({x,-w});
    }

    vector<ll> vis(n+1);
    vector<ll> value(n+1,0);

    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            bfs(i,vis,value,adj);
        }
    }

    for(ll i=1;i<=n;i++){
        cout<<value[i]<<" ";
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}