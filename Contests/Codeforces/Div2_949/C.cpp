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
ll get_lca(ll x,ll y){
    
    while(x!=y){
        if(x>y){
            x/=2;
        }else{
            y/=2;
        }
    }

    return x;
}

vector<ll> get_path(ll x,ll y){
    vector<ll> sol;

    ll lc=get_lca(x,y);

    vector<ll> x_lc,lc_y;
    

    while(x != lc){
        x_lc.pb(x);
        x/=2;
    }
    
    
    x_lc.pb(lc);

    while(y!=lc){
        lc_y.pb(y);
        y/=2;
    }

    
    

    reverse(all(lc_y));

    vector<ll> path;
    for(auto e:x_lc){
        path.pb(e);
    }

    for(auto e:lc_y){
        path.pb(e);
    }
    
    if(path.begin()==x){

    }

    return path;


}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n+1);
    

    for(ll i=1;i<=n;i++){
        cin>>a[i];
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