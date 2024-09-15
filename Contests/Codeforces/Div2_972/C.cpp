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
string cmp="narek";
ll solve_dp(ll ind,ll lst_f,ll n,vector<string> &a,vector<vector<ll> > &dp,vector<vector<ll> >&memo){
    if(ind==n){
        return 0;
    }

    if(memo[ind][lst_f]){
        return dp[ind][lst_f];
    }

    memo[ind][lst_f]=1;

    //skip the string
    ll res=solve_dp(ind+1,lst_f,n,a,dp,memo);

    //pick the string
    ll sz=a[ind].size();
    ll sc=0;

    ll prev_lst=lst_f;
    for(ll i=0;i<sz;i++){


        if(a[ind][i]==cmp[lst_f]){
            lst_f++;
        }

        if(a[ind][i]=='n' or a[ind][i]=='a' or a[ind][i]=='r' or a[ind][i]=='e' or a[ind][i]=='k'){
            sc--;
        }

        if(lst_f==5){
            lst_f=0;
            sc+=10;
        }
    }

    res=max(res,sc+solve_dp(ind+1,lst_f,n,a,dp,memo));
    return dp[ind][prev_lst]=res;


}
void solve(ll tc){
    

    ll n,m;
    cin>>n>>m;

    vector<vector<ll> >dp(n,vector<ll> (6));
    vector<vector<ll> >memo(n,vector<ll> (6,0));
    vector<string> a(n);

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<solve_dp(0,0,n,a,dp,memo)<<endl;


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