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
void dfs(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &cost,vector<ll> &subtree_cost,vector<ll> &subtree_function){

    

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        dfs(to,v,adj,cost,subtree_cost,subtree_function);
        subtree_function[v]+=subtree_function[to];
        subtree_cost[v]+=subtree_cost[to];
    }


    subtree_function[v]+=subtree_cost[v];//distances of all c in subtree incremented by 1
    //cout<<v<<" "<<subtree_function[v]<<endl;
    subtree_cost[v]+=cost[v];
}

void dfs2(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &cost,vector<ll> &subtree_cost,vector<ll> &subtree_function,ll prev_f,ll &ans){
    ans=min(ans,prev_f+subtree_function[v]);


    vector<ll> prefix_function,suffix_function;

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        prefix_function.pb(subtree_cost[to]+subtree_function[to]);
        suffix_function.pb(subtree_cost[to]+subtree_function[to]);
    }

    ll sz=prefix_function.size();
    for(ll i=1;i<sz;i++){
        prefix_function[i]+=prefix_function[i-1];
    }

    for(ll i=sz-2;i>=0;i--){
        suffix_function[i]+=suffix_function[i+1];
    }

    ll c=0;
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }

        ll nx_extra=prev_f;
        if(c-1>=0){
            nx_extra+=prefix_function[c-1];
        }

        if(c+1<sz){
            nx_extra+=suffix_function[c+1];
        }

        nx_extra+=(subtree_cost[1]-subtree_cost[to]);

        dfs2(to,v,adj,cost,subtree_cost,subtree_function,nx_extra,ans);


        c++;
    }
    
}
void solve(ll tc){ 
    ll n;
    cin>>n;

    vector<vector<ll>  > adj(n+1);
    vector<ll> subtree_function(n+1,0);
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

    dfs(1,-1,adj,cost,subtree_cost,subtree_function);



    ll ans=9e18;

    //re-rooting the tree
    dfs2(1,-1,adj,cost,subtree_cost,subtree_function,0,ans);


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