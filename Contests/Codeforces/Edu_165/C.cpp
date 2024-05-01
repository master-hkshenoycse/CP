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
ll solve_dp(ll ind,ll rem,vector<vector<ll> >&dp,vector<ll> &a){
    if(ind>=a.size()){
        return 0;
    }

    if(dp[ind][rem] != -1){
        return dp[ind][rem];
    }

    ll res=1e18;

    res=min(res,a[ind]+solve_dp(ind+1,rem,dp,a));


    ll mi=a[ind];
    ll ops=1;
    for(ll i=ind+1;i<=ind+rem;i++){
        if(i==a.size()){
            break;
        }
        mi=min(mi,a[i]);
        res=min(res,mi*(ops+1)+solve_dp(i+1,rem-ops,dp,a));
        ops++;
    }

    return dp[ind][rem]=res;
}
void solve(ll tc){

    ll n,k;
    cin>>n>>k;

    vector<vector<ll> > dp(n,vector<ll> (k+1,-1));
    vector<ll> a(n);

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<solve_dp(0,k,dp,a)<<endl;






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