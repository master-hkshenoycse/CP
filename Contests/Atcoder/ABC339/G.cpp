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
vector<ll> segtree[800005],csum_tree[800005];
ll a[200005];
vector<ll> merge(vector<ll> &a,vector<ll> &b){
    ll n=a.size(),m=b.size(),i=0,j=0;
    vector<ll> tmp;

    while(i<n and j<m){
        if(a[i]<=b[j]){
            tmp.pb(a[i]);
            i++;
        }else{
            tmp.pb(b[j]);
            j++;
        }
    }  

    while(i<n){
        tmp.pb(a[i++]);
    }  

    while(j<m){
        tmp.pb(b[j++]);
    }

    return tmp;
}

void build(ll node,ll l,ll r){
    if(l>r){
        return ;
    }

    if(l==r){
        segtree[node].push_back(a[l]);
        csum_tree[node].push_back(a[l]);
        return;
    }

    ll mid=(l+r)/2ll;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);

    segtree[node]=merge(segtree[node*2],segtree[node*2+1]);
    csum_tree[node]=segtree[node];

    ll sz=segtree[node].size();
    for(ll i=1;i<sz;i++){
        csum_tree[node][i]+=csum_tree[node][i-1];
    }

}

ll query(ll node,ll st,ll en,ll l,ll r,ll x){

    if(st>en){
        return 0;
    }

    if(l>en or r<st){
        return 0;
    }

    if(st>=l and en<=r){


        ll ind=upper_bound(all(segtree[node]),x)-segtree[node].begin();
        ind--;
        

        ll res=0;
        if(ind>=0){
            res=csum_tree[node][ind];
        }

        return res;
    }

    ll mid=(st+en)/2ll;
    return query(node*2,st,mid,l,r,x)+query(node*2+1,mid+1,en,l,r,x);

}

void solve(ll tc){

    ll n;
    cin>>n;

    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);
    
    ll q;
    cin>>q;

    ll alpha,beta,gamma;

    ll ans=0;

    while(q--){
        cin>>alpha>>beta>>gamma;
        ll l=alpha^ans;
        ll r=beta^ans;
        ll x=gamma^ans;

        //cout<<l<<" "<<r<<" "<<x<<endl;

        ans=query(1,1,n,l,r,x);

        cout<<ans<<endl;

    }


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