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

    vector<vector<ll> > a(n,vector<ll> (m,0)),dp(n,vector<ll> (m,1e9));



    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    //View the task in a relative perspective, with robot RT and the ending location moving downwards instead of rocks moving upwards.
    //rocks move upwars cylically every second

    // move the positions and make rocks stationary
    //moves allowed for robot is move upwards, move right,move downwards;
    //using relative motion, we can change the movmement to dont move,move downards twice , move right to move diagonal;

    queue<pair<ll,ll> > q;
    dp[0][0]=0;
    q.push({0,0});

    while(q.size()>0){
        ll x=q.front().first;
        ll y=q.front().second;
        q.pop();

        ll nx,ny;

        //moving downwards (relatively moving downwards twice)
        nx=(x+2)%n;
        ny=y;

        if(a[(nx-1+n)%n][ny]==0 and a[nx][ny]==0 and dp[nx][ny]>dp[x][y]+1){
            dp[nx][ny]=dp[x][y]+1;
            q.push({nx,ny});
        }



        //moving right (relatively diagonal)

        nx=(x+1)%n;
        ny=(y+1);

        if(ny<m and a[nx][ny]==0 and dp[nx][ny]>dp[x][y]+1){
            dp[nx][ny]=dp[x][y]+1;
            q.push({nx,ny});
        }

    }


    ll ans=1e9;
    for(ll i=0;i<n;i++){
        ll k=n-1+dp[i][m-1];
        k%=n;
        //k is current row of last point

        ans=min(ans,(i-k+n)%n+dp[i][m-1]);
    }

    if(ans==1e9){
        ans=-1;
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