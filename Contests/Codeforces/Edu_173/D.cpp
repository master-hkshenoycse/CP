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
    ll l,r,G;
    cin>>l>>r>>G;

    ll nx_gt=((l+G-1)/G)*G;
    ll prev_ls=(r/G)*G;



    nx_gt/=G;
    prev_ls/=G;

    ll d=-1;
    ll lx=-1,rx=-1;
    for(ll i=0;i<=30;i++){
        for(ll j=0;j<=30;j++){
            ll x=nx_gt+i;
            ll y=prev_ls-j;
            if(x<=y and __gcd(x*G,y*G)==G){
                if(G*(y-x) > d){
                    d=G*(y-x);
                    lx=G*x;
                    rx=G*y;

                }
            }
        }
    }

    cout<<lx<<" "<<rx<<endl;





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