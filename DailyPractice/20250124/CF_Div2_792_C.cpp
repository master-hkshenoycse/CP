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
bool check(vector<vector<ll> > &a){
    ll n=a.size(),m=a[0].size();

    for(ll i=0;i<n;i++){
        for(ll j=1;j<m;j++){
            if(a[i][j] < a[i][j-1]){
                return 0;
            }
        }
    }

    return 1;
}

void solve(ll tc){
    ll n,m;
    cin>>n>>m;


    vector<vector<ll> > a(n,vector<ll> (m,0));
    ll x=0,y=0;
    for(ll i=0;i<n;i++){

        ll ma_ind=-1,ma_val=-1e18;
        for(ll j=0;j<m;j++){
            cin>>a[i][j];

            if(a[i][j]>ma_val){
                ma_val=a[i][j];
                ma_ind=j;
            }else if(a[i][j]<ma_val){
                x=j;
                y=ma_ind;
            }
        }
    }

    for(ll i=0;i<n;i++){
        swap(a[i][x],a[i][y]);
    }

    if(check(a)){
        cout<<x+1<<" "<<y+1<<endl;
    }else{
        cout<<-1<<endl;
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