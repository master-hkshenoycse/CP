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

    string target;
    cin>>target;
    ll sz=target.size();
    vector<ll> dp(sz+1,1e15);
    dp[0]=0;




    ll n;
    cin>>n;

    string s;

    for(ll i=1;i<=n;i++){
        ll m;
        cin>>m;

        vector<ll> tmp=dp;

        while(m--){
            cin>>s;
            ll l=s.size();

            for(ll j=1;j<=sz;j++){
                
                if(j-l>=0 and dp[j-l]<1e15 and s==target.substr(j-l,l)){
                    tmp[j]=min(tmp[j],dp[j-l]+1);
                }
            }
        }

        dp=tmp;
    }




    if(dp[sz]>=1e15){
        dp[sz]=-1;
    }

    cout<<dp[sz]<<endl;



 



}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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