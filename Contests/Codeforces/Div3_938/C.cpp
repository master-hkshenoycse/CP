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
    }

    ll ans=0,l=0,r=n-1;

    while(l<r){
        
        if(a[l]<=a[r]){
            if(k>=2*a[l]-1){//as first operation is done on index l
                
                a[r]-=(a[l]-1);
                k-=(2*a[l]-1);
                ans++;
                l++;

                
                if(k>0){//so that next set of l,r can start from first element
                
                    a[r]--;
                    k--;

                    if(a[r]==0){
                        ans++;
                        r--;
                    }
                }
            }else{
                break;
            }
        }else{
            if(k>=2*a[r]){
                
                a[l]-=a[r];
                k-=2*a[r];
                ans++;
                r--;
            }else{
                break;
            }
        }
    }

    if(l==r){
        if(a[l]<=k){
            ans++;
        }
    }

    cout<<ans<<endl;


    

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