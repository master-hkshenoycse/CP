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
    ll n,x;
    cin>>n;
    ll sum=0,max_freq=0;
    map<ll,ll> freq;
    vector<ll> val(n);
    for(ll i=0;i<n;i++){
        cin>>val[i];
        ll x=val[i];
        freq[x]++;
        max_freq=max(max_freq,freq[x]);
        sum+=x;
    }

    if(max_freq>(n+1)/2){
        ll other_freq=n-max_freq;
        ll max_val=-1;
        for(auto it:freq){
            if(it.ss==max_freq){
                max_val=it.ff;
                sum-=max_val*(max_freq);
                break;
            }
        }

        sum+=max_val*min(max_freq,other_freq+2);
        cout<<sum<<endl;



    }else{
        cout<<sum<<endl;
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