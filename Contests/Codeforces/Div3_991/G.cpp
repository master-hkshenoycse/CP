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
ll dfs(ll v,ll p,vector<vector<ll> >&adj,ll &ans){
    ans=max(ans,adj[v].size()*1ll);
    vector<ll> ch;
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        ch.pb(dfs(to,v,adj,ans));
    } 

    ll sz=ch.size();

    sort(all(ch));
    reverse(all(ch));
    ll ret=sz;
    ans=max(ans,sz);
    if(ch.size()>0){
        ans=max(ans,ch[0]+sz-(p<0));
        ret=max(ret,ch[0]+sz-1);
    }

    if(ch.size()>1){
        ans=max(ans,ch[0]+ch[1]+sz-1-(p<0));
    }
    //cout<<v<<" "<<ans<<endl;

    
    return ret;

    
}
void solve(ll tc){
    
    ll n;
    cin>>n;

    ll x,y;
    vector<vector<ll> > adj(n+1);
    for(ll i=1;i<=n-1;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }    

    ll ans=0;
    dfs(1,-1,adj,ans);
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