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
ll get_sum(ll l,ll r,vector<ll> &a){

    ll n=a.size();

    if(r>=l){
        ll cs=a[r];
        if(l-1>=0){
            cs-=a[l-1];
        }
        return cs;
    }

    return get_sum(l,n-1,a)+get_sum(0,r,a);
}
ll solve_dp(ll x,ll y,ll k,vector<vector<ll> > &a,vector<vector<ll> > &dp){
    
    if(x==a.size()){
        return 0;
    }

    if(dp[x][y]!=-1){
        return dp[x][y];
    }

    ll ret=1e15;

    ll n=a.size();
    ll m=a[0].size();

    ll len_lo=1;
    ll len_hi=m-y;

    if(x==n-1){
        len_lo=len_hi;
    }



    for(ll j=0;j<m;j++){
        for(ll l=len_lo;l<=len_hi;l++){
            

            ll st=(y+j)%m;
            ll en=(y+j+l-1)%m;

               
            ret=min(ret,get_sum(st,en,a[x])+j*k+solve_dp(x+1,y+l-1,k,a,dp));

        }
    }

    

    return dp[x][y]=ret;

}
void solve(ll tc){
    ll n,m,k;
    cin>>n>>m>>k;

    vector<vector<ll> > a(n,vector<ll> (m));
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){

            cin>>a[i][j];
            if(j>0){
                a[i][j]+=a[i][j-1];
            }
        }        
    }

    //vector<vector<ll> > dp(n,vector<ll> (m,-1));

    //cout<<solve_dp(0,0,k,a,dp)<<endl;
    

    vector<ll> dp(m,1e18);
    dp[0]=0;

    for(ll i=0;i<n;i++){

        vector<vector<ll> > len_value(m+1,vector<ll> (m));
        for(ll j=0;j<m;j++){
            for(ll len=1;len<=m;len++){
                len_value[len][j]=get_sum(j,(j+len-1)%m,a[i]);
            }
        }

        vector<ll> tmp(m,1e18);

        for(ll len=1;len<=m;len++){
            ll mi_ex=1e18;
            for(ll j=0;j<m;j++){
                mi_ex=min(mi_ex,len_value[len][j]+(j+1)*k);
                if(j+len-1>=m){
                    continue;
                }

                
                tmp[j+len-1]=min(tmp[j+len-1],dp[j]+mi_ex+(m-j-1)*k);
            
            }

            mi_ex=1e18;
            for(ll j=m-1;j>=0;j--){
                mi_ex=min(mi_ex,len_value[len][j]+j*k);
                if(j+len-1>=m){
                    continue;
                }
                
                tmp[j+len-1]=min(tmp[j+len-1],dp[j]+mi_ex-j*k);
            }
        }

        /*for(ll j=0;j<m;j++){
            cout<<tmp[j]<<" ";
        }
        cout<<endl;
        */

        dp=tmp;
    }

    cout<<dp[m-1]<<endl;
    




    
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