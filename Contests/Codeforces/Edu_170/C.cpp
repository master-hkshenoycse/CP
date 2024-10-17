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
    ll n,k;
    cin>>n>>k;

    map<ll,ll> help;
    ll e;
    vector<pair<ll,ll> > a;
    vector<ll> csum;
    for(ll i=0;i<n;i++){
        cin>>e;
        help[e]++;
    }

    for(auto it:help){
        a.pb({it.ff,it.ss});
        csum.pb(it.ss);
    }

    ll sz=a.size();

    for(ll i=1;i<sz;i++){
        csum[i]+=csum[i-1];
    }

    ll ans=0;
    ll i=0;
    while(i<sz){
        ll j=i+1;
        while(j<sz and a[j].ff-a[j-1].ff==1){
            j++;
        }

        for(ll p=i;p<j;p++){
            ll lim=min(p+k-1,j-1);
            ll r=csum[lim];
            
            if(p-1>=0){
                r-=csum[p-1];
            }
            ans=max(ans,r);
        }

        i=j;
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