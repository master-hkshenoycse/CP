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

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll minimumMaxima=1e15,maximumMinima=-1e15;

    ll lo=-1e15,hi=1e15;
    while(hi>=lo){
        ll mid=(hi+lo)/2ll;

        vector<ll> curr=a;
        for(ll i=0;i+1<n;i++){
            if(curr[i]>mid){
                ll ex=curr[i]-mid;
                curr[i]=mid;
                curr[i+1]+=ex;
            }
        }

        if(curr[n-1]<=mid){
            minimumMaxima=min(minimumMaxima,mid);
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }

    lo=-1e15,hi=1e15;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;

        vector<ll> curr=a;
        for(ll i=n-1;i>0;i--){
            if(curr[i]<mid){
                ll ex=mid-curr[i];
                curr[i]=mid;
                curr[i-1]-=ex;
            }
        }

        if(curr[0]>=mid){
            maximumMinima=max(maximumMinima,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }

    //cout<<minimumMaxima<<" "<<maximumMinima<<endl;


    cout<<max(0ll,minimumMaxima-maximumMinima)<<endl;

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