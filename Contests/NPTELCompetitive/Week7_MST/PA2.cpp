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
ll get_par(ll x,vector<ll> &par){
    if(x==par[x]){
        return x;
    }
    return get_par(par[x],par);
}

ll do_dsu(ll x,ll y,vector<ll> &par,vector<ll> &sz){
    ll px=get_par(x,par);
    ll py=get_par(y,par);

    if(px==py){
        return 0;
    }

    if(sz[px]>sz[py]){
        swap(px,py);
    }

    par[px]=py;
    sz[py]+=sz[py];
    sz[px]=0;

    return 1;
}
void solve(ll tc){ 
    ll n,m;
    cin>>n;

    vector<vector<ll> > edges;
    vector<vector<ll> > cords(n+1,vector<ll> (2));
    for(ll i=1;i<=n;i++){
        cin>>cords[i][0]>>cords[i][1];
    }

    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            edges.pb({2*(abs(cords[i][0]-cords[j][0])+abs(cords[i][1]-cords[j][1])),i,j});
        }
    }

    
    vector<ll> par(n+1,-1),sz(n+1,1);
    for(ll i=1;i<=n;i++){
        par[i]=i;
    }

    sort(all(edges));
    ll ans=0;
    
    for(auto e:edges){
        ll wt=e[0];
        ll x=e[1];
        ll y=e[2];

        if(do_dsu(x,y,par,sz)){
            ans=ans+wt;
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