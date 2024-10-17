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

void solve(ll tc){
    ll n,m;
    cin>>n>>m;

    vector<ll> events(n+1);
    vector<ll> cnt_type_1(m+1,0),cnt_type_2(m+1,0);
    for(ll i=1;i<=n;i++){
        cin>>events[i];
        if(events[i]>0){
            cnt_type_1[events[i]]++;
        }else if(events[i]<0){
            cnt_type_2[abs(events[i])]++;
        }
    }

    vector<ll> dp(m+1,-1e9);
    dp[0]=0;

    ll sz=0;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(events[i]==0){
            sz++;
            for(ll j=sz;j>=0;j--){
                ll x=dp[j]+cnt_type_2[sz-j];// jth point to type2(Inteligence)
                ll y=(j-1>=0 ? dp[j-1] : 0)+cnt_type_1[j];//jth point to typ1(stringth)
                dp[j]=max(x,y);
                ans=max(ans,dp[j]);

            }
        }else if(events[i]>0){
            cnt_type_1[events[i]]--;
        }else if(events[i]<0){
            cnt_type_2[abs(events[i])]--;
        }
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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}