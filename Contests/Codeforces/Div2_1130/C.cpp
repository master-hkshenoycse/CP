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
bool chk(ll mid,vector<ll> &a,ll k){
    ll n=a.size();
    vector<ll> reqd;

    for(ll i=0;i<n;i++){
        bool lef_req=(i==0 || a[i]-a[i-1]>mid);
        bool rig_req=(i==n-1 || a[i+1]-a[i]>mid);

        if(lef_req && rig_req)
            reqd.push_back(a[i]);
    }

    ll need=0;
    for(ll i=0;i<reqd.size();){
        if(i+1<reqd.size() && 1ll*reqd[i+1]-reqd[i]<=2ll*mid){
            need++;
            i+=2;
        }else{
            need++;
            i++;
        }

        if(need>k)
            return 0;
    }
    return 1;
}
void solve(ll tc){
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    
    ll lo=1,hi=a[n-1]-a[0];
    ll ret=hi;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;

        if(chk(mid,a,k)){
            ret=min(ret,mid);
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ret<<endl;
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