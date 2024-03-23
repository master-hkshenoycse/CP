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
/*https://codeforces.com/problemset/problem/722/C
https://codeforces.com/contest/722/submission/247449838
*/
ll par[200005];
ll sz[200005];
ll ord[200005],a[200005],curr[200005],comp_sum[200005];
ll get_par(ll v){
    if(v==par[v]){
        return v;
    }
    return get_par(par[v]);
}

void do_dsu(ll x,ll n,ll &ans){
    ll next_x=x+1;
    ll prev_x=x-1;
    ans=max(ans,a[x]);
    comp_sum[x]=a[x];

    curr[x]=1;

    if(next_x<=n and curr[next_x] != -1){
        ll px=get_par(x);
        ll py=get_par(next_x);
        
        par[px]=py;

        comp_sum[py]+=comp_sum[px];
        comp_sum[px]=0;
        
        sz[py]+=sz[px];
        sz[px]=0;


        ans=max(ans,comp_sum[py]);

    }

    if(prev_x>=1 and curr[prev_x] != -1){
        ll px=get_par(x);
        ll py=get_par(prev_x);

        if(sz[px]>sz[py]){
            swap(px,py);
        }

        par[px]=py;

        comp_sum[py]+=comp_sum[px];
        comp_sum[px]=0;
        
        sz[py]+=sz[px];
        sz[px]=0;

        
        ans=max(ans,comp_sum[py]);



    }


}
void solve(ll tc){ 
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        sz[i]=1;
        comp_sum[i]=1;

        par[i]=i;
        curr[i]=-1;

        cin>>a[i];


    }

    for(ll i=1;i<=n;i++){
        cin>>ord[i];
    }

    ll ans=0;
    vector<ll> sol;
    for(ll i=n;i>=1;i--){   
        sol.pb(ans);
        do_dsu(ord[i],n,ans);
    }

    reverse(all(sol));
    for(auto e:sol){
        cout<<e<<endl;
    }
    cout<<endl;


    



}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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