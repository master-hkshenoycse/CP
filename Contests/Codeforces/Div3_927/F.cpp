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
ll max_segtree[4000005];
ll to_propogate[4000005];

/*https://codeforces.com/contest/1932/submission/248195870*/
void push(ll ind,vector<ll> &max_segtree,vector<ll> &to_propogate){
    if(to_propogate[ind]){
        max_segtree[2*ind]=max(max_segtree[2*ind],max_segtree[ind]);
        max_segtree[2*ind+1]=max(max_segtree[2*ind+1],max_segtree[ind]);
        to_propogate[ind]=0;
        to_propogate[2*ind]=1;
        to_propogate[2*ind+1]=1;
    }
}

void update(ll node,ll st,ll en,ll l,ll r,ll val,vector<ll> &max_segtree,vector<ll> &to_propogate){

    if(st>en or st>r or en<l){
        return;
    }

    if(st>=l and en<=r){
        max_segtree[node]=max(max_segtree[node],val);
        to_propogate[node]=1;
        return;
    }

    push(node,max_segtree,to_propogate);
    ll mid=(st+en)/2ll;
    update(node*2,st,mid,l,r,val,max_segtree,to_propogate);
    update(node*2+1,mid+1,en,l,r,val,max_segtree,to_propogate);
}

ll query(ll node,ll st,ll en,ll pos,vector<ll> &max_segtree,vector<ll> &to_propogate){

    if(st==en){
        return max_segtree[node];
    }

    push(node,max_segtree,to_propogate);

    ll mid=(st+en)/2ll;

    if(pos<=mid){
        return query(node*2,st,mid,pos,max_segtree,to_propogate);
    }else{
        return query(node*2+1,mid+1,en,pos,max_segtree,to_propogate);
    }


}
void solve(ll tc){ 
    ll n,m;
    cin>>n>>m;

    vector<ll> dp(n+5,0);
    vector<ll> range_sum(n+5,0);
    vector<ll> max_segtree(4*n+5,0),to_propogate(4*n+5,0);

    

    ll l,r;
    for(ll i=1;i<=m;i++){
        cin>>l>>r;

        range_sum[l]++;
        range_sum[r+1]--;
        update(1,1,n,l,r,r,max_segtree,to_propogate);

    }   

    for(ll i=1;i<=n;i++){
        range_sum[i]+=range_sum[i-1];
    }



    for(ll i=n;i>=1;i--){
        dp[i]=dp[i+1];

        

        if(range_sum[i]>0){
            
            ll max_end=query(1,1,n,i,max_segtree,to_propogate);
            //cout<<i<<" "<<range_sum[i]<<" "<<max_end<<endl;
            dp[i]=max(dp[i],range_sum[i]+dp[max_end+1]);
            dp[i]=max(dp[i],range_sum[i]);
        }
    }

    cout<<dp[1]<<endl;




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