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

    map<ll,vector<ll> > help;
    vector<ll> sol(n+1,1e9);
    ll e;

    for(ll i=1;i<=n;i++){
        cin>>e;
        help[e].pb(i);
    }

    //if an element has to be present in every subarray of size k then distance between each of adjacent index of this element <=k
    for(ll i=1;i<=n;i++){
        ll sz=help[i].size();
        if(sz==0){
            continue;
        }
        ll ma=0;
        for(ll j=0;j<sz;j++){
            if(j==0){
                ma=max(ma,help[i][j]);
            }else{
                ma=max(ma,help[i][j]-help[i][j-1]);
            }
        }
        ma=max(ma,n+1-help[i].back());
        sol[ma]=min(sol[ma],i);
    }

    for(ll i=1;i<=n;i++){
        sol[i]=min(sol[i],sol[i-1]);
    }

    for(ll i=1;i<=n;i++){
        if(sol[i]==1e9){
            sol[i]=-1;
        }
        cout<<sol[i]<<" ";
    }
    cout<<endl;

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