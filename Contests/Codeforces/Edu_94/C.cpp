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
   ll n,x;
   string s;
   cin>>s;
   cin>>x;
   
   string sol;
   n=s.size();
   for(ll i=0;i<n;i++){
      sol+='1';
   }

   //for value=0 enforce that both index i-x and i+x if they exist should be equal to 0
   for(ll i=0;i<n;i++){
    if(s[i]=='0'){
        if(i-x>=0){
            sol[i-x]='0';
        }

        if(i+x<n){
            sol[i+x]='0';
        }
    }
   }

    //now check enforcing 0 does not violate values of 1.
   for(ll i=0;i<n;i++){
     if(s[i]=='1'){
        ll f=0;
        if(i-x>=0 and sol[i-x]=='1'){
            f=1;
        }

        if(i+x<n and sol[i+x]=='1'){
            f=1;
        }

        if(f==0){
            cout<<-1<<endl;
            return;
        }
     }
   }

   cout<<sol<<endl;




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