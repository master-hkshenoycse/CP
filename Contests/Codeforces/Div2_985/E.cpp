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

/*
2 can generate everyting execept odd prime 
If 2 odd primes are in input answer is -1.
If 0 odd primes are in input answer is 2.
else check if the odd prime present in input can generate all the numbers
let the odd prime be p.
It can geenrate even number if number >=2*p
It can generate odd number if number >= x-min_div(x)
min_div(x)=least prime number dividing x
*/
ll min_div[400005];
void pre_cum(){
    

    for(ll i=2;i<=400000;i++){
        if(min_div[i]==0){
            min_div[i]=i;
            for(ll j=i*i;j<=400000;j+=i){
                if(min_div[j]==0){
                    min_div[j]=i;
                }
            }
        }
    }
}
void solve(ll tc){

    ll n,e;
    cin>>n;  

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll p=0;

    

    for(ll i=0;i<n;i++){
        if(a[i]%2 and min_div[a[i]]==a[i]){
            p=a[i];
        }
    }

    if(p==0){
        cout<<2<<endl;
        return;
    }

    for(ll i=0;i<n;i++){
        if(a[i]==p){
            continue;
        }

        if(a[i]%2==0){
            if(a[i]<2*p){
                cout<<-1<<endl;
                return;
            }
        }else{
            if(a[i]-min_div[a[i]] < 2*p){
                cout<<-1<<endl;
                return;
            }
        }
    }

    cout<<p<<endl;



}
int main(){
    boost;

    pre_cum();
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