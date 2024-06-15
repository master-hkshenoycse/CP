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
void dfs(ll x,ll y,ll n,ll m,vector<vector<char> > &a,vector<vector<ll> >&vis, vector<ll> &sz_comps){
    vis[x][y]=sz_comps.size();
    sz_comps.back()++;

    for(ll i=0;i<4;i++){
        ll nx=x+dx[i];
        ll ny=y+dy[i];
        if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0 and a[nx][ny]=='#'){
            dfs(nx,ny,n,m,a,vis,sz_comps);
        }
    }
}
void solve(ll tc){

    ll n,m;
    cin>>n>>m;


    vector<vector<char>  > a(n,vector<char>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    ll comp=0;
    vector<ll> sz_comps;
    vector<vector<ll> > vis(n,vector<ll> (m,0));

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(vis[i][j]==0 and a[i][j]=='#'){
                sz_comps.pb(0);
                dfs(i,j,n,m,a,vis,sz_comps);
            }
        }
    }   

    ll ans=0;

    for(ll i=0;i<n;i++){
        set<ll> comps_consider;
        ll tot_size=0;
        for(ll j=0;j<m;j++){
           if(vis[i][j]>0){
            if(comps_consider.find(vis[i][j]) ==comps_consider.end()){
                comps_consider.insert(vis[i][j]);
                tot_size+=sz_comps[vis[i][j]-1];
            }
           }else{
            tot_size++;
           }

           for(ll k=0;k<4;k++){
            ll ni=i+dx[k];
            ll nj=j+dy[k];
            if(ni>=0 and ni<n and nj>=0 and nj<m and vis[ni][nj]>0){
                if(comps_consider.find(vis[ni][nj]) ==comps_consider.end()){
                    comps_consider.insert(vis[ni][nj]);
                    tot_size+=sz_comps[vis[ni][nj]-1];
                }   
            }
           }
        }

        ans=max(ans,tot_size);
    }

    for(ll j=0;j<m;j++){
        set<ll> comps_consider;
        ll tot_size=0;
        for(ll i=0;i<n;i++){
           if(vis[i][j]>0){
            if(comps_consider.find(vis[i][j]) ==comps_consider.end()){
                comps_consider.insert(vis[i][j]);
                tot_size+=sz_comps[vis[i][j]-1];
            }
           }else{
            tot_size++;
           }

           for(ll k=0;k<4;k++){
            ll ni=i+dx[k];
            ll nj=j+dy[k];
            if(ni>=0 and ni<n and nj>=0 and nj<m and vis[ni][nj]>0){
                if(comps_consider.find(vis[ni][nj]) ==comps_consider.end()){
                    comps_consider.insert(vis[ni][nj]);
                    tot_size+=sz_comps[vis[ni][nj]-1];
                }   
            }
           }
        }

        ans=max(ans,tot_size);
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