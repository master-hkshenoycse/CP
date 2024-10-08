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
#define fre freopen("prime_subtractorization_input.txt","r",stdin),freopen("prime_subtractorization_output.txt","w",stdout)
#define arr array 
using namespace std;
vector<ll> prime_list;
int pri[10000005];
void pre_cum(){


    prime_list.pb(2);
    for(ll i=2;i<=10000000;i++){
        if(pri[i]==0){
            if(i>4 and pri[i-2]==0){
                prime_list.pb(i-2);
                
            }
            for(ll j=i*i;j<=10000000;j+=i){
                pri[j]=1;
            }
        }
    }
}
void solve(ll tc){
    ll n;
    cin>>n;
    if(n<5){
        cout<<"Case #"<<tc<<": "<<0<<endl;
        return;
    }

    ll ind=lower_bound(all(prime_list),n)-prime_list.begin();
    ind--;

    if(ind<prime_list.size() and prime_list[ind]+2>n){
        ind--;
    }

 

    cout<<"Case #"<<tc<<": "<<ind+1<<endl;
    

}
int main(){
    boost;

    pre_cum();
    //prec(10);
	fre;


    ll t=1;
    ll tc=1;
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}