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
ll isp[200005];
map<ll,pair<ll,ll> > spec_numbers;
void pre_cum(){
    for(ll i=2;i<=200000;i++){
        if(isp[i]==0){
            for(ll j=i*i;j<=200000;j+=i){
                isp[j]=1;
            }
        }
    }

    for(ll i=2;i<=200000;i++){
        if(isp[i]==0){
            for(ll j=2;i*j<=200000;j++){
                if(isp[j]==0){
                    spec_numbers[i*j]={i,j};
                }
            }
        }
    }
}
void solve(ll tc){
    ll e,n;
    cin>>n;
    ll c1=0,c_prime=0,c_pr_sq=0,ans=0;
    map<ll,ll> cnt;

    for(ll i=1;i<=n;i++){
        cin>>e;

        if(e==1){
            ans=ans+c_pr_sq;
            c1++;
        }else if(isp[e]==1){
            ans=ans+c_prime;
            c_prime++;
        }else if(is_sq_prime.find(e) != is_sq_prime.end()){
            ans=ans+c1;
            c_pr_sq++;
        }
    }

    cout<<ans<<endl;
    
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