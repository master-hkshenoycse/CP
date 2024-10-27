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
void do_rec(ll curr,map<ll,vector<ll> > &help,map<ll,ll> &vis,ll &ans){
    ans=max(ans,curr);
    vis[curr]=1;
    if(help.find(curr) == help.end()){
        return;
    }
    for(auto it:help[curr]){
        if(vis.find(it) == vis.end()){
            do_rec(it,help,vis,ans);
        }
    }
}
void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> a(n+1),len_req(n+1,-1);
    map<ll,vector<ll> > help;
    map<ll,ll> vis;
    for(ll i=1;i<=n;i++){
        cin>>a[i];

        if(i>1 and a[i]+i-1>=n){
            len_req[i]=a[i]+i-1;
            help[len_req[i]].pb(len_req[i]+i-1);
        }

    }

    ll ans=n;   
    do_rec(n,help,vis,ans);
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