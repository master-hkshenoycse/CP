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
/*https://codeforces.com/contest/1932/submission/248185344*/
/* Eg-12345+1234+123+12+1*/
void solve(ll tc){ 
    ll n;
    cin>>n;

    string s;
    cin>>s;

    vector<ll> prefix_sum(n,0);
    for(ll i=0;i<n;i++){
        prefix_sum[i]=s[i]-'0';
        if(i-1>=0){
            prefix_sum[i]+=prefix_sum[i-1];
        }
    }

    string sol;
    ll c=0;
    for(ll i=n-1;i>=0;i--){
        
        ll d=(c+prefix_sum[i])%10;
        //cout<<d<<" ";
        c=(c+prefix_sum[i])/10;
        sol+=char('0'+d);
        
    }   
    //cout<<endl;

    if(c>0){
        sol+=to_string(c);
    }

    
    reverse(sol.begin(),sol.end());

    ll i=0;
    while(sol[i]=='0'){
        i++;
    }
    sol=sol.substr(i);
    cout<<sol<<endl;


}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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