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
/*https://www.youtube.com/watch?v=Ok09ORgjjJU*/
void solve(ll tc){ 
    ll n,k,y;
    cin>>n>>k>>y;

    vector<ll> a(k);
    for(ll i=0;i<k;i++){
        cin>>a[i];
    }

    //k-2 triangles will be there from k points
    //as a polygon of side k can be constructed
    ll ans=k-2;
    sort(all(a));

    vector<ll> odd_values;
    ll cnt_even=0;
    ll intial_y=y;


    //now if adjacent points are at distance 2 add the extra trainagle with edges of the main polygon
    //so trying to put points at distance of 2 in between so they will contribute to the triangle
    for(ll i=0;i<k;i++){
        ll d=0;
        if(i+1<k){
            d=a[i+1]-a[i]-1;
        }else{
            d=n-a[i]+a[0]-1;
        }

        if(d==1){
            ans++;
        }else if(d%2){
            odd_values.pb(d/2);
        }else{
            cnt_even+=d/2;
        }
    }

    sort(all(odd_values));

    for(auto g:odd_values){
        if(y>=g){
            ans=ans+g+1;
            y-=g;
        }else{
            ans+=y;
            y=0;
        }
    }

    ll even_req=min(cnt_even,y);
    ans+=even_req;
    y-=even_req;


    ll used=intial_y-y;

    ans+=used;

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