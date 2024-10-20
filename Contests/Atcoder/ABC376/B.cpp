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

    ll l=0,r=1;
    ll ans=0;

    char ch;
    ll p;

    while(q--){
        cin>>ch>>p;
        p--;

        if(ch=='L'){

            if(p==l){
                continue;
            }

            if(p>l){
                if(r>l and r<p){
                    ans=ans+l+n-p;
                }else{
                    ans=ans+(p-l);
                }
            }else{

                if(r<l and r>p){
                    ans=ans+l+n-p;
                }else{
                    ans=ans+(l-p);
                }

            }

            l=p;

        }else{

            if(p==r){
                continue;
            }

            if(p>r){

                if(l>r and l<p){
                    ans=ans+r+n-p;
                }else{
                    ans=ans+(p-r);
                }

            }else{

                if(l<r and l>p){
                    ans=ans+r+n-p;
                }else{
                    ans=ans+(r-p);
                }
            }

            r=p;
        }
        cout<<ans<<" ";
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