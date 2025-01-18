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
ll f[200005];
ll mod=1e9;

void pre_cum(){
    f[0]=1;
    f[1]=1;

    for(ll i=2;i<=2000;i++){
        f[i]=(f[i-1]+f[i-2])%mod;
    }
}
void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ty,l,r,x,v;

    while(m--){
        cin>>ty;

        if(ty==1){
            cin>>x>>v;
            a[x]=v;
        }else if(ty==2){
            cin>>l>>r;
            ll res=0;
            for(ll i=0;i<=r-l;i++){
                res=res+(f[i]*a[i+l])%mod;
                res%=mod;
            }
            cout<<res<<endl;
        }


    }


}
int main(){
    boost;

    pre_cum();
    //prec(10);
	//fre;


    ll t=1;
    ll tc=1;
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}