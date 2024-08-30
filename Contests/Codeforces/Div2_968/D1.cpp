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
ll get_mex(map<ll,ll> &help){
    ll mex=0;
    while(help[mex]>0){
        mex++;
    }

    return mex;
}

ll get_sum(ll l,ll r){
    return ((r-l+1)*(r+l))/2ll;
}
void solve(ll tc){

    ll n,m;
    cin>>n>>m;

    vector<ll> mex(n),mex_o_mex(n);
    map<ll,ll> freq;
    ll mx_mex=0;

    for(ll i=0;i<n;i++){
        ll len,e;
        cin>>len;
        
        while(len--){
            cin>>e;
            freq[e]++;
        }
        mex[i]=get_mex(freq);
        freq[mex[i]]++;
        mex_o_mex[i]=get_mex(freq);
        freq.clear();
        mx_mex=max(mx_mex,mex_o_mex[i]);
    }

    //cout<<mx_mex<<endl;
    if(m<mx_mex){
        cout<<(m+1)*mx_mex<<endl;
    }else{
        ll ans=(mx_mex+1)*mx_mex;
        ans+=get_sum(mx_mex+1,m);
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