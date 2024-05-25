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
ll tree_prefix[800005],tree_suffix[800005];
ll dp[200005];
void upd(ll index,ll l,ll r,ll p,ll val,ll *tree){
    if(l>r){
        return;
    }

    

    if(l==r){
        tree[index]=val;
        return;
    }

    ll mid=(l+r)/2ll;
    
    if(p<=mid){
        upd(index*2,l,mid,p,val,tree);
    }else{
        upd(index*2+1,mid+1,r,p,val,tree);
    }

    tree[index]=max(tree[index*2],tree[index*2+1]);
}

ll query(ll index,ll l,ll r,ll st,ll en,ll *tree){
    if(l>r or l>en or r<st){
        return -2e18;
    }

    if(l>=st and r<=en){
        return tree[index];
    }

    ll mid=(l+r)/2ll;

    return max(query(index*2,l,mid,st,en,tree),query(index*2+1,mid+1,r,st,en,tree));
}

void solve(ll tc){
    ll n,c;
    cin>>n>>c;

    for(ll i=1;i<=n;i++){
        dp[i]=-2e18;
        if(i==1){
            
            dp[1]=0;
            upd(1,1,n,i,dp[1]+c,tree_prefix);
            upd(1,1,n,i,dp[1]-c,tree_suffix);
            
        }else{
            upd(1,1,n,i,dp[i],tree_prefix);
            upd(1,1,n,i,dp[i],tree_suffix);
        }

    }

    

    

    ll m;
    cin>>m;
    ll t,p;



    ll ans=0;
    while(m--){
        cin>>t>>p;

        ll max_prefix=query(1,1,n,1,t,tree_prefix);
        ll max_suffix=query(1,1,n,t,n,tree_suffix);

      //  cout<<t<<" "<<max_prefix<<" "<<max_suffix<<endl;

        dp[t]=max(dp[t],max_prefix-c*t+p);
        dp[t]=max(dp[t],max_suffix+c*t+p);

        ans=max(ans,dp[t]);

       // cout<<dp[t]<<endl;
        upd(1,1,n,t,dp[t]+c*t,tree_prefix);
        upd(1,1,n,t,dp[t]-c*t,tree_suffix);
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}