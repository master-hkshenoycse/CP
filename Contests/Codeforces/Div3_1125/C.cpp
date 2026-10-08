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
ll get_cnt(vector<ll> &v){
    set<ll> c;
    ll ret=0;
    for(ll i=0;i<v.size();i++){
        ret=ret+i;
        if(c.find(v[i]-2) != c.end())
            ret--;
        if(c.find(v[i]-4) != c.end())
            ret--;
        c.insert(v[i]);
    }
    return ret;
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    
    map<ll,vector<ll> > help;
    for(ll i=0;i<n;i++){
        if(i+2<n && i+4<n)
            help[a[i]+a[i+2]-a[i+4]].pb(i);
    }

    ll ans=0;

    for(auto it:help){
        vector<ll> od_ind,ev_ind;
        for(auto ind:it.ss){
            if(ind%2==0){
                ev_ind.pb(ind);
            }else{  
                od_ind.pb(ind);
            }
        }

        ans=ans+(od_ind.size())*(ev_ind.size());

        ans=ans+get_cnt(od_ind);
        ans=ans+get_cnt(ev_ind);
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
    cin>>t;

	while(t--){
		solve(tc);
        tc++;
    
	}

    return 0;
    
     
}