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

void solve(ll tc){
    ll n,m;
    cin>>n>>m;
    ll s=0;

    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        s=max(s,a[i]);
    }

    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    
    vector<ll> dp(s+5,0),f(s+5,1e9);

    for(ll i=0;i<n;i++){
        f[a[i]]=min(f[a[i]],a[i]-b[i]);
    }

    //finding the minimum usage

    for(ll i=1;i<=s;i++){
        f[i]=min(f[i],f[i-1]);
    }

    //maximum items possible by i metal units
    for(ll i=1;i<=s;i++){
        dp[i]=dp[i-1];

        if(i-f[i]>=0){
            dp[i]=max(dp[i],dp[i-f[i]]+1);
        }
    }

    ll c;
    ll ans=0;
    for(ll i=1;i<=m;i++){
        cin>>c;

        if(c>s){
            ll item=(c-s)/f[s]+1;
            ans+=2*item;
            c-=item*f[s];
        }

        ans=ans+2*dp[c];

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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}