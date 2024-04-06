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
ll dfs(ll v,ll p,vector<vector<ll> > &adj,vector<ll> &par,vector<ll> &centroid,ll n){
    
    par[v]=p;
    ll sz=1;
    ll ma_size=0;
    ll is_centroid=1;

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }

        ll cnt=dfs(to,v,adj,par,centroid,n);
        
        if(cnt > n/2){
            is_centroid=0;
        }

        sz+=cnt;
    }

    if(n-sz > n/2){
        is_centroid=0;
    }

    

    if(is_centroid){
        centroid.pb(v);
    }
    return sz;

}
void solve(ll tc){ 
    
    ll n;
    cin>>n;

    vector<vector<ll> > adj(n+1);
    ll x,y;

    vector<ll> par(n+1,-1),centroid;
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,-1,adj,par,centroid,n);


    //there can be atmost 2 centroids in a tree
    //if there are 2 centriods then they are connected
    // if tree is even vertices then definatley only one centrod

    if(centroid.size()==1){
        cout<<x<<" "<<y<<endl;
        cout<<x<<" "<<y<<endl;
    }else{
        ll c=centroid[0];//this will be the child
        
        //find a child of c
        ll i=0;
        while(adj[c][i]==par[c]){
            i++;
        }

        //disconnect this child from centroid and connect it to parent of centroid
        cout<<c<<" "<<adj[c][i]<<endl;
        cout<<par[c]<<" "<<adj[c][i]<<endl;




    }



   
    
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