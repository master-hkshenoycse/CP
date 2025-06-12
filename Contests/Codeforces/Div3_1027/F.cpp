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
ll solve_dp(ll x,vector<ll> &dp,ll k){
    if(x==1){
        return 0;
    }

    if(x<=k){
        return dp[x]=1;
    }

    if(dp[x] != -1){
        return dp[x];
    }

    ll ret=1e9;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            if(i<=k){
                ret=min(ret,1+solve_dp(x/i,dp,k));
            } 
            
            if(x/i<=k){
                ret=min(ret,1+solve_dp(i,dp,k));
            }
        }
    }

    return dp[x]=ret;
}
ll get_ops(ll x,ll k){
    vector<ll> dp(x+1,-1);
    return solve_dp(x,dp,k);
}
void solve(ll tc){
    ll x,y,k;
    cin>>x>>y>>k;
    
    ll gc=__gcd(x,y);
    x/=gc;
    y/=gc;
    
    ll r1=get_ops(x,k);
    ll r2=get_ops(y,k);
    
    if(r1>x ||  r2>y){
        cout<<-1<<endl;
    }else{
        cout<<r1+r2<<endl;
    }
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
