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
ll get_mex(vector<ll> &a){
    ll n=a.size();
    vector<ll> cnt(n+2,0);

    for(auto e:a){
        if(e<=n){
            cnt[e]++;
        }
    }

    ll mex=0;
    while(cnt[mex]>0){
        mex++;
    }

    return mex;
}


void solve(ll tc){
    ll n;
    cin>>n; 

    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    vector<vector<ll> > ops;

    while(get_mex(a) > 0){

        ll n=a.size();
        ll fs_zero=-1,ls_zero=-1;

        for(ll i=0;i<n;i++){
            if(a[i]==0){
                if(fs_zero==-1){
                    fs_zero=i;
                }
                ls_zero=i;
            }
        }



        if(ls_zero-fs_zero+1<n && ls_zero!=fs_zero){
            
            ops.pb({fs_zero,ls_zero});
            vector<ll> tmp;
            for(ll j=fs_zero;j<=ls_zero;j++){
                tmp.pb(a[j]);
            }

            vector<ll> nx;
            for(ll j=0;j<fs_zero;j++){
                nx.push_back(a[j]);
            }

            nx.pb(get_mex(tmp));

            for(ll j=ls_zero+1;j<n;j++){
                nx.pb(a[j]);
            }

            a=nx;
            

        }else if(fs_zero == ls_zero){

            if(fs_zero+1<n){
                ops.pb({fs_zero,fs_zero+1});
                vector<ll> tmp;
                tmp.pb({a[fs_zero]});
                tmp.pb({a[fs_zero+1]});

                vector<ll> nx;
                for(ll j=0;j<fs_zero;j++){
                    nx.pb(a[j]);
                }

                nx.pb(get_mex(tmp));

                for(ll j=fs_zero+2;j<n;j++){
                    nx.pb(a[j]);
                }
                
                a=nx;


            }else if(fs_zero-1>=0){
                ops.pb({fs_zero-1,fs_zero});
                
                vector<ll> tmp;
                tmp.pb({a[fs_zero-1]});
                tmp.pb({a[fs_zero]});
                
                vector<ll> nx;
                for(ll j=0;j<fs_zero-1;j++){
                    nx.pb(a[j]);
                }

                nx.pb(get_mex(tmp));

                for(ll j=fs_zero+1;j<n;j++){
                    nx.pb(a[j]);
                }

                a=nx;
            }

        }else{

            vector<ll> t1;
            for(ll j=fs_zero;j<=ls_zero-2;j++){
                t1.pb(a[j]);
            }

            ops.pb({fs_zero,ls_zero-2});

            vector<ll> nx;
            for(ll j=0;j<fs_zero;j++){
                nx.push_back(a[j]);
            }

            nx.pb(get_mex(t1));


            for(ll j=ls_zero-1;j<n;j++){
                nx.pb(a[j]);
            }

            a=nx;

            
        }

      
    }

    if(a.size()>1){
        ops.pb({0,a.size()-1});
    }

    cout<<ops.size()<<endl;
    for(auto o:ops){
        cout<<o[0]+1<<" "<<o[1]+1<<endl;
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