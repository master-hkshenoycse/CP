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

void dfs(ll node,ll n,vector<ll> &sz_subtree,vector<ll> &min_pos_subtree,vector<ll> &max_pos_subtree){

    if(node>n){
        return;
    }

    sz_subtree[node]=1;
    if(node*2<=n){
        dfs(node*2,n,sz_subtree,min_pos_subtree,max_pos_subtree);
        sz_subtree[node]+=sz_subtree[node*2];
        min_pos_subtree[node]=min(min_pos_subtree[node],min_pos_subtree[node*2]);
        max_pos_subtree[node]=max(max_pos_subtree[node],max_pos_subtree[node*2]);
    }


    if(node*2+1<=n){
        dfs(node*2+1,n,sz_subtree,min_pos_subtree,max_pos_subtree);
        sz_subtree[node]+=sz_subtree[node*2+1];
        min_pos_subtree[node]=min(min_pos_subtree[node],min_pos_subtree[node*2+1]);
        max_pos_subtree[node]=max(max_pos_subtree[node],max_pos_subtree[node*2+1]);
    }

}

void update(ll node,vector<ll> &pos,vector<ll> &min_pos_subtree,vector<ll> &max_pos_subtree,vector<ll> &is_invalid,vector<ll> &sz_subtree,ll &cnt_invalid){

    ll n=pos.size()-1;
    min_pos_subtree[node]=pos[node];
    max_pos_subtree[node]=pos[node];

    if(node *2 <=n){
        min_pos_subtree[node]=min(min_pos_subtree[node],min_pos_subtree[node*2]);
        max_pos_subtree[node]=max(max_pos_subtree[node],max_pos_subtree[node*2]);
    }

    if(node *2+1<=n){
        min_pos_subtree[node]=min(min_pos_subtree[node],min_pos_subtree[node*2+1]);
        max_pos_subtree[node]=max(max_pos_subtree[node],max_pos_subtree[node*2+1]);
    }


    if(min_pos_subtree[node]<pos[node] or max_pos_subtree[node]>pos[node]+sz_subtree[node]-1){
        if(is_invalid[node]==0){
            cnt_invalid++;
        }
        is_invalid[node]=1;
    }else{
        if(is_invalid[node]==1){
            cnt_invalid--;
        }
        is_invalid[node]=0;
    }

    if(node>1){
        update(node/2,pos,min_pos_subtree,max_pos_subtree,is_invalid,sz_subtree,cnt_invalid);
    }


}
void solve(ll tc){
    ll n,q;
    cin>>n>>q;

    vector<ll> pos(n+1);
    vector<ll> perm(n+1);
    vector<ll> sz_subtree(n+1,0),is_invalid(n+1,0);
    vector<ll> min_pos_subtree(n+1),max_pos_subtree(n+1);
    ll e;

    for(ll i=2;i<=n;i++){
        cin>>e;//ignore as structure of tree is defined.
    }

    for(ll i=1;i<=n;i++){
        cin>>perm[i];
        e=perm[i];
        pos[e]=i;
        min_pos_subtree[e]=pos[e];
        max_pos_subtree[e]=pos[e];
    }

    
    dfs(1,n,sz_subtree,min_pos_subtree,max_pos_subtree);


    ll cnt_invalid=0;
    for(ll i=1;i<=n;i++){
        if(min_pos_subtree[i]<pos[i] or max_pos_subtree[i]>pos[i]+sz_subtree[i]-1){
            is_invalid[i]=1;
            cnt_invalid++;
        }
    }

    ll x,y;

    
    while(q--){
        
        cin>>x>>y;
        ll val_x=perm[x];
        ll val_y=perm[y];




        swap(pos[val_x],pos[val_y]);
        swap(perm[x],perm[y]);

        update(val_x,pos,min_pos_subtree,max_pos_subtree,is_invalid,sz_subtree,cnt_invalid);
        update(val_y,pos,min_pos_subtree,max_pos_subtree,is_invalid,sz_subtree,cnt_invalid);




        if(cnt_invalid==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
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