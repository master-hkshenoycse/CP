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
    ll ans=0;
    ll n,m;
    cin>>n>>m;
    multiset<ll> end_points;
    map<ll,multiset<ll> > help;

    ll x,y;
    for(ll i=1;i<=n;i++){
        cin>>x>>y;
        help[x].insert(y);
        end_points.insert(y);
    }

    for(ll i=1;i<=m;i++){
        ll nearest_end=m+1;
        auto it=end_points.lower_bound(i);
        if(it != end_points.end()){
            nearest_end=*it;
        }

        nearest_end--;
        ans=ans+nearest_end-i+1;
       // cout<<i<<" "<<nearest_end<<endl;
        for(auto p:help[i]){
            end_points.erase(end_points.find(p));
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}