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
void upd(ll ind,ll v,ll n,vector<ll> &bit){
    while(ind<=n){
        bit[ind]+=v;
        ind+=(ind & (-ind));
    }
}

ll query(ll ind,vector<ll> &bit){
    ll s=0;
    
    while(ind>0){
        s=s+bit[ind];
        ind-=(ind & (-ind));
    }
    return s;
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n+1,0),b(n+1,0);
    map<ll,ll> help;

    for(ll i=1;i<=n;i++){
        cin>>a[i];
        help[a[i]]=i;
    }

    ll f=1;
    for(ll i=1;i<=n;i++){
        cin>>b[i];
        if(help.find(b[i])==help.end()){
            f=0;
        }
        b[i]=help[b[i]];
    }

    if(f==0){
        cout<<"No"<<endl;
        return;
    }

    vector<ll> bit(n+1,0);
    ll inv=0;
    for(ll i=1;i<=n;i++){
        inv=inv+query(n,bit)-query(b[i],bit);
        upd(b[i],1,n,bit);
    }

    if(inv%2){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
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