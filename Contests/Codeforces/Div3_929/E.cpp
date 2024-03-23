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
ll get_sum(ll lo,ll hi){
    if(lo>hi){
        return 0;
    }
    return ((hi+lo)*(hi-lo+1))/2ll;
}
ll get_gain(ll s,ll u){
    

    if(s<=u){
        return get_sum(u-s+1,u);
    }
    
    ll tot=0;
    tot+=get_sum(1,u);
    s-=u;
    tot-=get_sum(1,s-1);

    return tot;

}
void solve(ll tc){ 
    ll n,q;
    cin>>n;

    vector<ll> a(n+1),csum(n+1,0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        csum[i]=csum[i-1]+a[i];
    }

    cin>>q;

    ll l,u;
    while(q--){
        cin>>l>>u;

        ll ans=get_gain(a[l],u);
        ll sol=l;

        ll ind=lower_bound(all(csum),csum[l-1]+u)-csum.begin();
        
    
        if(ind>n){
            ind--;
        }




        if(ind>=l and get_gain(csum[ind]-csum[l-1],u)>ans){
            ans=get_gain(csum[ind]-csum[l-1],u);
            sol=ind; 
        }

        ind--;

        if(ind>=l and get_gain(csum[ind]-csum[l-1],u)>=ans){
            ans=get_gain(csum[ind]-csum[l-1],u);
            sol=ind; 
        }

        cout<<sol<<" ";

    }

    cout<<endl;
    
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