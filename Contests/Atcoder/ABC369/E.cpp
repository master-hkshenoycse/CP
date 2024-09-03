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
ll get_distance(ll n,vector<vector<pair<ll,ll> > >&adj,vector<vector<ll> >&bridges,map<ll,ll> &bridge_mapping){
    ll sz=bridge_mapping.size();
    vector<vector<ll> > dp(n+1,vector<ll> (1<<sz,1e18));

    dp[1][0]=0;
    set<vector<ll>  > s;
    s.insert({0,0,1});

    while(s.size()>0){
        ll v=(*s.begin())[2];
        ll mask=(*s.begin())[1];
        ll d=(*s.begin())[0];
        s.erase(s.begin());

        if(d> dp[v][mask]){
            continue;
        }

        if(v==n and mask==(1<<sz)-1){
            return dp[v][mask];
        }

        for(auto to:adj[v]){
            ll nx=to.first;
            ll b_no=to.second;
            ll n_mask=mask;

            if(bridge_mapping.find(b_no) != bridge_mapping.end()){
                n_mask=(n_mask | (1<<bridge_mapping[b_no]));
            }
            
            ll n_d=d+bridges[b_no][2];

            if(n_d < dp[nx][n_mask]){
                //cout<<nx<<" "<<n_mask<<endl;
                dp[nx][n_mask]=n_d;
                s.insert({dp[nx][n_mask],n_mask,nx});
            }
        }
    }

    return dp[n][(1<<sz)-1];

}
void solve(ll tc){

    ll n,m;
    cin>>n>>m;
    vector<vector<ll> > bridges(m+1);
    vector<vector<pair<ll,ll> > > adj(n+1);

    ll u,v,t;
    for(ll i=1;i<=m;i++){
        cin>>u>>v>>t;
        bridges[i]={u,v,t};
        adj[u].pb({v,i});
        adj[v].pb({u,i});
    }

    ll q;
    cin>>q;

    while(q--){

        ll k;
        cin>>k;

        ll e;
        map<ll,ll> bridge_mapping;

        for(ll i=0;i<k;i++){
            cin>>e;
            bridge_mapping[e]=i;
        }   

        cout<<get_distance(n,adj,bridges,bridge_mapping)<<endl;
    }

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