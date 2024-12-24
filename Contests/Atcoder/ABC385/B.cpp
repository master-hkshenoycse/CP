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
    ll h,w,x,y;
    cin>>h>>w>>x>>y;

    vector<vector<char> > a(h,vector<char> (w));
    
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin>>a[i][j];
        }
    }

    x--;
    y--;


    string s;
    cin>>s;

    set<pair<ll,ll> > houses;

    for(auto ch:s){
        ll nx=x;
        ll ny=y;

        

        if(ch=='U'){
            nx--;
        }else if(ch=='D'){
            nx++;
        }else if(ch=='L'){
            ny--;
        }else{
            ny++;
        }

        if(a[nx][ny] != '#'){
            x=nx;
            y=ny;

            if(a[nx][ny]=='@'){
                houses.insert({nx,ny});
            }

        }
    }

    cout<<x+1<<" "<<y+1<<" "<<(houses.size())<<endl;


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