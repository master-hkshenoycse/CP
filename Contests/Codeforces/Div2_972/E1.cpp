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
ll solve_dp(ll r,ll c,ll l,ll n,ll m,vector<ll> &a,vector<vector< vector<ll> > > &dp,map<ll,vector<arr<ll,2> > > &help){
    if(r>=n or c>=m or l==a.size()){
        return 0;
    }

    if(help.find(a[l])==help.end()){
        return 0;
    }

    if(dp[l][r][c] != -1){
        return dp[l][r][c];
    }

    ll res=0;

    for(auto it:help[a[l]]){
        if(it[0]>=r and it[1]>=c and solve_dp(it[0]+1,it[1]+1,l+1,n,m,a,dp,help)==0){
            res=1;
            break;
        }
    }



    return dp[l][r][c]=res;

}
void solve(ll tc){
    ll l,n,m;
    cin>>l>>n>>m;
    vector<vector< vector<ll> > > dp(l,vector<vector<ll> > (n,vector<ll> (m,-1))); 
    vector<ll> a(l);
    for(ll i=0;i<l;i++){
        cin>>a[i];
    }    
    
    map<ll,vector<arr<ll,2> > >help;
    ll e;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>e;
            help[e].pb({i,j});
        }
    }

 
    if(solve_dp(0,0,0,n,m,a,dp,help)){
        cout<<"T"<<endl;
    }else{
        cout<<"N"<<endl;
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