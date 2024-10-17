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
ll solve_dp(ll ind,ll sc_1,ll sc_2,ll lim,vector<ll> &a,vector<ll> &b,vector<vector<vector<ll> > > &dp){
    if(sc_1>lim){
        return 1e9;
    }

    if(sc_2>lim){
        return 1e9;
    }

    if(ind==a.size()){
        if(sc_1==lim and sc_2==lim){
            return 0;
        }

        return 1e9;
    }

    if(dp[ind][sc_1][sc_2] != -1){
        return dp[ind][sc_1][sc_2];
    }

    ll res=1e9;
    for(ll i=0;i<3;i++){
        ll ex=(b[ind] != i);
        if(i==0){
            res=min(res,ex+solve_dp(ind+1,sc_1+a[ind],sc_2,lim,a,b,dp));
        }else if(i==1){
            res=min(res,ex+solve_dp(ind+1,sc_1,sc_2+a[ind],lim,a,b,dp));
        }else{
            res=min(res,ex+solve_dp(ind+1,sc_1,sc_2,lim,a,b,dp));
        }
    }

    return dp[ind][sc_1][sc_2]=res;


}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n),b(n);
    ll tot=0;
    for(ll i=0;i<n;i++){
        cin>>a[i]>>b[i];
        swap(a[i],b[i]);
        b[i]--;
    

        tot+=a[i];
    }



    if(tot%3){
        cout<<-1<<endl;
        return;
    }

    ll req=tot/3;

    vector<vector<vector<ll> > > dp(n,vector<vector<ll> > (req+1,vector<ll> (req+1,-1)));
    ll res=solve_dp(0,0,0,req,a,b,dp);
    if(res>=1e9){
        res=-1;
    }

    cout<<res<<endl;



}
int main(){
    boost;

    //pre_cum();
    prec(20);
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