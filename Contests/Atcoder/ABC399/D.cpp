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

bool check(vector<ll> &p,vector<ll> &q,ll m){
    ll f=0;

    if(p[0]==p[1] || q[0]==q[1]){
        return 0;
    }

    if((p[0]+1)%m == p[1]){
        f++;
    }
    if((p[1]+1)%m == p[0]){
        f++;
    }

    if((q[0]+1)%m == q[1]){
        f++;
    }
    if((q[1]+1)%m == q[0]){
        f++;
    }

    return f==2;


    
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(2*n);

    map<ll,vector<ll> > pos;
    map<ll,set<ll> > neigh;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        pos[a[i]].pb(i);
        
    }

    vector<ll> is_adj(n+1,0);
    for(ll i=0;i<2*n;i++){
        if(a[i]==(a[(i+1)%(2*n)])){
            is_adj[a[i]]=1;
        }

        neigh[a[i]].insert(a[((i-1)%(2*n)+2*n)%(2*n)]);
        neigh[a[i]].insert(a[((i+1)%(2*n)+2*n)%(2*n)]);

    }

    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(is_adj[i]==0){
            for(auto nx:neigh[i]){
                
            }
        }
    }

    cout<<ans/2<<endl;

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