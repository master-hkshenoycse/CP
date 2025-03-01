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

//sequence shoudl be of form 12\1+3.
void solve(ll tc){
    ll n;
    cin>>n;
    
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    vector<ll> c2(n+1,0);
    for(ll i=1;i<=n;i++){
        c2[i]=(c2[i-1]+(a[i]==2));
    }

    ll suff_value=0,suff_cnt=0;
    ll ans=0;

    for(ll i=n;i>=1;i--){
        if(a[i]==3){
            suff_value=(suff_value + modpow(2,c2[i]))%mod;
            suff_cnt++;
        }else if(a[i]==1){
           
            ll den=modpow(modpow(2,c2[i]),mod-2);
            //cout<<i<<" "<<suff_value<<" "<<den<<endl;
            ll ex=(den * suff_value-suff_cnt+mod)%mod;
            ans=(ans+ex)%mod;
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
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}
