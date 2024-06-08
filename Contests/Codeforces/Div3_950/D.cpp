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

    vector<ll> a(n+2),b(n+2),suffix_increasing(n+3,0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    for(ll i=1;i+1<=n;i++){
        b[i]=__gcd(a[i],a[i+1]);
    }

    
    for(ll i=n;i>=1;i--){
        if(i>=n-1){
            suffix_increasing[i]=1;
        }else{
            if(b[i]<=b[i+1] and suffix_increasing[i+1]){
                suffix_increasing[i]=1;
            }
        }
    }

    ll prev=-1;
    for(ll i=1;i<=n;i++){
        

        if(i==1){
            
            if(suffix_increasing[i+1]){
                cout<<"YES"<<endl;
                return;
            }

        }else if(i==n){
            cout<<"YES"<<endl;
            return;
        }else{
            ll curr_gc=__gcd(a[i-1],a[i+1]);
            ll nx_gc=1e9;
            if(i+2<=n)nx_gc=__gcd(a[i+1],a[i+2]);
            //cout<<i<<" "<<curr_gc<<" "<<nx_gc<<endl;

            if(curr_gc>=prev and curr_gc<=nx_gc){
                
                if(suffix_increasing[i+1]){
                    cout<<"YES"<<endl;
                    return;
                }

            }
        }

       // cout<<prev<<" ";
        if(i>1){
            ll curr=__gcd(a[i],a[i-1]);
            if(curr < prev){
                break;
            }
            prev=curr;
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