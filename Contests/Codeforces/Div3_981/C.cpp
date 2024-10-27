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
ll get_contri(ll ind,vector<ll> &a){
    ll c=0;

    if(ind-1>=0){
        c+=(a[ind]==a[ind-1]);
    }

    if(ind+1<a.size()){
        c+=(a[ind]==a[ind+1]);
    }

    return c;
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<vector<ll> > dp(n+1,vector<ll> (2,1e9));
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    dp[0][0]=0;
    dp[1][0]=0;

    for(ll i=1;i<=(n+1)/2;i++){
        ll ind=i;
        ll cmp_ind=n-i+1;
        ll prev=i-1;
        ll prev_cmp=n-prev+1;


        // assume previous not swapped;
        dp[i][0]=min(dp[i][0],dp[i-1][0]+(prev>=1 and a[i]==a[prev]) + (prev_cmp<=n and a[cmp_ind]==a[prev_cmp]));
        dp[i][0]=min(dp[i][0],dp[i-1][1]+(prev_cmp<=n and a[i]==a[prev_cmp]) + (i-1>=1 and a[cmp_ind]==a[i-1]));
        dp[i][1]=min(dp[i][1],dp[i-1][0]+(prev>=1 and a[cmp_ind]==a[prev]) + (prev_cmp<=n and a[i]==a[prev_cmp]));
        dp[i][1]=min(dp[i][1],dp[i-1][1]+(prev_cmp<=n and a[cmp_ind]==a[prev_cmp]) + (prev>=1 and a[i]==a[prev]));

    }

    ll ex=0;
    if(n%2==0){
        ex=(a[n/2]==a[n/2+1]);
    }

    cout<<ex+min(dp[(n+1)/2][0],dp[(n+1)/2][1])<<endl;






    
    
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