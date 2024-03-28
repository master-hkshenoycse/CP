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
    ll n,m;
    cin>>n>>m;

    vector<ll> a(n),b(m);
    vector<vector<ll> > cons(n,vector<ll> (m,1));
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    for(ll i=0;i<m;i++){
        cin>>b[i];
    }

    //greedily try getting the bits to 0
    //by selecting elements from b to get 0 at particular bit
    
    ll ans=0;
    for(ll bit=10;bit>=0;bit--){

        ll poss=1;
        for(ll i=0;i<n;i++){
            if((a[i] & (1ll<<bit))==0){
                continue;
            }

            ll f=0;
            for(ll j=0;j<m;j++){
                if(cons[i][j]==1 and (b[j] & (1ll<<bit))==0){
                    f=1;
                    break;
                }
            }

            if(f==0){
                poss=0;
                break;
            }
        }

        if(poss){
            for(ll i=0;i<n;i++){
                if((a[i] & (1ll<<bit))==0){
                    continue;
                }

                for(ll j=0;j<m;j++){
                    if(cons[i][j]==1 and (b[j] & (1ll<<bit))>0){
                        cons[i][j]=0;
                    }
                }
            }
        }else{
            ans=ans+(1ll<<bit);
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}