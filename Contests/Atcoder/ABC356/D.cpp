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
ll cnt_set(ll lim,ll p){
    ll period=(1ll<<(p+1));
    ll in_each=(1ll<<p);
    ll tot_periods=lim/period;
    ll cnt=((tot_periods%mod)*(in_each%mod))%mod;
    ll rem=lim%period;
    cnt+=max(0ll,rem-in_each+1);
    return cnt%mod;
}
void solve(ll tc){
    ll ans=0;
    ll n,m;
    cin>>n>>m;


    //counting set bits contribution at each index
    for(ll i=0;i<=60;i++){
        if(m & (1ll<<i)){
            ans=ans+cnt_set(n,i);
            ans%=mod;
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