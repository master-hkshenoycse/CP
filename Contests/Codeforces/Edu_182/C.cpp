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
ll MOD = 998244353;
void solve(ll tc){
    ll n;
    cin>>n;
    
    vector<ll> a(n), b(n);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    // dp[i][0]: number of ways up to i, no swap at i
    // dp[i][1]: number of ways up to i, swap at i
    vector<vector<ll>> dp(n, vector<ll>(2, 0));

    // Base case
    dp[0][0] = 1;
    dp[0][1] = 1;
 
    for (int i = 1; i < n; ++i) {
        // No swap at i
        if (a[i] >= a[i-1] && b[i]>=b[i-1]) dp[i][0] = (dp[i][0] + dp[i-1][0]) % MOD;
        if (a[i] >= b[i-1] && b[i]>=a[i-1]) dp[i][0] = (dp[i][0] + dp[i-1][1]) % MOD;
        
        // Swap at i
        if (b[i] >= a[i-1] && a[i]>=b[i-1]) dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
        if (b[i] >= b[i-1] && a[i]>=a[i-1]) dp[i][1] = (dp[i][1] + dp[i-1][1]) % MOD;
        

    }

    ll ans = (dp[n-1][0] + dp[n-1][1]) % MOD;
    cout << ans << endl;
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