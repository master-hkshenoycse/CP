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
bool check(vector<ll> &b){
    ll n=b.size(),mex=0;
    vector<ll> suff_mex(n),used(n+2,0);
    for(ll i=n-1;i>=0;i--){
        if(b[i] <=n){
            used[b[i]]++;
        }

        while(used[mex]>0){
            mex++;
        }

        suff_mex[i]=mex;
    }

    ll mini=b[0];
    for(ll i=0;i<n-1;i++){
        mini=min(mini,b[i]);
        if(mini < suff_mex[i+1]){
            return 0;
        }
    }
    return 1;
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    ll zero_incl=0,cnt0=0;
    vector<ll> b;

    for(ll i=1;i<=n;i++){
        if(a[i]==0){
            cnt0++;

            if(zero_incl==0){
                zero_incl=1;
                b.pb(a[i]);
            }

        }else{
            b.pb(a[i]);
        }
    }

    if(cnt0 >0 && check(b)){
        cout<<n-(cnt0-1)<<endl;
    }else{
        cout<<n-cnt0<<endl;
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