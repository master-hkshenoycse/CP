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
    
    ll ma_x=-1e18,mi_x=1e18,ma_y=-1e18,mi_y=1e18;
    ll area=0;

    ll x1,y1,x2,y2;
    for(ll i=1;i<=n;i++){
        cin>>x1>>y1>>x2>>y2;

        if(x1>x2){
            swap(x1,x2);
        }

        if(y1>y2){
            swap(y1,y2);
        }

        ma_x=max(ma_x,x2);
        mi_x=min(mi_x,x1);
        ma_y=max(ma_y,y2);
        mi_y=min(mi_y,y1);

        area+=(x2-x1)*(y2-y1);
    }

   // cout<<area<<endl;

   for(ll i=1;i<=1000000;i++){
        if(area==i*i and ma_x-mi_x==i and ma_y-mi_y==i){
            cout<<"YES"<<endl;
            return;
        }
   }

    cout<<"NO"<<endl;
    



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