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

void fill_set(set<ll> &x,ll n){
    for(ll i=0;i<=n+1;i++){
        x.insert(i);
    }
}
void solve(ll tc){ 

    ll n;
    cin>>n;

    vector<ll> a(n),prefix_mex(n),suffix_mex(n);

    set<ll> x;
    fill_set(x,n);

    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(x.find(a[i])!=x.end()){
            x.erase(a[i]);
        }
    }

    ll mex=*x.begin();

    fill_set(x,n);
    
    for(ll i=0;i<n;i++){
        if(x.find(a[i])!=x.end()){
            x.erase(a[i]);
        }

        prefix_mex[i]=*x.begin();
    }

    fill_set(x,n);
    for(ll i=n-1;i>=0;i--){
        if(x.find(a[i]) != x.end()){
            x.erase(a[i]);
        }
        suffix_mex[i]=*x.begin();
    }

    for(ll i=0;i+1<n;i++){
        if(prefix_mex[i]==suffix_mex[i+1]){
            cout<<2<<endl;
            cout<<1<<" "<<i+1<<endl;
            cout<<i+2<<" "<<n<<endl;
            return;
        }
    }

    cout<<-1<<endl;

 
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