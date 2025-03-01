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
void rec(ll rem,ll x,ll y,vector<arr<ll,2> > &sol){

    if(rem==0){
        return;
    }

    ll r=0,st=1;
    while((st*st-st)/2ll <= rem){
        r=st;
        st++;
    }

    for(ll i=1;i<=r;i++){
        sol.pb({x+i-1,y});
    }

    rem-=(r*r-r)/2ll;
    rec(rem,x+r,y+1,sol);


}
void solve(ll tc){
    
   ll n;
   cin>>n;

   vector<arr<ll,2> > sol;
   rec(n,0,0,sol);

   cout<<sol.size()<<endl;
   for(auto p:sol){
    cout<<p[0]<<" "<<p[1]<<endl;
   }
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