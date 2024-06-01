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
ll get_occ(vector<ll> &help,ll l,ll r){
    
    ll en=lower_bound(all(help),r)-help.begin();
    en--;
    ll st=upper_bound(all(help),l)-help.begin();

    return max(0ll,en-st+1);

}
void solve(ll tc){

    
    string s;
    cin>>s;
    ll n=s.size();

    ll ans=0;
    //those substrings whose balance is 0 and minimum balance reached never is less than 0 can be reversed.
    map<ll,ll> help;
    help[0]++;
    ll bal=0;

    //iterating over the right end point.
    for(ll i=1;i<=n;i++){
        if(s[i-1]=='('){
            bal++;
        }else{
            bal--;
        }

        
        ans=ans+help[bal];
        help[bal]++;

        //minimum balance must be >0
        //-(bal(i)-bal(l-1))+bal(l-1)>=0
        while(help.begin()->first*2 < bal){
            help.erase(help.begin());
        }

    }

    
    

    cout<<ans<<endl;

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