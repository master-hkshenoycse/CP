/*https://codeforces.com/contest/1278/problem/D*/
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

    vector<ll> a(n+1,0),nx(n+1,n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    map<ll,ll> help;
    for(ll i=n;i>=1;i--){
        if(help.find(a[i]) != help.end()){
            nx[i]=help[a[i]];
        }
        help[a[i]]=i;
    }

    ll ans=0,x=0,y=0;


    for(ll i=1;i<=n;i++){

        if(a[x] == a[i]){
            ans+=(a[y] != a[i]);
            y=i;
        }else if(a[y] == a[i]){
            ans+=(a[x] != a[i]);
            x=i;
        }else{
            ll next_x=nx[x];
            ll next_y=nx[y];

            if(next_x < next_y){
                x=i;
                ans++;
            }else{
                y=i;
                ans++;
            }
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