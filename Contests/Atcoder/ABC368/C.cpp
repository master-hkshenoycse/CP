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
ll get_cnt(ll lo,ll hi){

    ll ret=hi-lo+1;
    ll cnt_multiples=(hi/3)-(lo-1)/3;
    ret+=cnt_multiples*2;
    return ret;
}


void solve(ll tc){

    ll n,e;
    cin>>n;

    ll t=0;
    ll h;

    for(ll i=1;i<=n;i++){
        cin>>h;

        ll lo=1,hi=1e10,ch=hi;
        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            ll ac=get_cnt(t+1,t+mid);
            if(ac>=h){
                ch=min(ch,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        t+=ch;
        
    }

    cout<<t<<endl;



}
int main(){
    boost;

    //pre_cum();
    //prec(10);
	//fre;


    ll t=1;
    ll tc=1;
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}