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

    if(n==1){
        cout<<1<<endl;
        return;
    }

    if(n%2==0){
        ll ans=0;
        for(ll i=0;i<n;i+=2){
            ans=max(ans,a[i+1]-a[i]);
        }
        cout<<ans<<endl;
        return;
    }

    ll ans=1e18;

    for(ll i=0;i<n;i++){
        vector<ll> b=a;
        if(i==0 or b[i-1] +1 != b[i]){
            b.pb(b[i]-1);
        }else if(i==n-1 or b[i+1]-1!=b[i]){
            b.pb(a[i]+1);
        }else{
            continue;
        }

        sort(all(b));

        ll curr=0;
        for(ll j=0;j<b.size();j+=2){
            curr=max(curr,b[j+1]-b[j]);
        }

        ans=min(ans,curr);


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