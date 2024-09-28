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

/*
If the final depth of the leaves is d it's optimal to keep in the tree all the nodes at depth d
and all their ancestors. These nodes are the only ones which satisfy the following two conditions:

their depth (ai) is ≤d.
the maximum depth of a node in their subtree (bi) is ≥d.
So every node is alive in the interval of depths [ai,bi]. 
The optimal d is the one contained in the maximum number of intervals.
*/
void dfs(ll v,ll p,ll d,vector<vector<ll> >&adj,vector<ll> &sub_tree,vector<ll> &h,vector<ll> &pref){
    
    h[v]=d;
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        dfs(to,v,d+1,adj,sub_tree,h,pref);
        sub_tree[v]+=sub_tree[to];
        h[v]=max(h[v],h[to]);
    }
    sub_tree[v]++;
    pref[d]++;
    pref[h[v]+1]--;

}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<vector<ll> > adj(n+1);
    vector<ll> sub_tree(n+1,0);
    vector<ll> h(n+1,0);
    vector<ll> pref(n+3,0);

    ll x,y;
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,-1,0,adj,sub_tree,h,pref);

    ll ans=0;
    for(ll i=0;i<=n;i++){
        if(i>=1)pref[i]+=pref[i-1];
        ans=max(ans,pref[i]);
    }

    cout<<n-ans<<endl;

    
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