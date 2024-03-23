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
//inclusion exclusion

void solve(ll tc){ 
    ll n,c;
    cin>>n>>c;

    ll e;
    ll ans=((c+1)*(c+2))/2ll;//all pairs

    ll even_count=0,odd_count=0;

    for(ll i=0;i<n;i++){
        cin>>e;


        //no of pairs x+y whose sum is a[i]


        ans=ans-(e/2+1);   //pairs satisfying x+y=e
        ans=ans-(c-e+1);   //pairs satisfying y-x=e

        if(e%2==0){
            even_count++;
        }else{
            odd_count++;
        }
    }



    //for pair satisfying x+y=ai, y-x=aj;
    //this only satisfies for intger pairs if parities of ai and aj are same
    //parity same is neccesary as well as sufficient condition
    ans=ans+(even_count*(even_count+1))/2ll;
    ans=ans+(odd_count*(odd_count+1))/2ll;

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