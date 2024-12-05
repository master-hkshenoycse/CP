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
    

    vector<ll> dp(9,-1);
    string s;

    cin>>s;
    ll n=s.size();

    for(ll i=0;i<n;i++){
        vector<ll> tmp(10,-1);
        vector<ll> poss;
        ll dig=s[i]-'0';
        poss.pb(dig);

        if(dig*dig<=9){
            poss.pb(dig *dig);
        }

        for(auto p:poss){
            for(ll j=0;j<9;j++){
                if(dp[j]==1){
                    tmp[(j+p)%9]=1;
                }
            }
        }

        for(ll j=0;j<9;j++){
            dp[j]=tmp[j];
        }

        if(i==0){
            for(auto p:poss){
                dp[p%9]=1;
            }
        }

    }


    if(dp[0]==1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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