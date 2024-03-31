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

void dfs(ll v,ll p,vector<vector<pair<ll,ll> > > &adj,vector<ll> &cnt_leaves,priority_queue<vector<ll> > &pq,ll d,ll &tot){


    for(auto to:adj[v]){
        
        if(to.ff==p){
            continue;
        }

        
        
        ll wt=to.ss;
        dfs(to.ff,v,adj,cnt_leaves,pq,d+wt,tot);

        ll leaf_count=cnt_leaves[to.ff];

        cnt_leaves[v]+=leaf_count;

        pq.push({(wt-wt/2)*leaf_count,leaf_count,wt});
        

    }

    if(v!=1 and adj[v].size()==1){
        tot+=d;
        cnt_leaves[v]=1;
    }
}
void solve(ll tc){ 
    ll n,S;
    cin>>n>>S;

    vector<vector<pair<ll,ll> > >adj(n+1);
    priority_queue<vector<ll> > pq;//{gain,current_weight,leaves}

    //contribution of edge is no of leaves in  its subtree * curent weight
    //select the edge with max contribution


    ll x,y,w;

    ll tot=0;
    vector<ll> cnt_leaves(n+1,0);

    for(ll i=1;i<=n-1;i++){
        cin>>x>>y>>w;

        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }

    dfs(1,-1,adj,cnt_leaves,pq,0,tot);


    ll ans=0;
    while(tot>S){
        ans++;
        tot-=pq.top()[0];
        ll curr_wt=pq.top()[2]/2;
        ll leaf_cnt=pq.top()[1];

        pq.pop();
        pq.push({(curr_wt-curr_wt/2)*leaf_cnt,leaf_cnt,curr_wt});

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