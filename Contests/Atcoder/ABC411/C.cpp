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
    ll n,q;
    cin>>n>>q;

    vector<ll> col(n+1,0);
    ll ind;
    ll intervals=0;
    
    for(ll i=1;i<=q;i++){
        cin>>ind;

        if(col[ind]==0){
            if(ind-1>=0 && ind+1<=n && col[ind-1] && col[ind+1]){
                intervals--;
            }else if(ind-1>=0 && col[ind-1]){

            }else if(ind+1<=n && col[ind+1]){

            }else{
                intervals++;
            }

        }else{

            if(ind-1>=0 && ind+1<=n && col[ind-1] && col[ind+1]){
                intervals++;
            }else if(ind-1>=0 && col[ind-1]){

            }else if(ind+1<=n && col[ind+1]){

            }else{
                intervals--;
            }

        }

        col[ind] = 1 - col[ind];
        cout<<intervals<<endl;
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