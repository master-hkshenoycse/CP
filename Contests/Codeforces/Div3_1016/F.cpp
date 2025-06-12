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

    vector<string> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll max_correct=0;
    set<string> potential[n];

    string inp;
    for(ll i=0;i<m;i++){
        ll curr_correct = 0; 
        for(ll i=0;i<n;i++){
            cin>>inp;
            if(inp == a[i]){
                curr_correct++;
            }
            potential[i].insert(inp);
        }
        max_correct=max(max_correct,curr_correct);
    }

    for(ll i=0;i<n;i++){
        if(potential[i].find(a[i]) == potential[i].end()){
            cout<<-1<<endl;
            return;
        }
    }

    cout<<n+2*(n-max_correct)<<endl;

    
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
