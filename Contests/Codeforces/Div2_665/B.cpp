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

    vector<ll> a(3),b(3);

    cin>>a[0]>>a[1]>>a[2];
    cin>>b[0]>>b[1]>>b[2];


    //pairs where ai=2,bi=1
    ll pair_21=min(a[2],b[1]);
    a[2]-=pair_21;
    b[1]-=pair_21;

    //pairs where ai=0,bi=2;
    ll pair_02=min(a[0],b[2]);
    a[0]-=pair_02;
    b[2]-=pair_02;


    //pairs where ai=1,bi=0;
    ll pair_10=min(a[1],b[0]);
    a[1]-=pair_10;
    b[0]-=pair_10;


    //pairs where ai=0,bi=1;
    ll pair_01=min(a[0],b[1]);
    a[0]-=pair_01;
    b[1]-=pair_01;

    

    
    
    


    //pairs where ai=0,bi=0;
    ll pair_00=min(a[0],b[0]);
    a[0]-=pair_00;
    b[0]-=pair_00;


    //pairs where ai=1,bi=1;
    ll pair_11=min(a[1],b[1]);
    a[1]-=pair_11;
    b[1]-=pair_11;


    //pairs where ai=2,bi=2;
    ll pair_22=min(a[2],b[2]);
    a[2]-=pair_22;
    b[2]-=pair_22;


    //pairs where ai=2,bi=0;
    ll pair_20=min(a[2],b[0]);
    a[2]-=pair_20;
    b[0]-=pair_20;



    //pairs where ai=1,bi=2;
    ll pair_12=min(a[1],b[2]);
    a[1]-=pair_12;
    b[2]-=pair_12;

    ll ans=pair_21*2-pair_12*2;

    cout<<ans<<endl;






   
    
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