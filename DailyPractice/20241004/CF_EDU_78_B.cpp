/*https://codeforces.com/contest/1278/problem/D*/
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

    ll cs=0;
    vector<ll> a(2*n+1);
    for(ll i=1;i<=2*n;i++){
        cin>>a[i];
        if(a[i]==1){
            cs++;
        }else{
            cs--;
        }
    }

    if(cs==0){
        cout<<0<<endl;
        return;
    }
    ll req=-cs;
    ll ans=2*n;
    map<ll,ll> help;
    help[0]=0;


    cs=0;
    for(ll i=1;i<=2*n;i++){
        if(a[i]==1){
            cs++;
        }else{
            cs--;
        }

        ll r=cs+req;

        if(i>n and help.find(r) != help.end()){
            ans=min(ans,i-help[r]);

            
        }
        if(i<=n ){
            help[cs]=i;
        }

    }


    cs=0;
    for(ll i=n;i>=1;i--){
        if(a[i]==1){
            cs++;
        }else{
            cs--;
        }

        if(cs==-req){
            ans=min(ans,n-i+1);
        }
    }

    cs=0;
    for(ll i=n+1;i<=2*n;i++){
        if(a[i]==1){
            cs++;
        }else{
            cs--;
        }

        if(cs==-req){
            ans=min(ans,i-n);
        }
    }

    cout<<ans<<endl;

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