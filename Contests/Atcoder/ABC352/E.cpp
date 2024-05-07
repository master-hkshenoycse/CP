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
ll par[300005];
ll sz[300005];
ll get_par(ll v){
    if(v==par[v])return v;
    return get_par(par[v]);
}

ll do_dsu(ll x,ll y){
    ll px=get_par(x);
    ll py=get_par(y);
    if(px==py){
        return 0;
    }

    if(sz[px]>sz[py]){
        swap(px,py);
    }

    par[px]=py;
    sz[py]+=sz[px];
    sz[px]=0;


    return 1;
}
void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    for(ll i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }


    ll k,c,e;
    vector<vector<ll> > comps;
    for(ll i=1;i<=m;i++){
        cin>>k>>c;
        comps.pb({c});
        for(ll i=1;i<=k;i++){
            cin>>e;
            comps.back().pb(e);
        }

    }

    sort(all(comps));

    ll ans=0;
    for(auto c:comps){
        ll sz=c.size();
        for(ll i=2;i<sz;i++){
            if(do_dsu(c[i],c[i-1])){
                ans=ans+c[0];
            }
        }
    }

    for(ll i=2;i<=n;i++){
        if(get_par(i) != get_par(i-1)){
            cout<<-1<<endl;
            return;
        }
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}