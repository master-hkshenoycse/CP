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

ll find_ind(vector<ll> &csum_a,ll st,ll req){

    ll lo=st;
    ll hi=csum_a.size()-1;
    ll ret=st-1;
    while(hi>=lo){
        ll mid=(hi+lo)/2ll;
        if(csum_a[mid]-csum_a[st-1]<=req){
            ret=max(ret,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }

    return ret;

}
ll solve_dp(ll ind,ll k,vector<vector<ll> >&dp,vector<ll> &csum_a,vector<ll> &b){
    if(ind==csum_a.size()){
        return 0;
    }

    if(k==b.size()){
        return 1e18;
    }

    if(dp[ind][k] != -1){
        return dp[ind][k];
    }

    ll res=solve_dp(ind,k+1,dp,csum_a,b);
    ll cost=b.size()-1-k;

    ll nx_poss=find_ind(csum_a,ind,b[k]);
    if(nx_poss>=ind){
        res=min(res,solve_dp(nx_poss+1,k,dp,csum_a,b)+cost);
    }

    return dp[ind][k]=res;


    
}
void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<ll> a(n+1),b(m+1),csum_a(n+1,0);
    
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        csum_a[i]=csum_a[i-1]+a[i];
        
    }

    for(ll i=1;i<=m;i++){
        cin>>b[i];
    }

    vector<vector<ll> > dp(n+1,vector<ll> (m+1,-1));

    ll res=solve_dp(1,1,dp,csum_a,b);
    if(res>=1e18){
        res=-1;
    }

    cout<<res<<endl;
    
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