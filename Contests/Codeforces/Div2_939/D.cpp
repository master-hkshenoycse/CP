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
void do_ops(ll l,ll r,vector<arr<ll,2> > &ops,vector<ll> &a){
    if(l==r){
        if(a[l]){
            a[l]=0;
            ops.pb({l,l});
        }
        return ;
    }

    //ensure all the l,r are 0...r-l
    do_ops(l,r-1,ops,a);

    if(a[r]==r-l){
        return;
    }

    ops.pb({l,r});
    fill(a.begin()+l,a.begin()+r+1,r-l);
    
    //ensure all the l,r are 0...r-l
    do_ops(l,r-1,ops,a);


}
void solve(ll tc){ 
    ll n;
    cin>>n;

    vector<ll> a(n+1),dp(n+1,0),par(n+1,0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }    

    //for a subarray of length l , all elements can be made equal to l
    //hence max possible sum is l*l, 

    for(ll i=1;i<=n;i++){
        dp[i]=dp[i-1]+a[i];
        


        for(ll j=i;j>=1;j--){
            if(dp[i]<dp[j-1]+(i-j+1)*(i-j+1)){
                dp[i]=dp[j-1]+(i-j+1)*(i-j+1);
                par[i]=j;
            }
        }
    }

    
    vector<arr<ll,2> > ops;
    //operations will be done in recursive way

    ll en=n;
    while(en>0){

        if(par[en]){
            ll l=par[en];
            do_ops(l,en,ops,a);
            ops.pb({l,en});
            en=l-1;
        }else{
            en--;
        }
    }

    cout<<dp[n]<<" "<<ops.size()<<endl;
    for(auto op:ops){
        cout<<op[0]<<" "<<op[1]<<endl;
    }

    

     
}   
int main(){
    boost;

    //pre_cum();
    //prec(20);
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