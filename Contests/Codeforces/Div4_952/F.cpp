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
    ll h,n;
    cin>>h>>n;

    vector<ll> a(n),c(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    map<ll,ll> help;
    for(ll i=0;i<n;i++){
        cin>>c[i];
        help[c[i]]+=a[i];
    }
    ll lo=1,hi=1e12,ans=hi;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;

        ll curr=h;

        for(auto it:help){
            ll rep=(mid-1)/(it.ff)+1;

            if(curr/it.ss +1<=rep){
                curr=0;
                break;
            }
            curr-=rep*it.ss;
        
            if(curr<=0){
                break;
            }
        }

        if(curr<=0){
            ans=min(ans,mid);
            hi=mid-1;
        }else{
            lo=mid+1;
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