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
    ll n;
    cin>>n;

    vector<ll> a(n+1),csum(n+1,0);

    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0){
            csum[i]=csum[i-1]+a[i];
        }else{
            csum[i]=csum[i-1];
        }
        
        
    }


    ll sm_max=-1e18,st=-1,en=-1;
    map<ll,ll> help;
    for(ll i=1;i<=n;i++){

        if(a[i]<0){
            continue;
        }

        if(help.find(a[i]) != help.end() and csum[i]-csum[help[a[i]]-1]>sm_max){
        
            sm_max=csum[i]-csum[help[a[i]]-1];
            en=i;
            st=help[a[i]];
            
        }else{
            if(help.find(a[i])==help.end()){
                help[a[i]]=i;
            }
        }
    }

    


    for(ll i=1;i<=n;i++){

        if(a[i]>=0){
            continue;
        }
        
        if(help.find(a[i]) != help.end() and csum[i]-csum[help[a[i]]-1]+2*a[i]>sm_max){
            
            sm_max=csum[i]-csum[help[a[i]]-1]+a[i]*2;
            en=i;
            st=help[a[i]];
            
        }else{
            if(help.find(a[i])==help.end()){
                help[a[i]]=i;
            }

        }
    }
       

    
    set<ll> inc;
    for(ll i=1;i<=n;i++){
        if(i<st or i>en){
            continue;
        }
        if(i==st or i==en){
            inc.insert(i);
        }else{
            if(a[i]>0){
                inc.insert(i);
            }
        }
       
    }

    cout<<sm_max<<" "<<n-inc.size()<<endl;
    for(ll i=1;i<=n;i++){
        if(inc.find(i) == inc.end()){
            cout<<i<<" ";
        }
    }

}
int main(){
    boost;

    //pre_cum();
    //prec(10);
	//fre;


    ll t=1;
    ll tc=1;
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}
