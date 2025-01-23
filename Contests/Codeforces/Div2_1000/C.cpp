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

void dfs(ll v,ll p,vector<vector<ll> > &adj,vector<ll> &gain,ll &ans){
    ll ex_comp=adj[v].size();
    if(p != -1){
        ex_comp--;
    }
    gain[v]=0;

    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        dfs(to,v,adj,gain,ans);
        gain[v]=max(gain[v],gain[to]);
    }

    ans=max(ans,gain[v]+ex_comp);
    gain[v]=max(gain[v],ex_comp);
}

void dfs2(ll v,ll p,vector<vector<ll> >&adj,ll prev,vector<ll> &gain,ll &ans){
    vector<ll> suff,pref;
    ans=max(ans,gain[v]+prev);
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        pref.pb(gain[to]);
        suff.pb(gain[to]);
    }
    ll sz=pref.size();
    for(ll i=1;i<sz;i++){
        pref[i]=max(pref[i],pref[i-1]);
    }

    for(ll i=sz-2;i>=0;i--){
        suff[i]=max(suff[i],suff[i+1]);
    }

    ll c=0;
    for(auto to:adj[v]){
        if(to==p){
            continue;
        }
        ll nx_p=prev;
        if(c-1>=0){
            nx_p=max(nx_p,pref[c-1]);
        }
        if(c+1<sz){
            nx_p=max(nx_p,suff[c+1]);
        }

        dfs2(to,v,adj,nx_p,gain,ans);
    }
}

void solve(ll tc){
    ll n;
    cin>>n;

    vector<vector<ll> > adj(n+1);
    vector<ll> gain(n+1,0);
    ll x,y;
    for(ll i=1;i<=n-1;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    
    }

    ll ans=0;
    dfs(1,-1,adj,gain,ans);
    dfs2(1,-1,adj,0,gain,ans);
    cout<<ans<<endl;

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