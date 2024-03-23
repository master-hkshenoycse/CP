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
ll other,edges_rem;

ll dfs(ll v,ll p,vector<vector<ll> > &adj,ll lim){
    vector<ll> sz_sub;

    for(auto to:adj[v]){
        
        if(to==p){
            continue;
        }

        sz_sub.pb(dfs(to,v,adj,lim));
    }

    sort(all(sz_sub));

    ll tot=0;
    for(auto &s:sz_sub){
        if(s>=lim and other-s>=lim){
            edges_rem++;
            other-=s;
            s=0;
        }
        tot+=s;
    }
    tot++;

    return tot;
}
void solve(ll tc){ 
    ll n,k;
    cin>>n>>k;

    vector<vector<ll> > adj(n+1);
    ll x,y;
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ll lo=1,hi=n,ans=1;
    while(hi>=lo){
        ll mid=(hi+lo)/2ll;

        other=n;
        edges_rem=0;
        dfs(1,-1,adj,mid);

        if(edges_rem>=k){
            ans=max(ans,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }

    }

    cout<<ans<<endl;



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