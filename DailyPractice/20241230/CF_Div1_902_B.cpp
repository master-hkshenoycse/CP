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
        a=(a* a)%mod;
    }
    return res;
}

void solve(ll tc){


    ll n;
    cin>>n;

    vector<ll> a(n+1);
    map<ll,ll> highest_fac;


    for(ll i=1;i<=n;i++){
        cin>>a[i];

        for(ll j=1;j*j<=i;j++){
            if(i%j==0){
                highest_fac[j]=max(highest_fac[j],a[i]);
                highest_fac[i/j]=max(highest_fac[i/j],a[i]);
            }
        }

    }

    

    /*ll lim = (1ll<<n);  
    map<ll,ll> cnt_val;
    ll s=0;
    
    for(ll i=0;i<lim;i++){

        ll ma=-1;

        for(ll j=0;j<n;j++){
            if(i & (1ll<<j)){
                ma=max(ma,highest_fac[j+1]);
                ma=max(ma,a[j+1]);
            }
        } 

        if(ma != -1){
            cnt_val[ma]++;
        }

    }


    for(auto it:cnt_val){
        cout<<it.ff<<" "<<it.ss<<endl;
        s=s+(it.ff * it.ss);
        s%=mod;
    }

    cout<<s<<endl;
    cout<<endl;
    */



    map<ll,ll> cnt_poss;

    for(ll i=1;i<=n;i++){
        cnt_poss[highest_fac[i]]++;    
    }

    ll curr_ways=1;
    ll ans=0;
    for(auto it:cnt_poss){
        ll val=it.ff;
        ll ways=(modpow(2,it.ss)-1)%mod;
        ways=(ways+mod)%mod;

        ways=(ways*curr_ways)%mod;

        //cout<<val<<" "<<it.ss<<" "<<ways<<endl;
        ans=ans+(val*ways);
        ans%=mod;


        curr_ways=curr_ways*modpow(2,it.ss);
        curr_ways%=mod;

        
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