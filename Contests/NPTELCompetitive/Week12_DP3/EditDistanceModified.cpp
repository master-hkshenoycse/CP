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
    ll n,m,a,x,y,z;
    string p,q;
    cin>>n>>m>>a>>x>>y>>z;


    //upto x changes dollar y then dollar z

    cin>>p>>q;

    vector<vector<ll> > dp(n+1,vector<ll> (m+1,3e18));
    dp[0][0]=0;

    for(ll i=0;i<=m;i++){
        dp[i][0]=i;//i deleteions
    }

    for(ll i=0;i<=n;i++){
        dp[0][i]=i;//i insertions
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            
            dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
            if(p[i-1]==q[j-1]){
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            }
            
        }
    }   

    ll cost=min(x,dp[n][m])*y;
    if(dp[n][m]>x){
        cost=cost+(dp[n][m]-x)*z;
    }

    cout<<a-cost<<endl;

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