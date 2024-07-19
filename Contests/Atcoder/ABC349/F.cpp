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
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
void solve(ll tc){

    
    ll n,m;
    cin>>n>>m;
    
    ll e,count_one=0;
    ll og_m=m;

    vector<ll> factors;
    for(ll i=2;i*i<=m;i++){
        if(m%i==0){
            ll val=1;
            while(m%i==0){
                m/=i;
                val=val*i;
            }
            factors.push_back(val);
        }

    }

    if(m>1){
        factors.push_back(m);
    }
    ll sz=factors.size();

    vector<ll> cnt_factor((1<<sz),0);

    for(ll i=1;i<=n;i++){
        cin>>e;

        if(og_m%e){
            continue;
        }


        if(e==1){
            count_one++;
        }else{
            ll mask=0;
            for(ll j=0;j<sz;j++){
                if(e%factors[j]==0){
                    e/=factors[j];
                }
            }   
        }
    }




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