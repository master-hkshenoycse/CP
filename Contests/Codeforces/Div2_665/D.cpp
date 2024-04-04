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
ll mod=1e9+7;
ll dfs(ll v,ll p,ll n,vector<vector<ll> >&adj,vector<ll> &edges_contri){
    ll cnt=1;

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }

        ll y=dfs(to,v,n,adj,edges_contri);
        edges_contri.pb(y*(n-y));
        cnt+=y;
    }

    return cnt;

}
void solve(ll tc){ 
    
    ll n;
    cin>>n;
    vector<vector<ll> > adj(n+1);
    vector<ll> edges_contri;

    ll x,y;
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
        
    }

    dfs(1,-1,n,adj,edges_contri);

    //sort the edges by their contribution
    sort(all(edges_contri));
    

    ll e,m;
    cin>>m;

    vector<ll> vals(m);
    for(ll i=0;i<m;i++){
        cin>>vals[i];
    }
    sort(all(vals));
    while(vals.size()>n-1){
        ll ls=vals.back();
        vals.pop_back();
        vals.back()=(vals.back() * ls)%mod;
    }

    //give the  value of max contribution to max multiolaction

    ll ans=0;
    while(edges_contri.size()>0){
        ll p=1;
        if(vals.size()>0){
            p=vals.back();
            vals.pop_back();
        }
        
        ans=ans+(p*edges_contri.back());
        edges_contri.pop_back();
        ans%=mod;
    }
    
    cout<<ans<<endl;


   
    
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