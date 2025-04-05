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
ll get_tot(ll chunk,ll m,ll n){
    ll lo=0,hi=m,comp_groups=0;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;
        if(mid-1 + (mid)*chunk <= m){
            comp_groups=max(comp_groups,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }

    ll tot=comp_groups*chunk*n;
    ll rem_per_row= max(0ll,m- (comp_groups+ comp_groups*chunk));
    ll ex=min(rem_per_row,chunk);
    tot+=ex*n;
    return tot;

}
void solve(ll tc){
    ll n,m,k;
    cin>>n>>m>>k;

    ll lo=1,hi=1e10,ret=1e10;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;


        

        if(get_tot(mid,m,n)>=k){
            ret=min(ret,mid);
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }

   // cout<<get_tot(4,m,n)<<endl;

    cout<<ret<<endl;
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