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

    vector<ll> a(n+1),csum(n+1),suffix_sum(n+2,0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        csum[i]=(csum[i-1]+a[i])%m;
    }


    for(ll i=n;i>=1;i--){
        suffix_sum[i]=(suffix_sum[i+1]+a[i])%m;
    }


    ll ans=0;

    map<ll,ll> help;
    help[0]=1;


    for(ll i=2;i<=n;i++){
        ll req=csum[i-1];
        if(help.find(req) != help.end()){
            ans=ans+help[req];
        }
        help[csum[i-1]]++;
    }

    help.clear();
    help[suffix_sum[n]]++;

    for(ll i=n-1;i>=1;i--){
        ll req=(m-csum[i-1])%m;
        if(help.find(req) != help.end()){
            ans=ans+help[req];
        }

        help[suffix_sum[i]]++;
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