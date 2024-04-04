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
void dfs(ll v,ll p,vector<vector<ll> > &adj,ll h,ll &dist_ab,ll &dia,ll &max_vert,ll b){
    if(v==b){
        dist_ab=h;
    }

    if(h>dia){
        dia=h;
        max_vert=v;
    }

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        dfs(to,v,adj,h+1,dist_ab,dia,max_vert,b);
    }

    
}
void solve(ll tc){ 

    ll n,a,b,da,db;
    cin>>n>>a>>b>>da>>db;

    ll x,y;
    vector<vector<ll> >adj(n+1);
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ll dist_ab=0,dia=-1,max_vert=a;
    dfs(a,-1,adj,0,dist_ab,dia,max_vert,b);

    dfs(max_vert,-1,adj,0,dist_ab,dia,max_vert,-1);
    

    //Bob is withing the reach of alice in first move
    if(dist_ab <= da){
        cout<<"Alice"<<endl;
        return;
    }

    //Alice can catch bob in second move, as diameter is the maximum distance possible
    if(2*da>=dia){
        cout<<"Alice"<<endl;
        return;
    }


    //Bob can always escape alice
    //Since we are not in case 2, there is at least one vertex with distance at least da
    //there is some vertex v,with dist(a,v)=da+1
    //Then dist(b,v)≤dist(b,a)+dist(a,v)≤da+(da+1)=2da+1≤d  so Bob can jump to v on his turn.
    if(db > 2*da){
        cout<<"Bob"<<endl;
        return;
    }

    //Let's root the tree at a. Bob is located in some subtree of a
    //, say with k vertices. Alice moves one vertex deeper, decreasing Bob's subtree size by at least one vertex. Since db≤2da
    //, Bob cannot move to another subtree without being immediately captured, so Bob must stay in this shrinking subtree until he meets his inevitable defeat.
    cout<<"Alice"<<endl;


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