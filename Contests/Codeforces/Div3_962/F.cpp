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
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n),b(n),ops_poss(n,0);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    for(ll i=0;i<n;i++){
        cin>>b[i];
        
    }

    ll lo=1,hi=1e9,r=0;

    while(hi>=lo){
        ll mid=(hi+lo)/2ll;
        ll ops=0;

        for(ll i=0;i<n;i++){
            if(mid>a[i]){
                continue;
            }

            ops+=(a[i]-mid)/b[i]+1;

        }


        if(ops>=k){
            r=max(r,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }

    ll ans=0;
    for(ll i=0;i<n;i++){
        if(a[i]<r+1){
            continue;
        }

        ll ops_curr=(a[i]-(r+1))/b[i]+1;
        ll ops_poss=min(ops_curr,k);

        ans=ans+a[i]*ops_poss-b[i]*((ops_poss*ops_poss-ops_poss)/2ll);

        k-=ops_poss;
        a[i]=a[i]-ops_poss*b[i];

    }

    for(ll i=0;i<n;i++){
        if(a[i]>=r and k){
            k--;
            ans=ans+a[i];
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