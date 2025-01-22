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
ll get_cnt(ll n){
    ll c=0;
    while(n>0){
        c++;
        n=(n & (n-1));
    }
    return c;
}
void solve(ll tc){
    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll> a(n),b(m);
    ll ans=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        ans+=a[i];
    }

    for(ll i=0;i<m;i++){
        cin>>b[i];
    }
    ll lim=(1<<m);
    vector<ll> and_val(lim+1),one_cnt(lim+1);
    for(ll i=1;i<(1<<m);i++){
        ll v=-1,cnt=0;
        for(ll j=0;j<m;j++){
            if(i&(1ll<<j)){
                cnt++;
                if(v==-1){
                    v=b[j];
                }else{
                    v=(v & b[j]);
                }
            }
        }
       and_val[i]=v;
       one_cnt[i]=cnt;
    }

    vector<ll> diff;
    for(ll i=0;i<n;i++){
        vector<ll> min_val(m+1,a[i]);

        for(ll j=1;j<(1<<m);j++){
           
            min_val[one_cnt[j]]=min(min_val[one_cnt[j]],and_val[j]&a[i]);
        }

        for(ll j=1;j<=m;j++){
            diff.pb(min_val[j]-min_val[j-1]);
        }
    }

    
    sort(all(diff));
    for(ll i=0;i<k;i++){
        ans=ans+diff[i];
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