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
    cin>>m>>n;

    string s;
    getline(cin,s);

    vector<arr<ll,3> >points(n);
    for(ll i=0;i<n;i++){
        cin>>points[i][1]>>points[i][0];
        points[i][2]=i;
    } 

    sort(all(points));
    ll tot=0;
    vector<arr<ll,2> > selected_points;
    for(ll i=0;i<2*m;i++){
        tot+=points[i][0];

        selected_points.push_back({points[i][1],points[i][2]});
    }

    sort(all(selected_points));

    ll lo=0,hi=2*m-1;
    cout<<tot<<endl;
    while(hi>lo){
        cout<<selected_points[lo][1]+1<<" "<<selected_points[hi][1]+1<<endl;
        lo++;
        hi--;
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