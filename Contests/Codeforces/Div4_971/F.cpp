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
ll get_csum(ll l,ll r,vector<ll> &csum){
    ll ret=csum[r];
    if(l-1>=0){
        ret-=csum[l-1];
    }
    return ret;
}
ll get_sum(ll ind,ll n,vector<ll> &csum){
    ll full_cycle=(ind)/n;
    ind-=full_cycle*n;

    ll start_index=full_cycle;

    //cout<<ind<<" "<<n<<" "<<full_cycle<<" "<<start_index<<endl;
    

    ll ret=full_cycle*csum[n-1];

    if(start_index+ind<n){
        ret+=get_csum(start_index,start_index+ind,csum);
    }else{
        ret+=get_csum(start_index,n-1,csum);
        ret+=get_csum(0,start_index+ind-n,csum);
    }

    return ret;



}
void solve(ll tc){
    ll n,q;
    cin>>n>>q;

    vector<ll> csum(n,0);
    for(ll i=0;i<n;i++){
        cin>>csum[i];
        if(i-1>=0){
            csum[i]+=csum[i-1];
        }
    }

    ll l,r;


    while(q--){
        cin>>l>>r;
        l--;
        r--;
        ll ans=get_sum(r,n,csum);
        if(l-1>=0){
            ans-=get_sum(l-1,n,csum);
        }
        cout<<ans<<endl;
    }




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