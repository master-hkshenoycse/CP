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
ll solve_dp(ll ind,ll extra_moves,vector<ll> &a,vector<vector<ll> >&dp){
    if(ind==a.size()){
        return 0;
    }

    if(dp[ind][extra_moves] != -1){
        return dp[ind][extra_moves];
    }

    ll res=solve_dp(ind+1,extra_moves+1,a,dp);

    if(extra_moves-a[ind]>=0){
        res=max(res,1+solve_dp(ind+1,extra_moves-a[ind],a,dp));
    }

    return dp[ind][extra_moves]=res;
}
void solve(ll tc){
    ll n,e;
    cin>>n;

    map<ll,ll> freq;
    vector<ll> a;

    for(ll i=0;i<n;i++){
        cin>>e;
        freq[e]++;
    }

    for(auto it:freq){
        a.push_back(it.ss);
    }

    n=a.size();
    vector<vector<ll>  > dp(n+2,vector<ll> (n+2,-1));
    //cuurently on index i,and j extra moves available,maximum possible elements that can be removed by B

    cout<<n-solve_dp(0,0,a,dp)<<endl;



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