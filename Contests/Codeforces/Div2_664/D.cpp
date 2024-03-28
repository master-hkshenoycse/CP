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

    ll n,d,m;
    cin>>n>>d>>m;

    ll e;
    vector<ll> gt_m,ls_m;
    for(ll i=1;i<=n;i++){
        cin>>e;
        if(e>m){
            gt_m.pb(e);//all values>m
        }else{
            ls_m.pb(e);//all values<=m
        }
    }

    sort(all(gt_m));
    reverse(all(gt_m));

    sort(all(ls_m));

    ll ans=0;
    ll sz_gt_m=gt_m.size();
    ll sz_lse_m=ls_m.size();
    vector<ll> csum_gt(sz_gt_m+1,0),csum_lse(sz_lse_m+1,0);
    
    for(ll i=1;i<=sz_gt_m;i++){
        csum_gt[i]=csum_gt[i-1]+gt_m[i-1];
    }

    for(ll i=1;i<=sz_lse_m;i++){
        csum_lse[i]=csum_lse[i-1]+ls_m[i-1];
    }

    ans=csum_lse.back();//least possible with no value >m read

    //iterate on number of values > m which will be read
    for(ll i=1;i<=sz_gt_m;i++){
        ll rem_req=(i-1)*d;//atleast these many will be required to fill the ignored values
        ll still_left=(sz_gt_m-i)+sz_lse_m;

        
        if(still_left>=rem_req){//it is possible to fill the ignored values

            ll from_ls=max(0ll,rem_req-(sz_gt_m-i));//these many will be required from <=m set

            //least sum is 
            ll extra_ls=csum_lse.back()-csum_lse[from_ls];
            ans=max(ans,extra_ls+csum_gt[i]);
            
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}