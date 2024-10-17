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
ll get_min_cost(ll m1_output,ll m1_cost,ll m2_output,ll m2_cost,ll req){

    if(m1_output *m2_cost  < m2_output * m1_cost){
        return get_min_cost(m2_output,m2_cost,m1_output,m1_cost,req);
    }

    ll m2_outputs_used=(m2_output*m1_output)/__gcd(m1_output,m2_output);
    ll m2_used=m2_outputs_used/m2_output;//no of times m2 can be used;
    //no of times less efficient machine can be used;

    ll ret=1e10;
    for(ll i=0;i<=m2_used;i++){
        ll m1_outputs_req=max(0ll,req-i*m2_output);
        ll m1_req=(m1_outputs_req+m1_output-1)/m1_output;
        ret=min(ret,i*m2_cost+m1_req*m1_cost);
    }

    return ret;

}
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
            cost=cost+get_min_cost(a[i][0],a[i][1],a[i][2],a[i][3],mid);
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