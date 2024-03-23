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
ll segtree[2000005];
void upd(ll node,ll st,ll en,ll ind,ll val){
    if(st>en){
        return;
    }

    if(st==en and ind==st){
        segtree[node]=max(segtree[node],val);
        return;
    }

    ll mid=(st+en)/2ll;
    if(ind<=mid){
        upd(node*2,st,mid,ind,val);
    }else{
        upd(node*2+1,mid+1,en,ind,val);
    }

    segtree[node]=max(segtree[node*2],segtree[node*2+1]);
}

ll query(ll node,ll st,ll en,ll l,ll r){
    if(st>en){
        return -1e9;
    }

    if(l>en or r<st){
        return -1e9;
    }

    if(st>=l and en<=r){
        return segtree[node];
    }

    ll mid=(st+en)/2ll;

    return max(query(node*2,st,mid,l,r),query(node*2+1,mid+1,en,l,r));
}

void solve(ll tc){ 
    ll n,d;
    cin>>n>>d;
    ll lim=500000;
    ll ans=1;
    ll e;
    for(ll i=1;i<=n;i++){
        cin>>e;
        ll lo=max(1ll,e-d);
        ll hi=min(lim,e+d);

        ll val=query(1,1,lim,lo,hi)+1;
        ans=max(ans,val);
        upd(1,1,lim,e,val);
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}