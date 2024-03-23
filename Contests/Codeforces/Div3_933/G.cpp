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

    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll> > > adj(n+1);
    map<ll,ll> col;
    
    

    ll u,v,c;
    ll ind=0;
    while(m--){
        cin>>u>>v>>c;

        adj[u].pb({v,c});
        adj[v].pb({u,c});

        if(col.find(c)==col.end()){
            ind++;
            col[c]=ind;
        }

    }

    ll s,t;
    cin>>s>>t;


    vector<set <ll> > station_graph(n+ind+1);
    //making graph between stations and subway lines
    //stations are marked from 1 to n and subway lines are marked from n+1 to n+ind;
    //shortest path will be half of shartest path betwwn s to t in above graph
    for(ll i=1;i<=n;i++){
        for(auto to:adj[i]){
            ll nx=to.first;
            ll c=col[to.second]+n;
            
            //cout<<i<<" "<<nx<<" "<<c<<endl;
            station_graph[c].insert(i);
            station_graph[i].insert(c);

            station_graph[c].insert(nx);
            station_graph[nx].insert(c);


        }
    }

    vector<ll> dp(n+ind+2,INT_MAX);


    dp[s]=0;
    queue<ll> q;
    q.push(s);

    while(q.size()>0){
        ll v=q.front();
        q.pop();

        for(auto to:station_graph[v]){
           // cout<<to<<" "<<v<<endl;
            if(dp[to]>dp[v]+1){
                dp[to]=dp[v]+1;
                q.push(to);
            }
        }


    }

   // cout<<endl;




    cout<<dp[t]/2<<endl;


 
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