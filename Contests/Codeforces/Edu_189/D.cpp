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
ll prefix_xor(ll n){
    ll r=(n%4);
    if(r==0) return n;
    if(r==1) return 1;
    if(r==2) return n+1;
    return 0;
}
ll get_cnt(ll ft,ll cd,ll lim){
    if(lim<ft) return 0;
    return (lim-ft)/cd+1;
}

map<ll,ll> get_pref_cnt(ll st,ll lim){
    map<ll,ll> ret;
    for(ll i=0;i<4;i++){
        ret[(st+i)%4]=get_cnt(st+i,4,lim);
    }
    return ret;
}
void solve(){
    ll n,x;
    cin>>n>>x;  
    ll cnt=0;

    map<ll,ll> cnt_prefix=get_pref_cnt(1,x-1);
    map<ll,ll> cnt_suffix=get_pref_cnt(x,n);
    cnt_prefix[3]++;

   
    ll ret=0;
    ret=((cnt_suffix[1]%mod)*(cnt_prefix[1]%mod))%mod;
    ret=(ret+((cnt_suffix[3]%mod)*(cnt_prefix[3]%mod)%mod))%mod;
    cout<<ret<<endl;
}
int main(){
 boost;

    //pre_cum();
    //prec(10);
	//fre;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}