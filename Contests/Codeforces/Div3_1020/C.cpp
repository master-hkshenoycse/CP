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

    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    set<ll> poss_values_x;
    for(ll i=0;i<n;i++){
        cin>>b[i];

        if(b[i] != -1){
            poss_values_x.insert(a[i]+b[i]);
        }

    }


    if (poss_values_x.size()>1) {
        cout<<0<<endl;
        return;
    }

    ll ret=1;
    if(poss_values_x.size()==0){
        
        sort(a.begin(),a.end());
        ret = (k+a[0])-(a[n-1])+1;

    }else{
        ll x=*poss_values_x.begin();
        for(ll i=0;i<n;i++){
            if(b[i]==-1 && (a[i]+k<x || a[i]>x)){
                ret=0;
            }
        }
    }

    cout<<ret<<endl;
        


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