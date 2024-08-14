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
void check_contri(ll n,ll m,ll k){
    vector<vector<ll> > check(n+1,vector<ll>(m+1,0));

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){

            if(i+k-1<=n and j+k-1<=m){
                for(ll x=i;x<=i+k-1;x++){
                    for(ll y=j;y<=j+k-1;y++){
                        check[x][y]++;
                    }
                }
            }
        }
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cout<<i<<" "<<j<<" "<<check[i][j]<<endl;
        }
    }
}
void solve(ll tc){
    
    ll n,m,k;
    cin>>n>>m>>k;

    ll w;
    cin>>w;


    vector<ll> a(w);
    for(ll i=0;i<w;i++){
        cin>>a[i];
    }

    sort(all(a));
    reverse(all(a));

    vector<ll> contris;

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            ll x_start_max=min(i,n-k+1);
            ll x_start_min=max(1ll,i-k+1);

            ll y_start_max=min(j,m-k+1);
            ll y_start_min=max(1ll,j-k+1);

           // cout<<i<<" "<<j<<" "<<(  (x_start_max-x_start_min+1)*(y_start_max-y_start_min+1) )<<endl;

            contris.pb((x_start_max-x_start_min+1)*(y_start_max-y_start_min+1));

        }
    }



    sort(all(contris));
    reverse(all(contris));

    ll ans=0;
    for(ll i=0;i<w;i++){
        ans=ans+contris[i]*a[i];
    }

    cout<<ans<<endl;

    
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