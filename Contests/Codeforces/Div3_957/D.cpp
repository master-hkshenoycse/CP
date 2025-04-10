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
    ll n,m,k;
    cin>>n>>m>>k;

    vector<char> river(n+1);
    vector<ll> dp(n+2,1e18);
    dp[n+1]=0;

    for(ll i=1;i<=n;i++){
        cin>>river[i];
    }

    
    river[0]='B';

    for(ll i=n;i>=0;i--){
        if(river[i]=='W'){
            dp[i]=min(dp[i],dp[i+1]+1);
        }else if(river[i]=='B' or river[i]=='L'){
            for(ll j=i+1;j<=min(n+1,i+m);j++){
                dp[i]=min(dp[i],dp[j]);
            }
        }
    }

    if(dp[0]<=k){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }


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