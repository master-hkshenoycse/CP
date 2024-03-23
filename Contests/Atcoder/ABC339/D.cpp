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
ll dp[61][61][61][61];

void solve(ll tc){ 


    ll n;
    cin>>n;

    vector<vector<char> > a(n,vector<char> (n));

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            for(ll k=0;k<n;k++){
                for(ll l=0;l<n;l++){
                    dp[i][j][k][l]=1e9;
                }
            }
        }
    }

    ll x1=-1,y1=-1,x2=-1,y2=-1;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]=='P'){
                if(x1==-1){
                    x1=i;
                    y1=j;
                }else{
                    x2=i;
                    y2=j;
                }
            }
        }
    }    

    dp[x1][y1][x2][y2]=0;
    queue<vector<ll> > q;
    q.push({x1,y1,x2,y2});
    ll ans=1e9;

    while(q.size()>0){
        ll x1=q.front()[0];
        ll y1=q.front()[1];

        ll x2=q.front()[2];
        ll y2=q.front()[3];

        q.pop();

        for(ll i=0;i<4;i++){

            ll nx1=x1+dx[i];
            ll ny1=y1+dy[i];
            ll nx2=x2+dx[i];
            ll ny2=y2+dy[i];

            if(nx1<0 or nx1>=n or ny1<0 or ny1>=n or a[nx1][ny1]=='#'){
                nx1=x1;
                ny1=y1;
            }

            if(nx2<0 or nx2>=n or ny2<0 or ny2>=n or a[nx2][ny2]=='#'){
                nx2=x2;
                ny2=y2;
            }


            if(dp[nx1][ny1][nx2][ny2]>dp[x1][y1][x2][y2]+1){
                dp[nx1][ny1][nx2][ny2]=dp[x1][y1][x2][y2]+1;
                q.push({nx1,ny1,nx2,ny2});

                if(nx1==nx2 and ny1==ny2){
                    //cout<<nx1<<" "<<ny1<<" ";
                    ans=min(ans,dp[nx1][ny1][nx2][ny2]);
                }
            }
        }

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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}