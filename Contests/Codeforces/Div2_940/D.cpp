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
ll get_msb(ll n){
    for(ll i=35;i>=0;i--){
        if(n & (1ll<<i)){
            return i;
        }
    }
    return -1;
}
void solve(ll tc){
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    vector<ll> pref(n+1,0);

    for(ll i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=(pref[i-1] ^ a[i]);
    }


    vector<vector<ll> > pref_set(35,vector<ll> (n+1,0));
    vector<vector<ll> > pref_unset(35,vector<ll> (n+1,0));

    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=31;j++){
            pref_set[j][i]=pref_set[j][i-1];
            pref_unset[j][i]=pref_unset[j][i-1];

            if(pref[i] & (1ll<<j)){
                pref_set[j][i]++;
            }else{
                pref_unset[j][i]++;
            }

        }
    }

    for(ll i=1;i<=n;i++){
        ll msb=get_msb(a[i]);

        


    }





    

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