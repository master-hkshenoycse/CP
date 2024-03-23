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
ll query(ll x,ll y){
    cout<<"? "<<x<<" "<<y<<endl;
    ll z;
    cin>>z;
    return z;
}

pair<ll,ll> get_val(ll a,ll b){
    pair<ll,ll> ret={-1,-1};

    if((a+b)%2){
        return ret;
    }

    ret.ff=(a+b)/2ll;

    ret.ss=a-ret.ff;


    return ret;
}
void solve(ll tc){ 

    ll n,m;
    cin>>n>>m;

    ll d1=query(1,1); //equation x+y=d1+2
    ll d2=query(n,m); //equation n-x+m-y=d2 => x+y=n+m-d2

    //cordinates can be differnt for equation 1 and 2
    
    //find intersection with 3rd 
    ll d3=query(1,m); //equaton for x-1+m-y=d3 =>  x-y=d3+1-m;

    pair<ll,ll> r;
    
    r=get_val(d1+2,d3+1-m);
    ll x1=r.first,y1=r.second;
    x1=max(min(x1,n),1ll);
    y1=max(min(y1,m),1ll);

    r=get_val(n+m-d2,d3+1-m);
    ll x2=r.first,y2=r.second;

    x2=max(min(x2,n),1ll);
    y2=max(min(y2,m),1ll);

    if(x1>=1 and x1<=n and y1>=1 and y1<=m and query(x2,y2)>0){
        cout<<"! "<<x1<<" "<<y1<<endl;
    }else{
        cout<<"! "<<x2<<" "<<y2<<endl;
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