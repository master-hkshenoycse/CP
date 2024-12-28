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
    ll n,m,k;
    cin>>n>>k>>m;

    string s;
    cin>>s;

    /*
    it is always optimal to choose the first character as the one whose first index of occurrence 
    in the given string is the highest
    */

   string sol;
   vector<ll> found(k);
   ll count=0;

   for(auto ch:s){
        if(sol.size()==n){
            break;
        }
        count+=(found[ch-'a']==0);
        found[ch-'a']=1;

        if(count==k){
            for(ll i=0;i<k;i++){
                found[i]=0;
            }
            sol+=ch;
            count=0;
        }
   }

    if(sol.size()==n){
        cout<<"YES"<<endl;
        return;
    }else{
        cout<<"NO"<<endl;
        for(ll i=0;i<k;i++){
            if(found[i]==0){
                while(sol.size()<n){
                    sol+=char('a'+i);
                }
            }
        }
        cout<<sol<<endl;
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