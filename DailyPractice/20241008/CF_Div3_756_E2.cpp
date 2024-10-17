/*https://codeforces.com/contest/1278/problem/D*/
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
ll dfs(ll v,ll p,ll d,vector<ll> &nearest,vector<vector<ll> >&adj){
    ll c=0,f=1;
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }

        ll r=dfs(to,v,d+1,nearest,adj);
        c=c+r;
        if(r<0){
            f=0;
        }

        nearest[v]=min(nearest[v],nearest[to]+1);
    }

    if(nearest[v]<=d){
        return 1;
    }

    if(c==0 or f==0){
        return -1;
    }

    return c;
}
void solve(ll tc){
    string s;
    getline(cin,s);

    ll n,k;
    cin>>n>>k;

    

    vector<ll> nearest(n+1,1e9);
    vector<vector<ll> > adj(n+1);

    ll e;
    for(ll i=1;i<=k;i++){
        cin>>e;
        nearest[e]=0;
    }

    ll u,v;
    for(ll i=1;i<n;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll res=dfs(1,-1,0,nearest,adj);

    cout<<res<<endl;

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