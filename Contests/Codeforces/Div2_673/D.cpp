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

    ll s=0;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }

    //operations dont change the sum of values hence sum should be divisible by n
    if(s%n){
        cout<<-1<<endl;
        return;
    }

    ll req=s/n;//all values should be equal to sum/n

    vector<vector<ll> > ops;
    for(ll i=2;i<=n;i++){
        if(a[i]%i){//to transfer all the values to 1 a[i]should be divisble by i
            ll rem=i-(a[i]%i);
            ops.pb({1,i,rem});
            a[1]-=rem*1;
            a[i]+=rem*1;   
        }

        ops.pb({i,1,a[i]/i});
        a[1]+=a[i];
        a[i]=0;
    }


    for(ll i=2;i<=n;i++){
        ops.pb({1,i,req});
        a[1]-=req;
        a[i]+=req;
    }

    cout<<ops.size()<<endl;
    for(auto op:ops){
        cout<<op[0]<<" "<<op[1]<<" "<<op[2]<<endl;
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