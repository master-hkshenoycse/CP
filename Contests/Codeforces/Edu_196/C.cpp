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
    int n;
    cin>>n;

    int p=1,bits=0;
    while(p<=n){
        p*=2;
        bits++;
    }

    int xr=0;
    for(int i=1;i<=n;i++)
        xr=(xr ^ i);
    
    int val = xr ^ (2*(p-1));
    int pref=0,recover=0;

    for(int b=0;b<=bits;b++){
        pref ^= (val >>b) &1;
        if(pref)recover |= (1<<b);
    }

    if(recover>=p)
        recover ^= (2*p-1);
    
    vector<int> ans(n+1,0);
    if(recover<=n && recover>0)
        ans[recover]=1;
    else
        ans[n]=1,ans[n ^ recover]=1;

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
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