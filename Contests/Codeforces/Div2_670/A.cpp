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
ll get_mex(vector<ll> &a){

    //calculate mex

    vector<ll> cnt(105,0);
    for(auto e:a){
        cnt[e]++;
    }
    for(ll i=0;i<=101;i++){
        if(cnt[i]==0){
            return i;
        }
    }

    return -1;
}
void solve(ll tc){ 
    ll e,n;
    cin>>n;

    vector<ll> cnt(105,0);
    ll ans=0;

    for(ll i=0;i<n;i++){
        cin>>e;
        cnt[e]++;
    }


    //if an element occurs 1 time put it in a
    //if it occurs more than 1 time put it in a,b both
    //else break

    vector<ll>  a,b;
    for(ll i=0;i<=100;i++){
        if(cnt[i]==1){
            a.pb(i);
        }else if(cnt[i]>1){
            a.pb(i);
            b.pb(i);
        }else{
            break;
        }
    }

    cout<<get_mex(a)+get_mex(b)<<endl;






   
    
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