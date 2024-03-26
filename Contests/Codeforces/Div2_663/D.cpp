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
ll steps_req(vector<ll> &a,ll mask){
    ll n=a.size();
    ll cnt=0;
    for(ll i=0;i<n;i++){
        if(a[i] != ((mask>>i)&1)){
            cnt++;
        }
    }
    return cnt;
}

ll is_compatible(ll prev,ll curr,ll n){
    vector<ll> a,b;
    for(ll i=0;i<n;i++){
        a.pb((prev>>i)&1);
        b.pb((curr>>i)&1);
    }

    for(ll i=1;i<n;i++){
       
        if(((a[i-1]+a[i]+b[i-1]+b[i])%2)==0){
            return 0;
        }

    }

    return 1;
}
void solve(ll tc){ 

    ll n,m;
    cin>>n>>m;

    if(min(n,m)>3){//because then 4*4 square will contain 4 2*2 square thus even number of ones so , not possible to get all squares odd
        cout<<-1<<endl;
        return;
    }

    if(min(n,m)==1){
        cout<<0<<endl;
        return;
    }

    //for other cases i.e n=2 or n=3 dp can be done on bitmasks

    vector<vector<ll> > a(m+1,vector<ll> (n));
    char ch;
    for(ll i=0;i<n;i++){
        
        for(ll j=1;j<=m;j++){
            cin>>ch;
            a[j][i]=ch-'0';
        }

    }

 

    ll lim=(1<<n);
    vector<vector<ll> > compatible(lim);

    for(ll i=0;i<lim;i++){
        for(ll j=0;j<lim;j++){
            if(is_compatible(i,j,n)){
                compatible[i].pb(j);
            }
        }
    }

    vector<vector<ll> > dp(m+1,vector<ll> (lim,1e18));

    for(ll j=0;j<lim;j++){
        dp[1][j]=steps_req(a[1],j);
    }

    ll ans=1e18;
    for(ll i=2;i<=m;i++){

       
        for(ll j=0;j<lim;j++){
            ll extra=steps_req(a[i],j);
            for(auto k:compatible[j]){
                
                dp[i][j]=min(dp[i][j],dp[i-1][k]+extra);
                
            }

            if(i==m){
                ans=min(ans,dp[i][j]);
            }

        }
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}