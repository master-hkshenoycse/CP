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
ll mod=998244353;
void solve(ll tc){
    ll n;
    cin>>n;
    ll tot=0;

    vector<ll> a(n);

    for(ll i=0;i<n;i++){
        cin>>a[i];
        tot+=a[i];
    }

    sort(all(a));

    
    ll ans=0;

    vector<ll> dp(tot+1,0);
    dp[0]=1;


    for(auto e:a){


        for(ll j=0;j<=tot;j++){
            ll val=(j+e+1)/2ll;//if e is included in set the value will be
            if(e>j){
                val=e;
            }

            ans=(ans+val*dp[j]);//number of subsets for value given e is added
            ans%=mod;
        }

        for(ll j=tot;j>=0;j--){
            if(j+e<=tot){
                dp[j+e]=(dp[j+e]+dp[j])%mod;
            }
        }

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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}