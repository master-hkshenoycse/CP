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

void solve(ll tc){
    ll n,x;
    cin>>n>>x;

    vector<ll> a(n+1),csum(n+1,0);
    vector<ll> zero_nxt_cnt(n+2,-1);

    for(ll i=1;i<=n;i++){
        cin>>a[i];
        csum[i]=csum[i-1]+a[i];
    }

    for(ll i=n;i>=1;i--){
        ll lo=i+1,hi=n,nearest_gt_eq_x=n+1;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            if(csum[mid]-csum[i]>x){
                nearest_gt_eq_x=min(nearest_gt_eq_x,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        zero_nxt_cnt[i]=zero_nxt_cnt[nearest_gt_eq_x]+1;
    }

    ll ans=0;
    for(ll i=1;i<=n;i++){

        ll lo=i,hi=n,nearest_gt_eq_x=n+1;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;

            if(csum[mid]-csum[i-1]>x){
                nearest_gt_eq_x=min(nearest_gt_eq_x,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        ans=ans+(n-i+1)-(1+zero_nxt_cnt[nearest_gt_eq_x]);

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