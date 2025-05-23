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
ll dx[4]={-1,1,0,0};
ll dy[4]={0,0,-1,1};

void solve(ll tc){ 
    ll n,m;
    cin>>n>>m;
    vector<vector<ll> > board(n,vector<ll> (m));
    vector<vector<ll> > dp(n,vector<ll> (m,1e9));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    queue<pair<ll,ll> > q;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(board[i][j]==0){
                q.push({i,j});
                dp[i][j]=0;
            }
        }
    }

    while(q.size()>0){
        ll x=q.front().first;
        ll y=q.front().second;

        q.pop();

        for(ll i=0;i<4;i++){
            ll nx=x+dx[i];
            ll ny=y+dy[i];
            if(nx>=0 and ny>=0 and nx<n and ny<m and board[nx][ny] != -1 and dp[nx][ny] > dp[x][y]+1){
        
                dp[nx][ny]=dp[x][y]+1;
                q.push({nx,ny});
            }
        }

    }

    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(board[i][j] == -1){
                continue;
            }
            
            ans=max(ans,dp[i][j]*2);
        }
    }

    if(ans>=1e9){
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