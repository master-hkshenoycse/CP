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
vector<ll> get_sol(ll n){

    if(n==4){
        vector<ll> ret;
        for(ll i=1;i<=n;i++){
            ret.pb(i);
        }
        return ret;
    }

    if((n & (n-1))==0){
        vector<ll> ret=get_sol(n-2);
        ret.pb(n-1);
        ret.pb(n);
        return ret;
    }

    vector<ll> ret(n),mark(n+1,0);
    ret[n-1]=n;
    ll req=0;
    ll st=-1;
    for(ll i=40;i>=0;i--){
        if(n & (1ll<<i)){
            st=1;
        }else{
            if(st == 1){
                req+=(1ll<<i);
            }
        }
    }


    ll fs=-1,sc=-1;
    for(ll i=1;i<n;i++){
        if((i & req)==req){
            if(fs==-1){
                fs=i;
            }else{
                sc=i;
            }
        }
    }

    mark[n]=1;
    mark[fs]=1;
    mark[sc]=1;
    ret[n-2]=fs;
    ret[n-3]=sc;


    ll j=1;
    for(ll i=0;i<n-3;i++){
        while(mark[j]==1){
            j++;
        }
        ret[i]=j;
        mark[j]=1;
    }


    return ret;



}
void solve(ll tc){
    ll n;
    cin>>n;

    if(n==5){
        cout<<5<<endl;
        cout<<"2 1 3 4 5"<<endl;
        return;
    }
    vector<ll> sol;
    if((n & (n-1))==0){
        sol=get_sol(n-2);
        sol.pb(n-1);
        sol.pb(n);
    }else if(n%2==0){
        sol=get_sol(n);
        sol.pb(n);
    }else{
        sol=get_sol(n-1);
        sol.pb(n);
    }
    ll get_val=0;
    for(ll i=0;i<n;i++){
        if(i%2==0){
            get_val=(get_val & sol[i]);
        }else{
            get_val=(get_val | sol[i]);
        }
    }

    cout<<get_val<<endl;
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