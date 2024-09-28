#include<bits/stdc++.h>
#include <iterator>
#include <iostream>
#include <numeric>
#include <math.h>
#include <cstdlib> 
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
#define fre freopen("fall_in_line_input.txt","r",stdin),freopen("ProblemC_output.txt","w",stdout)
#define arr array 
using namespace std;
bool check(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
    return (y2-y1)*(x3-x2) == (y3-y2)*(x2-x1);
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> x(n),y(n);
    for(ll i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }


    ll iter=100;

    ll same=0;
    while(iter--){
        ll p=rand()%n;
        ll q=rand()%n;

        while(q==p){
            q=rand()%n;
        }   

        ll cnt=0;

        for(ll i=0;i<n;i++){
            cnt=cnt+check(x[p],y[p],x[q],y[q],x[i],y[i]);
        }

        same=max(same,cnt);
    }
    
    

    cout<<"Case #"<<tc<<": "<<n-same<<endl;

    
    

}
int main(){
    boost;

    //pre_cum();
    //prec(10);
	fre;


    ll t=1;
    ll tc=1;
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}