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
    ll n,l;
    cin>>n>>l;

    vector<dd> a(n+4);
    a[0]=0;
    a[n+1]=l*1.00;

    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    dd lo=0,hi=1e9,ans=hi;

    for(ll iter=1;iter<=300;iter++){
        dd dis=0;
        dd mid=(hi+lo)/2.00;

        dd speed=1.00;
        dd rem=mid;

        for(ll i=1;i<=n+1;i++){

            dd time_req=(a[i]-a[i-1])/speed;

            if(time_req>=rem){
                dis+=speed*rem;
                break;
            }else{
                dis+=time_req*speed;
                speed=speed+1.0;
                rem-=time_req;
            }

        }





        rem=mid,speed=1.0;
        for(ll i=n;i>=0;i--){
            dd time_req=(a[i+1]-a[i])/speed;

            if(time_req>=rem){
                dis+=speed*rem;
                break;
            }else{
                dis+=time_req*speed;
                speed=speed+1.0;
                rem-=time_req;
            }
        }

        

        if(dis>=l){
            ans=min(ans,mid);
            hi=mid;
        }else{
            lo=mid;
        }
    }

    cout<<ans<<endl;



}
int main(){
    boost;

    //pre_cum();
    prec(10);
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