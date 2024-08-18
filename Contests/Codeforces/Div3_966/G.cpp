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


    ll t0,t1,t2;
    cin>>t0>>t1>>t2;


    vector<vector<  arr<ll,4> > > adj(n+1);

    
    ll u,v,l1,l2; 
    for(ll i=1;i<=m;i++){
        cin>>u>>v>>l1>>l2;

        adj[u].pb({v,l1,l2});
        adj[v].pb({u,l1,l2});

    }


    //to find latest start from 
    vector<ll> dp(n+1,-1);
    

    priority_queue<arr<ll,2> > pq;

    pq.push({t0,n});

    while(pq.size()>0){
        ll v=pq.top()[1];
        ll tim=pq.top()[0];
        
        pq.pop();
        
        if(dp[v]!=-1){
            continue;
        }

        dp[v]=tim;



        for(auto to:adj[v]){
            ll nx=to[0];
            ll bus_time=to[1];
            ll walk_time=to[2];

           

            ll nt=min(dp[v],t1)-bus_time;

            
            if(dp[v]-bus_time>=t2){
                nt=max(nt,dp[v]-bus_time);
            }

            nt=max(nt,dp[v]-walk_time);

            
            if(nt>=0){
            
                pq.push({nt,nx});
            }
        }
    }



    if(dp[1]<0){
        dp[1]=-1;
    } 

    cout<<dp[1]<<endl;


    
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