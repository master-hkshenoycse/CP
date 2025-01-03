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

    vector<ll> csum(2*n+2,0),indi(2*n+2,0);
    vector<ll> l(n+1),r(n+1);
    for(ll i=1;i<=n;i++){
        cin>>l[i]>>r[i];
        if(l[i]==r[i]){
            csum[l[i]]++;
            indi[l[i]]=1;
        }
    }

    for(ll i=1;i<=2*n;i++){
        csum[i]+=csum[i-1];
        indi[i]+=indi[i-1];
    }

    for(ll i=1;i<=n;i++){
        ll f=1;
        if(r[i]-l[i]+1>1){
            if(indi[r[i]]-indi[l[i]-1]==r[i]-l[i]+1){
                f=0;
            }
        }else{
            if(csum[r[i]]-csum[l[i]-1]>1){
               f=0;
            }
        }
        cout<<f;
    }

    cout<<endl;
    
    
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