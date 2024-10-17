/*https://codeforces.com/contest/1278/problem/D*/
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
    ll n;
    cin>>n;

    vector<ll> a(n+1),p(n+1);
    ll root=-1;

    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==i){
            root=i;
        }
    }


    for(ll i=1;i<=n;i++){
        cin>>p[i];
    }

    if(p[1] != root){
        cout<<-1<<endl;
        return;
    }

    vector<ll> dist(n+1,-1),wt(n+1);
    ll max_so_far=0;
    dist[root]=0;
    wt[root]=0;
    
    for(ll i=2;i<=n;i++){
        ll node=p[i];
        ll parent=a[node];

        //cout<<parent<<" "<<dist[parent]<<endl;

        if(dist[parent]==-1){
            cout<<-1<<endl;
            return;
        }

        ll req=max_so_far-dist[parent]+1;
        dist[node]=max_so_far+1;
        wt[node]=req;
        max_so_far++;
    }

    for(ll i=1;i<=n;i++){
        cout<<wt[i]<<" ";
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