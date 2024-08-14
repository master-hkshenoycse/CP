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
    ll xc,yc,k;
    cin>>xc>>yc>>k;

    ll sum_x=xc*k;
    ll sum_y=yc*k;

    vector<ll> x_k,y_k;

    
    for(ll i=1;i<=k-1;i++){
        x_k.push_back(i);
        y_k.push_back(i);
        sum_x-=i;
        sum_y-=i;
    }

    x_k.push_back(sum_x);
    y_k.push_back(sum_y);

    for(ll i=0;i<k;i++){
        for(ll j=i+1;j<k;j++){
            if(x_k[i]==x_k[j] and y_k[i]==y_k[j]){
                x_k[i]++;
                x_k[j]--;

                y_k[i]--;
                y_k[j]++;


                break;
            }
        }
    }

    for(ll i=0;i<k;i++){
        cout<<x_k[i]<<" "<<y_k[i]<<endl;
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