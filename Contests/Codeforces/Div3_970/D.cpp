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
void dfs(ll v,vector<vector<ll> >&adj,vector<ll> &vis,ll c,map<ll,ll> &cnt_comp,string &s){
    cnt_comp[c]+=(s[v-1]=='0');
    vis[v]=c;

    for(auto to:adj[v]){
        if(vis[to]==0){
            dfs(to,adj,vis,c,cnt_comp,s);     
        }
    }

}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<vector<ll> > adj(n+1);
    
    

    ll e;
    for(ll i=1;i<=n;i++){
        cin>>e;
        adj[i].pb(e);
        adj[e].pb(i);
    }

    string s;
    cin>>s;


    vector<ll> vis(n+1,0),sol(n+1,0);


    ll c=0;
    map<ll,ll> cnt_comp;

    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            c++;
            dfs(i,adj,vis,c,cnt_comp,s);
        }
    }

    for(ll i=1;i<=n;i++){
        cout<<cnt_comp[vis[i]]<<" ";
    }
    cout<<endl;


    
    
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