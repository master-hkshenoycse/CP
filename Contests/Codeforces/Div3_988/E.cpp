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

   vector<ll> vals(n+1,-1);
   ll res;
   for(ll i=2;i<=n;i++){
     cout<<"? "<<1<<" "<<i<<endl;
     cin>>res;
     vals[i]=res;
   }

   string ret;
   for(ll i=2;i<=n;i++){
        if(vals[i]>0){
            ll trail_zero=vals[i];
            ll lead_ones=i-trail_zero-1;
            for(ll j=1;j<=lead_ones;j++){
                ret=ret+'1';
            }
            for(ll j=1;j<=trail_zero;j++){
                ret=ret+'0';
            }

            ret+='1';

            for(ll j=i+1;j<=n;j++){
                if(vals[j]==vals[j-1]){
                    ret=ret+'0';
                }else{
                    ret=ret+'1';
                }
            }

            cout<<"! "<<ret<<endl;
            return;

        }
   }

   
    cout<<"! IMPOSSIBLE"<<endl;
    return;
   
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