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
#define fre freopen("subsonic_subway_input.txt","r",stdin),freopen("subsonic_subway_output.txt","w",stdout)
#define arr array 
using namespace std;

void solve(ll tc){
    ll n;
    cin>>n;

    vector<arr<dd,2> > a(n);
    
    dd low_speed=0.00,high_speed=1e9;
    for(ll i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
        low_speed=max(low_speed,(i*1.00+1.00)/a[i][1]);
        high_speed=min(high_speed,(i*1.00+1.00)/a[i][0]);

    }

    if(low_speed>high_speed){
        cout<<"Case #"<<tc<<": "<<-1<<endl;
    }else{
        cout<<"Case #"<<tc<<": "<<low_speed<<endl;
    }
;

    
   

    

}
int main(){
    boost;

    //pre_cum();
    prec(10);
	fre;


    ll t=1;
    ll tc=1;
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}