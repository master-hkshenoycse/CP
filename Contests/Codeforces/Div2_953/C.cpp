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

ll get_value(vector<ll> &a){
    ll n=a.size();
    ll ret=0;
    for(ll i=0;i<n;i++){
        ret=ret+abs(a[i]-i);
    }
    return ret;
}

void solve(ll tc){
    ll n,k;
    cin>>n>>k;


    if(k%2){
        cout<<"No"<<endl;
        return;
    }
    
    vector<ll> v;
    for(ll i=0;i<n;i++){
        v.pb(i);
    }


    reverse(all(v));
    ll mi=0,ma=get_value(v);
    reverse(all(v));
    if(k>ma){
        cout<<"No"<<endl;
        return;
    }

    ll lo=0,hi=n-1,rem=k;
    while(rem>0 and  hi>lo){
        if(rem>=2*abs(hi-lo)){
            swap(v[hi],v[lo]);
            rem-=2*abs(hi-lo);
            hi--;
            lo++;
        }else{
            hi--;
        }
    }

    cout<<"Yes"<<endl;
    
    for(auto e:v){
        cout<<e+1<<" ";
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