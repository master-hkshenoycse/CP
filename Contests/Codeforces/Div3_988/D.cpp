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
    
    ll n,m,L;
    cin>>n>>m>>L;

    vector<arr<ll,2> > a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }

    vector<arr<ll,2> > p(m);
    for(ll i=0;i<m;i++){
        cin>>p[i][0]>>p[i][1];
    }

    ll i=0,j=0,k=1,ans=0;
    priority_queue<ll> pq;


    while(i<n){
        while(j<m && p[j][0]<=a[i][0]){
            pq.push(p[j][1]);
            j++;
        }

        while(pq.size()>0 && a[i][0]-1+k<=a[i][1]){
            k=k+pq.top();
            pq.pop();
            ans++;
        }

        if(a[i][0]-1+k<=a[i][1]){
            cout<<-1<<endl;
            return;
        }

        i++;
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