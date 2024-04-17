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

    vector<ll> a(n+1);

    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }    


    //iterate till there are no three consecative index with all values >0.(
    // this will take atmost (v^1/3) iterations where v<=2e5

    while(1){
        for(ll i=1;i<=n;i++){
            ll nx=i+1;
            if(nx>n){
                nx-=n;
            }
            a[nx]=max(0ll,a[nx]-a[i]);
        }

        ll ok=1;
        for(ll i=1;i<=n;i++){
            ll j=i+1;
            if(j>n){
                j-=n;
            }

            ll k=j+1;
            if(k>n){
                k-=n;
            }

            if(a[i]>0 and a[j]>0 and a[k]>0){
                ok=0;
                break;
            }
        }

        if(ok){
            break;
        }
    }

    vector<ll> sol;
    for(ll i=1;i<=n;i++){
        ll j=i+1;
        if(j>n){
            j-=n;
        }

        if(a[i]>0 and a[j]>0){
            a[j]=0;
        }
    }

    for(ll i=0;i<=n;i++){
        if(a[i]>0){
            sol.pb(i);
        }
    }

    cout<<sol.size()<<endl;
    for(auto ind:sol){
        cout<<ind<<" ";
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