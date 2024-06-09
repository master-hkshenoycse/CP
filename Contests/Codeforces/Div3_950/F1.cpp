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

    vector<ll> sol(k,0);
    ll tot=0;

    ll x,y;
    map<ll,vector<arr<ll,2> > > help;
    for(ll i=0;i<k;i++){
        cin>>x>>y;
        help[y].push_back({x,i});
    }

    ll prev=1;
    ll val=0;



    for(auto it:help){
        
        vector<arr<ll,2> > x=it.ss;
        sort(all(x));
        ll max_val=x.back()[0];
        ll ind=x.back()[1];

        if(max_val>val){

            sol[ind]=1;
            tot=tot+(it.first-prev)*(n-val);
            prev=it.first;
            val=max_val;
        }

    }

    tot=tot+(m+1-prev)*(n-val);

    cout<<tot<<endl;
    for(ll i=0;i<k;i++){
        cout<<sol[i]<<" ";
    }
    cout<<endl;

    


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