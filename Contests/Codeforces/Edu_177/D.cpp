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
ll fact[500005];
ll inv_fact[500005];
ll mod=998244353;
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res*a)%mod;
        }
        n/=2;
        a=(a*a)%mod;
    }
    return res;
}
void pre_cum(){
    fact[0]=1;
    inv_fact[0]=1;

    for(ll i=1;i<=500000;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv_fact[i]=modpow(fact[i],mod-2);
    }
}
void solve(ll tc){
    vector<ll> cnt; 
    ll e,s=0;
    for(ll i=1;i<=26;i++){
        cin>>e;
        if(e>0){
            s+=e;
            cnt.pb(e);
        }
        
    }

    sort(all(cnt));
    reverse(all(cnt));

    ll sz=cnt.size();
    ll lim=(1<<sz);

    ll od_index=(s+1)/2ll;
    ll ev_index=s-od_index;
    ll ans=0;

    for(ll i=0;i<lim;i++){
        ll cnt_od=0;
        ll od_perms=fact[od_index];
        ll ev_perms=fact[ev_index];

        for(ll j=0;j<sz;j++){
            if(i & (1ll<<j)){
                cnt_od+=cnt[j];
                od_perms=(od_perms * inv_fact[cnt[j]])%mod;
            }else{
                ev_perms=(ev_perms * inv_fact[cnt[j]])%mod;
            }
            if(cnt_od > od_index){
                break;
            }
        }

        if(cnt_od==od_index){
            od_perms = (od_perms * ev_perms)%mod;
            ans=(ans+od_perms)%mod;
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