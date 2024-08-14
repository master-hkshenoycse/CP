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
bool comp(vector<ll> &a,vector<ll> &b){
    return a[0]*b[1] <= b[0]*a[1];
}

void solve(ll tc){
    ll n,k;
    cin>>n>>k;

    ll tot=0;
    vector<ll> a(n),b(n);

    for(ll i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    

    vector<ll> dp(k+k+3,1e9);

    dp[0]=0;

    for(ll i=0;i<n;i++){

        if(a[i]>b[i]){
            swap(a[i],b[i]);
        }

        ll x=a[i],y=b[i];
        ll poss=x+y;

        
        
        vector<ll> ops(poss+1,1e9);
        ops[0]=0;


        for(ll j=1;j<=y-1;j++){
            ops[j]=min(ops[j],x*j);
        }

        for(ll j=y;j<=poss-2;j++){
            ops[j]=min(ops[j],x*(y-1)+(j-y+1));
        }

        for(ll j=1;j<=x-1;j++){
            ops[j]=min(ops[j],y*j);
        }

        for(ll j=x;j<=poss-2;j++){
            ops[j]=min(ops[j],(x-1)*y+(j-x+1));
        }

        ops[poss]=x*y;
        ops[poss-1]=x*y;

        cout<<x<<" "<<y<<endl;

        for(ll j=1;j<=poss;j++){
            cout<<j<<" "<<ops[j]<<endl;
        }
        cout<<endl;


        vector<ll> n_dp(k+k+3,1e9);
        for(ll j=1;j<=k+k;j++){
            for(ll o=1;o<=poss;o++){
                if(j-o>=0){
                    n_dp[j]=min(n_dp[j],dp[j-o]+ops[o]);
                }else{
                    break;
                }
            }
        }

        for(ll j=0;j<=k+k;j++){
            dp[j]=min(dp[j],n_dp[j]);
        }



    }

    ll ans=1e9;

    for(ll i=k;i<=2*k;i++){
        ans=min(ans,dp[i]);
    }

    if(ans==1e9){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
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