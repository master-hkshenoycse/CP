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
ll do_query(string &s){
    ll resp;
    cout<<"? "<<s<<endl;
    cin>>resp;
    return resp;
}
void solve(ll tc){
    ll n;
    cin>>n;

    string sol,tmp;

    while(sol.size()<n){
        tmp=sol;
        tmp+='0';

        if(do_query(tmp)){
            sol+='0';
            continue;
        }
        
        tmp=sol;
        tmp+='1';

        if(do_query(tmp)){
            sol+='1';
            continue;
        }

        break;   
    }

    while(sol.size()<n){
        tmp=sol;
        tmp='0'+sol;

        if(do_query(tmp)){
            sol='0'+sol;
        }else{
            sol='1'+sol;
        }
        
    }


    cout<<"! "<<sol<<endl;

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