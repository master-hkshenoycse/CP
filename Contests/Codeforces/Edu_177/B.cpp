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
ll get_sum(ll st,ll en,vector<ll> &csum,ll n){
    if(en>n){
        ll ret=csum[n]-csum[st-1];
        ll len_rem=en-n;
        ll complete_segs=len_rem/n;
        ret+=csum[n]*complete_segs;
        ret+=csum[len_rem%n];
        return ret;
    }
        
    return csum[en]-csum[st-1];
}
void solve(ll tc){
    ll n,k,x;
    cin>>n>>k>>x;

    vector<ll> a(n+1),csum(n+1,0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        csum[i]=csum[i-1]+a[i];
    }

    ll ls=n*k;
    
    ll ans=0;

    for(ll i=1;i<=n;i++){
        ll lo=i,hi=ls,r=ls+1;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            //cout<<i<<" "<<mid<<" "<<get_sum(i,mid,csum,n)<<endl;
            if(get_sum(i,mid,csum,n)>=x){
                r=min(r,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        if(r>ls){
            continue;
        }

        ll fs_add=(ls-r)/n+1;
        
        ans=ans+fs_add;




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