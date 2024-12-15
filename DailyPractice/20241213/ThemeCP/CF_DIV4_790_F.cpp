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
    ll n,k;
    cin>>n>>k;

    map<ll,ll> help;  
    vector<ll> a(n);

    for(ll i=0;i<n;i++){
        cin>>a[i];
        help[a[i]]++;
    }

    vector<ll> x;
    for(auto it:help){
        if(it.ss >= k){
            x.push_back(it.ff);
        }
    }

    ll sz=x.size();
    ll i=0,ans=-1,l=-1,r=-1;
    while(i<sz){
        ll j=i+1;
        while(j<sz and x[j]-x[j-1]==1){
            j++;
        }

        if(j-i>ans){
            ans=j-i;
            l=x[i];
            r=x[j-1];
        }

        i=j;

    }

    if(ans==-1){
        cout<<-1<<endl;
    }else{
        cout<<l<<" "<<r<<endl; 
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