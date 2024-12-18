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
    ll k,l1,r1,l2,r2;
    cin>>k>>l1>>r1>>l2>>r2;
    ll mul=k;
    ll ans=0;
    k=1;
    while(k<=r2){

        ll smallest_x=r1+1,largest_x=l1-1;


        ll lo=l1,hi=r1;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            if(mid*k >= l2){
                smallest_x=min(smallest_x,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        lo=l1,hi=r1;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            if(mid * k<=r2){
                largest_x=max(largest_x,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }


        ans=ans+max(0ll,largest_x-smallest_x+1);


        k=k*mul;
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