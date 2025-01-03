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
ll dfs(ll v,ll p,vector<vector<ll> >&adj,vector<vector<ll> > &sol){
    
    ll ind=-1;

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        ll ret=dfs(to,v,adj,sol);
        if(ind ==-1 ){
            ind=ret;
        }
    }

    if(ind==-1){
        sol.push_back({v});
        ind=sol.size()-1;
    }else{
        sol[ind].push_back(v);
    }

    return ind;

}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<vector<ll> > sol;
    vector<vector<ll> > adj(n+1);
    ll root=-1,e;
    for(ll i=1;i<=n;i++){
        cin>>e;

        if(e==i){
            root=i;
        }else{
            adj[e].pb(i);
            adj[i].pb(e);
        }
    }
    
    dfs(root,-1,adj,sol);

    cout<<sol.size()<<endl;
    for(auto s:sol){
        cout<<s.size()<<endl;
        while(s.size()>0){
            cout<<(s.back())<<" ";
            s.pop_back();
        }
    }
    cout<<endl;
    cout<<endl;
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