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
ll get_sum(ll l,ll r){
    return ((r-l+1)*(r+l))/2ll;
}
void solve(ll tc){
    ll n,k;   
    cin>>n>>k;

    ll tot_sum=get_sum(k,k+n-1);
    ll req=tot_sum/2ll;

    ll lo=k,hi=k+n-1,r=lo;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;
        if(get_sum(k,mid)<=req){
            r=max(r,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }

    ll ans=abs(get_sum(k,r)-(tot_sum-get_sum(k,r)));
    r++;
    if(r<=k+n-1){
        ans=min(ans,abs(get_sum(k,r)-(tot_sum-get_sum(k,r))));
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
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}