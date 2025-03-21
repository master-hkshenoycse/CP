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

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll tot_inversion=0;
    ll c1=0,c0=0;

    for(ll i=0;i<n;i++){

        if(a[i]==0){
            tot_inversion+=c1;
        }

        c1+=(a[i]==1);
        c0+=(a[i]==0);
    }

    ll ans=tot_inversion;

    ll p1=0,p0=0;

    for(ll i=0;i<n;i++){
        ll pref_1=p1;
        ll pref_0=p0;
        ll suff_1=c1-pref_1-(a[i]==1);
        ll suff_0=c0-pref_0-(a[i]==0);

        if(a[i]==0){
            p0++;
            ans=max(ans,tot_inversion - pref_1 + suff_0);
        }else{
            p1++;
            ans=max(ans,tot_inversion - suff_0 + pref_1);
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