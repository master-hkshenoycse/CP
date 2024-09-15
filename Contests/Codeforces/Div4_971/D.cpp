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

    vector<ll> x_[2];
    map<ll,ll> cnt_x[2];

    ll x,y;
    for(ll i=1;i<=n;i++){
        cin>>x>>y;

        x_[y].pb(x);
        cnt_x[y][x]++;

    }

    ll ans=0;



    for(ll i=0;i<2;i++){
        for(auto c:x_[i]){
            ll b=c-1;
            ll f=c+1;
            if(cnt_x[1-i].find(b)!=cnt_x[1-i].end() and cnt_x[1-i].find(f) != cnt_x[1-i].end()){
                ans++;
            }
        }
    }

    for(auto c:x_[0]){
        if(cnt_x[1].find(c) != cnt_x[1].end()){
            ans=ans+(x_[1].size()-1)+(x_[0].size()-1);
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