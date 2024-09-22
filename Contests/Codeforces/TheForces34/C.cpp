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
string get_rep(ll n){
    string ret;
    while(n>0){
        ret+=char('0'+(n%2));
        n/=2;
    }
    reverse(ret.begin(),ret.end());

    return ret;
}
ll get_value(string &s){
    ll ret=0;
    for(auto ch:s){
        ret=ret*2+(ch-'0');
    }
    return ret;
}
void solve(ll tc){

    ll n;
    cin>>n;

    ll ans=0;

    string rep=get_rep(n);
    ll tight=1;

    string curr;
    for(ll i=0;i<rep.size();i++){
        if(tight){
            if(rep[i]=='1'){

                if(curr.size()==0 or curr.back()=='0'){
                    curr+='1';
                }else{
                    curr+='0';
                    tight=0;
                }
            }else{
                curr+='0';
            }
        }else{

            if(curr.back()=='1'){
                curr+='0';
            }else{
                curr+='1';
            }

        }
    }

    ll value=get_value(curr);
    value/=2;
    cout<<value<<endl;


    
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