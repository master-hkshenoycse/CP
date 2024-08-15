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

ll dfs(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &get_sz,vector<ll> &max_pos,vector<ll> &min_pos,vector<ll> &pos){

    max_pos[v]=pos[v];
    min_pos[v]=pos[v];

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }

        dfs(to,v,adj,get_sz,max_pos,min_pos,pos);
        max_pos[v]=max(max_pos[v],max_pos[to]);
        min_pos[v]=min(min_pos[v],min_pos[to]);
        get_sz[v]+=get_sz[to];
    }

    get_sz[v]++;

}

void update(ll v,vector<vector<ll> > &adj,vector<ll> &max_pos,vector<ll> &min_pos,vector<ll> &pos){
    
    for(auto to:adj[v]){
        if(to>v){
            max_pos[v]=max(max_pos)
        }
    }

    
    if(v>1){
        update(v/2,adj,max_pos,min_pos,pos);
    }
}
void solve(ll tc){
    ll n,q;
    cin>>n>>q;
    
    ll p;
    vector<vector<ll> > adj(n+1);
    vector<ll> get_sz(n+1,0);
    vector<ll> is_invalid(n+1,0);

    for(ll i=2;i<=n;i++){
        cin>>p;
        adj[p].pb(i);
        adj[i].pb(p);
    }   

    vector<ll> max_pos(n+1),min_pos(n+1);

    dfs(1,-1,adj,get_sz,max_pos,min_pos,pos);

    vector<ll> pos(n+1);
    for(ll i=1;i<=n;i++){
        cin>>p;
        pos[p]=i;
    }

    ll cnt_invalid=0;
    for(ll i=1;i<=n;i++){
        ll curr_pos=pos[i];
        vector<ll> p=get_path(i);
        check(1,0,1,p,curr_pos,is_invalid);


        cnt_invalid+=is_invalid[i];
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