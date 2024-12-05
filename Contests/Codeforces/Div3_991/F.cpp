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
void build(ll node,ll l,ll r,vector<ll> &tree,vector<ll> &diff){
    if(l>r){
        return;
    }


    if(l==r){
        tree[node]=diff[l];
        return;
    }

    ll mid=(l+r)/2ll;
    build(node*2,l,mid,tree,diff);
    build(node*2+1,mid+1,r,tree,diff);

    tree[node]=__gcd(tree[node*2],tree[node*2+1]);
}

ll query(ll node,ll l,ll r,ll st,ll en,vector<ll> &tree){
    if(l>r or r<st or l>en){
        return 0;
    }

    if(l>=st and r<=en){
        return tree[node];
    }

    ll mid=(l+r)/2ll;
    return __gcd(query(node*2,l,mid,st,en,tree),query(node*2+1,mid+1,r,st,en,tree));

}
void solve(ll tc){
    
    ll n,q;
    cin>>n>>q;

    vector<ll> a(n+1);
    vector<ll> tree(8*n+5);

    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    vector<ll> diff(n+1),c_diff(n+1,0);
    for(ll i=1;i<=n-1;i++){
        diff[i]=a[i+1]-a[i];
    }

    build(1,1,n-1,tree,diff);

    ll l,r;
    while(q--){
        cin>>l>>r;
        ll ret=query(1,1,n-1,l,r-1,tree);
        if(l==r){
            ret=0;
        }

        cout<<abs(ret)<<" ";
    }
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