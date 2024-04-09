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
    
    /*If n == k,one stall with price = 1,
     k > n is not possible.
     k <= ceil(n / 2),  have two stalls, with the first having price n — k + 1 and the second having price 1. 
     else not possible  i.e. k > ceil(n/2) and k != n, 
    Since you k < n, buy k/x jewels from the first stand, where x >= 2, 
    less than floor(n / 2) coins remain and at least one jewel buy at max floor(n/2) + 1 jewels, 
    but as k > ceil(n/2) , this is contradiction */

    ll n,k;
    cin>>n>>k;

    if(n==k){
        cout<<"YES"<<endl;
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }

    if(k>n){
        cout<<"NO"<<endl;
        return;
    }

    if(k > (n+1)/2ll){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    cout<<2<<endl;
    cout<<n-k+1<<" "<<1<<endl;
    



    
    
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