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
ll get_msb(ll n){
    for(ll i=60;i>=0;i--){
        if(n & (1ll<<i)){
            return i;
        }
    }
}
void solve(ll tc){ 


    ll n,m;
    cin>>n>>m;

    if((n & (n-1))==0){
        cout<<-1<<endl;
        return;
    }


    ll msb_n=get_msb(n);
    ll s_msb_n=get_msb(n- (1ll<<msb_n));
    ll msb_m=get_msb(m);

    if(msb_m>s_msb_n and msb_m<msb_n){
        cout<<-1<<endl;
        return;
    }

    if(msb_m < s_msb_n){
        cout<<2<<endl;
        cout<<n<<" "<<(1ll<<(s_msb_n+1))-1<<" "<<m<<endl;
    }else{
        cout<<1<<endl;
        cout<<n<<" "<<m<<endl;
    }



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