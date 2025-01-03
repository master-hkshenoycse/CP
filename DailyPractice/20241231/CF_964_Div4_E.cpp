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
ll fact[200005],inv_fact[200005];
ll mod=1e9+7;
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res * a)%mod;
        }
        n/=2;
        a=(a*a)%mod;
    }
    return res;
}
void pre_cum(){
    fact[0]=1;
    inv_fact[0]=1;

    for(ll i=1;i<=200000;i++){
        fact[i]=(fact[i-1] * i)%mod;
        inv_fact[i]=modpow(fact[i],mod-2);
    }
}

ll ncr(ll n,ll r){
    if(r>n){
        return 0;
    }

    ll ret=fact[n];
    ret=(ret * inv_fact[r])%mod;
    ret=(ret * inv_fact[n-r])%mod;
    return ret;
}
void solve(ll tc){
    ll n,k;
    cin>>n>>k;


    ll e,c1=0,c0=0;
    for(ll i=1;i<=n;i++){
        cin>>e;
        c1+=e;
        c0+=1-e;
    }

    ll ans=0;
    for(ll i=1;i<=k;i++){
        if(i > k-i){
            ans=ans+ncr(c1,i)*ncr(c0,k-i);
            ans%=mod;
        }
    }

    cout<<ans<<endl;
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