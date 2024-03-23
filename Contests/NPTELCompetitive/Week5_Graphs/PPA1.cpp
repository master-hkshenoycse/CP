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

ll dfs(ll v,ll p,vector<vector<ll> >&adj){
    

    ll ma=0;
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        ma=max(ma,dfs(to,v,adj));
    }

    return ma+1;
}
void solve(ll tc){ 
    ll n;
    cin>>n;

    vector<vector<ll> > adj(n+1);
    vector<ll> roots;
    ll p;

    for(ll i=1;i<=n;i++){
        cin>>p;
        if(p==-1){
            roots.pb(i);
        }else{
            adj[i].pb(p);
            adj[p].pb(i);
        }
    }

    ll ans=0;
    for(auto r:roots){
        ans=max(ans,dfs(r,-1,adj));
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}