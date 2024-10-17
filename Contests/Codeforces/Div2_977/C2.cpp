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
struct node{
    
    bool is_sorted;
    ll min_index,max_index;

    node(){
        is_sorted=0;
        min_index=1e9;
        max_index=-1;
    }
};

node combine(node a,node b){
    node ret;
    ret.is_sorted=(a.is_sorted and b.is_sorted);
    if(a.max_index >= b.min_index){
        ret.is_sorted=0;
    }

    ret.min_index=min(a.min_index,b.min_index);
    ret.max_index=max(a.max_index,b.max_index);
    return ret;

}

void update(ll ind,ll l,ll r,ll x,ll val,vector<node> &tree){
    if(l>r){
        return;
    }

    if(l==r){
        tree[ind].is_sorted=1;
        tree[ind].min_index=val;
        tree[ind].max_index=val;
        return;
    }

    ll mid=(l+r)/2ll;

    if(x<=mid){
        update(ind*2,l,mid,x,val,tree);
    }else{
        update(ind*2+1,mid+1,r,x,val,tree);
    }

    tree[ind]=combine(tree[ind*2],tree[ind*2+1]);
}

void solve(ll tc){

    ll e,n,m,q;
    cin>>n>>m>>q;

    vector<ll> pos(n+1,0);
    for(ll i=1;i<=n;i++){
        cin>>e;
        pos[e]=i;
    }


    vector<ll> b(m+1);
    set<ll> occ[n+1];
    for(ll i=1;i<=n;i++){
        occ[i].insert(m+i);
    }

    for(ll i=1;i<=m;i++){
        cin>>b[i];
        b[i]=pos[b[i]];
        occ[b[i]].insert(i);
    }

    vector<node> tree(n*5+4);
    for(ll i=1;i<=n;i++){
        
        update(1,1,n,i,*occ[i].begin(),tree);
    }






    if(tree[1].is_sorted){
        cout<<"YA"<<endl;
    }else{
        cout<<"TIDAK"<<endl;
    }

    ll s,t;

    while(q--){
        cin>>s>>t;
        t=pos[t];

        occ[b[s]].erase(s);
        update(1,1,n,b[s],*occ[b[s]].begin(),tree);

        b[s]=t;
        occ[b[s]].insert(s);
        update(1,1,n,b[s],*occ[b[s]].begin(),tree);

        if(tree[1].is_sorted){
            cout<<"YA"<<endl;
        }else{
            cout<<"TIDAK"<<endl;
        }

    }
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