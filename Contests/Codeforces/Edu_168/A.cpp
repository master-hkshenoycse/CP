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
ll calculate(string &s){
    ll n=s.size();
    ll ret=0;

    for(ll i=0;i<n;i++){
        ret=ret+2;
        if(i>0 and s[i]==s[i-1]){
            ret--;
        }
    }

    return ret;
}
void solve(ll tc){

    string s;
    cin>>s;


    ll n=s.size();
    ll curr_cost=0;
    string sol;

    for(char ch='a';ch<='d';ch++){
        string tmp;
        for(ll i=0;i<=n;i++){
            tmp+=s.substr(0,i);
            tmp+=ch;
            if(i<n)tmp+=s.substr(i);
            if(calculate(tmp)>curr_cost){
                curr_cost=calculate(tmp);
                sol=tmp;
            }
            tmp.clear();
        }
    }

    cout<<sol<<endl;

    

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