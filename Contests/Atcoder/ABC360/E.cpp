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
        n/=2;
        a=(a*a)%mod;
    }
    return res;
}
void solve(ll tc){

    ll p_1=1,p_other=0;
    ll n,k;
    cin>>n>>k;

    ll n_1=modpow(n,mod-2);
    ll nn_1=modpow((n*n)%mod,mod-2);

    if(n==1){
        cout<<1<<endl;
        return;
    }

    //probablity of 1 is different to others after every step
    
    ll sum_others=(n*n+n)/2ll-1;
    sum_others%=mod;
    for(ll i=1;i<=k;i++){
        
        ll n_p1=0;

        ll curr_prob;
        //x=1 y=1
        curr_prob=(p_1*nn_1)%mod;
        n_p1=(n_p1+curr_prob)%mod;

        //x!=1 y=j, j!=1
        curr_prob=(p_1*nn_1)%mod;
        curr_prob=(curr_prob * (n-1))%mod;
        curr_prob=(curr_prob * (n-1))%mod;
        n_p1=(n_p1+curr_prob)%mod;            


        //below will be summed from j=2 to n
        //x=1 y=j, j!=1
        //x=j y=1 j!=1
        curr_prob=(p_other*(n-1))%mod;
        curr_prob=(curr_prob*(nn_1))%mod;
        curr_prob=(curr_prob*2)%mod;

        n_p1=(n_p1+curr_prob)%mod;

        p_1=n_p1;
        p_other=(1-p_1+mod)%mod;
        p_other=(p_other*modpow(n-1,mod-2))%mod;
    





    }

    ll ans=p_1+(p_other*sum_others)%mod;
    ans%=mod;


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