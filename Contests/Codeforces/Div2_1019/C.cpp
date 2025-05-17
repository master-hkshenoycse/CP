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

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];

        if(a[i]<=k){
            a[i]=-1;
        }else{
            a[i]=1;
        }
    }


    ll cs=0;

    set<ll> is_valid;
    for(ll i=0;i<n-1;i++){
        cs=cs+a[i];

        if(is_valid.size()>0 && is_valid.lower_bound(cs) != is_valid.end()){
            cout<<"YES"<<endl;
            return;
        }

        if(cs<=0){
            is_valid.insert(cs);
        }

    }

    is_valid.clear();
    cs=0;
    for(ll i=n-1;i>0;i--){
        cs=cs+a[i];
        
        if(is_valid.size()>0 && is_valid.lower_bound(cs) != is_valid.end()){
            cout<<"YES"<<endl;
            return;
        }

        if(cs<=0){
            is_valid.insert(cs);
        }

    }

    vector<ll> cs_suffix_val(n);
    multiset<ll> cs_suffix;
    cs=0;

    for(ll i=n-1;i>=0;i--){
        cs=cs+a[i];
        cs_suffix_val[i]=cs;
        cs_suffix.insert(cs);
    }

    cs=0;
    for(ll i=0;i<n;i++){
        cs=cs+a[i];
        if(i+2<n){
            cs_suffix.erase(cs_suffix.find(cs_suffix_val[i+1]));
            if(cs<=0){
                if(cs_suffix.size()>0 && (*cs_suffix.begin())<=0){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }        
    }

    



    cout<<"NO"<<endl;

    

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
