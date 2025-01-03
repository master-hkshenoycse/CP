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
void dfs(ll v,vector<char> &act,vector<vector<ll> >&adj,vector<ll> &curr ,vector<ll> &vis){
    curr[act[v]-'a']++;
    vis[v]=1;

    for(auto to:adj[v]){
        if(vis[to]==0){
            dfs(to,act,adj,curr,vis);
        }
    }

}
void solve(ll tc){
    ll n,m;
    cin>>n;
    m=n;
    

    vector<vector<ll> > adj(n*m);

    vector<char> act(n*m);

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll x=i*m+j;
            ll y=j*m+(n-i-1);
            cin>>act[i*m+j];
            adj[x].pb(y);
            adj[y].pb(x);
        }
    }

    vector<vector<ll> > cnt;
    vector<ll> vis(n*m,0);
    for(ll i=0;i<n*m;i++){
        if(vis[i]==0){
            vector<ll> curr(26,0);  
            dfs(i,act,adj,curr,vis);
            cnt.push_back(curr);
        }
    }

    ll ans=0;

    for(auto c:cnt){
        ll ma=0,tot=0,sum=0;
        for(ll j=0;j<26;j++){
            sum=sum+c[j]*j;
            if(c[j]>0){
                tot=tot+c[j];  
                ma=j;  
            }
        }

        ans=ans+tot*ma-sum;
    }

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
