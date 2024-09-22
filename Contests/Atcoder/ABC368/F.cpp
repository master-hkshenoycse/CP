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
ll spf[100005];
ll x[100005];

void pre_cum(){
    x[1]=0;
    for(ll i=2;i<=100000;i++){
        if(spf[i]==0){
            for(ll j=i;j<=100000;j+=i){
                if(spf[j]==0){
                    spf[j]=i;
                }
            }
        }
    }

    for(ll i=2;i<=100000;i++){
        ll c=0,j=i;
        while(j%spf[i]==0){
            j/=spf[i];
            c++;
        }
        x[i]=x[j]+c;
    }

}
void solve(ll tc){
    ll n,e;
    cin>>n;

    ll game_value=0;
    for(ll i=1;i<=n;i++){
        cin>>e;
        game_value=(game_value ^ x[e]);
    }

    if(game_value>0){
        cout<<"Anna"<<endl;
    }else{
        cout<<"Bruno"<<endl;
    }


}
int main(){
    boost;

    pre_cum();
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