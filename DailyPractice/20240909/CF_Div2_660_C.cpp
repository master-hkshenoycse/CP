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

bool dfs(ll v,ll par,vector<vector<ll> >&adj,vector<ll> &h,vector<ll> &p,vector<ll> &act_happy){

    bool res=true;

    ll req=p[v];
    ll good_mood_children=0;
    for(auto to:adj[v]){

        if(to==par){
            continue;
        }

        res=(res & dfs(to,v,adj,h,p,act_happy));

        req+=p[to];
        good_mood_children+=act_happy[to];

    }

    p[v]=req;

    req+=h[v];    
    if(req%2 or req<0){
        res=0;
    }

    req/=2;
    if(good_mood_children > req){
        res=0;
    }

    if(req>p[v]){
        res=0;
    }

    act_happy[v]=req;
    

    



    return res;
}

void solve(ll tc){


    ll n,m;
    cin>>n>>m;
    vector<ll> p(n+1),h(n+1);
    vector<vector<ll> > adj(n+1);
    vector<ll> act_happy(n+1,0);

    for(ll i=1;i<=n;i++){
     cin>>p[i];
    }

    for(ll i=1;i<=n;i++){
     cin>>h[i];
    }

    ll x,y;
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    if(dfs(1,-1,adj,h,p,act_happy)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }





    
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