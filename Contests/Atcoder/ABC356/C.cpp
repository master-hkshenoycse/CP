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
    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll> no_keys(m);
    vector<vector<ll> > key_in_test(m);
    vector<char> results(m);

    ll e;
    for(ll i=0;i<m;i++){
        cin>>no_keys[i];
        key_in_test[i].resize(no_keys[i]);
        for(ll j=0;j<no_keys[i];j++){
            cin>>key_in_test[i][j];
            key_in_test[i][j]--;
        }
        cin>>results[i];
    }

    ll ans=0;
    ll lim=(1<<n);

    for(ll mask=0;mask<lim;mask++){

        
        ll f=1;
        for(ll i=0;i<m;i++){
            ll cnt=0;
            
            for(auto k:key_in_test[i]){
                if(mask & (1<<k)){
                    cnt++;
                }
            }

            if(results[i]=='o'){
                if(cnt<k){
                    f=0;
                    break;
                }
            }else{
                if(cnt>=k){
                    f=0;
                    break;
                }
            }
        }

        ans+=f;
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