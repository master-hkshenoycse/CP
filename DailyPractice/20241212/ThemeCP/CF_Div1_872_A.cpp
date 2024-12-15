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

    vector<ll> csum(m+1,0);
    ll x,cnt_l=0,cnt_r=0;

    for(ll i=1;i<=n;i++){
        cin>>x;

        if(x==-1){
            cnt_l++;
        }else if(x==-2){
            cnt_r++;
        }else{
            csum[x]=1;
        }
    }

    for(ll i=1;i<=m;i++){
        csum[i]+=csum[i-1];
    }

    ll ans=0;
    ans=max(ans,min(m,cnt_l+csum[m]));
    ans=max(ans,min(m,cnt_r+csum[m]));

    for(ll i=1;i<=m;i++){
        if(csum[i]-csum[i-1]==1){

            ll lef_poss=min(i-1,csum[i-1]+cnt_l);
            ll right_poss=min(m-i,csum[m]-csum[i]+cnt_r);

            ans=max(ans,lef_poss+right_poss+1);



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
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}