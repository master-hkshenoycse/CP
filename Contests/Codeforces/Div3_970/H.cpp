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
    ll n,q;
    cin>>n>>q;

    vector<ll> a(n);
    vector<ll> cnt(n+1,0);

    for(ll i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }

    for(ll i=1;i<=n;i++){
        cnt[i]+=cnt[i-1];
    }

    vector<ll> sol(n+1,n);

    for(ll i=1;i<=n;i++){


        ll lo=0,hi=i,ans=i;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            
            ll c=cnt[mid];


            for(ll k=1;k*i<=n;k++){
                c+=cnt[min(k*i+mid,n)]-cnt[k*i-1];
            }

            if(c-1>=n/2){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        sol[i]=ans;


    }

    ll x;
    while(q--){
        cin>>x;
        cout<<sol[x]<<" ";
    }

    cout<<endl;
    
    
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