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
    ll n,m,q;
    cin>>n>>m>>q;

    vector<vector<ll> > edges;
    ll x,y,w;
    
    for(ll i=0;i<m;i++){
        cin>>x>>y>>w;
        edges.push_back({w,x,y});
    }

    sort(all(edges));
    vector<vector<vector<ll> > >  dp(m+1,vector<vector<ll> > (n+1,vector<ll> (n+1,1e18)));

    for(auto e:edges){
        dp[0][e[1]][e[2]]=1;
        dp[0][e[2]][e[1]]=1;
    }


    for(ll i=1;i<=n;i++){
        dp[0][i][i]=0;
    }

    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                dp[0][i][j]=min(dp[0][i][j],dp[0][i][k]+dp[0][k][j]);
            }
        }
    }
    
    for(ll i=1;i<=m;i++){

        ll x=edges[i-1][1];
        ll y=edges[i-1][2];

        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                dp[i][j][k]=min({dp[i-1][j][k],dp[i-1][j][x]+dp[i-1][y][k],dp[i-1][j][y]+dp[i-1][x][k]});
            }
        }
    }


    ll a,b,k;
    while(q--){
        cin>>a>>b>>k;
        ll lo=0,hi=m,ans=m;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;

            if(dp[mid][a][b]<k){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        
        cout<<edges[ans-1][0]<<" ";
    }

    cout<<endl;

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