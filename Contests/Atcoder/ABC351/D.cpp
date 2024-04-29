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
void dfs(ll x,ll y,vector<vector<ll> >&is_free,vector<vector<ll> > &vis,vector<ll> &comp){
    vis[x][y]=comp.size();
    comp.back()++;

    if(is_free[x][y]==0){
        return;
    }
    for(ll i=0;i<4;i++){

        ll nx=x+dx[i];
        ll ny=y+dy[i];

        if(nx>=0 and ny>=0 and nx<is_free.size() and ny<is_free[0].size() and vis[nx][ny]==0 and is_free[nx][ny]!=2){
            dfs(nx,ny,is_free,vis,comp);
        }
    }

}
void solve(ll tc){
    ll h,w;
    cin>>h>>w;


    vector<vector<char> > grid(h,vector<char>(w));
    vector<vector<ll> > is_free(h,vector<ll> (w,1));
    vector<vector<ll> > vis(h,vector<ll> (w,0));


    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='#'){
                is_free[i][j]=2;
            }
        }
    }

    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            
            for(ll k=0;k<4;k++){
                ll ni=i+dx[k];
                ll nj=j+dy[k];
                if(ni>=0 and nj>=0 and ni<h and nj<w and grid[ni][nj]=='#'){
                    is_free[i][j]=0;
                    break;
                }
            }
        }
    }

    

    vector<ll> comp;
    ll ans=1;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            if(is_free[i][j]==1 and vis[i][j]==0){
                comp.push_back(0);
                dfs(i,j,is_free,vis,comp);
                ans=max(ans,comp.back());
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}