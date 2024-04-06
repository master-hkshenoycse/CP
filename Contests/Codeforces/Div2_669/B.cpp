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
    vector<ll> sol;

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    sort(all(a));
    sol.pb(a.back());
    a.pop_back();
    ll gc=sol[0];
    while(a.size()>0){

        ll val_max=0,ind=-1;
        for(ll j=0;j<a.size();j++){
            if(__gcd(gc,a[j])>val_max){
                val_max=__gcd(gc,a[j]);
                ind=j;
            }
        }

        
        gc=__gcd(gc,a[ind]);
        sol.pb(a[ind]);
        a.erase(a.begin()+ind);

    }

    for(auto e:sol){
        cout<<e<<" ";
    }
    cout<<endl;
    

   
    
}   
int main(){
    boost;

    //pre_cum();
    //prec(20);
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