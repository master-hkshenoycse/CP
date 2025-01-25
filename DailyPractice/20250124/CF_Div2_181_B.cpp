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
void dfs(ll v,vector<vector<ll> >&adj,vector<ll> &vis,vector<vector<ll> >&comps){
    vis[v]=1;
    comps.back().push_back(v);

    for(auto to:adj[v]){
        if(vis[to]==0){
            dfs(to,adj,vis,comps);
        }
    }
}
void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<vector<ll> > adj(n+1);

    ll x,y;
    for(ll i=1;i<=m;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }    

    vector<vector<ll> > comps;
    vector<ll> vis(n+1,0);

    vector<ll> ones;
    vector<vector<ll> > two_s;

    vector<vector<ll> > sol;
    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            comps.pb({});
            dfs(i,adj,vis,comps);
            if(comps.back().size() > 3){
                cout<<-1<<endl;
                return;
            }

            if(comps.back().size()==3){
                sol.push_back(comps.back());
            }else if(comps.back().size()==1){
                ones.pb(comps.back()[0]);
            }else if(comps.back().size()==2){
                two_s.pb(comps.back());
            }

        }
    }

    if(two_s.size()>ones.size()){
        cout<<-1<<endl;
        return;
    }

    while(two_s.size()>0){
        two_s.back().push_back(ones.back());
        sol.push_back(two_s.back());

        ones.pop_back();
        two_s.pop_back();
    }

    ll sz=ones.size();
    for(ll i=0;i<sz;i+=3){
        sol.pb({ones[i],ones[i+1],ones[i+2]});
    }

    //cout<<sol.size()<<endl;
    for(auto s:sol){
        cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<endl;
    }






}
int main(){
    boost;

    //pre_cum();
    //prec(10);
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