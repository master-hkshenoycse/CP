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
ll is_prime[500005];
vector<ll> primes;
void pre_cum(){
    for(ll i=2;i<=500000;i++){
        if(is_prime[i]==0){
            primes.pb(i);
            for(ll j=i;j<=500000;j+=i){
                is_prime[j]=1;
            }
        }
    }
}
void solve(ll tc){
    ll n;
    cin>>n;


    ll sum_so_far=0;
    ll req=n/3-1;
    

    set<ll> rem;
    for(ll i=1;i<=n;i++){
        rem.insert(i);
    }

    ll c=0;


    vector<ll> sol;

    for(ll i=1;i<=n;i++){
        if(req>0){
            
            //cout<<sum_so_far<<endl;
            while(1){
                ll lo=i*(primes[c]-1)+1;
                ll hi=i*primes[c];

                set<ll>::iterator it;
                ll h=lo-sum_so_far;
                it=rem.lower_bound(h);

                if( sum_so_far+(*it) > hi){
                    c++;
                }else{
                    sol.push_back(*it);
                    sum_so_far+=(*it);
                    rem.erase(*it);

                 //   cout<<i<<" "<<lo<<" "<<hi<<" "<<primes[c]<<" "<<(sum_so_far+i-1)/i<<endl;
                    req--;
                    break;
                }
            }
            
        }else{
            sol.push_back(*rem.begin());
            rem.erase(rem.begin());
        }
    }



    for(auto e:sol){
        cout<<e<<" ";
    }
    cout<<endl;


}
int main(){
    boost;

    pre_cum();
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