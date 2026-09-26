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
    ll n,q;
    cin>>n>>q;

    vector<ll> a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    
    vector<ll> ret;

    ret.push_back(*max_element(all(a))-*min_element(all(a)));

    for(ll iter=1;iter<=60;iter++){
        vector<ll> v;
        v.reserve((n*(n-1))/2ll);
        for(ll i=0;i<n;i++)
            for(ll j=i+1;j<n;j++)
                v.push_back(a[i] ^ a[j]);
        
        nth_element(v.begin(),v.begin()+n,v.end());
        v.resize(n);
        a=move(v);

        ll mn=*min_element(a.begin(),a.end());
        ll mx=*max_element(a.begin(),a.end());

        ret.push_back(mx-mn);
    }

    while(q--){
        ll x;
        cin>>x;
        if(x<ret.size())
            cout<<ret[x]<<endl;
        else    
            cout<<0<<endl;
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