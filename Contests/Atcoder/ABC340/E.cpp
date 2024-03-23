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
ll segtree[800005],lazy[800005];
void push(ll node,ll st,ll en){

    if(lazy[node]==0){
        return;
    }
    
    segtree[node]+=(en-st+1)*lazy[node];

    if(st != en){
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
    }

    lazy[node]=0;

}
void update(ll node,ll st,ll en,ll l,ll r,ll val){
    
    if(st>en or st>r or en<l){
        return ;
    }


    push(node,st,en);

    if(st>=l and en<=r){
        
        segtree[node]+=val*(en-st+1);

        
        if(st!=en){
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }

        lazy[node]=0;
        return;
    }

    ll mid=(st+en)/2ll;
    update(node*2,st,mid,l,r,val);
    update(node*2+1,mid+1,en,l,r,val);

    segtree[node]=segtree[node*2]+segtree[node*2+1];

}

ll query(ll node,ll st,ll en,ll pos){
    
    if(st>en){
        return 0;
    }

    push(node,st,en);
    if(st==en){
        return segtree[node];
    }

    ll mid=(st+en)/2ll;

    if(pos<=mid){
        return query(node*2,st,mid,pos);
    }else{
        return query(node*2+1,mid+1,en,pos);
    }
}


void solve(ll tc){ 
    ll n,m;
    cin>>n>>m;

    ll e;

    for(ll i=0;i<n;i++){
        cin>>e;
        update(1,0,n-1,i,i,e);
    }


    

    for(ll i=0;i<m;i++){
        cin>>e;

        ll curr_balls=query(1,0,n-1,e);
        update(1,0,n-1,e,e,-curr_balls);

        ll all_gain=curr_balls/n;
        ll rem=curr_balls%n;


        if(all_gain>0){
            update(1,0,n-1,0,n-1,all_gain);
        }



        
        if(rem>0){
            ll l=(e+1)%n;
            ll r=(e+rem)%n; 

            if(r>=l){
                update(1,0,n-1,l,r,1);
            }else{
                update(1,0,n-1,l,n-1,1);
                update(1,0,n-1,0,r,1);
            }

            /*cout<<i<<" "<<e<<" "<<l<<" "<<r<<endl;
            for(ll j=0;j<n;j++){
                cout<<j<<" "<<query(1,0,n-1,j)<<endl;
            }
            cout<<endl;*/
        }
        

    }
    
    for(ll i=0;i<n;i++){
        cout<<query(1,0,n-1,i)<<" ";
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