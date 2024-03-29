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
    ll R,G,B;
    cin>>R>>G>>B;
    
    vector<vector<vector<ll> > >  dp(R+1,vector<vector<ll> >(G+1,vector<ll>(B+1,0)));

    vector<ll> a(R),b(G),c(B);

    for(ll i=0;i<R;i++){
        cin>>a[i];
    }

    for(ll i=0;i<G;i++){
        cin>>b[i];
    }

    for(ll i=0;i<B;i++){
        cin>>c[i];
    }

    sort(all(a));
    sort(all(b));
    sort(all(c));

    //finally suffix of sorted pairs will be selected.
    reverse(all(a));
    reverse(all(b));
    reverse(all(c));


    for(ll i=0;i<=R;i++){
        for(ll j=0;j<=G;j++){
            for(ll k=0;k<=B;k++){
                
                //pair ith and jth index
                
                if(i-1>=0 and j-1>=0){
                    dp[i][j][k]=max(dp[i-1][j-1][k]+a[i-1]*b[j-1],dp[i][j][k]);
                }
                //pair jth and kth index
                if(j-1>=0 and k-1>=0){
                    dp[i][j][k]=max(dp[i][j-1][k-1]+b[j-1]*c[k-1],dp[i][j][k]);
                }
                
                //pair ith and kth index
                if(i-1>=0 and k-1>=0){
                    dp[i][j][k]=max(dp[i-1][j][k-1]+a[i-1]*c[k-1],dp[i][j][k]);
                }


                if(i-1>=0){
                    dp[i][j][k]=max(dp[i-1][j][k],dp[i][j][k]);
                }

                if(j-1>=0){
                    dp[i][j][k]=max(dp[i][j-1][k],dp[i][j][k]);
                }

                if(k-1>=0){
                    dp[i][j][k]=max(dp[i][j][k-1],dp[i][j][k]);
                }

                //dp[i][j][k]=max(dp[i-1][j-1][k-1],dp[i][j][k]);

                //cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
                
            }
        }
    }

    cout<<dp[R][G][B]<<endl;




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