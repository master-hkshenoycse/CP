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

    vector<ll> x(n+1);
    set<ll> check;
    for(ll i=1;i<=n;i++){
        cin>>x[i];
        check.insert(x[i]);        
    }

    ll resp;
    if(check.size() != n){//i.e x is not a permutation
        ll y=-1;
        ll x=-1;
        
        for(ll i=1;i<=n;i++){
            if(check.find(i) == check.end()){
                y=i;
            }else{
                x=i;
            }
        }

        cout<<"? "<<y<<" "<<x<<endl;
        cin>>resp;

        if(resp == 0){
            cout<<"! A"<<endl;
        }else{
            cout<<"! B"<<endl;
        }


    }else{
        ll r1,r2;
        ll st=-1,en=-1;

        for(ll i=1;i<=n;i++){
            if(x[i]==1){
                st=i;
            }

            if(x[i]==n){
                en=i;
            }
        }
        cout<<"? "<<st<<" "<<en<<endl;
        cin>>r1;

        cout<<"? "<<en<<" "<<st<<endl;
        cin>>r2;

        if(r1>=n-1 && r2>=n-1 && r1==r2){
            cout<<"! B"<<endl;
        }else{
            cout<<"! A"<<endl;
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