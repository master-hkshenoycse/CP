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
ll mod=998244353;
void solve(ll tc){
    ll n;
    cin>>n;


    map<arr<ll,2> , ll> dp;

    ll e;
    for( ll i=1;i<=n;i++){
        cin>>e;

        if(i==1){
            if(e==0){
                dp[{1,1}]=1;
                dp[{0,0}]=1;
            }else{
                dp[{1,1}]=1;
            }
        }else{

            map<arr<ll,2>,ll> tmp;
            //assume this is a truth teller
            for(auto it:dp){
                ll lier_cnt=it.first[0];
            
                if(lier_cnt==e){
                    tmp[{lier_cnt,0}]=(tmp[{lier_cnt,0}]+it.ss)%mod;
                }

            }


            //assume this is a lier;
            for(auto it:dp){
                ll lier_cnt=it.first[0];
                ll is_lier=it.first[1];
              

                if(is_lier==0){
                    tmp[{lier_cnt+1,1}]=(tmp[{lier_cnt+1,1}]+it.ss)%mod;
                }

            }

            dp=tmp;
        }
    }

    ll ans=0;
    for(auto it:dp){
        ans=(ans+ it.second)%mod;
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