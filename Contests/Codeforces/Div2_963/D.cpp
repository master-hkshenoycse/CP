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
ll chk(ll value,ll k,vector<ll> &a){
    ll n=a.size();
    vector<ll> b(n);
    for(ll i=0;i<n;i++){
        if(a[i]>=value){
            b[i]=1;
        }else{
            b[i]=-1;
        }
    }


    vector<ll> dp(n);
    dp[0]=b[0];
    

    for(ll i=1;i<n;i++){
        if(i%k==0){
            dp[i]=max(dp[i-k],b[i]);
        }else{
            dp[i]=dp[i-1]+b[i];
            if(i>k){
                dp[i]=max(dp[i],dp[i-k]);
            }
        }
    }
    

    return dp[n-1]>0;
}
void solve(ll tc){
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll lo=0,hi=1e10,ans=0;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;

        if(chk(mid,k,a)){
            ans=max(ans,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }

    cout<<ans<<endl;




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