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

    ll n,m,k,d;
    cin>>n>>m>>k>>d;

    vector<ll> costs;
    vector<ll> dp(m+1,1e18);
    ll h;


    for(ll i=1;i<=n;i++){

        for(ll j=1;j<=m;j++){
            dp[j]=1e18;
        }    

        dp[0]=0;
        deque<ll> dq;

        
        for(ll j=1;j<=m;j++){
            cin>>h;
            if(j==1){
                dp[j]=1;
                dq.push_front(1);
            }else{
                
                dp[j]=dp[dq.front()]+h+1;

                while(dq.size()>0 and dp[dq.back()]>dp[j]){
                    dq.pop_back();
                }

                while(dq.size()>0 and j-dq.front()>d){
                    dq.pop_front();
                }

                dq.push_back(j);



            }
        }

        //cout<<i<<" "<<dp[m]<<endl;

        costs.pb(dp[m]);
        
    }

    ll ans=1e18;
    for(ll i=1;i<n;i++){
        costs[i]+=costs[i-1];
    }

    for(ll i=0;i+k-1<n;i++){
        ll tot=costs[i+k-1];
        if(i-1>=0){
            tot-=costs[i-1];
        }
        ans=min(ans,tot);
    }

    cout<<ans<<endl;

}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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