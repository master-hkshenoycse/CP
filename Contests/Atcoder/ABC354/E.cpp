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
ll is_winning(ll mask,vector<ll> &dp,vector<vector<ll> >&compatible){
    if(mask==0){
        return 0;
    }

    if(dp[mask] != -1){
        return dp[mask];
    }



    ll n=compatible.size();

    for(ll i=0;i<n;i++){
        if((mask & (1<<i))){
            for(ll j=i+1;j<n;j++){
                if((mask & (1<<j))){
                    if(compatible[i][j]){
                        if(is_winning(mask ^ (1<<i) ^ (1<<j),dp,compatible)==0){
                            return dp[mask]=1;
                        }
                    }
                }
            }
        }
    }

    return dp[mask]=0;
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<vector<ll> > a(n,vector<ll> (2));
    vector<vector<ll> > compatible(n,vector<ll> (n,0));
    for(ll i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }

    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            if(a[i][0]==a[j][0] or a[i][1]==a[j][1]){
                compatible[i][j]=1;
                compatible[j][i]=1;
            }
        }
    }

    ll lim=(1<<n);
    vector<ll> dp(lim,-1);
    if(is_winning(lim-1,dp,compatible)){
        cout<<"Takahashi"<<endl;
    }else{
        cout<<"Aoki"<<endl;
    }

    

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