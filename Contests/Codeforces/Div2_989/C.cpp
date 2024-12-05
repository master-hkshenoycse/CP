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
bool is_out(ll x,ll y,ll n,ll m){
    return (x<0 or y<0 or x>=n or y>=m);
}
void solve(ll tc){
    
    ll n,m;
    cin>>n>>m;

    vector<vector<char> >a(n+2,vector<char> (m+2));
    vector<vector<ll> > vis(n+2,vector<ll> (m+2,0));
    vector<pair<ll,ll> > adj[n+2][m+2];
    for(ll i=1;i<=n;i++){
        string s;
        cin>>s;
        for(ll j=1;j<=m;j++){
            a[i][j]=s[j-1];

            if(a[i][j]=='U'){
                adj[i-1][j].pb({i,j});
            }

            if(a[i][j]=='D'){
                adj[i+1][j].pb({i,j});
            }

            if(a[i][j]=='L'){
                adj[i][j-1].pb({i,j});
            }

            if(a[i][j]=='R'){
                adj[i][j+1].pb({i,j});
            }
        }
    }

    queue<pair<ll,ll> >q;
    for(ll i=0;i<=n+1;i++){
        for(ll j=0;j<=m+1;j++){
            if(i==0 or i==n+1 or j==0 or j==m+1){
                q.push({i,j});
                vis[i][j]=1;
            }
        }
    }

    while(q.size()>0){
        ll x=q.front().ff;
        ll y=q.front().ss;
        q.pop();

        for(auto to:adj[x][y]){
            if(vis[to.ff][to.ss]==0){
                q.push({to.ff,to.ss});
                vis[to.ff][to.ss]=1;
            }
        }
    }
    ll ans=n*m;

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(vis[i][j]==1){
                ans--;
            }else if(a[i][j]=='?'){
                
                if(vis[i-1][j] && vis[i+1][j] && vis[i][j-1] && vis[i][j+1]){
                    ans--;
                }
            
            }
        }
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