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

    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll> a(n),b(m);
    map<ll,ll> help,curr_help;

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    for(ll i=0;i<m;i++){
        cin>>b[i];
        help[b[i]]++;
    }

    
    ll curr=0;
    ll ans=0;

    for(ll i=0;i<n;i++){
        
        curr-=min(help[a[i]],curr_help[a[i]]);//remove the current contribution to curr
        curr_help[a[i]]++;//update the frequency
        curr+=min(help[a[i]],curr_help[a[i]]);//update the current contribution

        if(i-m>=0){//remove the element
            curr-=min(help[a[i-m]],curr_help[a[i-m]]);
            curr_help[a[i-m]]--;
            curr+=min(help[a[i-m]],curr_help[a[i-m]]);
        }

        //cout<<i<<" "<<curr<<endl;
        if(i>=m-1 and curr>=k){
            ans++;
        }
    }

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