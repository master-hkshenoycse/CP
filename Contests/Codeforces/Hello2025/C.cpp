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
    ll l,r;
    cin>>l>>r;

    ll a=0,c=0,b=0;
    ll hsb=0;

    for(ll i=31;i>=0;i--){
        ll b1=(l & (1ll<<i));
        ll b2=(r & (1ll<<i));

        if(hsb){
            a+=0;
            b+=(1ll<<i);
        }else{

            if(b1==b2){
                if(b1){
                    a+=(1ll<<i);
                    b+=(1ll<<i);
                }
            }else{
                  a+=(1ll<<i);
                  b+=0;
                  hsb=1;
            } 
        }
    }

    c=l;
    while(c==a or c==b){
        c++;
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
   
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