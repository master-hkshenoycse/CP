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
    ll n,l,r;
    cin>>n>>l>>r;

    vector<ll> a(2*n+10),pref(2*n+10,0);

    for(ll i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=(pref[i-1] ^ a[i]);
    }

    if(n%2==0){
        a[n+1]=pref[n/2];
        pref[n+1]=(pref[n] ^ a[n+1]);
        n++;
    }

    for(ll i=n+1;i<=2*n;i++){
        a[i]=pref[i/2];
        pref[i]=(pref[i-1] ^ a[i]);
    }


    ll p=pref[n];
    ll res=0;

    while(1){

        
        if(l<=n*2){
            res=(res ^ a[l]);
            break;
        }

        res=(res ^ p);
        if((l/2)%2){
            break;
        }
        l/=2ll;
    }


    cout<<res<<endl;


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