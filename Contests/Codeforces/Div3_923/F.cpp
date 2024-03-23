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
    if(v==par[v]){
        return v;
    }
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

}

void dfs(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &par){
    par[v]=p;

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        dfs(to,v,adj,par);
    }
}


void solve(ll tc){ 
    ll n,m;
    cin>>n>>m;
   

    vector<vector<ll> > edges(m,vector<ll> (3));
    vector<ll> par(n+1,-1),sz(n+1,1);

    for(ll i=1;i<=n;i++){
        par[i]=i;
    }

    for(ll i=0;i<m;i++){
        cin>>edges[i][1]>>edges[i][2]>>edges[i][0];
    }

    sort(all(edges));
    reverse(all(edges));


    vector<vector<ll> >adj(n+1);
    vector<ll> sol;

    ll b;
    ll ans_x=-1,ans_y=-1;

    for(auto e:edges){
        ll x=e[1];
        ll y=e[2];
        

        if(dsu(x,y,par,sz)==0){
            b=e[0];
            ans_x=x;
            ans_y=y;
        }else{
            adj[x].pb(y);
            adj[y].pb(x);
        }
    }

    dfs(ans_x,-1,adj,par);

    while(ans_y != -1){
        sol.pb(ans_y);
        ans_y=par[ans_y];
    }

    cout<<b<<" "<<sol.size()<<endl;
    for(auto s:sol){
        cout<<s<<" ";
    }
    cout<<endl;




    


}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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