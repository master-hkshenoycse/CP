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
ll mod = 998244353;
ll fact[200005],inv_fact[200005];
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
void pre_cum(){
    fact[0]=1;
    inv_fact[0]=1;
    for(ll i=1;i<=200000;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv_fact[i]=modpow(i,mod-2);
    }

}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    
    sort(a.begin(),a.end());

    ll ans = 0;
    ll suffix = a[n - 1];

    for (int i = n - 2; i >= 0; i--) {

        ll choices = n - i - 1;

        ll edgeSum =
            (suffix - choices % mod * (a[i] % mod)) % mod;

        if (edgeSum < 0)
            edgeSum += mod;

        // Number of ways to choose the remaining parents
        ll ways =
            (fact[n - 1] * inv_fact[choices]) % mod;

        ans = (ans + edgeSum * ways) % mod;

        suffix += a[i];
        suffix %= mod;
    }

    cout << ans << endl;

}
    
int main(){
    boost;

    pre_cum();
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