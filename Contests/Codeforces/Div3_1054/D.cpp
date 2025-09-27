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
    string s;
    cin>>s;
    vector<ll> a(n+1);

    vector<ll> ones,zero,one_sum,zero_sum;

    ones.pb(0);
    zero.pb(0);
    one_sum.pb(0);
    zero_sum.pb(0);


    for(ll i=1;i<=n;i++){
        if(s[i-1]=='a'){
            a[i]=0;
        }else{
            a[i]=1;
        }

        if(a[i]==0){
            zero.pb(i);
            zero_sum.pb(zero_sum.back()+i);
        }else{
            ones.pb(i);
            one_sum.pb(one_sum.back()+i);
        }
    }

    ll ans=1e18;

    ll ls_cnt=0,ls_sum=0;
    for(ll i=1;i<=n;i++){

        ll tot_one=ones.size()-1;
        ll cnt_gt=tot_one-ls_cnt;
        ll ls_const=(ls_cnt*(ls_cnt+1))/2ll;
        ll gt_const=(cnt_gt*(cnt_gt-1))/2ll;
        ll sum_ls=i*ls_cnt-ls_const-ls_sum;
        ll sum_gt=(one_sum[tot_one]-ls_sum)-(i*cnt_gt+gt_const);
        ans=min(ans,sum_ls+sum_gt);

        //cout<<i<<" "<<sum_ls<<" "<<sum_gt<<endl;

        if(a[i]==1){
            ls_cnt++;
            ls_sum+=i;
        }
    }

    ls_cnt=0,ls_sum=0;
    for(ll i=1;i<=n;i++){

        ll tot_zero=zero.size()-1;
        ll cnt_gt=tot_zero-ls_cnt;
        ll ls_const=(ls_cnt*(ls_cnt+1))/2ll;
        ll gt_const=(cnt_gt*(cnt_gt-1))/2ll;
        ll sum_ls=i*ls_cnt-ls_const-ls_sum;
        ll sum_gt=(zero_sum[tot_zero]-ls_sum)-(i*cnt_gt+gt_const);
        ans=min(ans,sum_ls+sum_gt);
        if(a[i]==0){
            ls_cnt++;
            ls_sum+=i;
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