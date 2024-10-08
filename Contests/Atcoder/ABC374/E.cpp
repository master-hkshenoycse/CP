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
    cin>>n>>x;

    vector<vector<ll> >a(n,vector<ll> (4));
    for(ll i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
    }

    ll lo=0,hi=1e9,ans=0;
    while(hi>=lo){
        ll mid=(hi+lo)/2ll;
        ll cost=0;

        for(ll i=0;i<n;i++){
            vector<ll> cnt_a={(mid+a[i][0]-1)/a[i][0],0,mid/a[i][0],1};
            vector<ll> cnt_b={0,(mid+a[i][2]-1)/a[i][2],1,mid/a[i][2]};
            ll c=1e18;

            for(ll j=0;j<4;j++){
                ll req_b=max(0ll,mid-cnt_a[j]*a[i][0]);
                req_b=(req_b+a[i][2]-1)/a[i][2];
                c=min(c,cnt_a[j]*a[i][1]+req_b*a[i][3]);
            }

            for(ll j=0;j<4;j++){
                ll req_a=max(0ll,mid-cnt_b[j]*a[i][2]);
                req_a=(req_a+a[i][0]-1)/a[i][0];
                c=min(c,req_a*a[i][1]+cnt_b[j]*a[i][3]);
            }


            cost=cost+c;
        }

        if(cost<=x){
            ans=max(ans,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }

    cout<<ans<<endl;


}
int main(){
    boost;

    //pre_cum();
    prec(20);
	//fre;


    ll t=1;
    ll tc=1;
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}