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

    vector<vector<ll> > G(n+1,vector<ll>(n+1,0));
    vector<vector<ll> > H(n+1,vector<ll>(n+1,0));
    vector<vector<ll> > A(n+1,vector<ll>(n+1,0));

    ll mg,mh;
    cin>>mg;

    ll u,v;
    while(mg--){
        cin>>u>>v;
        G[u][v]=1;
        G[v][u]=1;
    }

    cin>>mh;
    while(mh--){
        cin>>u>>v;
        H[u][v]=1;
        H[v][u]=1;
    }

    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            cin>>A[i][j];
        }
    }

    vector<ll> mapping(n);
    for(ll i=1;i<=n;i++){
        mapping[i-1]=i;
    }

    ll ans=1e18;
    do{

        ll cost=0;
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){

                ll ni=mapping[i-1];
                ll nj=mapping[j-1];
                if(H[ni][nj] != G[i][j]){
                    cost+=A[min(ni,nj)][max(ni,nj)];
                }



            }
        }



        ans=min(ans,cost);

    }while(next_permutation(all(mapping)));

    cout<<ans<<endl;

    

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