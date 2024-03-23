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

    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll>a(n),model(m),functions(k);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    for(ll i=0;i<m;i++){
        cin>>model[i];
    }

    for(ll i=0;i<k;i++){
        cin>>functions[i];
    }

    sort(all(functions));
    ll ans=1e18,lo=0,hi=1e18;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;
        ll diff=0;  

        ll p=-1,q=-1;

        for(ll i=1;i<n;i++){
            if(a[i]-a[i-1]>mid){
                diff++;
                q=a[i];
                p=a[i-1];
            }
        }

        if(diff==0){
            ans=min(ans,mid);
            hi=mid-1;
        }else if(diff>1 or q-p>2*mid){
            lo=mid+1;
        }else{
            ll req=p+mid;
            ll f=0;
            //largest number less than equal to p+diff;
            for(ll i=0;i<m;i++){
                if(model[i]>req){
                    continue;
                }

                ll x=req-model[i];
                auto it=upper_bound(all(functions),x);
                if(it != functions.begin()){
                    it--;
                    if(q-(*it+model[i])<=mid){
                        f=1;
                        break;
                    }
                }
            }

            if(f){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }

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
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}