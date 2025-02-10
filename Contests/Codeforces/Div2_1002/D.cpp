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
    ll n,s1,s2;
    cin>>n>>s1>>s2;

    ll m1,m2;
    cin>>m1;

    vector<vector<ll> > adj_a(n+1),adj_b(n+1);
    ll x,y;
    set<arr<ll,2> > edges;
    vector<ll> is_good(n+1);
     

    for(ll i=0;i<m1;i++){
        cin>>x>>y;
        if(x>y){
            swap(x,y);
        }
        edges.insert({x,y});
        adj_a[x].pb(y);
        adj_a[y].pb(x);
    }

    cin>>m2;
    for(ll i=0;i<m2;i++){
        cin>>x>>y;
        if(x>y){
            swap(x,y);
        }

        if(edges.find({x,y}) != edges.end()){
            is_good[x]=1;
            is_good[y]=1;
        }

        adj_b[x].pb(y);
        adj_b[y].pb(x);
    }

    vector<vector<ll> > dp(n+1,vector<ll> (n+1,1e18));
    dp[s1][s2]=0;

    set<pair<ll,pair<ll,ll> > > s;
    s.insert({0,{s1,s2}});

    while(s.size()>0){
        auto it=*s.begin();
        ll d=it.first;
        ll x=it.second.first;
        ll y=it.second.second;
        s.erase(s.begin());

        for(auto nx:adj_a[x]){
            for(auto ny:adj_b[y]){
                if(dp[nx][ny] > d + abs(nx-ny)){
                    dp[nx][ny]=d+abs(nx-ny);
                    s.insert({dp[nx][ny],{nx,ny}});
                }
            }
        }
    }

    ll ans=1e18;

    for(ll i=1;i<=n;i++){
        if(is_good[i]){
            if(dp[i][i] != 1e18){
                ans=min(ans,dp[i][i]);
            }
        }
    }

    if(ans == 1e18){
        ans=-1;
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