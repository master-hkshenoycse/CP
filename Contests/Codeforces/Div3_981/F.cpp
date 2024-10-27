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
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res * a)%mod;
        }
        a=(a * a)%mod;
        n/=2;
    }
    return res;
}
void solve(ll tc){

    ll n,k;
    cin>>n>>k;

    //pissano period
    vector<ll> rem;
    rem.pb(1%k);
    rem.pb(1%k);

    while(1){
        rem.pb((rem[rem.size()-1]+rem[rem.size()-2])%k);
        if(rem.back()==rem[1] and rem[rem.size()-2]==rem[0]){
            break;
        }
    }
    rem.pop_back();
    rem.pop_back();
    ll period=rem.size();
    vector<ll> rem_0;

    for(ll i=0;i<period;i++){
        if(rem[i]==0){
            rem_0.pb(i);
        }
    }
    n--;

    ll cnt=rem_0.size();
    ll full_periods=n/cnt;
    ll ex=rem_0[n%cnt];

    ll ans=((full_periods%mod) * (period))%mod;
    ans=ans+ex;
    ex%=mod;
    ans=(ans+1)%mod;

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