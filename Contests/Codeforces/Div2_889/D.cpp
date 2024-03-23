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
ll solve_dp(ll ind ,ll unlock_max,vector<ll> &a,vector<vector<ll> >&dp){
    ll n=a.size();

    if(ind>=n){
        return 0;
    }

    if(unlock_max<ind){
        return 0;
    }


    if(dp[ind][unlock_max]!=-1){
        return dp[ind][unlock_max];
    }

    ll res=0;

    res=max(res,a[ind]+solve_dp(ind+1,unlock_max,a,dp));
    res=max(res,solve_dp(ind+1,min(n,unlock_max+a[ind]),a,dp));

    return dp[ind][unlock_max]=res;

}
void solve(ll tc){ 
    

    ll n;
    cin>>n;

    vector<ll> a(n);
    vector<vector<ll> >dp(n+1,vector<ll> (n+1,-1));

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<solve_dp(0,0,a,dp)<<endl;






}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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