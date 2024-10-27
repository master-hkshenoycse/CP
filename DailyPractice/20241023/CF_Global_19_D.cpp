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
    ll sum_tot=0;
    ll tot=0;


    set<ll> poss;
    poss.insert(0);

    vector<ll> a(n+1),b(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sum_tot+=a[i]*a[i];
        tot+=a[i];
    }

    for(ll i=1;i<=n;i++){
        cin>>b[i];
        sum_tot+=b[i]*b[i];
        tot+=b[i];
    }

    for(ll i=1;i<=n;i++){
        set<ll> tmp;
        for(auto e:poss){
            tmp.insert(e+a[i]);
            tmp.insert(e+b[i]);
        }

        poss=tmp;
    }

    ll ans=1e18;

    for(auto e:poss){
        ans=min(ans,sum_tot*(n-2)+e*e+(tot-e)*(tot-e));
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