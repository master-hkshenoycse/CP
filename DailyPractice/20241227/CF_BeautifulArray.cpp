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
    ll a,b;
    cin>>a>>b;

    ll lim=1000000;
    for(ll len=1;len<=1000;len++){
        if(len%2==0){
            ll halfs=(len-1)/2;
            ll min_poss=halfs*(-lim)+halfs*b+b;
            ll max_poss=halfs*b+halfs*lim+b;
            if(a*len>=min_poss and a*len<=max_poss){
                

                vector<ll> sol,max_poss;
                ll s=0;
                for(ll i=0;i<len;i++){
                    if(i<halfs){
                        sol.pb(-1000000);
                        max_poss.pb(b);
                    }else if(i>=halfs){
                        sol.pb(b);
                        if(i==halfs){
                            max_poss.pb(b);
                        }else{
                            max_poss.pb(1000000);
                        }
                    }
                    s+=sol.back();
                }

                for(ll i=0;i<len;i++){
                    ll ex_poss=max_poss[i]-sol[i];
                    ll req=min(ex_poss,a*len-s);
                    sol[i]+=req;
                    s+=req;
                }

                cout<<sol.size()<<endl;
                for(ll i=0;i<len;i++){
                    cout<<sol[i]<<" ";
                }

                return;
            }

        }else{
            ll halfs=(len-2)/2;
            ll min_poss=halfs*(-lim) + (halfs * b)+2*b;
            ll max_poss=halfs*(b)+ halfs*lim+2*b;
            ll s=0;

            if(a*len>=min_poss and a*len<=max_poss){
                vector<ll> sol,max_poss;
                for(ll i=0;i<len;i++){
                    if(i<halfs){
                        sol.pb(-1000000);
                        max_poss.pb(b);
                    }else if(i==halfs+1 or i==halfs){
                        sol.pb(b);
                        max_poss.pb(b);
                    }else{
                        sol.pb(b);
                        max_poss.pb(1000000);
                    }
                    s+=sol.back();
                }

                cout<<sol.size()<<endl;
                for(ll i=0;i<len;i++){
                    ll ex_poss=max_poss[i]-sol[i];
                    ll req=min(ex_poss,a*len-s);
                    sol[i]+=req;
                    s+=req;
                }

                for(ll i=0;i<len;i++){
                    cout<<sol[i]<<" ";
                }

                return;



            }
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