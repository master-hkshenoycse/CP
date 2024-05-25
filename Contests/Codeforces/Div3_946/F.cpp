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
    set<arr<ll,2> > chips_by_x;
    set<arr<ll,2> > chips_by_y;

    ll a,b,n,m;
    cin>>a>>b>>n>>m;

    ll alice_points=0,bob_points=0;

    ll x,y;

    ll lo_x=1,hi_x=a,lo_y=1,hi_y=b;
    for(ll i=1;i<=n;i++){
        cin>>x>>y;
        chips_by_x.insert({x,y});
        chips_by_y.insert({y,x});
    }   


    char ch;
    ll k;

    set<arr<ll,2> >::reverse_iterator rit; 
    for(ll i=1;i<=m;i++){
        cin>>ch>>k;

        vector<arr<ll,2> > chips_rem_x;
        vector<arr<ll,2> > chips_rem_y;

        ll cnt=0;
        if(ch=='U'){
            lo_x=lo_x+k;
            
            for(auto it:chips_by_x){
                if(it[0] < lo_x){
                    cnt++;
                    chips_rem_x.pb(it);
                    chips_rem_y.pb({it[1],it[0]});
                }else{
                    break;
                }
            }

            
        }else if(ch=='D'){
            
  
            hi_x=hi_x-k; 
            for (rit = chips_by_x.rbegin(); rit != chips_by_x.rend(); rit++) {

                auto tmp=*rit;
                //cout<<tmp[0]<<" "<<tmp[1]<<endl;
                if((*rit)[0] > hi_x){
                    cnt++;
                    auto tmp=*rit;
                    chips_rem_x.pb(tmp);
                    chips_rem_y.pb({tmp[1],tmp[0]});
                }else{
                    break;
                }
            }
        }else if(ch=='L'){
            lo_y=lo_y+k;
            for(auto it:chips_by_y){
                if(it[0] < lo_y){
                    cnt++;

                    chips_rem_y.pb(it);
                    chips_rem_x.pb({it[1],it[0]});
                }else{
                    break;
                }
            }
        }else if(ch=='R'){

            hi_y=hi_y-k;
            for (rit = chips_by_y.rbegin(); rit != chips_by_y.rend(); rit++) {
                if((*rit)[0] > hi_y){
                    cnt++;
                    auto tmp=*rit;
                    chips_rem_y.pb(tmp);
                    chips_rem_x.pb({tmp[1],tmp[0]});
                }else{
                    break;
                }
            }


        }

        for(auto it:chips_rem_x){
            chips_by_x.erase(it);
        }

        for(auto it:chips_rem_y){
            chips_by_y.erase(it);
        }

        if(i%2){
            alice_points+=cnt;
        }else{
            bob_points+=cnt;
        }
    }

    cout<<alice_points<<" "<<bob_points<<endl;
    
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