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
string g[25],w[25];
ll is_compatible[25][25];
ll solve_dp(ll mask,ll prev,ll n,vector<vector<ll> > &dp){
    if(mask==n){
        return 0;
    }

    if(dp[mask][prev] != -1){
        return dp[mask][prev];
    }

    ll res=0;
    for(ll i=0;i<n;i++){
        if(mask  & (1<<i)){
            continue;
        }

        if(is_compatible[prev][i]){
            res=max(res,1+solve_dp(mask|(1<<i),i,n,dp));
        }

    }

    return dp[mask][prev]=res;

    
}
void solve(ll tc){ 
    ll n;
    cin>>n;

    //dp with bitmasks
    for(ll i=0;i<n;i++){
        cin>>g[i]>>w[i];
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(j==i){
                continue;
            }

            if(g[i]==g[j] or w[i]==w[j]){
                is_compatible[i][j]=1;
            }else{
                is_compatible[i][j]=0;
            }
        }
    }

    ll lim=(1<<n);
    vector<vector<ll> > dp(lim,vector<ll> (n,-1));
    

    ll ans=0;
    for(ll i=0;i<n;i++){
        ans=max(ans,1+solve_dp(1<<i,i,n,dp));
    }

    cout<<n-ans<<endl;







}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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