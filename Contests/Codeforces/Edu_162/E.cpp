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
/*https://codeforces.com/contest/1923/submission/249249479*/
/*Binary search on subarray and a subarray can b combined if theere are atleast two distinct elements in it*/

void dfs(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &a,vector<map<ll,ll> > &help,ll &ans){

    ll best=-1;
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }

        dfs(to,v,adj,a,help,ans);

        if(best==-1 or help[to].size()>help[best].size()){
            best=to;
        }
    }

    for(auto to:adj[v]){
        if(to==p or to==best){
            continue;
        }
        for(auto it:help[to]){
            ll col=it.first;
            ll cnt=it.second;
            if(col!=a[v]){
                ans=ans+cnt*help[best][col];
            }
            help[best][col]+=cnt;
        }
    }

    if(best!=-1){
        ans=ans+help[best][a[v]];
        swap(help[best],help[v]);
    }

    //this ensures that no other vertex on path starting from/ below v has same color vertex
    help[v][a[v]]=1;

    
}
void solve(ll tc){ 
    ll n;
    cin>>n;

    vector<ll> col(n+1);
    vector<vector<ll> > adj(n+1);
    vector<map<ll,ll> > help(n+1);

    ll ans=0;
    
    for(ll i=1;i<=n;i++){
        cin>>col[i];
    }

    ll x,y;
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,-1,adj,col,help,ans);

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