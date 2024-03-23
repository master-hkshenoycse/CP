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

    ll n,k;
    cin>>n>>k;

    map<ll,ll> first_half,second_half;
    ll e;
    for(ll i=1;i<=2*n;i++){
        cin>>e;

        if(i<=n){
            first_half[e]++;
        }else{
            second_half[e]++;
        }
    }


    vector<ll> a,b;
    for(ll i=1;i<=n;i++){

        if(first_half[i]==1 and second_half[i]==1){
            if(a.size()<2*k){
                a.pb(i);
                b.pb(i);
            }
        }
    }

    if(a.size()%2){
        a.pop_back();
        b.pop_back();
    }

    for(ll i=1;i<=n;i++){
        if(first_half[i]==2){
            if(a.size()<2*k){
                a.pb(i);
                a.pb(i);
            }
        }

        if(second_half[i]==2){
            if(b.size()<2*k){
                b.pb(i);
                b.pb(i);
            }
        }
    }

    for(auto e:a){
        cout<<e<<" ";
    }
    cout<<endl;

    for(auto e:b){
        cout<<e<<" ";
    }
    cout<<endl;

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