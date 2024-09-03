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
ll fact[1005],inv_fact[1005];
ll modpow(ll a,ll n,ll p){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res*a)%p;
        }
        n/=2;
        a=(a*a)%p;
    }
    return res;
}
ll get_ncr(ll n,ll r,ll p){
    ll num=fact[n];
    ll den=(inv_fact[r]*inv_fact[n-r])%p;
    num=(num * den)%p;
    return num;
}

ll solve_dp(ll level,ll sum,ll eq_allow,ll p,vector<vector<vector<ll> > >&dp){
    
    
    if(sum==0 or level==1){
        return 1;
    }



    if(dp[level][sum][eq_allow] != -1){
        return dp[level][sum][eq_allow];
    }

    ll res=0;

    for(ll j=0;j<=sum;j++){
        ll new_sum=sum-j;
        for(ll i=0;i<=new_sum;i++){

            if(eq_allow){
                res=(res + solve_dp(level-1,i,eq_allow,p,dp)*solve_dp(level-1,new_sum-i,eq_allow,p,dp))%p;
            }else{
                if(i!=new_sum-i){
                    if(i>new_sum-i){
                        res=(res + solve_dp(level-1,i,0,p,dp)*solve_dp(level-1,new_sum-i,1,p,dp))%p;
                    }else{
                        res=(res + solve_dp(level-1,i,1,p,dp)*solve_dp(level-1,new_sum-i,0,p,dp))%p;
                    }
                }
            }   
        }
    }

    return dp[level][sum][eq_allow]=res;
    
}
void solve(ll tc){
    ll n,k,p;
    cin>>n>>k>>p;
    
    fact[0]=1;
    inv_fact[0]=1;
    for(ll i=1;i<=n+k;i++){
        fact[i]=(fact[i-1]*p)%p;
        inv_fact[i]=modpow(fact[i],p-2);
    }


    vector<vector<vector<ll> > > dp(n+1,vector<vector<ll> > (k+1,vector<ll> (2,-1)));

    cout<<solve_dp(n,k,0,p,dp)<<endl;


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