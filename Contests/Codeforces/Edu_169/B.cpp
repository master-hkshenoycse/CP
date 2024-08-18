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
    ll l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;


    if(max(l1,l2)>min(r1,r2)){
        cout<<1<<endl;
        return;
    }

    if(l1>=l2 and r1<=r2){
        ll ans=r1-l1;
        
        if(l1>l2){
            ans++;
        }

        if(r1<r2){
            ans++;
        }

        cout<<ans<<endl;
    }else if(l2>=l1 and r2<=r1){

        ll ans=r2-l2;
        if(l2>l1){
            ans++;
        }

        if(r2<r1){
            ans++;
        }

        cout<<ans<<endl;


    }else{

        ll ans=min(r1,r2)-max(l1,l2)+2;
        cout<<ans<<endl;

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