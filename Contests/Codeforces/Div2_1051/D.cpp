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
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    vector<vector<ll> > dp(n+1,vector<ll> (2,0));
    ll ans=0;
    for(ll i=1;i<=n;i++){
        
        dp[i][0]=1;//subseuence of length 1.

        for(ll j=1;j<i;j++){
            if(a[i]<a[j]){
                dp[i][1]=(dp[i][1]+dp[j][0])%mod;
            }else{
                dp[i][0]=(dp[i][0]+dp[j][0])%mod;
                dp[i][1]=(dp[i][1]+dp[j][1])%mod;
            }
        }

        ans=(ans+dp[i][0]+dp[i][1])%mod;
        
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