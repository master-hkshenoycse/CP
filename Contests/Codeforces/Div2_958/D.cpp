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
void dfs(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &a,vector<vector<ll> >&dp){

    for(ll i=1;i<=20;i++){
        dp[v][i]=i*a[v];
    }

    for(auto to:adj[v]){

        if(to==p){
            continue;
        }

        dfs(to,v,adj,a,dp);

        vector<ll> tmp;
        for(ll i=1;i<=20;i++){
            tmp.push_back(dp[to][i]);
        }

        for(ll i=1;i<20;i++){
            tmp[i]=min(tmp[i],tmp[i-1]);
        }
        

        ll suff_min=8e18;
        for(ll i=20;i>=1;i--){
            ll min_extra=suff_min;
            if(i>1){
                min_extra=min(min_extra,tmp[i-2]);
            }

            dp[v][i]+=min_extra;
            
            suff_min=min(suff_min,dp[to][i]);

        }
    }
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n+1);
    vector<vector<ll> > adj(n+1);
    vector<vector<ll> > dp(n+1,vector<ll> (21,0));
    //dp[v][i]= the value if the vertex v is removed in ith round
    //total loss is a[i]*b[i],where b[i]= round in which it is removed.
    //as adjacent items can;t be picked in same round, round number will differ.
    //due to max set The "independent set" constraint ,the upper bound will be around 19 
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    ll x,y;
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,-1,adj,a,dp);

    ll ans=8e18;
    for(ll i=1;i<=20;i++){
        ans=min(ans,dp[1][i]);
    }

    cout<<ans<<endl;


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