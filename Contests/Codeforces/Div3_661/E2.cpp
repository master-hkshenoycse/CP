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
vector<ll> wt,leaf_cnt,cost;
ll get_diff(ll ind){
    return (wt[ind]-wt[ind]/2)*leaf_cnt[ind];
}

void dfs(ll v,ll p,vector<vector<pair<ll,ll> > > &adj){



    for(auto to:adj[v]){
        //cout<<v<<" "<<p<<" "<<to.first<<" "<<to.second<<endl;

        if(to.second == p){
            continue;
        }   

        

        dfs(to.first,to.second,adj);
        if(p!=-1)leaf_cnt[p]+=leaf_cnt[to.second];


    }

    if(adj[v].size()==1 and p!= -1){
        leaf_cnt[p]=1;
    }

}

vector<ll> get(ll c,ll n){
    ll tot=0;
    set<pair<ll,ll> > s;
    for(ll i=1;i<=n-1;i++){
        if(cost[i]==c){//for a particular cost edge
            tot+=leaf_cnt[i]*wt[i];
            s.insert({get_diff(i),i});//gain if we half the leaf.
        }
    }

    vector<ll> res;//stores the contribution sum if operations are done greedily fro these edges
    //i.e subtracting the highest diff(i) edge from tot;

    res.pb(tot);//0 operatons, no reduction in total;

    while(tot>0 and s.size()>0){
        auto it=*(--s.end());
        if(it.ff==0){
            break;
        }

        ll ind=it.ss;
        tot-=it.ff;
        res.pb(tot);

        s.erase(it);
        wt[ind]/=2;
        s.insert({get_diff(ind),ind});
    }

    return res;

}


void solve(ll tc){ 
    ll n,S;
    cin>>n>>S;

    vector<vector<pair<ll,ll > > >adj(n+1);


    ll x,y;

    ll tot=0;
    wt.resize(n+1,0ll);
    leaf_cnt.resize(n+1,0ll);
    cost.resize(n+1,0ll);


    for(ll i=1;i<=n-1;i++){
        cin>>x>>y>>wt[i]>>cost[i];

        leaf_cnt[i]=0;
    

        adj[x].pb({y,i});
        adj[y].pb({x,i});
    }
    
    dfs(1,-1,adj);


    
    vector<ll> v1=get(1,n);
    vector<ll> v2=get(2,n);

    ll ans=1e18;

    ll p=v2.size()-1;
    //two pointer to iterae the possible value;

    for(ll i=0;i<v1.size();i++){
        while(p>0 and v1[i]+v2[p-1]<=S){
            p--;
        }

        //cout<<i<<" "<<p<<" "<<v1[i]+v2[p-1]<<endl;
        if(v1[i]+v2[p]<=S){
            ans=min(ans,i+2*p);
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