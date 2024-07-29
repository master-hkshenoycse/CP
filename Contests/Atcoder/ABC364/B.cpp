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
    ll h,w;
    cin>>h>>w;

    ll sx,sy;
    cin>>sx>>sy;

    sx--;
    sy--;

    vector<vector<char> > board(h,vector<char> (w));
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin>>board[i][j];
        }
    }

    


    string x;
    cin>>x;

    for(auto ch:x){
        if(ch=='L'){
            if(sy-1>=0 and board[sx][sy-1]=='.'){
                sy--;
            }
        }else if(ch=='R'){
            if(sy+1<w and board[sx][sy+1]=='.'){
                sy++;
            }
        }else if(ch=='U'){
            if(sx-1>=0 and board[sx-1][sy]=='.'){
                sx--;
            }
        }else{
            if(sx+1<h and board[sx+1][sy]=='.'){
                sx++;
            }
        }
    }

    cout<<sx+1<<" "<<sy+1<<endl;


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