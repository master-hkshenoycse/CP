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
/*https://codeforces.com/contest/1931/submission/246453454
see if DAG can be created from order given in question*/
void solve(ll tc){ 

    ll n,k;
    cin>>n>>k;

    vector<ll> indeg(n+1,0);
    vector<ll> adj[n+1];

    for(ll i=1;i<=k;i++){
        ll e,p=-1;
        for(ll j=1;j<=n;j++){
            cin>>e;
            
            if(j>2){
                indeg[e]++;
                adj[p].pb(e);
            }

            p=e;
        }
    }    

    queue<ll> q;
    vector<ll> ord;

    for(ll i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
            ord.pb(i);
        }
    }

    while(q.size()>0){
        int v=q.front();
        q.pop();

        for(auto to:adj[v]){
            indeg[to]--;
            if(indeg[to]==0){
                q.push(to);
                ord.pb(to);
            }
        }
    }

    if(ord.size()==n){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }


}
int main(){
    boost;

    //pre_cum();
    //prec(20);
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