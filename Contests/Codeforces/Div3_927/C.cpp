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

void build(ll node,ll l,ll r,ll m,vector<ll> &segtree,vector<ll> &a){
    if(l>r){
        segtree[node]=1;
        return; 
    }

    if(l==r){
        segtree[node]=a[l];
        return;
    }

    ll mid=(l+r)/2ll;
    build(node*2,l,mid,m,segtree,a);
    build(node*2+1,mid+1,r,m,segtree,a);

    segtree[node]=(segtree[node*2]*segtree[node*2+1])%m;
}

ll query(ll node,ll l,ll r,ll st,ll en,ll m,vector<ll> &segtree){
    if(l>r){
        return 1;
    }

    if(st>r or en<l){
        return 1;
    }

    if(l>=st and r<=en){
        return segtree[node];
    }

    ll mid=(l+r)/2ll;
    return (query(node*2,l,mid,st,en,m,segtree)*query(node*2+1,mid+1,r,st,en,m,segtree))%m;

}
void solve(ll tc){ 
    ll n,m;
    cin>>n>>m;
    vector<ll> segtree(5*n+4);
    vector<ll> a(n);

    for(ll i=0;i<n;i++){
        cin>>a[i];
        a[i]%=m;
    }

    build(1,0,n-1,m,segtree,a);

    char ch;
    ll l=0,r=n-1;

    for(ll i=1;i<=n;i++){
        cout<<query(1,0,n-1,l,r,m,segtree)<<" ";
        cin>>ch;
        if(ch=='L'){
            l++;
        }else{
            r--;
        }
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
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}