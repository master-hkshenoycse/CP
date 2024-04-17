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
ll dp[205][205][205];

ll solve_dp(ll ind,ll ops_left,ll cnt_f,string &s,string &t){

    if(ind==s.size()){
        return 0;
    }

    if(dp[ind][ops_left][cnt_f] != -1){
        return dp[ind][ops_left][cnt_f];
    }

    ll res=0;

    //dont do any change;
    res=max(res,solve_dp(ind+1,ops_left,cnt_f+(s[ind]==t[0]),s,t)+(s[ind]==t[1])*cnt_f);


    //change s[ind] to t[0]
    if(ops_left>0){
        char ch=s[ind];
        s[ind]=t[0];
        res=max(res,solve_dp(ind+1,ops_left-1,cnt_f+(s[ind]==t[0]),s,t)+(s[ind]==t[1])*cnt_f);
        s[ind]=ch;
    }


    //change s[ind] to t[1];
    if(ops_left>0){
        char ch=s[ind];
        s[ind]=t[1];
        res=max(res,solve_dp(ind+1,ops_left-1,cnt_f+(s[ind]==t[0]),s,t)+(s[ind]==t[1])*cnt_f);
        s[ind]=ch;

    }

    return dp[ind][ops_left][cnt_f]=res;
    
}
void solve(ll tc){
    
    ll n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;

    memset(dp,-1,sizeof(dp));

    //dp(i,j,k)=> at ith index of string s, operatons j remain , count of first character of t[0] in prefix is k

    cout<<solve_dp(0,k,0,s,t)<<endl;


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