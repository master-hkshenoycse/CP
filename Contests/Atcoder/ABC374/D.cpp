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
dd get_dist(vector<dd> a){
    return sqrt((a[0]-a[2])*(a[0]-a[2])+(a[1]-a[3])*(a[1]-a[3]));
}
void solve(ll tc){
    ll n;
    dd s,t;
    cin>>n>>s>>t;
    vector<vector<dd> > a(n,vector<dd> (4));
    vector<ll> ord;
    for(ll i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
        ord.pb(i);
    }
    dd ans=1e9;
    do{
        vector<vector<dd> > dp(n,vector<dd>(2));
        dp[0][0]=get_dist({0,0,a[ord[0]][0],a[ord[0]][1]})/s+get_dist(a[ord[0]])/t;
        dp[0][1]=get_dist({0,0,a[ord[0]][2],a[ord[0]][3]})/s+get_dist(a[ord[0]])/t;

        for(int i=1;i<n;i++){
            int ind=ord[i];
            int prev=ord[i-1];

            dd len=get_dist(a[ord[i]]);
            dp[i][0]=min(dp[i-1][0]+get_dist({a[prev][2],a[prev][3],a[ind][0],a[ind][1]})/s+len/t,dp[i-1][1]+get_dist({a[prev][0],a[prev][1],a[ind][0],a[ind][1]})/s+len/t);
            dp[i][1]=min(dp[i-1][0]+get_dist({a[prev][2],a[prev][3],a[ind][2],a[ind][3]})/s+len/t,dp[i-1][1]+get_dist({a[prev][0],a[prev][1],a[ind][2],a[ind][3]})/s+len/t);
        }
        ans=min(ans,dp[n-1][0]);
        ans=min(ans,dp[n-1][1]);
    }while(next_permutation(all(ord)));

    cout<<ans<<endl;


}
int main(){
    boost;

    //pre_cum();
    prec(20);
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