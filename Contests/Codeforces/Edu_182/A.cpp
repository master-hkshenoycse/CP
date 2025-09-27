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
    vector<ll> a(n+1),sum_(n+1,0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sum_[i]=sum_[i-1]+a[i];
    }

    for(ll i=1;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll a=(sum_[i])%3;
            ll b=(sum_[j]-sum_[i])%3;
            ll c=(sum_[n]-sum_[j])%3;

            if(a==b && b==c){
                cout<<i<<" "<<j<<endl;
                return;
            }
            
            if(a==1 && b==2 && c==0){
                cout<<i<<" "<<j<<endl;
                return;
            }

            if(a==1 && b==0 && c==2){
                cout<<i<<" "<<j<<endl;
                return;
            }

            if(a==0 && b==1 && c==2){
                cout<<i<<" "<<j<<endl;
                return;
            }

            if(a==0 && b==2 && c==1){
                cout<<i<<" "<<j<<endl;
                return;
            }
            
            if(a==2 && b==1 && c==0){
                cout<<i<<" "<<j<<endl;
                return;
            }

            if(a==2 && b==0 && c==1){
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }

    cout<<0<<" "<<0<<endl;

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