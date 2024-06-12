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
    ll n,e;
    cin>>n;

    ll ma=0,mi=0;
    ll ways_ma=1,ways_mi=1;
    ll mod=998244353;


    for(ll i=0;i<n;i++){
        cin>>e;
        ll t_ma=max({ma+e,mi+e,abs(ma+e),abs(mi+e)});
        ll t_mi=min({ma+e,mi+e,abs(ma+e),abs(mi+e)});

        ll nx_ways_ma=0;
        ll nx_ways_mi=0;

        if(t_ma==ma+e){
            nx_ways_ma=(nx_ways_ma+ways_ma)%mod;
        }
        if(t_ma==mi+e and ma!=mi){
            nx_ways_ma=(nx_ways_ma+ways_mi)%mod;
        }
        if(t_ma==abs(ma+e)){
            nx_ways_ma=(nx_ways_ma+ways_ma)%mod;
        }

        if(t_ma==abs(mi+e) and ma!=mi){
            nx_ways_ma=(nx_ways_ma+ways_mi)%mod;
        }


        
        if(t_mi==mi+e){
            nx_ways_mi=(nx_ways_mi+ways_mi)%mod;
        }

        if(t_mi==abs(mi+e) and ma!=mi){
            nx_ways_mi=(nx_ways_mi+ways_mi)%mod;
        }

        if(t_mi==abs(ma+e)){
            nx_ways_mi=(nx_ways_mi+ways_ma)%mod;
        }

        if(t_mi==ma+e and ma!=mi){
            nx_ways_mi=(nx_ways_mi+ways_ma)%mod;
        }
        

        ma=t_ma;
        mi=t_mi;
        ways_ma=nx_ways_ma;
        ways_mi=nx_ways_mi;

       // cout<<ma<<" "<<mi<<" "<<ways_ma<<" "<<ways_mi<<endl;
    }

    cout<<ways_ma<<endl;

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