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
ll get_first_y(ll x,ll r){
    ll lo=0,hi=r,ret=r+1;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;
        if(x*x+mid*mid>=r*r){
            ret=min(ret,mid);
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }

    return ret;
}

ll get_last_y(ll x,ll r){
    ll lo=0,hi=r,ret=0;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;
        if(x*x+mid*mid<(r+1)*(r+1)){
            ret=max(ret,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }

    return ret;
}
void solve(ll tc){
    ll r;
    cin>>r;
    ll ans=0;

    for(ll x=0;x<=r;x++){
        ll fst_y=get_first_y(x,r);
        ll lst_y=get_last_y(x,r);
        
        if(lst_y<fst_y){
            continue;
        }

        ll cnt_y=lst_y-fst_y+1;
        //cout<<x<<" "<<r<<" "<<fst_y<<" "<<lst_y<<endl;

        if(x>0){
            ans=ans+cnt_y*4;
            if(fst_y==0){
                ans=ans-2;
            }
        }else{
            ans=ans+cnt_y*2;
            if(fst_y==0){
                ans=ans-1;
            }
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