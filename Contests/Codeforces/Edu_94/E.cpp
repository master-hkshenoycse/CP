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
ll a[50005];
ll solve_dp(ll l,ll r,ll ex){
    if(l>r){
        return 0;
    }

    ll mi=a[l];
    for(ll i=l+1;i<=r;i++){
        mi=min(mi,a[i]);
    }

    ll res=r-l+1;

    ll prev=l-1;
    ll curr=mi-ex;  

    //break at minimum and reduce them sepratley

    for(ll i=l;i<=r;i++){
        if(a[i]==mi){
            curr=curr+solve_dp(prev+1,i-1,mi);
            prev=i;
        }
    }
    curr=curr+solve_dp(prev+1,r,mi);

    res=min(res,curr);

    return res;
}
void solve(ll tc){ 
    ll n;
    cin>>n;

    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    cout<<solve_dp(1,n,0)<<endl;

   
    
}   
int main(){
    boost;

    //pre_cum();
    //prec(20);
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