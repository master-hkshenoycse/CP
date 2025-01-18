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
ll calc_mex(vector<vector<ll> > &a){
    ll n=a.size();
    ll m=a[0].size();
    map<ll,ll> overall;

    for(ll j=0;j<m;j++){
        map<ll,ll> help;
        for(ll i=0;i<n;i++){
            help[a[i][j]]++;
        }

        ll mex=0;
        while(help[mex]>0){
            mex++;
        }
        overall[mex]++;
    }

    ll ret=0;
    while(overall[ret]>0){
        ret++;
    }
    return ret;
}
void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<vector<ll> > sol(n,vector<ll> (m,0));
    
    for(ll i=0;i<n;i++){
        if(i<m-1){
            for(ll j=0;j<m;j++){
                sol[i][j]=(i+j)%m;
            }
        }else{
            for(ll j=0;j<m;j++){
                if(i>0)sol[i][j]=sol[i-1][j];
            }
        }
    }

    cout<<calc_mex(sol)<<endl;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<sol[i][j]<<" ";
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