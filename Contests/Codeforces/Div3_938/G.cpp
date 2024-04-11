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

    vector<vector<ll> > a(n,vector<ll> (m,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    ll gc=__gcd(a[0][0],a[n-1][m-1]);

    set<ll> gcd_candidates;
    for(ll i=1;i*i<=gc;i++){
        if(gc%i==0){
            gcd_candidates.insert(i);
            gcd_candidates.insert(gc/i);
        }
    }
    vector<ll> v;
    for(auto e:gcd_candidates){
        v.pb(e);
    }

    reverse(all(v));
    ll ans=1;
    vector<vector<int> > vis(n,vector<int> (m,0));

    for(auto g:v){
        
        vis[0][0]=g;

        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(i==0 and j==0){
                    continue;
                }else if(a[i][j]%g==0){
                    if(i-1>=0 and vis[i-1][j]==g){
                        vis[i][j]=vis[i-1][j];
                    }

                    if(j-1>=0 and vis[i][j-1]==g){
                        vis[i][j]=vis[i][j-1];
                    }
                }
            }
        }

        if(vis[n-1][m-1]==g){
            cout<<g<<endl;
            return;
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
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}