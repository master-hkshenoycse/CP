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
ll fact[300005];
ll inv_fact[300005];
ll mod=1e9+7;
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

    for(ll i=1;i<=300000;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv_fact[i]=modpow(fact[i],mod-2);
    }

}

ll ncr(ll n,ll r){
    if(r==0){
        return 1;
    }
    if(n==r){
        return 1;
    }

    ll ans=fact[n];
    ans=(ans * inv_fact[r])%mod;
    ans=(ans * inv_fact[n-r])%mod;

    return ans;
}
void solve(ll tc){
    
    //out of all rows and columns remaining
    //assume m rows and columns are remainning,
    //x (r,c) pair are such that ruch that (r!=c), remiaing have r=c
    //total combination is C(2x,x)*x! ways to choose 2x number from m is C(m,2*x);
    //summing x from 0 to all possible even numbers <= m/2  C(m,2x)*C(2x,x)*x!

    ll ans=0;
    
    ll n,m;
    cin>>n>>m;
    vector<ll> is_used(n+1,0);

    ll x,y;
    for(ll i=1;i<=m;i++){
        cin>>x>>y;
        is_used[x]++;
        is_used[y]++;
    }
    
    ll rem=0;
    for(ll i=1;i<=n;i++){
        if(is_used[i]==0){
            rem++;
        }
    }

    for(ll i=0;i<=rem;i+=2){
        ll total_non_diag=i;
        ll to_choose=i/2;

        ll ways_to_make_pair=(ncr(total_non_diag,to_choose)*fact[to_choose])%mod;
        ll ways_to_choose=ncr(rem,i);

        ans=ans+(ways_to_choose*ways_to_make_pair);
        ans%=mod;
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