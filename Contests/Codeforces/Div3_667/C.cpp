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
    ll n,a,b;
    cin>>n>>a>>b;

    ll diff=b-a;
    ll max_end=1e18;
    vector<ll> ans;

    for(ll i=1;i<=diff;i++){
        if(diff%i==0){//as it is arithmetic progression

            for(ll j=1;j<=50;j++){

                vector<ll> sol;
                sol.pb(j);
                
                ll c=0;
                if(j==b or j==a){
                    c++;
                }
                while(sol.size()<n){
                    sol.pb(sol.back()+i);
                    if(sol.back()==a or sol.back()==b){
                        c++;
                    }
                }

                
                if(c==2 and max_end>sol.back()){
                    max_end=sol.back();
                    ans=sol;
                }


            }
        }
    }

    for(auto e:ans){
        cout<<e<<" ";
    }
    cout<<endl;


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