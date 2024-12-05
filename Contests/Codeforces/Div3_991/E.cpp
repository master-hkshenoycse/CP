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
ll solve_dp(ll a_ind,ll b_ind,vector<vector<ll> >&dp,string &a,string &b,string &c){
    if(a_ind==a.size() and b_ind==b.size()){
        return 0;
    }

    if(dp[a_ind][b_ind]!=-1){
        return dp[a_ind][b_ind];
    }

    ll ret=1e9;
    ll c_ind=a_ind+b_ind;

    if(a_ind < a.size()){
        ret=min(ret,(c[c_ind] != a[a_ind])+solve_dp(a_ind+1,b_ind,dp,a,b,c));
    }

    if(b_ind < b.size()){
        ret=min(ret,(c[c_ind] != b[b_ind])+solve_dp(a_ind,b_ind+1,dp,a,b,c));
    }

    return dp[a_ind][b_ind]=ret;
}
void solve(ll tc){
    
    string a,b,c;
    cin>>a>>b>>c;

    ll n=a.size(),m=b.size();
    vector<vector<ll> > dp(n+1,vector<ll> (m+1,-1));
    cout<<solve_dp(0,0,dp,a,b,c)<<endl;

    
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