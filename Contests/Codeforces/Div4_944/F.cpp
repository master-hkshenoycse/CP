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
    ll n;
    cin>>n;

    ll ans=0;
    for(ll i=0;i<=n+1;i++){

        ll lo=0,hi=n+1,lowest_gt_r=n+1,highest_ls_r_1=0;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;

            if(i*i + mid*mid >= n*n){
                lowest_gt_r=min(lowest_gt_r,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }


        ans=ans+4*max(0ll,highest_ls_r_1-lowest_gt_r+1);

        lo=0,hi=n+1;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;

            if(i*i + mid*mid < (n+1)*(n+1)){
                highest_ls_r_1=max(highest_ls_r_1,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
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