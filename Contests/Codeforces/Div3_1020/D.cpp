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
    ll n,m;
    cin>>n>>m;

    vector<ll> a(n),b(m);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    for(ll i=0;i<m;i++){
        cin>>b[i];
    }

    vector<ll> prefix_poss(n,0),suff_poss(m,0);
    ll c=0;
    for(ll i=0;i<n;i++){
    
        if(c<m && a[i]>=b[c]){
            c++;
        }

        prefix_poss[i]=c;

    }

    

    c=m-1;
    for(ll i=n-1;i>=0;i--){
        if(c>=0 && a[i]>=b[c]){
            suff_poss[i] = m-c;
            c--;
        }
    }







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