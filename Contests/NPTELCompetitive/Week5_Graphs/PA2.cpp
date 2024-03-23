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
    ll n,m;
    cin>>n>>m;


    vector<ll> in_deg(n,0);
    vector<vector<ll> > adj(n);

    ll x,y;
    while(m--){
        cin>>x>>y;
        adj[y].pb(x);
        in_deg[x]++;
    }

    ll cnt=0;
    queue<ll> q;
    for(ll i=0;i<n;i++){
        if(in_deg[i]==0){
            q.push(i);
        }
    }

    while(q.size()>0){
        ll v=q.front();
        cnt++;
        q.pop();

        for(auto to:adj[v]){
            in_deg[to]--;
            if(in_deg[to]==0){
                q.push(to);
            }
        }
    }




    if(cnt<n){
        cout<<"False"<<endl;
    }else{
        cout<<"True"<<endl;
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