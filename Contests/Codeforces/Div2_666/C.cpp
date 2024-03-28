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

    //add multiple of n-1 the first n-1 segment
    //add multiple of 1 the last number
    //this will make all the values divisible by n
    ll n;
    cin>>n;
    vector<ll> a(n);

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    if(n==1){
        cout<<1<<" "<<1<<endl;
        cout<<-a[0]<<endl;

        cout<<1<<" "<<1<<endl;
        cout<<0<<endl;

        cout<<1<<" "<<1<<endl;
        cout<<0<<endl;
        return;
    }


    cout<<1<<" "<<n-1<<endl;
    for(ll i=0;i<n-1;i++){
        ll l=(a[i]%n);
        cout<<(n-1)*l<<" ";
        a[i]=a[i]+(n-1)*l;
    }
    cout<<endl;
    cout<<n<<" "<<n<<endl;
    cout<<-a[n-1]<<endl;
    a[n-1]=0;

    cout<<1<<" "<<n<<endl;
    for(ll i=0;i<n;i++){
        cout<<-a[i]<<" ";
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}