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

ll val[500005];
ll tree[2000005];

void upd(ll node,ll l,ll r,ll p){
    if(l>r){
        return;
    }

    if(l==r){
        tree[node]=val[p];
        return;
    }

    ll mid=(l+r)/2ll;

    if(p<=mid){
        upd(node*2,l,mid,p);
    }else{
        upd(node*2+1,mid+1,r,p);
    }
 
    tree[node]=tree[node*2]+tree[node*2+1];
 }

ll query(ll node,ll st,ll en,ll l,ll r){
    if(st>en or r<st or l>en){
        return 0;
    }

    if(st>=l and en<=r){
        return tree[node];
    }


    ll mid=(st+en)/2ll;
    return query(node*2,st,mid,l,r)+query(node*2+1,mid+1,en,l,r);
}


void solve(ll tc){ 
    ll n,q;
    cin>>n>>q;


    string s;
    cin>>s;
    

    for(ll i=1;i<=n-1;i++){
        val[i]=(s[i-1] != s[i]);
        upd(1,1,n-1,i);
    }



    
    ll ty,l,r;
    while(q--){
        cin>>ty>>l>>r;
        if(ty==1){
            if(l > 1){
                val[l-1]=1-val[l-1];
                upd(1,1,n-1,l-1);
            }

            if(r<n){
                val[r]=1-val[r];
                upd(1,1,n-1,r);
            }
        }else{

            ll f=1;
            if(r>l){

                //cout<<l<<" "<<r<<" "<<query(1,1,n-1,l,r-1)<<endl;
                if(query(1,1,n-1,l,r-1) != r-l){
                    f=0;
                }

            }

            if(f){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
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