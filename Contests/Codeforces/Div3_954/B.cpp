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
ll dx[4]={-1,1,0,0};
ll dy[4]={0,0,-1,1};
void solve(ll tc){

    ll n,m;
    cin>>n>>m;

    vector<vector<ll>  > a(n,vector<ll> (m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll ma=0;
            for(ll k=0;k<4;k++){
                ll ni=i+dx[k];
                ll nj=j+dy[k];
                if(ni>=0 and nj>=0 and ni<n and nj<m){
                    ma=max(ma,a[ni][nj]);
                }
            }

            if(a[i][j]>ma){
                a[i][j]=ma;
            }
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
       

   


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