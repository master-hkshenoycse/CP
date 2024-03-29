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
    ll a,b,c;
    cin>>a>>b>>c;

    //because the nodes with 1 children do not reduce the leaves, 
    //and adding a node with 2 children increases the count of leaf by 1
    if(c!=a+1){
        cout<<-1<<endl;
        return;
    }

    if(a+b+c==1){
        cout<<0<<endl;
        return;
    }

    ll s=0,st=1,h=1;
    ll last_level_a=a;
    while(s<a){

        s+=st;
        a-=min(s,a);
        last_level_a=a;
        st*=2;
        h++;
    }

    
    
    ll rem=st-last_level_a;
    b-=min(b,rem);

    h+=(b+st-1)/st;

    cout<<h<<endl;




}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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