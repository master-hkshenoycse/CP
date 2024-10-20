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
void upd(ll node,ll l,ll r,ll ind,ll val,vector<ll> &tree){
    if(l>r){
        return;
    }

    if(l==r){
        tree[node]=min(tree[node],val);
        return;
    }

    ll mid=(l+r)/2ll;
    if(ind<=mid){
        upd(node*2,l,mid,ind,val,tree);
    }else{
        upd(node*2+1,mid+1,r,ind,val,tree);
    }

    tree[node]=min(tree[node*2],tree[node*2+1]);
}

ll query(ll node,ll l,ll r,ll st,ll en,vector<ll> &tree){
    if(l>r or l>en or r<st){
        return 1e18;
    }

    if(l>=st and r<=en){
        return tree[node];
    }

    ll mid=(l+r)/2ll;
    return min(query(node*2,l,mid,st,en,tree),query(node*2+1,mid+1,r,st,en,tree));
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n+1),b(n+1),dp(n+1,1e18),csum(n+1,0);
    vector<ll> tree(6*n+5,1e18);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        csum[i]=csum[i-1]+a[i];
    }

    for(ll i=1;i<=n;i++){
        cin>>b[i];
    }

    dp[0]=0;
    dp[1]=0;
    upd(1,1,n,b[1],dp[1]+a[1],tree);

    for(ll i=2;i<=n;i++){   
        ll x=query(1,1,n,i,n,tree);
        dp[i]=min(x,dp[i]);
        upd(1,1,n,b[i],dp[i]+a[i],tree);
        /*for(ll j=1;j<i;j++){
            if(dp[j]<1e18 and b[j]>=i){
                dp[i]=min(dp[i],dp[j]+a[j]);
            }
        }*/
    }

    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans=max(ans,csum[i]-dp[i]);
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