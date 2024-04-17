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
    
    ll n,T;
    cin>>n>>T;

    map<ll,vector<ll> > help;
    vector<ll> sol(n,0);
    ll e;

    //for T , for x there is y which is T-x, unique assign them in different subarray
    for(ll i=0;i<n;i++){
        cin>>e;
        help[e].pb(i);
    }

    for(auto &it:help){
        if(it.ss.size()==0){
            continue;
        }

        ll req=T-it.ff;
        if(help.find(req) != help.end()){
            if(it.ff*2==T){
                ll sz=it.ss.size();
                for(ll i=0;i<sz;i++){
                    sol[it.ss[i]]=i%2;
                }

                
            }else{
                while(it.ss.size()>0){
                    sol[it.ss.back()]=1;
                    it.ss.pop_back();
                }

                while(help[req].size()>0){
                    sol[help[req].back()]=0;
                    help[req].pop_back();
                }
            }
        }
    }

    for(ll i=0;i<n;i++){
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