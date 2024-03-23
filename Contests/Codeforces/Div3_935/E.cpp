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
bool check(vector<ll> &a,ll x){
    ll l=1,r=a.size();

        while(r-l!=1){

            
        ll mid=(l+r)/2;
        cout<<mid<<endl;

        if(a[mid]<=x){
            l=mid;
        }else{
            r=mid;
        }
    }

    return a[l]==x;


}
void solve(ll tc){ 
    ll n,x;
    cin>>n>>x;

    vector<ll> a(n+1),indexof(n+1);
    

    for(ll i=1;i<=n;i++){
        cin>>a[i];
        indexof[a[i]]=i;
    }

    if(n==1){
        cout<<0<<endl;
        return;
    }

    ll l=1,r=n+1;
    vector<ll> index_accesed;
    while(r-l!=1){
        ll mid=(l+r)/2;
    
        index_accesed.pb(mid);
        

        if(a[mid]<=x){
            l=mid;
        }else{
            r=mid;
        }
    }

    
    if(a[l]==x){
        cout<<0<<endl;
        return;
    }


    ll lst_access=index_accesed.back();


    cout<<1<<endl;
    cout<<l<<" "<<indexof[x]<<endl;
    
    
    
    
     






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