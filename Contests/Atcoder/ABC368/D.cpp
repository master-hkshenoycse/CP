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
ll dfs(ll v,ll p,ll &lca,vector<vector<ll> >&adj,vector<ll> &mark,ll req){
    ll ret=0;
    ret+=mark[v];

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        ret+=dfs(to,v,lca,adj,mark,req);
    }

    if(ret==req and lca==-1){
        lca=v;
    }

    return ret;
}

ll get_sol(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &mark){
    ll ret=0;
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }

        ret+=get_sol(to,v,adj,mark);

    }

    if(ret>0 or mark[v]>0){
        ret++;
    }

    return ret;
}
void solve(ll tc){
    ll n,k;
    cin>>n>>k;

    vector<vector<ll> > adj(n+1);
    ll x,y;
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ll v;
    vector<ll> mark(n+1,0);
    for(ll i=1;i<=k;i++){
        cin>>v;
        mark[v]=1;
    }

    ll lca_req=-1;
    dfs(1,-1,lca_req,adj,mark,k);
    //cout<<lca_req<<endl;

    
    cout<<get_sol(lca_req,-1,adj,mark)<<endl;



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