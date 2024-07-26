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
ll return_cnt(ll petals,ll avail,ll m){
    return min(avail,m/petals);
}
void solve(ll tc){
    map<ll,ll> help;
    ll n,m;
    cin>>n>>m;

    vector<ll> a(n),c(n);
    ll ans=0;

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    for(ll i=0;i<n;i++){
        cin>>c[i];
    }

    for(ll i=0;i<n;i++){
        help[a[i]]=c[i];
    }   

    for(auto it:help){
        
        ll petals=it.ff;

        ll rem=m;
        ll cnt=min(help[petals],rem/petals);
        ans=max(ans,cnt*petals);
        
        if(help.find(petals+1) != help.end()){

            rem=rem-cnt*petals;
            ll cnt_gt=min(help[petals+1],rem/(petals+1));
            rem=rem-cnt_gt*(petals+1);
            
            ll ex=0;
            ex=min(cnt,min(rem,help[petals+1]-cnt_gt));
            ans=max(ans,(cnt-ex)*petals+(cnt_gt+ex)*(petals+1));


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