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

    vector<ll> a(n);
    map<ll,ll> freq;

    k=min(k,k%2+2);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        freq[a[i]]++;
    }

    while(k--){
        vector<ll> b(n);
        map<ll,ll> nx_freq;
        for(ll i=0;i<n;i++){
            freq[a[i]]--;

            ll mex=0;
            while(freq[mex]>0){
                mex++;
            }
            
            nx_freq[mex]++;
            b[i]=mex;

            freq[a[i]]++;
        }

        a=b;
        freq=nx_freq;
        
    }

    ll ans=0;
    for(ll i=0;i<n;i++){
        ans=ans+a[i];
    }
    cout<<ans<<"\n";
    
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