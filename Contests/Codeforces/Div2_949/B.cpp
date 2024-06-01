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
ll get_cnt(ll v,ll p){
    ll period=(1ll<<(p+1));
    ll tot_periods=v/period;
    ll in_each=(1ll<<p);
    ll cnt=in_each*tot_periods;
    ll rem=v%period;

    cnt+=max(0ll,rem-(1ll<<p)+1);

    return cnt;

}
void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    ll lim=(m*m+m)/2ll;


    ll ans=0;
    for(ll i=0;i<=40;i++){
        ll lo=max(n-m,0ll);
        ll hi=n+m;



        ll cnt_set=get_cnt(hi,i);
        if(lo-1>=0){
            cnt_set-=get_cnt(lo-1,i);
        }

    
        if(cnt_set>0){
           // cout<<i<<" "<<" "lo<<" "hi<<" "<<cnt_set<<endl;
            ans=ans+(1ll<<i);
        }
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