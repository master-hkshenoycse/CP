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
ll get_solve(ll ind,ll n,vector<ll> &cnt,vector<ll> &csum,vector<ll> &csum_csum,vector<ll> &complete_){

    ll lo=1,hi=n,r=0;
    while(hi>=lo){
        ll mid=(hi+lo)/2ll;

        if(cnt[mid] <= ind){
            r=max(r,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }

    ll tot=complete_[r];
    ll rem_indx=ind-cnt[r];
    ll st=r+1;

    tot+=(csum_csum[r+rem_indx]-csum_csum[r])-csum[r]*(rem_indx);

    return tot;

}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n+1),csum(n+1,0),csum_csum(n+1,0),complete_(n+1,0),cnt(n+1,0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        csum[i]=csum[i-1]+a[i];
        csum_csum[i]=csum_csum[i-1]+csum[i];
    }
    for(ll i=1;i<=n;i++){
        complete_[i]=(csum_csum[n]-csum_csum[i-1])-csum[i-1]*(n-i+1);
        complete_[i]+=complete_[i-1];
        cnt[i]=cnt[i-1]+(n-i+1);
    }

    ll q;
    cin>>q;

    ll l,r;
    while(q--){
        cin>>l>>r;
        cout<<get_solve(r,n,cnt,csum,csum_csum,complete_)-get_solve(l-1,n,cnt,csum,csum_csum,complete_)<<endl;
    }

}
int main(){
    boost;

    //pre_cum();
    //prec(10);
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