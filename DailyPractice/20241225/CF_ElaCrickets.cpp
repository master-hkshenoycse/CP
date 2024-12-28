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
arr<ll,2> central_cordi(vector<ll> &r,vector<ll> &c){
    ll x,y; 
    if(r[0]==r[1])x=r[0];
    else x=r[2];

    if(c[0]==c[1])y=c[0];
    else y=c[2];

    return {x,y};
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> r(3),c(3);
    cin>>r[0]>>c[0]>>r[1]>>c[1]>>r[2]>>c[2];


    ll x,y;
    cin>>x>>y;

    auto p=central_cordi(r,c);
    ll u=p[0],v=p[1];

    if((u==1 or u==n) and (v==1 or v==n)){
        if(u==x or v==y){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{

        if((x+y)%2==(u+v)%2){
            if(x%2==u%2){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            cout<<"YES"<<endl;
        }

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