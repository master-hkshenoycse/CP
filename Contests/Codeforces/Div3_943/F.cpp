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
    map<ll,vector<ll> > help;
    ll n,q;

    cin>>n>>q;
    vector<ll> a(n+1);
    vector<ll> c_xor(n+1,0);

    for(ll i=1;i<=n;i++){
        cin>>a[i];
        c_xor[i]=(c_xor[i-1] ^ a[i]);
        help[c_xor[i]].pb(i);
    }



    ll l,r;
    while(q--){
        cin>>l>>r;
        
        if((c_xor[r] ^ c_xor[l-1])==0){
            cout<<"YES"<<endl;
        }else{
            ll req=c_xor[r];
            auto it=upper_bound(all(help[req]),l-1);

            if(it != help[req].end() and (*it)<r){
                auto nx=upper_bound(all(help[c_xor[l-1]]),*it);
                if(nx != help[c_xor[l-1]].end() and *nx<r){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }else{
                cout<<"NO"<<endl;
            }
        }
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