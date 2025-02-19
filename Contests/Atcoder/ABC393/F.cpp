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
ll bit[2000005];
void upd(ll ind,ll n,ll val){
    while(ind<=n){
        bit[ind]=max(bit[ind],val);
        ind+=(ind & (-ind));
    }
}

ll get_query(ll ind){
    ll ret=0;
    while(ind>0){
        ret=max(ret,bit[ind]);
        ind-=(ind & (-ind));
    }
    return ret;
}
void solve(ll tc){
    
    map<ll,ll> help;
    ll n,q;
    cin>>n>>q;

    vector<ll> a(n+1);
    vector<vector<ll> > query(q+1,vector<ll> (2));
    vector<vector<ll> > query_by_index(n+1);
    vector<ll> sol(q+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        help[a[i]]++;
    }

    for(ll i=1;i<=q;i++){
        cin>>query[i][0]>>query[i][1];
        query_by_index[query[i][0]].push_back(i);
        help[query[i][1]]++;
    }

    ll c=0;
    for(auto &it:help){
        c++;
        it.ss=c;
    }

    for(ll i=1;i<=n;i++){
        ll r=get_query(help[a[i]]-1);
        upd(help[a[i]],c,r+1);

        for(auto u:query_by_index[i]){
            ll v=help[query[u][1]];
            sol[u]=get_query(v);
        }


    }

    for(ll i=1;i<=q;i++){
        cout<<sol[i]<<endl;
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