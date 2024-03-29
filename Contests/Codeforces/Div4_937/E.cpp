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
    ll n;
    cin>>n;

    string s;
    cin>>s;

    //value of k should be mutiple of n

    for(ll i=1;i<=n;i++){
        if(n%i==0){
            ll rem=1;
            for(ll j=0;j<i;j++){
                ll diff=0;
                set<char> cnt_distinct;
                for(ll k=j;k<n;k+=i){
                    diff+=(s[k] != s[j]);
                    cnt_distinct.insert(s[k]);
                }

                //cout<<i<<" "<<s<<" "<<j<<" "<<diff<<endl;
                if(diff==0){
                    rem-=0;
                }else if(diff==1){
                    rem--;
                }else if(diff==n/i-1 and cnt_distinct.size()<=2){
                    rem--;
                }else{
                    rem-=2;
                }

                if(rem<0){
                    break;
                }


            }

            if(rem>=0){
                cout<<i<<endl;
                return;
            }
        }
    }

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