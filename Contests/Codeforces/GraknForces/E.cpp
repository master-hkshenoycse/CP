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
ll get_par(ll v,vector<ll> &par){
    if(v==par[v])return v;
    return get_par(par[v],par);
}

ll dsu(ll x,ll y,vector<ll> &par,vector<ll> &sz){
    ll px=get_par(x,par);
    ll py=get_par(y,par);
    if(px==py){
        return 0;
    }

    if(sz[px]>sz[py]){
        swap(px,py);
    }

    par[px]=py;
    sz[py]+=sz[px];
    sz[px]=0;


    return 1;
}
void solve(ll tc){

    ll n,m;
    cin>>m>>n;

    //graph will not contain rainbow cycle if and only if bipartite graph between 
    //i, j dont have cycle
    //bipartite graph will be constructed as if element i is in set j the there will be a ede (i,j)
    //cost of edge will be ai+bj
    //find the maximum spanning tree
    
    vector<ll> cost_sets(m),cost_integer(n);

    for(ll i=0;i<m;i++){
        cin>>cost_sets[i];
    }

    for(ll i=0;i<n;i++){
        cin>>cost_integer[i];
    }

    vector<ll> par(n+m+5),sz(n+m+5,1);
    for(ll i=1;i<=n+m+2;i++){
        par[i]=i;
    }

    ll e,tot_cost=0;
    vector<vector<ll> > edges;
    for(ll i=1;i<=m;i++){
        ll sz;
        cin>>sz;

        while(sz--){
            cin>>e;
            tot_cost+=cost_sets[i-1]+cost_integer[e-1];
            edges.pb({cost_sets[i-1]+cost_integer[e-1],i,e+m});
        }

    }

    sort(all(edges));
    reverse(all(edges));

    ll ans=0;


    for(auto e:edges){
        ll wt=e[0];
        ll x=e[1];
        ll y=e[2];
        if(dsu(x,y,par,sz)){
            ans+=wt;
        }
    }

    cout<<tot_cost-ans<<endl;



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