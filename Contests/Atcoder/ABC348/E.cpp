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
void dfs(ll v,ll p,vector<vector<ll> > &adj,vector<ll> &cost,vector<ll> &subtree_cost){
    
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        dfs(to,v,adj,cost,subtree_cost);
        subtree_cost[v]=subtree_cost[v]+2*subtree_cost[to]+cost[to];
    }

}

void dfs2(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &cost,vector<ll> &subtree_cost,ll prev,ll &ans){
    ans=min(ans,prev+subtree_cost[v]);


    vector<ll> pref_cost,suff_cost;

    for(auto to:adj[v]){

        if(to==p){
            continue;
        }

        pref_cost.pb(subtree_cost[to]*3+cost[to]*2);
        suff_cost.pb(subtree_cost[to]*3+cost[to]*2);
    }
    ll sz=pref_cost.size();

    for(ll i=1;i<sz;i++){
        pref_cost[i]+=pref_cost[i-1];
    }

    for(ll i=sz-2;i>=0;i--){
        suff_cost[i]+=suff_cost[i+1];
    }

    ll c=0;
    for(auto to:adj[v]){
        
        if(to==p){
            continue;
        }

        ll new_value=prev*2+cost[v];
        
        if(c-1>=0){
            new_value+=pref_cost[c-1];
        }

        if(c+1<sz){
            new_value+=suff_cost[c+1];
        }

        dfs2(to,v,adj,cost,subtree_cost,new_value,ans);
        c++;
        
    }



}
void solve(ll tc){ 
    ll n;
    cin>>n;

    vector<vector<ll>  > adj(n+1);
    vector<ll> subtree_cost(n+1,0);
    vector<ll> cost(n+1,0);
    ll x,y;
    for(ll i=1;i<=n-1;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(ll i=1;i<=n;i++){
        cin>>cost[i];
    }
    dfs(1,-1,adj,cost,subtree_cost);


    ll ans=9e18;

    //re-rooting the tree
    dfs2(1,-1,adj,cost,subtree_cost,0,ans);


    cout<<ans<<endl;
    

     
}   
int main(){
    boost;

    //pre_cum();
    //prec(20);
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