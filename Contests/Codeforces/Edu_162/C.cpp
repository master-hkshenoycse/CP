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
    vector<ll> cum_sum(n+1,0),count_one(n+1,0);
    ll e;

    for(ll i=1;i<=n;i++){
        cin>>e;
        cum_sum[i]=cum_sum[i-1]+e;
        count_one[i]=count_one[i-1]+(e==1);
    }   

    ll l,r;

    while(q--){
        cin>>l>>r;
        ll c_one=(count_one[r]-count_one[l-1]);
        ll sum_min=2*c_one+(r-l+1)-c_one;
        
        if((cum_sum[r]-cum_sum[l-1] < sum_min) or r==l){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }


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