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
string get_xor(string &a,string &b){
    ll diff=a.size()-b.size();
    string ex;
    while(diff--){
        ex+='0';
    }

    b=ex+b;

    string ret;
    for(ll i=0;i<a.size();i++){
        if(a[i] != b[i]){
            ret+='1';
        }else{
            ret+='0';
        }
    }

    return ret;
}
void solve(ll tc){
    string s;
    cin>>s;
    ll n=s.size();

    ll fst_0=-1;

    string sol;
    ll l=-1,r=-1;

    for(ll i=0;i<n;i++){
        if(s[i]=='0'){
            fst_0=i;
            break;
        }
    }

    if(fst_0==-1){
        cout<<1<<" "<<n<<" "<<n<<" "<<n<<endl;
        return;
    }

    ll len_req=n-fst_0;
    
    for(ll i=0;i+len_req-1<n;i++){
        string b=s.substr(i,len_req);
        string x=get_xor(s,b);
        //cout<<b<<" "<<x<<endl;
        if(sol<x){
            sol=x;
            l=i;
            r=i+len_req-1;
        }
    }
    cout<<1<<" "<<n<<" "<<l+1<<" "<<r+1<<endl;

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