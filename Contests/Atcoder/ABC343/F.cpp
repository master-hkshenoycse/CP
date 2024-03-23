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
    ll n1,n2,c1,c2;
    node(){
        n1=-1;
        n2=-1;
        c1=0;
        c2=0;
    }   
} ;

node tree[2000005];

node combine(node a,node b){

    map<ll,ll> help;

    if(a.n1>=0){
        help[a.n1]+=a.c1;
    }

    if(a.n2>=0){
        help[a.n2]+=a.c2;
    }

    if(b.n1>=0){
        help[b.n1]+=b.c1;
    }

    if(b.n2>=0){
        help[b.n2]+=b.c2;
    }


    vector<arr<ll,2> > v;
    for(auto it:help){
        v.pb({it.first,it.second});
    }
    reverse(all(v));

    node ret;
    ret.n1=-1,ret.n2=-1,ret.c1=0,ret.c2=0;

    ret.n1=v[0][0];
    ret.c1=v[0][1];

    if(v.size()>1 and v[1][0]!=-1){
        ret.n2=v[1][0];
        ret.c2=v[1][1];
    }   

    return ret;
}

void upd(ll index,ll st,ll en,ll pos,ll val){
    if(st>en){
        return ;
    }

    if(st==en){
        tree[index].n1=val;
        tree[index].c1=1;
        tree[index].n2=-1;
        tree[index].c2=0;

        return ;
    }

    ll mid=(st+en)/2ll;

    if(pos<=mid){
        upd(index*2,st,mid,pos,val);
    }else{
        upd(index*2+1,mid+1,en,pos,val);
    }

    tree[index]=combine(tree[index*2],tree[index*2+1]);
}

node query(ll index,ll st,ll en,ll l,ll r){
    if(st>en or r<st or l>en){
        node tmp;
        tmp.n1=-1,tmp.n2=-1,tmp.c1=0,tmp.c2=0;
        return tmp;
    }
    
    if(st>=l and en<=r){
        //cout<<tree[index].n1<<" "<<tree[index].n2<<" "<<st<<" "<<endl;
        return tree[index];
    }

    ll mid=(st+en)/2ll;
    
    return combine(query(index*2,st,mid,l,r),query(index*2+1,mid+1,en,l,r));
}

void solve(ll tc){ 
    ll n,q;
    cin>>n>>q;



    ll ty,pos,val;
    ll l,r;
    for(ll i=1;i<=n;i++){
        cin>>val;
        upd(1,1,n,i,val);
    }

    while(q--){
        cin>>ty;
        if(ty==1){
            cin>>pos>>val;
            upd(1,1,n,pos,val);
        }else{  
            cin>>l>>r;
            cout<<query(1,1,n,l,r).c2<<endl;

        }
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