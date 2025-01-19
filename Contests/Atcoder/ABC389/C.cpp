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
    ll offset=0,rem_sum=0;
    vector<ll> snakes,len_so_far;

    snakes.pb(0);
    len_so_far.pb(0);

    ll q;
    cin>>q;

    ll ty,inp;
    while(q--){
        cin>>ty;

        if(ty==1){
            cin>>inp;
            len_so_far.push_back(len_so_far.back()+inp);
            snakes.push_back(inp);
        }else if(ty==2){
            offset++;
            rem_sum+=snakes[offset];
            
        }else if(ty==3){
            cin>>inp;

            ll ind_req=offset+inp;
           // cout<<ind_req<<" "<<len_so_far[ind_req]<<endl;

            cout<<len_so_far[ind_req]-snakes[ind_req]-rem_sum<<endl;

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
    //cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}