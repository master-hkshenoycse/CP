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
    ll n,m;
    cin>>n>>m;


    vector<ll> c1_(m,0),c2_(m,0),r1_(n,0),r2_(n,0);
    string s;

    
    for(ll i=1;i<=n;i++){
        cin>>s;
        for(ll j=0;j<m;j++){
            c1_[j]=(c1_[j]+(s[j]-'0'))%3;
            r1_[i-1]=(r1_[i-1]+(s[j]-'0'))%3;
        }
    }

    for(ll i=1;i<=n;i++){
        cin>>s;
        for(ll j=0;j<m;j++){
            c2_[j]=(c2_[j]+(s[j]-'0'))%3;
            r2_[i-1]=(r2_[i-1]+(s[j]-'0'))%3;
        }
    }

    for(ll i=0;i<m;i++){
        if(c1_[i] != c2_[i]){
            cout<<"NO"<<endl;
            return;
        }
    }

    for(ll i=0;i<n;i++){
        if(r1_[i] != r2_[i]){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;



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