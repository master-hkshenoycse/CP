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
void dfs(ll v,vector<vector<ll> >&adj,vector<ll> &vis,ll c){
    vis[v]=c;
    for(auto to:adj[v]){
        if(vis[to]==0){
            dfs(to,adj,vis,c);
        }
    }
}
void solve(ll tc){
    ll n,m1,m2;
    cin>>n>>m1>>m2;

    vector<vector<ll> > adj_g(n+1),adj_f(n+1);
    vector<arr<ll,2> > edges_f;
    vector<ll> vis_g(n+1,0),vis_f(n+1,0);    

    ll x,y;
    for(ll i=1;i<=m1;i++){
        cin>>x>>y;
        edges_f.pb({x,y});
    }

    for(ll i=1;i<=m2;i++){
        cin>>x>>y;
        adj_g[x].pb(y);
        adj_g[y].pb(x);
    }

    ll c=0;
    for(ll i=1;i<=n;i++){
        if(vis_g[i]==0){
            c++;
            dfs(i,adj_g,vis_g,c);
        }
    }   

    ll ans=0;

    for(auto e:edges_f){
        if(vis_g[e[0]]==vis_g[e[1]]){
            adj_f[e[0]].push_back(e[1]);
            adj_f[e[1]].push_back(e[0]);
        }else{
            
            ans++;
        }
    }


    ll c_f=0;
    for(ll i=1;i<=n;i++){
        if(vis_f[i]==0){
            c_f++;
            dfs(i,adj_f,vis_f,c_f);
        }
    }  



    cout<<ans+c_f-c<<endl;
    
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