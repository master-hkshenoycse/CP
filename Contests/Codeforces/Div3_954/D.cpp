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

    ll n;
    cin>>n;

    ll ans=1e18;
    string s;
    cin>>s;

    for(ll i=0;i+1<n;i++){
        ll val=(s[i]-'0')*10+(s[i+1]-'0');
        vector<ll> values;
        values.pb(val);
        for(ll j=0;j<n;j++){
            if(j==i or j==i+1){
                continue;
            }
            values.push_back(s[j]-'0');
        }

        sort(all(values));
        if(values[0]==0){
            cout<<0<<endl;
            return;
        }

        if(values.back()==1){
            ans=min(ans,1ll);
            continue;
        }

        ll sum=0;
        for(auto e:values){
            if(e==1){
                continue;
            }
            sum=sum+e;
        }
        ans=min(ans,sum);
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