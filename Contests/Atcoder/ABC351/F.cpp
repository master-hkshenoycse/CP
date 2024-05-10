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
ll bit[400005];
void upd(ll ind,ll val,ll n){
    while(ind<=n){
        bit[ind]+=val;
        ind+=(ind & (-ind));
    }
}

ll query(ll ind){
    ll s=0;
    while(ind>0){
        s=s+bit[ind];
        ind-=(ind & (-ind));
    }
    return s;
}
void solve(ll tc){
    ll n;
    cin>>n;

    map<ll,ll> value_hash;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        value_hash[a[i]]++;
    }

    ll c=0;
    for(auto &it:value_hash){
        c++;
        it.ss=c;
    }

    ll ans=0;

    for(ll i=0;i<n;i++){
        ll hsh=value_hash[a[i]];
        ll value_ls=query(hsh-1);
        ans=ans+value_ls*a[i];//count how many times this element will be in +ve contribution
        upd(hsh,1,n);
    }

    for(ll i=0;i<n;i++){
        ll hsh=value_hash[a[i]];
        upd(hsh,-1,n);
    }

    for(ll i=n-1;i>=0;i--){
        ll hsh=value_hash[a[i]];
        ll value_gt=query(n)-query(hsh);
        ans=ans-value_gt*a[i];//count how many times this element will be in -ve contribution
        upd(hsh,1,n);
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}