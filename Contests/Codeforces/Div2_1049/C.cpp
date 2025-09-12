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

    vector<ll> a(n+1);

    ll odd_sum=0,even_sum=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];

        if(i%2==0){
            even_sum+=a[i];
        }else{
            odd_sum+=a[i];
        }
    }
    
    ll ans=odd_sum-even_sum;

    ll even_gain=-1e18,odd_gain=-1e18;

    for(ll i=1;i<=n;i++){

        if(i%2==0){
            ans=max(ans,odd_sum-even_sum + (i-2));
            ans=max(ans,odd_sum-even_sum+i+2*a[i]+odd_gain);
            even_gain=max(even_gain,2*a[i]-i);
        }else{
            ans=max(ans,odd_sum-even_sum+i-1);
            ans=max(ans,odd_sum-even_sum+i-2*a[i]+even_gain);
            odd_gain=max(odd_gain,-i-2*a[i]);
        }

        /*for(ll j=i+1;j<=n;j++){
            if(i%2==0 && j%2==0){
                ans=max(ans,odd_sum-even_sum+j-i);
            }

            if(i%2==1 && j%2==1){
                ans=max(ans,odd_sum-even_sum+j-i);
            }

            if(i%2==1 && j%2==0){
                ans=max(ans,odd_sum-a[i]+a[j]-(even_sum-a[j]+a[i])+j-i);
            }

            if(i%2==0 && j%2==1){
                ans=max(ans,odd_sum-a[j]+a[i]-(even_sum-a[i]+a[j])+j-i);
            }
        }*/
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