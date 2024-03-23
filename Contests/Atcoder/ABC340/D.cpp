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

void solve(ll tc){ 
    ll n;
    cin>>n;

    vector<pair<ll,ll> > adj[n+1];
    ll a,b,x;

    for(ll i=1;i<=n;i++){
        cin>>a>>b>>x;
        if(i+1<=n){
            adj[i].pb({i+1,a});
        }
        adj[i].pb({x,b});
    }

    vector<ll> dp(n+1,1e18);
    dp[1]=0;
    priority_queue<pair<ll,ll> ,vector<pair<ll,ll> > ,greater<pair<ll,ll> > > pq;
    pq.push({0,1});

    while(pq.size()>0){
        ll v=pq.top().second;
        pq.pop();

        for(auto to:adj[v]){
            ll nx=to.first;
            ll wt=to.second;
            if(dp[nx]>dp[v]+wt){
                dp[nx]=dp[v]+wt;
                pq.push({dp[nx],nx});
            }
        }
    }


    cout<<dp[n]<<endl;




    

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