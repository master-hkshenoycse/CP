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

void dfs(ll x,ll y,ll &cnt,ll &ma_i,ll &mi_i,ll &ma_j,ll &mi_j,vector<vector<char> >&grid,vector<vector<ll> >&vis){
    vis[x][y]=1;
    ma_i=max(ma_i,x);
    mi_i=min(mi_i,x);
    ma_j=max(ma_j,y);
    mi_j=min(mi_j,y);

    cnt++;

    ll n=grid.size(),m=grid[0].size();


    for(ll i=0;i<4;i++){
        ll nx=x+dx[i];
        ll ny=y+dy[i];

        if(nx>=0 and ny>=0 and nx<n and ny<m and grid[nx][ny]=='1' and vis[nx][ny]==0){
            dfs(nx,ny,cnt,ma_i,mi_i,ma_j,mi_j,grid,vis);
        }

    }
}
void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<vector<char> > grid(n,vector<char> (m));
    for(ll i=0;i<n;i++){
        string s;
        cin>>s;

        for(ll j=0;j<m;j++){
            grid[i][j]=s[j];
        }
    }

    ll f=1;

    vector<vector<ll> > vis(n,vector<ll> (m,0));

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(vis[i][j]==0 and grid[i][j]=='1'){
                ll cnt=0,ma_i=i,mi_i=i,ma_j=j,mi_j=j;
                dfs(i,j,cnt,ma_i,mi_i,ma_j,mi_j,grid,vis);

                if(cnt != (ma_i-mi_i+1)*(ma_j-mi_j+1)){
                    f=0;
                }
            }
        }
    }

    if(f){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }






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