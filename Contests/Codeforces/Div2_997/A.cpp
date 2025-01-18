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

    ll n,m,ans=0;
    ll x1,x2,y1,y2;

    cin>>n>>m;

    ans=n*4*m;
    ll x,y;
    
    for(ll i=0;i<n;i++){
        cin>>x>>y;

        if(i==0){
            x1=x;
            x2=x+m;
            y1=y;
            y2=y+m;
        }else{

            ll x_inter=min(x2,x1+x+m)-max(x1,x1+x);
            ll y_inter=min(y2,y2+y+m)-max(y1,y1+y);
            ans=ans-2*(x_inter+y_inter);
            x1+=x;
            x2=x1+m;
            y1+=y;
            y2=y1+m;

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