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
#define dd double
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
ll is_D(ll n){



    ll lo=0,hi=1e9,ret=-1;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;

        if(mid*mid <= n){
            ret=max(ret,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }

    if(ret * ret !=n){
        ret = -1;
    }

    return ret;
}
void solve(ll tc){
    ll n;
    cin>>n;

    for(ll i=1;i<=min(1000000ll,n);i++){
        if(n%i==0){
            ll p=i;
            ll a=3;
            ll b=3*i;
            ll c=p*p-n/p;

            ll sqrt_D=is_D(b*b-4*a*c);

            if(sqrt_D == -1){
                continue;
            }

            ll num=(-b + sqrt_D);
            ll den= 2*a;

            if(num%den==0){
                ll y=num/den;
                ll x=y+i;
                
                if(x>=1 && y>=1){
                    cout<<x<<" "<<y<<endl;
                    return;
                }
            }



        }
    }

    cout<<-1<<endl;
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